#include <catch2/catch.hpp>

#include <memory>
#include <string>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the 01 day", "[day01]")
{
  AocDays days;
  auto aoc_day = days.GetDay(1);
  REQUIRE(aoc_day != nullptr);
}
