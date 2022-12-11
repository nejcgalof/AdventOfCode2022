#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 11 day", "[day11]")
{
  AocDays days;
  auto aoc_day = days.GetDay(11);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 11 day - part 1", "[day11]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(11)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_11/simple1.txt", {})));
}

TEST_CASE("File not exist 11 day - part 2", "[day11]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(11)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_11/simple1.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 11 day - part 1", "[day11]")
{
  AocDays days;
  REQUIRE(10605
          == std::get<int>(
            days.GetDay(11)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_11/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 11 day - part 1", "[day11]")
{
  AocDays days;
  REQUIRE(78678
          == std::get<int>(
            days.GetDay(11)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_11/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 11 day - part 2", "[day11]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(11)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_11/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 11 day - part 2", "[day11]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(11)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_11/puzzle.txt", {})));
}
