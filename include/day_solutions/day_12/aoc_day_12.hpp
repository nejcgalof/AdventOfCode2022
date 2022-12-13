#ifndef ADVENTOFCODE_AOC_DAY_12_HPP
#define ADVENTOFCODE_AOC_DAY_12_HPP

#include <map>
#include <stddef.h>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay12 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  void CheckItem(size_t lineCharacter, size_t character);

  void PrintConnections();

  size_t start = 0;
  size_t end = 0;
  std::vector<std::vector<char>> characters;
  std::map<size_t, std::vector<size_t>> connectionMap;

public:
  AocDay12();
  ~AocDay12() override;
};

#endif
