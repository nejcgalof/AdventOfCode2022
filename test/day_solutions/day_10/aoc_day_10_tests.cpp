#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 10 day", "[day10]")
{
  AocDays days;
  auto aoc_day = days.GetDay(10);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 10 day - part 1", "[day10]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(10)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_10/simple1.txt", {})));
}

TEST_CASE("File not exist 10 day - part 2", "[day10]")
{
  AocDays days;
  REQUIRE(std::get<std::string>(
    days.GetDay(10)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_10/simple1.txt", {}))
            .empty());
}

TEST_CASE("Solve simple puzzle of the 10 day - part 1", "[day10]")
{
  AocDays days;
  REQUIRE(13140
          == std::get<int>(
            days.GetDay(10)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_10/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 10 day - part 1", "[day10]")
{
  AocDays days;
  REQUIRE(12560
          == std::get<int>(
            days.GetDay(10)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_10/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 10 day - part 2", "[day10]")
{
  std::string solution =
    "##..##..##..##..##..##..##..##..##..##..\n"
    "###...###...###...###...###...###...###.\n"
    "####....####....####....####....####....\n"
    "#####.....#####.....#####.....#####.....\n"
    "######......######......######......####\n"
    "#######.......#######.......#######.....\n";
  AocDays days;
  REQUIRE(solution
          == std::get<std::string>(
            days.GetDay(10)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_10/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 10 day - part 2", "[day10]")
{
  std::string solution =
    "###..#....###...##..####.###...##..#...#\n"
    "#..#.#....#..#.#..#.#....#..#.#..#.#....\n"
    "#..#.#....#..#.#..#.###..###..#....#....\n"
    "###..#....###..####.#....#..#.#....#....\n"
    "#....#....#....#..#.#....#..#.#..#.#....\n"
    "#....####.#....#..#.#....###...##..####.\n";
  AocDays days;
  REQUIRE(solution
          == std::get<std::string>(
            days.GetDay(10)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_10/puzzle.txt", {})));
}
