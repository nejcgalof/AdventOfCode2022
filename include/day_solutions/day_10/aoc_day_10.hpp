#ifndef ADVENTOFCODE_AOC_DAY_10_HPP
#define ADVENTOFCODE_AOC_DAY_10_HPP

#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay10 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  void ExecuteCycle(int &sumSignalStrength);
  void ExecuteCycle(int &sumSignalStrength, std::string &crtScreen);
  void Draw(std::string &crtScreen);
  void ReadInstructionsAndGenerateResults(const std::string &file, int &sumSignalStrength, std::string &crtScreen);

  int registerValue;
  int cycle;
  int crtPos;

public:
  AocDay10();
  ~AocDay10() override;
};

#endif
