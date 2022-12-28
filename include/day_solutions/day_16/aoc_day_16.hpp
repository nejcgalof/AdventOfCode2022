#ifndef ADVENTOFCODE_AOC_DAY_16_HPP
#define ADVENTOFCODE_AOC_DAY_16_HPP

#include <cstddef>
#include <map>
#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay16 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  struct Valve
  {
    std::string name;
    int rate{ 0 };
    std::vector<std::string> neighbours;
  };

  std::map<std::string, Valve> valves;

  void ReadValvesFromFile(const std::string &file);

public:
  AocDay16();

  ~AocDay16() override;
};

#endif
