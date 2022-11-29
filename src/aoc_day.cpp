#include "aoc_day.hpp"
#include <fmt/core.h>

AocDay::AocDay(int inputDay) : day(inputDay) {}

AocDay::~AocDay() = default;

std::variant<int, double, std::string> AocDay::SolvePart(int part,
  [[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  if (part == 1) {
    return Part1(file, extraArgs);
  } else if (part == 2) {
    return Part2(file, extraArgs);
  } else {
    return "Wrong part number!";
  }
}

std::variant<int, double, std::string> AocDay::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return "Part 1 is not implemented!";
}

std::variant<int, double, std::string> AocDay::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return "Part 2 is not implemented!";
}
