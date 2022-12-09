#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 09 day", "[day09]")
{
  AocDays days;
  auto aoc_day = days.GetDay(9);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 09 day - part 1", "[day09]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(9)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_09/simple1.txt", {})));
}

TEST_CASE("File not exist 09 day - part 2", "[day09]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(9)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_09/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 09 day - part 1", "[day09]")
{
  AocDays days;
  REQUIRE(
    13
    == std::get<int>(days.GetDay(9)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_09/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 09 day - part 1", "[day09]")
{
  AocDays days;
  REQUIRE(
    6494
    == std::get<int>(days.GetDay(9)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_09/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 09 day - part 2", "[day09]")
{
  AocDays days;
  REQUIRE(
    1
    == std::get<int>(days.GetDay(9)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_09/simple.txt", {})));
}

TEST_CASE("Solve simple large puzzle of the 09 day - part 2", "[day09]")
{
  AocDays days;
  REQUIRE(36
          == std::get<int>(
            days.GetDay(9)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_09/simple_large.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 09 day - part 2", "[day09]")
{
  AocDays days;
  REQUIRE(
    2691
    == std::get<int>(days.GetDay(9)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_09/puzzle.txt", {})));
}
