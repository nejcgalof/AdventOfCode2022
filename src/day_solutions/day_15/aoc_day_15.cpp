#include "day_15/aoc_day_15.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>

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

    /*for (const auto &report : reports) {
      std::cout << "Sensor " << report.sensor.x << ", " << report.sensor.y;
      std::cout << " Beacon " << report.beacon.x << ", " << report.beacon.y << std::endl;
    }*/
    file_stream.close();
  }
}

int AocDay15::ManhattanDistance(int x1, int y1, int x2, int y2) { return std::abs(x1 - x2) + std::abs(y1 - y2); }

void AocDay15::CheckAllPoints()
{
  const int checked_y = 2000000;
  for (const auto &report : reports) {
    const int manhattan_distance =
      ManhattanDistance(report.sensor.x, report.sensor.y, report.beacon.x, report.beacon.y);
    for (int check = report.sensor.x; check >= report.sensor.x - manhattan_distance; check--) {
      const int manhattan_distance_temp = ManhattanDistance(report.sensor.x, report.sensor.y, check, checked_y);
      if (manhattan_distance_temp > manhattan_distance) { break; }
      lineCoverage.insert(check);
    }
    for (int check = report.sensor.x; check <= report.sensor.x + manhattan_distance; check++) {
      const int manhattan_distance_temp = ManhattanDistance(report.sensor.x, report.sensor.y, check, checked_y);
      if (manhattan_distance_temp > manhattan_distance) { break; }
      lineCoverage.insert(check);
    }
  }

  for (const auto &report : reports) {
    if (report.beacon.y == checked_y) { lineCoverage.erase(report.beacon.x); }
    // if (report.sensor.y == checked_y) { lineCoverage.erase(report.sensor.x); }
  }
}

void AocDay15::CheckAllPoints2(int checked_y)
{
  lineCoverage.clear();
  for (const auto &report : reports) {
    const int manhattan_distance =
      ManhattanDistance(report.sensor.x, report.sensor.y, report.beacon.x, report.beacon.y);
    for (int check = report.sensor.x; check >= report.sensor.x - manhattan_distance; check--) {
      if (lineCoverage.size() >= 4000001 || check > 4000000 || check < 0) { break; }
      const int manhattan_distance_temp = ManhattanDistance(report.sensor.x, report.sensor.y, check, checked_y);
      if (manhattan_distance_temp > manhattan_distance) { break; }
      lineCoverage.insert(check);
    }
    for (int check = report.sensor.x; check <= report.sensor.x + manhattan_distance; check++) {
      if (lineCoverage.size() >= 4000001 || check > 4000000 || check < 0) { break; }
      const int manhattan_distance_temp = ManhattanDistance(report.sensor.x, report.sensor.y, check, checked_y);
      if (manhattan_distance_temp > manhattan_distance) { break; }
      lineCoverage.insert(check);
    }
  }

  for (const auto &report : reports) {
    if (report.beacon.y == checked_y) { lineCoverage.insert(report.beacon.x); }
    // if (report.sensor.y == checked_y) { lineCoverage.erase(report.sensor.x); }
  }
  allLineCoverages.emplace_back(lineCoverage);
}

void AocDay15::CheckAllLines()
{
  for (int step = 0; step <= 4000000; step++) {
    CheckAllPoints2(step);
    if (allLineCoverages.back().size() < 4000001) { break; }
    std::cout << step << std::endl;
  }
}

std::variant<int, double, std::string> AocDay15::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadReportsFromFile(file);
  if (reports.empty()) { return 0; }
  CheckAllPoints();
  return static_cast<int>(lineCoverage.size());
}

std::variant<int, double, std::string> AocDay15::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadReportsFromFile(file);
  if (reports.empty()) { return 0; }
  CheckAllLines();
  auto smallest_line_coverage = std::min_element(allLineCoverages.begin(),
    allLineCoverages.end(),
    [](const auto &v1, const auto &v2) { return v1.size() < v2.size(); });

  int result_y = static_cast<int>(std::distance(allLineCoverages.begin(), smallest_line_coverage));
  std::cout << result_y << std::endl;
  std::set<int> ordered(smallest_line_coverage->begin(), smallest_line_coverage->end());
  int result_x = 0;
  for (auto it = ordered.begin(); it != ordered.end(); ++it, ++result_x) {
    if (*it != result_x) { break; }
  }
  std::cout << result_x << std::endl;
  return result_x * 4000000 + result_y;
}
