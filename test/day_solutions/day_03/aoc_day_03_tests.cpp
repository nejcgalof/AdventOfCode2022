#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 03 day", "[day03]")
{
  AocDays days;
  auto aoc_day = days.GetDay(3);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 03 day - part 1", "[day03]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(3)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_03/simple1.txt", {})));
}

TEST_CASE("File not exist 03 day - part 2", "[day03]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(3)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_03/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 03 day - part 1", "[day03]")
{
  AocDays days;
  REQUIRE(
    157
    == std::get<int>(days.GetDay(3)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_03/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 03 day - part 1", "[day03]")
{
  AocDays days;
  REQUIRE(
    7568
    == std::get<int>(days.GetDay(3)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_03/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 03 day - part 2", "[day03]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(3)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_03/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 03 day - part 2", "[day03]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(3)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_03/puzzle.txt", {})));
}
