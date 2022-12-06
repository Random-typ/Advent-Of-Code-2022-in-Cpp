#include "day5.h"

size_t height = 0;
void day5PrintOut(std::vector<std::vector<char>> _crates, COORD _coord)
{
	// get max height
	for (const auto column : _crates)
	{
		if (column.size() > height)
		{
			height = column.size();
		}
	}
	std::string out;
	// x-axis numbering
	for (size_t i = 0; i < _crates.size(); i++)
	{
		out += " " + std::to_string(i + 1) + "  ";
	}
	for (size_t i = 0, run = 1; run; i++)
	{
		run = 0;
		out.insert(0, "\n");
		for (size_t ii = 0; ii < _crates.size(); ii++)
		{
			if (_crates[ii].size() <= i)
			{
				out.insert(ii * 4, (std::string)"    ");
				continue;
			}
			run = 1;
			if (!_crates[ii][i])
			{
				out.insert(ii * 4, (std::string)"[ ] ");
				continue;
			}
			out.insert(ii * 4, (std::string)"[" + _crates[ii][i] + "] ");
		}
	}
	// adjust height
	int currentheight = 0;
	for (int i = 0; (i = out.find('\n', i)) != std::string::npos; i++) {
		currentheight++;
	}
	for (;currentheight < height + 1; currentheight++)
	{
		size_t start = out.find_last_of("\n");
		size_t end = out.substr(0, start - 1).find_last_of("\n");
		size_t widht = start - end - 1;
		std::string insrt;
		insrt.resize(widht, ' ');
		out.insert(0, insrt + "\n");
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _coord);
	std::cout << out << "\n";
}

std::string day5()
{
	std::string input = basics::getInput("day5") + "\n\n"; // append new line spares about 4 lines of code
	std::string initialCrates;
	// read initial crate state
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		// get elves areas
		std::string row = input.substr(lastPos + 1, pos - lastPos);
		if (row.size() < 2)
		{
			break;
		}
		initialCrates += row;
	}
	// parse initial crate state
	//	  x-axis  y-axis crate-type
	//      \/      \/       \/
	std::vector<std::vector<char>> crates;
	for (int width = initialCrates.find("\n") + 1, pos = initialCrates.find("["); pos != std::string::npos; pos = initialCrates.find("[", pos + 1))
	{
		
		char crate = initialCrates[pos + 1];
		size_t height = initialCrates.length() / width - 2;
		size_t x = (pos % width)/ 4;
		size_t y = height - (pos / width);
		
		if (crates.size() <= x)
		{// resize of necessary
			crates.resize(x + 1);
		}
		if (crates[x].size() <= y)
		{// resize of necessary
			crates[x].resize(y + 1);
		}
		crates[x][y] = crate;
	}
	// get console cursor pos 
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	day5PrintOut(crates, info.dwCursorPosition);

	// move crates according to plan
	for (int lastPos = initialCrates.size(), pos = input.find("\n", initialCrates.size() + 1); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		// get movement plan
		std::string plan = input.substr(lastPos + 1, pos - lastPos);
		size_t start = plan.find(' ');
		if (start == std::string::npos)
		{// done
			break;
		}
		size_t end = plan.find(' ', start + 1);
		int move = std::stoi(plan.substr(start, end));
		start = plan.find(' ', end + 1);
		end = plan.find(' ', start + 1);
		int from = std::stoi(plan.substr(start, end)) - 1;
		start = plan.find(' ', end + 1);
		end = plan.find(' ', start + 1);
		int to = std::stoi(plan.substr(start, end)) - 1;
		// move crates
		for (size_t i = 0; i < move; i++)
		{
			crates[to].insert(crates[to].end(), crates[from].back());
			crates[from].pop_back();
		}
		Sleep(30);// animation speed
		day5PrintOut(crates, info.dwCursorPosition);
	}
	std::string topCrates;
	for (size_t i = 0; i < crates.size(); i++)
	{
		topCrates += crates[i].back();
	}
	
	return "The top crates are: " + topCrates;
}
