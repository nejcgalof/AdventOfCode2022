#include "day_15/aoc_day_15.hpp"

#include <algorithm>
#include <bits/std_abs.h>
#include <cstddef>
#include <cstdlib>
#include <ext/alloc_traits.h>
#include <fstream>
#include <memory>
#include <variant>

AocDay15::AocDay15() : AocDay(15) {}

AocDay15::~AocDay15() = default;

void AocDay15::ReadReportsFromFile(const std::string &file)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      Report report;
      std::string delimeter = "Sensor at x=";
      line.erase(0, line.find(delimeter) + delimeter.length());

      size_t pos = line.find(", y=");
      report.sensor.x = std::stoi(line.substr(0, pos));
      line.erase(0, pos + 4);

      delimeter = ": closest beacon is at x=";
      pos = line.find(delimeter);
      report.sensor.y = std::stoi(line.substr(0, pos));
      line.erase(0, pos + delimeter.length());

      pos = line.find(", y=");
      report.beacon.x = std::stoi(line.substr(0, pos));
      line.erase(0, pos + 4);

      report.beacon.y = std::stoi(line.substr(0, line.size()));
      reports.emplace_back(report);
    }
    file_stream.close();
  }
}

constexpr int AocDay15::ManhattanDistance(int x1, int y1, int x2, int y2)
{
  return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int AocDay15::NonBeaconPositions(int line)
{
  const size_t holes = CalculateLineRanges(line);
  int sum = 0;
  for (size_t i = 0; i <= holes; i++) { sum += (ranges[i].to - ranges[i].from) + 1; }
  return sum - 1;
}

size_t AocDay15::CalculateLineRanges(int line)
{
  ranges.clear();
  for (const auto &report : reports) {
    const int manhattan_distance =
      ManhattanDistance(report.sensor.x, report.sensor.y, report.beacon.x, report.beacon.y);
    const int side = manhattan_distance - std::abs(report.sensor.y - line);
    if (side < 0) { continue; }
    ranges.emplace_back(report.sensor.x - side, report.sensor.x + side);
  }

  std::sort(ranges.begin(), ranges.end(), [](const auto &firstCell, const auto &secondCell) {
    return firstCell.from < secondCell.from;
  });

  size_t r = 0;
  for (size_t i = 1; i < ranges.size(); i++) {
    if (ranges[r].to >= ranges[i].from) {
      ranges[r].to = std::max(ranges[r].to, ranges[i].to);
    } else {
      r++;
      ranges[r] = ranges[i];
    }
  }
  return r;
}

double AocDay15::CalculateTuningFrequency(int maxStep)
{
  for (int step = 0; step <= maxStep; step++) {
    if (CalculateLineRanges(step) > 0) {
      return static_cast<double>(ranges[0].to + 1) * 4000000 + static_cast<double>(step);
    }
  }
  return 0;
}

std::variant<int, double, std::string> AocDay15::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadReportsFromFile(file);
  if (reports.empty() || extraArgs.empty()) { return 0; }
  int line = 0;
  try {
    line = std::get<int>(extraArgs.at(0));
  } catch (const std::bad_variant_access &ex) {
    line = std::stoi(std::get<std::string>(extraArgs.at(0)));
  }
  return NonBeaconPositions(line);
}

std::variant<int, double, std::string> AocDay15::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadReportsFromFile(file);
  if (reports.empty() || extraArgs.empty()) { return 0; }
  int max_step = 0;
  try {
    max_step = std::get<int>(extraArgs.at(0));
  } catch (const std::bad_variant_access &ex) {
    max_step = std::stoi(std::get<std::string>(extraArgs.at(0)));
  }
  return CalculateTuningFrequency(max_step);
}
