#include "day1.h"

std::string day1()
{
    std::string input = basics::getInput("day1") + "\n\n"; // append new line spares about 4 lines of code
	std::vector<int> elvs;
	for (int lastPos = -1, pos = input.find("\n"), calories = 0; pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		std::string numbstr = input.substr(lastPos + 1, pos - lastPos - 1);
		if (numbstr.empty())
		{// new elf
			elvs.push_back(calories);
			calories = 0;// reset calories for next elf
			continue;
		}
		calories += std::stoi(numbstr);
	}
	// find highest number of calories
	size_t highest = 0, Index = 0;
	for (size_t i = 0; i < elvs.size(); i++)
	{
		if (elvs[i] > highest)
		{// found new highest
			highest = elvs[i];
			Index = i;
		}
	}
	// Answer
	return "Elf number " + std::to_string(Index) + " has the highest calories with " + std::to_string(highest) + " calories.";
}

std::string day1Part2()
{
	std::string input = basics::getInput("day1") + "\n\n"; // append new line spares about 4 lines of code
	std::vector<int> elvs;
	for (int lastPos = -1, pos = input.find("\n"), calories = 0; pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		std::string numbstr = input.substr(lastPos + 1, pos - lastPos - 1);
		if (numbstr.empty())
		{// new elf
			elvs.push_back(calories);
			calories = 0;// reset calories for next elf
			continue;
		}
		calories += std::stoi(numbstr);
	}
	// sort 
	for (size_t i = 0; i < elvs.size(); i++)
	{
		for (size_t ii = 0; ii < elvs.size(); ii++)
		{
			if (elvs[ii] > elvs[i])
			{
				int tmp = elvs[i];
				elvs[i] = elvs[ii];
				elvs[ii] = tmp;
			}
		}
	}
	// Answer
	return "The top three elves have " + std::to_string(elvs[elvs.size() - 1] + elvs[elvs.size() - 2] + elvs[elvs.size() - 3]) + " calories together.";
}
