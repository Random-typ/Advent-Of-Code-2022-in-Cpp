#pragma once
#include "basics.h"
#include <Windows.h>

bool day8IsVisible(size_t _row, size_t _column, std::vector<std::vector<__int8>> _treeGrid);
int day8Part2GetScenicScore(size_t _row, size_t _column, std::vector<std::vector<__int8>> _treeGrid);
std::string day8();
std::string day8Part2();