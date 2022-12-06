#ifndef ADVENTOFCODE_AOC_DAY_06_HPP
#define ADVENTOFCODE_AOC_DAY_06_HPP

#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay06 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  static bool IsStringContainsUniqueCharacters(std::string inputString);
  static int TuningTrouble(const std::string &file, size_t startOfMsgMarker);

public:
  AocDay06();
  ~AocDay06() override;
};

#endif
