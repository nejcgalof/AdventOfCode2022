#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 07 day", "[day07]")
{
  AocDays days;
  auto aoc_day = days.GetDay(7);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 07 day - part 1", "[day07]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(7)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_07/simple1.txt", {})));
}

TEST_CASE("File not exist 07 day - part 2", "[day07]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(7)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_07/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 07 day - part 1", "[day07]")
{
  AocDays days;
  REQUIRE(
    95437
    == std::get<int>(days.GetDay(7)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_07/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 07 day - part 1", "[day07]")
{
  AocDays days;
  REQUIRE(
    1444896
    == std::get<int>(days.GetDay(7)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_07/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 07 day - part 2", "[day07]")
{
  AocDays days;
  REQUIRE(
    24933642
    == std::get<int>(days.GetDay(7)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_07/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 07 day - part 2", "[day07]")
{
  AocDays days;
  REQUIRE(
    404395
    == std::get<int>(days.GetDay(7)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_07/puzzle.txt", {})));
}
