#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 01 day", "[day01]")
{
  AocDays days;
  auto aoc_day = days.GetDay(1);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 01 day - part 1", "[day01]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(1)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_01/simple1.txt", {})));
}

TEST_CASE("File not exist 01 day - part 2", "[day01]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(1)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_01/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 01 day - part 1", "[day01]")
{
  AocDays days;
  REQUIRE(
    24000
    == std::get<int>(days.GetDay(1)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_01/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 01 day - part 1", "[day01]")
{
  AocDays days;
  REQUIRE(
    67658
    == std::get<int>(days.GetDay(1)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_01/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 01 day - part 2", "[day01]")
{
  AocDays days;
  REQUIRE(
    45000
    == std::get<int>(days.GetDay(1)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_01/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 01 day - part 2", "[day01]")
{
  AocDays days;
  REQUIRE(
    200158
    == std::get<int>(days.GetDay(1)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_01/puzzle.txt", {})));
}
