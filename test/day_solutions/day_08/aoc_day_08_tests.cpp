#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 08 day", "[day08]")
{
  AocDays days;
  auto aoc_day = days.GetDay(8);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 08 day - part 1", "[day08]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(8)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_08/simple1.txt", {})));
}

TEST_CASE("File not exist 08 day - part 2", "[day08]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(8)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_08/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 08 day - part 1", "[day08]")
{
  AocDays days;
  REQUIRE(
    21
    == std::get<int>(days.GetDay(8)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_08/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 08 day - part 1", "[day08]")
{
  AocDays days;
  REQUIRE(
    1807
    == std::get<int>(days.GetDay(8)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_08/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 08 day - part 2", "[day08]")
{
  AocDays days;
  REQUIRE(
    8
    == std::get<int>(days.GetDay(8)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_08/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 08 day - part 2", "[day08]")
{
  AocDays days;
  REQUIRE(
    480000
    == std::get<int>(days.GetDay(8)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_08/puzzle.txt", {})));
}
