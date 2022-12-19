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

    for (const auto &report : reports) {
      std::cout << "Sensor " << report.sensor.x << ", " << report.sensor.y;
      std::cout << " Beacon " << report.beacon.x << ", " << report.beacon.y << std::endl;
    }
    file_stream.close();
  }
}

std::variant<int, double, std::string> AocDay15::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadReportsFromFile(file);
  if (reports.empty()) { return 0; }
  return 0;
}

std::variant<int, double, std::string> AocDay15::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return 0;
}
