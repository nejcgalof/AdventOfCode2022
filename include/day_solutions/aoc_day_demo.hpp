#ifndef ADVENTOFCODE_AOC_DAY_DEMO_HPP
#define ADVENTOFCODE_AOC_DAY_DEMO_HPP

#include "aoc_day.hpp"

class AocDayDemo : public AocDay
{
public:
  AocDayDemo();
  ~AocDayDemo() override;
  std::variant<int, double, std::string> Part1(
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2(
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
};

#endif
