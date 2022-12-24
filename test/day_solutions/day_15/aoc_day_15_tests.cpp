#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 15 day", "[day15]")
{
  AocDays days;
  auto aoc_day = days.GetDay(15);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 15 day - part 1", "[day15]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(15)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_15/simple1.txt", {})));
}

TEST_CASE("File not exist 15 day - part 2", "[day15]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(15)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_15/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 15 day - part 1", "[day15]")
{
  AocDays days;
  REQUIRE(26
          == std::get<int>(
            days.GetDay(15)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_15/simple.txt", { 10 })));
}

TEST_CASE("Solve actual puzzle of the 15 day - part 1", "[day15]")
{
  AocDays days;
  REQUIRE(5112034
          == std::get<int>(days.GetDay(15)->SolvePart(
            1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_15/puzzle.txt", { 2000000 })));
}

TEST_CASE("Solve simple puzzle of the 15 day - part 2", "[day15]")
{
  AocDays days;
  REQUIRE(56000011
          == std::get<double>(
            days.GetDay(15)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_15/simple.txt", { 20 })));
}

TEST_CASE("Solve actual puzzle of the 15 day - part 2", "[day15]")
{
  AocDays days;
  REQUIRE(13172087230812
          == std::get<double>(days.GetDay(15)->SolvePart(
            2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_15/puzzle.txt", { 4000000 })));
}
