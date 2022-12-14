#ifndef ADVENTOFCODE_AOC_DAY_04_HPP
#define ADVENTOFCODE_AOC_DAY_04_HPP

#include <string>
#include <tuple>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay04 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  static std::tuple<int, int> GetMinAndMax(const std::string &stringRange);

public:
  AocDay04();
  ~AocDay04() override;
};

#endif
