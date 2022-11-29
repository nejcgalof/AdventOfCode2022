#include <catch2/catch.hpp>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the demo day", "[Demo]")
{
  AocDays days;
  auto aoc_day = days.GetDay(-1);
  REQUIRE(aoc_day != nullptr);
}
