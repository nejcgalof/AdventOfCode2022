#ifndef ADVENTOFCODE_AOC_DAY_09_HPP
#define ADVENTOFCODE_AOC_DAY_09_HPP

#include <cstddef>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay09 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

public:
  AocDay09();
  ~AocDay09() override;
};

#endif
