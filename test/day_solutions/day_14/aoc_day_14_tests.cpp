#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 14 day", "[day14]")
{
  AocDays days;
  auto aoc_day = days.GetDay(14);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 14 day - part 1", "[day14]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(14)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_14/simple1.txt", {})));
}

TEST_CASE("File not exist 14 day - part 2", "[day14]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(14)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_14/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 14 day - part 1", "[day14]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(14)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_14/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 14 day - part 1", "[day14]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(14)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_14/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 14 day - part 2", "[day14]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(14)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_14/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 14 day - part 2", "[day14]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(14)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_14/puzzle.txt", {})));
}
