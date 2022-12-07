#include "day6.h"
/* returns true on no recurrence yy*/
bool day6checkRecurrence(std::string _str)
{
	for (size_t i = 0; i < _str.size(); i++)
	{
		if (_str.find(_str[i], i + 1) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

std::string day6()
{
	std::string input = basics::getInput("day6");
	for (size_t i = 4; i < input.size(); i++)
	{
		std::string marker = input.substr(i - 4, 4);
		if (!day6checkRecurrence(marker))
		{
			return "The first marker appears after " + std::to_string(i) + " characters";
		}
	}
	return "There is no marker in this ";
}

std::string day6Part2()
{
	std::string input = basics::getInput("day6");
	for (size_t i = 14; i < input.size(); i++)
	{
		std::string marker = input.substr(i - 14, 14);
		if (!day6checkRecurrence(marker))
		{
			return "The first marker appears after " + std::to_string(i) + " characters";
		}
	}
	return "There is no marker in this ";
}