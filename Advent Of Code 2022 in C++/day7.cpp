#include "day7.h"

day7Directory& day7Directory::getdir(std::string _path)
{
	if (_path == "/")
	{// get root
		if (!parent)
		{
			return *this;
		}
		for (day7Directory& dir : parent->subdirectorys)
		{
			if (!dir.parent)
			{
				return dir;
			}
		}
		return getdir(_path);
	}
	if (_path[0] == '/')
	{
		_path.erase(_path.begin());
	}
	if (size_t pos = _path.find('/'); pos != std::string::npos)
	{
		day7Directory& dir = getdir(_path.substr(0, pos));
		return dir.getdir(_path.substr(pos));
	}
	for (day7Directory& dir : subdirectorys)
	{
		if (dir.name == _path)
		{
			return dir;
		}
	}
	// dir doesnt exist -> create it
	subdirectorys.emplace_back(_path, 0, this);
	return subdirectorys.back();
}

const size_t day7Directory::getSize(size_t maxsize)
{
	if (!isDirectory())
	{
		return size;
	}
	size_t dirSize = 0;
	for (day7Directory dir : subdirectorys)
	{
		if (dir.isDirectory() && maxsize)
		{
			size_t s = dir.getSize();
			if (s <= maxsize)
			{
				dirSize += dir.getSize();
			}
			continue;
		}
		dirSize += dir.getSize();
	}
	return dirSize;
}

const size_t day7Directory::getDirsAtMostOf(std::vector<day7Directory>& _dirs, size_t maxsize)
{
	size_t size = 0;
	for (day7Directory dir : subdirectorys)
	{
		if (dir.isDirectory())
		{
			dir.getDirsAtMostOf(_dirs, maxsize);
			size_t sizetmp = dir.getSize();
			if (sizetmp <= maxsize)
			{
				size += sizetmp;
				_dirs.push_back(dir);
			}
		}
		size_t sizetmp = dir.getSize();

		size += sizetmp;

		continue;
	}
	return size;
}

const bool day7Directory::isDirectory()
{
	return !size;
}

const bool day7Directory::doesntContainDirectorys()
{
	for (day7Directory dir : subdirectorys)
	{
		if (dir.isDirectory())
		{
			return false;
		}
	}
	return true;
}

const std::string day7Directory::print(size_t _nest)
{
	std::string out;
	if (!parent)
	{// root
		out += "- / (dir)\n";
		_nest++;
	}
	for (auto dir : subdirectorys)
	{
		if (dir.isDirectory())
		{
			out +=	printNest(_nest) + "- " + dir.name + " (dir)\n" +
					dir.print(_nest + 1);
			continue;
		}
		out += printNest(_nest) + "- " + dir.name + " (file, size=" + std::to_string(dir.size) + ")\n";
	}
	return out;
}

const std::string day7Directory::printNest(size_t _nest)
{
	std::string str;
	str.resize(_nest * 2, ' ');
	return str;
}

int count(day7Directory _root) {
	int num = 0;
	for (size_t i = 0; i < _root.subdirectorys.size(); i++)
	{
		if (_root.subdirectorys[i].isDirectory())
		{
			num += count(_root.subdirectorys[i]);
		}
		num ++;
	}
	return num;
}

std::string day7()
{
	std::string input = basics::getInput("day7") + "\n\n";
	day7Directory root;
	root.name = "/";
	std::string path = "/";
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		std::string line = input.substr(lastPos + 1, pos - lastPos - 1);
		if (line.size() < 2)
		{
			continue;
		}
		if (line[0] == '$')
		{// command
			std::string command = line.substr(2, line.find(' ', 2) - 2);
			if (command == "cd")
			{
				std::string arg = line.substr(line.find(' ', 2) + 1);
				if (arg == "/")
				{
					path = "/";
					continue;
				}
				if (arg == "..")
				{
					path.erase(path.begin() + path.find_last_of('/'), path.end());
					if (path.empty())
					{
						path = "/";
					}
					continue;
				}
				if (path.back() != '/')
				{
					path += '/';
				}
				path += arg;
				continue;
			}
			if (command == "ls");
			continue;
		}
		std::string size = line.substr(0, line.find(' '));
		day7Directory newdir;

		if (path == "/a/e")
		{
			newdir.parent = &root.getdir(path);

		}
		newdir.parent = &root.getdir(path);

		if (size != "dir")
		{
			newdir.size = std::stoull(size);
		}
		newdir.name = line.substr(size.size() + 1);
		day7Directory& dir = root.getdir(path); 
		dir.subdirectorys.push_back(newdir);
	}
	

	std::cout << root.print();
	std::vector<day7Directory> d;

	size_t size = 0; 
	root.getDirsAtMostOf(d, 100000);
	for (size_t i = 0; i < d.size(); i++)
	{
		size += d[i].getSize();
	}
	return "The total size of these directorys is " + std::to_string(size) + ".";
}