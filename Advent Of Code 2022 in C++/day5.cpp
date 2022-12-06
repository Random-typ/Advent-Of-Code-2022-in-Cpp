#include "day5.h"

void day5PrintOut(std::vector<std::vector<char>> _crates, COORD _coord)
{
	std::string out;
	// x-axis numbering
	for (size_t i = 0; i < _crates.size(); i++)
	{
		out += " " + std::to_string(i) + "  ";
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
			out.insert(ii * 4, (std::string)"[" + _crates[ii][i] + "] ");
		}
	}
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _coord);
	std::cout << out;
}

std::string day5()
{
	std::string input = basics::getInput("day4") + "\n\n"; // append new line spares about 4 lines of code
	input = (std::string)
		"    [D]    \n" +
		"[N] [C]    \n" +
		"[Z] [M] [P]\n" +
		" 1   2   3 \n\n";
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
		size_t x = (pos % width + 2)/ 5;
		size_t y = height - (pos + 1) / width;
		
		if (crates.size() <= x)
		{// resize of necessary
			crates.resize(x + 1);
		}
		if (crates[x].size() <= x)
		{// resize of necessary
			crates[x].resize(y + 1);
		}
		crates[x][y] = crate;
	}
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	day5PrintOut(crates, info.dwCursorPosition);

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



	// step 2. move the crates accordingly

	// optional: print out stack state in the console (very fancy :D)

	return std::string();
}
