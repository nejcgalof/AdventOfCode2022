#ifndef ADVENTOFCODE_AOC_DAY_09_HPP
#define ADVENTOFCODE_AOC_DAY_09_HPP

#include <cstddef>
#include <set>
#include <string>
#include <utility>
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

  struct Knot
  {
    int x;
    int y;
  };

  static void MoveKnot(Knot &currentKnot, const Knot &previousKnot);
  void MoveKnots(const std::string &direction);
  void MoveHeadByDirection(const std::string &direction);
  void SaveTailPosition(const Knot &tailKnot);
  int ReadFileAndMoveKnotsAndReturnTailVisitPositions(const std::string &file, const size_t numKnots);

  std::set<std::pair<int, int>> uniqueTailPositions;
  std::vector<Knot> knots;

public:
  AocDay09();
  ~AocDay09() override;
};

#endif
