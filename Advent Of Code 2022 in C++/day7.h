#pragma once
#include "basics.h"

struct day7Directory {
	std::string name;
	size_t size = 0;
	day7Directory* parent = nullptr;
	std::vector<day7Directory> subdirectorys;
	/* retrieves directory | if it doesnt exist it will be created */
	day7Directory& getdir(std::string _name);
	day7Directory getSmallestDir(size_t _size, day7Directory _smallest = {"", (size_t)-1});
	const size_t getSize(size_t maxsize = 0);
	const size_t getDirsAtMostOf(std::vector<day7Directory>& _dirs, size_t maxsize = 0);
	const bool isDirectory();
	const bool doesntContainDirectorys();
	const std::string print(size_t _nest = 0);

private:
	const std::string printNest(size_t _nest);
};

day7Directory parseRoot();
std::string day7();
std::string day7Part2();