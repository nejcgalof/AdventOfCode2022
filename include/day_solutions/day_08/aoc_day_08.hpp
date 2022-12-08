#ifndef ADVENTOFCODE_AOC_DAY_08_HPP
#define ADVENTOFCODE_AOC_DAY_08_HPP

#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay08 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

public:
  AocDay08();
  ~AocDay08() override;
};

#endif
