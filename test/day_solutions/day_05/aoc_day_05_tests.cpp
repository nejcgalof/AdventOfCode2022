#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 05 day", "[day05]")
{
  AocDays days;
  auto aoc_day = days.GetDay(5);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("File not exist 05 day - part 1", "[day05]")
{
  AocDays days;
  REQUIRE(std::get<std::string>(
    days.GetDay(5)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_05/simple1.txt", {}))
            .empty());
}

TEST_CASE("File not exist 05 day - part 2", "[day05]")
{
  AocDays days;
  REQUIRE(std::get<std::string>(
    days.GetDay(5)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_05/simple1.txt", {}))
            .empty());
}

TEST_CASE("Solve simple puzzle of the 05 day - part 1", "[day05]")
{
  AocDays days;
  REQUIRE("CMZ"
          == std::get<std::string>(
            days.GetDay(5)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_05/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 05 day - part 1", "[day05]")
{
  AocDays days;
  REQUIRE("TLFGBZHCN"
          == std::get<std::string>(
            days.GetDay(5)->SolvePart(1, "/workspaces/AdventOfCode2022/puzzle_inputs/day_05/puzzle.txt", {})));
}

TEST_CASE("Solve simple puzzle of the 05 day - part 2", "[day05]")
{
  AocDays days;
  REQUIRE("MCD"
          == std::get<std::string>(
            days.GetDay(5)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_05/simple.txt", {})));
}

TEST_CASE("Solve actual puzzle of the 05 day - part 2", "[day05]")
{
  AocDays days;
  REQUIRE("QRQFHFWCL"
          == std::get<std::string>(
            days.GetDay(5)->SolvePart(2, "/workspaces/AdventOfCode2022/puzzle_inputs/day_05/puzzle.txt", {})));
}
