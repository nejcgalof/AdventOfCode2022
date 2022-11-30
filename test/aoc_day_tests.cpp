#include <catch2/catch.hpp>

#include <memory>

#include "aoc_days.hpp"

TEST_CASE("GetDay returns nullptr if the day does not exist", "[Main]")
{
  AocDays days;
  auto aoc_day = days.GetDay(0);
  REQUIRE(aoc_day == nullptr);
}

TEST_CASE("GetDay returns the day if the day exists", "[Main]")
{
  AocDays days;
  auto aoc_day = days.GetDay(-1);
  REQUIRE(aoc_day != nullptr);
}
