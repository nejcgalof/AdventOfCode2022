#ifndef ADVENTOFCODE_AOC_DAY_02_HPP
#define ADVENTOFCODE_AOC_DAY_02_HPP

#include <map>
#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay02 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  std::map<std::string, int> kShapeScore;
  std::map<std::string, int> kYourShapeValue;
  std::map<std::string, int> kEnemyShapeValue;
  std::map<int, int> kMatchScore;

public:
  AocDay02();
  ~AocDay02() override;
};

#endif
