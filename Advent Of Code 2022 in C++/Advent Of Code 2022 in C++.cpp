#include "day1.h"
#include "day2.h"
#include <iostream>

int main()
{
    /*Day 1
    * https://adventofcode.com/2022/day/1
    * Find the Elf carrying the most Calories. 
    * How many total Calories is that Elf carrying?
    */
    std::cout << day1() << "\n";
    /*Day 1 Part 2
    * https://adventofcode.com/2022/day/1#part2
    * Find the top three Elves carrying the most Calories.
    * How many Calories are those Elves carrying in total?
    */
    std::cout << day1Part2() << "\n";
    /*Day 2
    * https://adventofcode.com/2022/day/2
    * What would your total score be if everything goes
    * exactly according to your strategy guide?
    */
    std::cout << day2() << "\n";
    /*Day 2 Part 2
    * https://adventofcode.com/2022/day/2#part2
    * What would your total score be if everything goes
    * exactly according to your strategy guide?
    */
    std::cout << day2Part2() << "\n";
    return 0;
}