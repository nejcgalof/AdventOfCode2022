#ifndef ADVENTOFCODE_AOC_DAY_05_HPP
#define ADVENTOFCODE_AOC_DAY_05_HPP

#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay05 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  static void ModifyStartingStacksFromReadedLine(std::string line, std::vector<std::vector<char>> &stacks);
  static void
    MakeMoveFromReadedLine(const std::string &line, std::vector<std::vector<char>> &stacks, bool move_same_order);

public:
  AocDay05();
  ~AocDay05() override;
};

#endif
