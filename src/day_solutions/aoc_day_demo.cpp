#include "aoc_day_demo.hpp"

AocDayDemo::AocDayDemo() : AocDay(-1) {}

AocDayDemo::~AocDayDemo() = default;

std::variant<int, double, std::string> AocDayDemo::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return "Demo solution part 1";
}

std::variant<int, double, std::string> AocDayDemo::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return "Demo solution part 2";
}
