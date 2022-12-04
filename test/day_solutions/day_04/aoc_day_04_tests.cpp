#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 04 day", "[day04]")
{
  AocDays days;
  auto aoc_day = days.GetDay(4);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 04 day - part 1", "[day04]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(4)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_04/simple1.txt", {})));
}

TEST_CASE("File not exist 04 day - part 2", "[day04]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(4)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_04/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 04 day - part 1", "[day04]")
{
  AocDays days;
  REQUIRE(
    2
    == std::get<int>(days.GetDay(4)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_04/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 04 day - part 1", "[day04]")
{
  AocDays days;
  REQUIRE(
    562
    == std::get<int>(days.GetDay(4)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_04/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 04 day - part 2", "[day04]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(4)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_04/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 04 day - part 2", "[day04]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(4)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_04/puzzle.txt", {})));
}
