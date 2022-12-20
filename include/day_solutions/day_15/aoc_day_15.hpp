#ifndef ADVENTOFCODE_AOC_DAY_15_HPP
#define ADVENTOFCODE_AOC_DAY_15_HPP

#include <map>
#include <set>
#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay15 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  struct Sensor
  {
    int x{ 0 };
    int y{ 0 };
  };

  struct Beacon
  {
    int x{ 0 };
    int y{ 0 };
  };

  struct Report
  {
    Sensor sensor;
    Beacon beacon;
  };

  std::vector<Report> reports;
  std::set<int> lineCoverage;

  void ReadReportsFromFile(const std::string &file);

  static int ManhattanDistance(int x1, int y1, int x2, int y2);

  void CheckAllPoints();

public:
  AocDay15();

  ~AocDay15() override;
};

#endif
