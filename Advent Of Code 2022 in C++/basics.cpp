#include "basics.h"

std::string basics::getInput(std::string _day)
{
    std::fstream f("input/" + _day + ".txt");

    std::string input((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    f.close();
    return input;
}
