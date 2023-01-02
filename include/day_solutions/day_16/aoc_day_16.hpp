#ifndef ADVENTOFCODE_AOC_DAY_16_HPP
#define ADVENTOFCODE_AOC_DAY_16_HPP

#include <cstddef>
#include <map>
#include <set>
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
    int index{ 0 };
    int pressure{ 0 };
    std::vector<std::string> tunnels;
  };

  std::map<std::string, Valve> valves;
  std::map<std::tuple<std::string, int, unsigned long>, int> sameScenarios;
  int bestPressure{ 0 };

  void ReadValvesFromFile(const std::string &file);
  void FindSolution(const std::string &currentValve, int timeLeft, int pressure, unsigned long openedValves);

public:
  AocDay16();

  ~AocDay16() override;
};

#endif
