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

  std::vector<std::vector<int>> trees;
  bool CheckTop(size_t row, size_t col);
  bool CheckBottom(size_t row, size_t col);
  bool CheckLeft(size_t row, size_t col);
  bool CheckRight(size_t row, size_t col);

public:
  AocDay08();
  ~AocDay08() override;
};

#endif
