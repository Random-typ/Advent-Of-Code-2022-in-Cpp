#include "day2.h"

std::string day2()
{
	std::string input = basics::getInput("day2") + "\n\n"; // append new line spares about 4 lines of code
	size_t score = 0;
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		std::string shapes = input.substr(lastPos + 1, pos - lastPos - 1);
		if (shapes.size() < 2)
			continue;

		char opponent = shapes[0], me = shapes[2];
		if (opponent == me - 23)
		{
			score += 3;
		}
		switch (me)
		{
		case 'X':// Rock
			score += 1;
			if (opponent == 'C')
				score += 6;
			break;
		case 'Y':// Paper
			score += 2;
			if (opponent == 'A')
				score += 6;
			break;
		case 'Z':// Scissors
			score += 3;
			if (opponent == 'B')
				score += 6;
			break;
		}
	}
    return "My total score would be " + std::to_string(score);
}

std::string day2Part2()
{ 
	
	std::string input = basics::getInput("day2") + "\n\n"; // append new line spares about 4 lines of code
	size_t score = 0;
	for (int lastPos = -1, pos = input.find("\n"); pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1))
	{
		std::string shapes = input.substr(lastPos + 1, pos - lastPos - 1);
		if (shapes.size() < 2)
			continue;

		char opponent = shapes[0], outcome = shapes[2], me = 0;

		switch (outcome)
		{
		case 'X':// Loose
			if (opponent == 'A')
			{
				me = 'Z';
			}
			if (opponent == 'B')
			{
				me = 'X';
			}
			if (opponent == 'C')
			{
				me = 'Y';
			}
			break;
		case 'Y':// Draw
			me = opponent + 23;
			break;
		case 'Z':// Win
			if (opponent == 'A')
			{
				me = 'Y';
			}
			if (opponent == 'B')
			{
				me = 'Z';
			}
			if (opponent == 'C')
			{
				me = 'X';
			}
			break;
		}
		if (opponent == me - 23)
		{
			score += 3;
		}
		switch (me)
		{
		case 'X':// Rock
			score += 1;
			if (opponent == 'C')
				score += 6;
			break;
		case 'Y':// Paper
			score += 2;
			if (opponent == 'A')
				score += 6;
			break;
		case 'Z':// Scissors
			score += 3;
			if (opponent == 'B')
				score += 6;
			break;
		}
	}
	return "My total score would be " + std::to_string(score);
}
