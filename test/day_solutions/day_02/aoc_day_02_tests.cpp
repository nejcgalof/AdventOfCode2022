#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 02 day", "[day02]")
{
  AocDays days;
  auto aoc_day = days.GetDay(2);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 02 day - part 1", "[day02]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(2)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_02/simple1.txt", {})));
}

TEST_CASE("File not exist 02 day - part 2", "[day02]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(2)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_02/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 02 day - part 1", "[day02]")
{
  AocDays days;
  REQUIRE(
    15
    == std::get<int>(days.GetDay(2)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_02/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 02 day - part 1", "[day02]")
{
  AocDays days;
  REQUIRE(
    11475
    == std::get<int>(days.GetDay(2)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_02/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 02 day - part 2", "[day02]")
{
  AocDays days;
  REQUIRE(
    12
    == std::get<int>(days.GetDay(2)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_02/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 02 day - part 2", "[day02]")
{
  AocDays days;
  REQUIRE(
    16862
    == std::get<int>(days.GetDay(2)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_02/puzzle.txt", {})));
}
