#include "day4.h"

std::string day4()
{
	std::string input = basics::getInput("day4") + "\n\n"; // append new line spares about 4 lines of code
	input = "2-4,6-8\n2-3,4-5\n5-7,7-9\n2-8,3-7\n6-6,4-6\n2-6,4-8\n\n";
	size_t pairCount = 0;
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		// get elves areas
		std::string pair = input.substr(lastPos + 1, pos - lastPos - 1);
		if (pair.empty())
			continue;
		std::string firstElf = pair.substr(0, pair.find(','));
		std::string secondElf = pair.substr(pair.find(',') + 1);
		int firstElfStart = std::stoi(firstElf.substr(0, firstElf.find('-')));
		int firstElfEnd = std::stoi(firstElf.substr(firstElf.find('-') + 1));
		int secondElfStart = std::stoi(secondElf.substr(0, secondElf.find('-')));
		int secondElfEnd = std::stoi(secondElf.substr(secondElf.find('-') + 1));
		// check if first elf areas fit into second elf areas
		if (firstElfStart >= secondElfStart && firstElfEnd <= secondElfEnd)
		{
			pairCount++;
			continue;
		}
		// check if second elf areas fit into first elf areas
		if (secondElfStart >= firstElfStart && secondElfEnd <= firstElfEnd)
		{
			pairCount++;
		}
	}
	return std::to_string(pairCount) + " pairs are fully contained by each other.";
}

std::string day4Part2()
{
	std::string input = basics::getInput("day4") + "\n\n"; // append new line spares about 4 lines of code
	size_t pairCount = 0;
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		// get elves areas
		std::string pair = input.substr(lastPos + 1, pos - lastPos - 1);
		if (pair.empty())
			continue;
		std::string firstElf = pair.substr(0, pair.find(','));
		std::string secondElf = pair.substr(pair.find(',') + 1);
		int firstElfStart = std::stoi(firstElf.substr(0, firstElf.find('-')));
		int firstElfEnd = std::stoi(firstElf.substr(firstElf.find('-') + 1));
		int secondElfStart = std::stoi(secondElf.substr(0, secondElf.find('-')));
		int secondElfEnd = std::stoi(secondElf.substr(secondElf.find('-') + 1));
		// check if first elf areas fit into second elf areas
		if (firstElfStart >= secondElfStart && firstElfStart <= secondElfEnd)
		{
			pairCount++;
			continue;
		}
		if (firstElfEnd >= secondElfStart && firstElfEnd <= secondElfEnd)
		{
			pairCount++;
			continue;
		}
		if (secondElfStart >= firstElfStart && secondElfStart <= firstElfEnd)
		{
			pairCount++;
			continue;
		}
	}
	return std::to_string(pairCount) + " assignment pairs ranges overlap.";
}
