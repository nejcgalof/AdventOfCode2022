#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 06 day", "[day06]")
{
  AocDays days;
  auto aoc_day = days.GetDay(6);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple1.txt", {})));
}

TEST_CASE("File not exist 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/puzzle.txt", {})));
}
