#include "day8.h"

bool day8IsVisible(size_t _row, size_t _column, std::vector<std::vector<__int8>> _treeGrid)
{
	// get grid dimensions
	size_t width = _treeGrid[0].size();
	size_t height = _treeGrid.size();

	// check if trees location is on the edge
	if (// check beginning
		!_row || !_column ||
		// check end
		_row == height - 1 || _column == width - 1)
	{
		return true;
	}
	// get tree height
	__int8 treeHeight = _treeGrid[_row][_column];
	// check left
	bool left = true;
	for (size_t i = 0; i < _column; i++)
	{
		if (_treeGrid[_row][i] >= treeHeight)
		{
			left = false;
		}
	}
	if (left)
	{
		// tree is visible from left
		return true;
	}
	// check right
	bool right = true;
	for (size_t i = _column + 1; i < width; i++)
	{
		if (_treeGrid[_row][i] >= treeHeight)
		{
			right = false;
		}
	}
	if (right)
	{
		// tree is visible from right
		return true;
	}
	// check top
	bool top = true;
	for (size_t i = 0; i < _row; i++)
	{
		if (_treeGrid[i][_column] >= treeHeight)
		{
			top = false;
		}
	}
	if (top)
	{
		// tree is visible from top
		return true;
	}
	// check bottom
	bool bottom = true;
	for (size_t i = _row + 1; i < height; i++)
	{
		if (_treeGrid[i][_column] >= treeHeight)
		{
			bottom = false;
		}
	}
	if (bottom)
	{
		// tree is visible from top
		return true;
	}
	// tree is not visible
	return false;
}

std::string day8()
{
	//     row      column  height
	//	    \/        \/      \/
	std::vector<std::vector<__int8>> treeGrid;

	std::string input = basics::getInput("day8") + "\n\n";

	for (int lastPos = -1, pos = input.find("\n"), rowIndex = 0; pos != std::string::npos; lastPos = pos, pos = input.find("\n", pos + 1), rowIndex++)
	{
		std::string row = input.substr(lastPos + 1, pos - lastPos - 1);
		if (row.empty())
		{
			continue;
		}
		// resize array
		treeGrid.resize(rowIndex + 1);
		treeGrid[rowIndex].resize(row.size());
		// copy data to array (supa fast)
		memcpy_s(treeGrid[rowIndex].data(), row.size(), row.data(), row.size());
	}
	size_t visibleCounter = 0;
	for (size_t row = 0; row < treeGrid.size(); row++)
	{
		for (size_t column = 0; column < treeGrid[row].size(); column++)
		{
			bool isVisible = day8IsVisible(row, column, treeGrid);
			if (isVisible)
			{
				visibleCounter++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			std::cout << treeGrid[row][column];
		}
		std::cout << "\n";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return "There are " + std::to_string(visibleCounter) + " visible trees.";
}
