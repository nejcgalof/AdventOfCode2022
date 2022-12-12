#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 12 day", "[day12]")
{
  AocDays days;
  auto aoc_day = days.GetDay(12);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 12 day - part 1", "[day12]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(12)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_12/simple1.txt", {})));
}

TEST_CASE("File not exist 12 day - part 2", "[day12]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(12)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_12/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 12 day - part 1", "[day12]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(12)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_12/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 12 day - part 1", "[day12]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(12)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_12/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 12 day - part 2", "[day12]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(12)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_12/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 12 day - part 2", "[day12]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(12)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_12/puzzle.txt", {})));
}
