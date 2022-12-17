#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 13 day", "[day13]")
{
  AocDays days;
  auto aoc_day = days.GetDay(13);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 13 day - part 1", "[day13]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(13)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_13/simple1.txt", {})));
}

TEST_CASE("File not exist 13 day - part 2", "[day13]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(13)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_13/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 13 day - part 1", "[day13]")
{
  AocDays days;
  REQUIRE(13
          == std::get<int>(
            days.GetDay(13)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_13/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 13 day - part 1", "[day13]")
{
  AocDays days;
  REQUIRE(5720
          == std::get<int>(
            days.GetDay(13)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_13/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 13 day - part 2", "[day13]")
{
  AocDays days;
  REQUIRE(140
          == std::get<int>(
            days.GetDay(13)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_13/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 13 day - part 2", "[day13]")
{
  AocDays days;
  REQUIRE(23504
          == std::get<int>(
            days.GetDay(13)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_13/puzzle.txt", {})));
}
