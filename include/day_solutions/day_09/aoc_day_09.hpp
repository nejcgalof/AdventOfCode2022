#ifndef ADVENTOFCODE_AOC_DAY_09_HPP
#define ADVENTOFCODE_AOC_DAY_09_HPP

#include <cstddef>
#include <set>
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

  struct pos
  {
    int x;
    int y;
  };

  void MoveTail(pos &tail, const pos &head);

  std::set<std::pair<int, int>> uniquePositions;

public:
  AocDay09();
  ~AocDay09() override;
};

#endif
