#include "aoc_day_demo.hpp"
#include <fmt/core.h>

AocDayDemo::AocDayDemo() : AocDay(-1) {}

AocDayDemo::~AocDayDemo() = default;

std::variant<int, double, std::string> AocDayDemo::Part1(
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  fmt::print("{}\n", "Part1");
  return "";
}

std::variant<int, double, std::string> AocDayDemo::Part2(
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  fmt::print("{}\n", "Part2");
  return "";
}
