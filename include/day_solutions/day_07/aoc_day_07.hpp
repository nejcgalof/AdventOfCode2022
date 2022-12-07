#ifndef ADVENTOFCODE_AOC_DAY_07_HPP
#define ADVENTOFCODE_AOC_DAY_07_HPP

#include <map>
#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay07 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  static int FindSmallestDirToFree(
    const std::map<const std::string, std::vector<std::pair<const std::string, int>>> &fileStructure);

  static int CalculateFileStructure(
    std::map<const std::string, std::vector<std::pair<const std::string, int>>> &fileStructure);

  static int CalculateCurrentFileStructure(
    std::map<const std::string, std::vector<std::pair<const std::string, int>>> &fileStructure,
    const std::string &currentFile);

public:
  AocDay07();
  ~AocDay07() override;
};

#endif
