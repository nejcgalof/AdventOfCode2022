#include <catch2/catch.hpp>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

TEST_CASE("Get the demo day", "[Demo]")
{
  AocDays days;
  auto aoc_day = days.GetDay(-1);
  REQUIRE(aoc_day != nullptr);
}

TEST_CASE("Test part 1 call", "[Demo]")
{
  AocDays days;
  REQUIRE("Demo solution part 1" == std::get<std::string>(days.GetDay(-1)->SolvePart(1, "/", {})));
}

TEST_CASE("Test part 2 call", "[Demo]")
{
  AocDays days;
  REQUIRE("Demo solution part 2" == std::get<std::string>(days.GetDay(-1)->SolvePart(2, "/", {})));
}

TEST_CASE("Test wrong part number", "[Demo]")
{
  AocDays days;
  REQUIRE("Wrong part number!" == std::get<std::string>(days.GetDay(-1)->SolvePart(3, "/", {})));
}

TEST_CASE("Call parts one by another", "[Demo]")
{
  AocDays days;
  REQUIRE("Demo solution part 1" == std::get<std::string>(days.GetDay(-1)->SolvePart(1, "/", {})));
  REQUIRE("Demo solution part 2" == std::get<std::string>(days.GetDay(-1)->SolvePart(2, "/", {})));
  REQUIRE("Wrong part number!" == std::get<std::string>(days.GetDay(-1)->SolvePart(3, "/", {})));
}
