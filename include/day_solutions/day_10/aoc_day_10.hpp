#ifndef ADVENTOFCODE_AOC_DAY_10_HPP
#define ADVENTOFCODE_AOC_DAY_10_HPP

#include <cstddef>
#include <set>
#include <string>
#include <utility>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay10 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  void ExecuteCycle(int &sumSignalStrength);

  int registerValue;
  int cycle;

public:
  AocDay10();
  ~AocDay10() override;
};

#endif
