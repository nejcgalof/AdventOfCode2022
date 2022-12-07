#ifndef ADVENTOFCODE_AOC_DAY_07_HPP
#define ADVENTOFCODE_AOC_DAY_07_HPP

#include <map>
#include <string>
#include <utility>
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

  int FindSmallestDirToFree();
  int SumOfSmallDirs(int limitSize) const;
  int CalculateCurrentFileStructure(const std::string &currentFile);
  void CalculateDirSize();
  void GenerateFileStructureFromReadedTerminal(const std::string &file);

  std::map<const std::string, std::vector<std::pair<const std::string, int>>> fileStructure;

public:
  AocDay07();
  ~AocDay07() override;
};

#endif
