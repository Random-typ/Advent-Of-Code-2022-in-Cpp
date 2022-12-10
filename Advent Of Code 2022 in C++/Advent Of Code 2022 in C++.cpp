#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"
#include "day7.h"
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
    /*Day 3
    * https://adventofcode.com/2022/day/3
    * Find the item type that appears in both compartments of 
    * each rucksack. 
    * What is the sum of the priorities of those item types?
    */
    std::cout << day3() << "\n";
    /*Day 3 Part 2
    * https://adventofcode.com/2022/day/3#part2
    * Find the item type that corresponds to the badges of each
    * three-Elf group. 
    * What is the sum of the priorities of those item types?
    */
    std::cout << day3Part2() << "\n";
    /*Day 4
    * https://adventofcode.com/2022/day/4
    * In how many assignment pairs does one range fully contain the other?
    */
    std::cout << day4() << "\n";
    /*Day 4 Part 2
    * https://adventofcode.com/2022/day/4#part2
    * In how many assignment pairs do the ranges overlap?
    */
    std::cout << day4Part2() << "\n";
    /*Day 5
    * https://adventofcode.com/2022/day/5
    * After the rearrangement procedure completes, what
    * crate ends up on top of each stack?
    */
    std::cout << day5() << "\n";
    /*Day 5 Part 2
    * https://adventofcode.com/2022/day/5#part2
    * After the rearrangement procedure completes,what
    * crate ends up on top of each stack?
    */
    std::cout << day5Part2() << "\n";
    /*Day 6
    * https://adventofcode.com/2022/day/6
    * How many characters need to be processed before
    * the first start-of-packet marker is detected?
    */
    std::cout << day6() << "\n";
    /*Day 6 Part 2
    * https://adventofcode.com/2022/day/6#part2
    * How many characters need to be processed before
    * the first start-of-message marker is detected?
    */
    std::cout << day6Part2() << "\n";
    /*Day 7
    * https://adventofcode.com/2022/day/7
    * Find all of the directories with a total size of
    * at most 100000.
    * What is the sum of the total sizes of those directories?
    */
    std::cout << day7() << "\n";
    /*Day 7 Part 2
    * https://adventofcode.com/2022/day/6#part2
    * Find the smallest directory that, if deleted, would free
    * up enough space on the filesystem to run the update.
    * What is the total size of that directory?
    */
    std::cout << day7Part2() << "\n";

    return 0;
}
