#ifndef ADVENTOFCODE_AOC_DAY_15_HPP
#define ADVENTOFCODE_AOC_DAY_15_HPP

#include <map>
#include <set>
#include <string>
#include <unordered_set>
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

  struct Range
  {
    Range(int fromInput, int toInput) : from(fromInput), to(toInput) {}

    int from{ 0 };
    int to{ 0 };
  };

  struct Report
  {
    Sensor sensor;
    Beacon beacon;
  };

  std::vector<Report> reports;
  std::vector<Range> ranges;

  void ReadReportsFromFile(const std::string &file);
  static constexpr int ManhattanDistance(int x1, int y1, int x2, int y2);
  int NonBeaconPositions(int line);
  size_t CalculateLineRanges(int line);
  double CalculateTuningFrequency(int maxStep);

public:
  AocDay15();

  ~AocDay15() override;
};

#endif
