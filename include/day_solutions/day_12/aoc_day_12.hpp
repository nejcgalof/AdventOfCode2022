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

  void CheckUp(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections);
  void CheckDown(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections);
  void CheckLeft(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections);
  void CheckRight(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections);
  void CheckItem(bool reverse, size_t lineCharacter, size_t character);
  void ModifyStartEndAndCheckItems(bool reverse);
  void ModifyStartEnd(bool reverse, size_t lineCharacter, size_t character);
  int BFS();
  int HillClimbingProblemFromFile(const std::string &file, bool reverse);

  size_t start = 0;
  std::vector<size_t> end;
  std::vector<std::vector<char>> characters;
  std::vector<std::vector<size_t>> connectionMap;

public:
  AocDay12();
  ~AocDay12() override;
};

#endif
