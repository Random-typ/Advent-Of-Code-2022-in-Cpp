#pragma once
#include "basics.h"

struct day7Directory {
	std::string name;
	size_t size = 0;
	day7Directory* parent = nullptr;
	std::vector<day7Directory> subdirectorys;
	/* retrieves directory | if it doesnt exist it will be created */
	day7Directory& getdir(std::string _name);
	const size_t getSize(size_t maxsize = 0);
	const size_t getDirsAtMostOf(std::vector<day7Directory>& _dirs, size_t maxsize = 0);
	const bool isDirectory();
	const bool doesntContainDirectorys();
	const std::string print(size_t _nest = 0);
private:
	const std::string printNest(size_t _nest);
};

std::string day7();