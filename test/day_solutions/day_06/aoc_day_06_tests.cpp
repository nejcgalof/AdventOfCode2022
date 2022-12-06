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
            days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple_no.txt", {})));
}

TEST_CASE("File not exist 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(0
          == std::get<int>(
            days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple_no.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(
    7
    == std::get<int>(days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple.txt", {})));
}

TEST_CASE("Solve simple2 puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(5
          == std::get<int>(
            days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple2.txt", {})));
}

TEST_CASE("Solve simple3 puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(6
          == std::get<int>(
            days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple3.txt", {})));
}

TEST_CASE("Solve simple4 puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(10
          == std::get<int>(
            days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple4.txt", {})));
}

TEST_CASE("Solve simple5 puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(11
          == std::get<int>(
            days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple5.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 06 day - part 1", "[day06]")
{
  AocDays days;
  REQUIRE(
    1850
    == std::get<int>(days.GetDay(6)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(
    19
    == std::get<int>(days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple.txt", {})));
}

TEST_CASE("Solve simple2 puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(23
          == std::get<int>(
            days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple2.txt", {})));
}

TEST_CASE("Solve simple3 puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(23
          == std::get<int>(
            days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple3.txt", {})));
}

TEST_CASE("Solve simple4 puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(29
          == std::get<int>(
            days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple4.txt", {})));
}

TEST_CASE("Solve simple5 puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(26
          == std::get<int>(
            days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/simple5.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 06 day - part 2", "[day06]")
{
  AocDays days;
  REQUIRE(
    2823
    == std::get<int>(days.GetDay(6)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_06/puzzle.txt", {})));
}
