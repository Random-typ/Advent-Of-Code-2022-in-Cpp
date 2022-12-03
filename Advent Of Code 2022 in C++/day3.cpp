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
			for (size_t ii = 0; ii < secondCompartment.size(); ii++)
			{
				if (secondCompartment[ii] == firstCompartment[i])
				{
					duplicates += firstCompartment[i];
					// break out of this backpack
					i = firstCompartment.size();
					break;
				}
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
