#ifndef ADVENTOFCODE_AOC_DAY_08_HPP
#define ADVENTOFCODE_AOC_DAY_08_HPP

#include <cstddef>
#include <string>
#include <tuple>
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

  std::tuple<bool, int> CheckTop(const size_t row, const size_t col);
  std::tuple<bool, int> CheckBottom(const size_t row, const size_t col);
  std::tuple<bool, int> CheckLeft(const size_t row, const size_t col);
  std::tuple<bool, int> CheckRight(const size_t row, const size_t col);

  void GenerateTreesFromFile(const std::string &file);

  std::vector<std::vector<int>> trees;

public:
  AocDay08();
  ~AocDay08() override;
};

#endif
