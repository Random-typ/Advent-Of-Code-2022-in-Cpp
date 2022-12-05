#include "day3.h"

std::string day3()
{
	std::string input = basics::getInput("day3") + "\n\n"; // append new line spares about 4 lines of code
	size_t score = 0;
	std::string duplicates;
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		std::string rucksack = input.substr(lastPos + 1, pos - lastPos - 1);
		std::string firstCompartment = rucksack.substr(0, rucksack.size() / 2);
		std::string secondCompartment = rucksack.substr(rucksack.size() / 2);
		// compare compartments
		for (size_t i = 0; i < firstCompartment.size(); i++)
		{
			if (secondCompartment.find(firstCompartment[i]) != std::string::npos)
			{
				duplicates += firstCompartment[i];
				break;
			}
		}
	}
	// calculate sum of the duplicates
	size_t sum = 0;
	for (size_t i = 0; i < duplicates.size(); i++)
	{
		if (duplicates[i] > 'a')
		{
			sum += duplicates[i] - 96;
			continue;
		}
		sum += duplicates[i] - 38;
	}
	return "The sum of the priorities is " + std::to_string(sum) +".";
}

std::string day3Part2()
{
	std::string input = basics::getInput("day3") + "\n\n"; // append new line spares about 4 lines of code
	std::string badges;
	std::vector<std::string> rucksacks;
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		std::string rucksack = input.substr(lastPos + 1, pos - lastPos - 1);
		// create group
		rucksacks.push_back(rucksack);
		if (rucksacks.size() < 3)
			continue;
		// find badge
		for (size_t i = 0; i < rucksacks[0].size(); i++)
		{
			if (rucksacks[1].find(rucksacks[0][i]) != std::string::npos && 
				rucksacks[2].find(rucksacks[0][i]) != std::string::npos)
			{
				badges += rucksacks[0][i];
				break;
			}
		}
		rucksacks.clear();
	}
	// calculate sum of the badges
	size_t sum = 0;
	for (size_t i = 0; i < badges.size(); i++)
	{
		if (badges[i] > 'a')
		{
			sum += badges[i] - 96;
			continue;
		}
		sum += badges[i] - 38;
	}
	return "The sum of the priorities is " + std::to_string(sum) + ".";
}
