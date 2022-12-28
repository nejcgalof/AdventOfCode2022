#include "day_16/aoc_day_16.hpp"

#include <algorithm>
#include <bits/std_abs.h>
#include <cstddef>
#include <cstdlib>
#include <ext/alloc_traits.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <variant>

AocDay16::AocDay16() : AocDay(16) {}

AocDay16::~AocDay16() = default;

void AocDay16::ReadValvesFromFile(const std::string &file)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      Valve valve;
      std::string delimeter = "Valve ";
      line.erase(0, line.find(delimeter) + delimeter.length());

      size_t pos = line.find(" has flow rate=");
      valve.name = line.substr(0, pos);
      line.erase(0, pos + 15);

      delimeter = "; tunnels lead to valves ";
      pos = line.find(delimeter);
      if (pos == std::string::npos) {
        delimeter = "; tunnel leads to valve ";
        pos = line.find(delimeter);
      }
      valve.rate = std::stoi(line.substr(0, pos));
      line.erase(0, pos + delimeter.length());
      for (size_t i = 0; i < line.length(); i += 4) { valve.neighbours.emplace_back(line.substr(i, 2)); }
      valves.insert({ valve.name, valve });
    }
    file_stream.close();
  }
}

std::variant<int, double, std::string> AocDay16::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadValvesFromFile(file);
  for (const auto &[name, valve] : valves) {
    std::cout << valve.name << std::endl;
    std::cout << valve.rate << std::endl;
    for (const auto &neigh : valve.neighbours) { std::cout << neigh << ","; }
    std::cout << std::endl << "?????" << std::endl;
  }
  return 0;
}

std::variant<int, double, std::string> AocDay16::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return 0;
}
