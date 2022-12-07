#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 7 day", "[day7]")
{
  AocDays days;
  auto aoc_day = days.GetDay(7);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 7 day - part 1", "[day7]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(7)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_7/simple1.txt", {})));
}

TEST_CASE("File not exist 7 day - part 2", "[day7]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(7)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_7/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 7 day - part 1", "[day7]")
{
  AocDays days;
  REQUIRE(
    95437
    == std::get<int>(days.GetDay(7)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_7/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 7 day - part 1", "[day7]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(7)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_7/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 7 day - part 2", "[day7]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(7)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_7/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 7 day - part 2", "[day7]")
{
  AocDays days;
  REQUIRE(
    0
    == std::get<int>(days.GetDay(7)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_7/puzzle.txt", {})));
}
