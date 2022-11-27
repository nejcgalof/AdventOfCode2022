#include "aoc_day.hpp"
#include <fmt/core.h>

AocDay::AocDay(int inputDay) : day(inputDay) {}

AocDay::~AocDay() = default;

std::variant<int, double, std::string> AocDay::Part1(
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  fmt::print("{}\n", "Part1 is not implemented");
  return "";
}

std::variant<int, double, std::string> AocDay::Part2(
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  fmt::print("{}\n", "Part2 is not implemented");
  return "";
}
