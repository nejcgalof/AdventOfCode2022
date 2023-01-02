#include "day_16/aoc_day_16.hpp"

#include <algorithm>
#include <bits/std_abs.h>
#include <cstddef>
#include <cstdlib>
#include <ext/alloc_traits.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <stack>
#include <variant>

AocDay16::AocDay16() : AocDay(16) {}

AocDay16::~AocDay16() = default;

void AocDay16::ReadValvesFromFile(const std::string &file)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    int index = 0;
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
      valve.pressure = std::stoi(line.substr(0, pos));
      line.erase(0, pos + delimeter.length());
      for (size_t i = 0; i < line.length(); i += 4) { valve.tunnels.emplace_back(line.substr(i, 2)); }

      valve.index = index++;
      valves.insert({ valve.name, valve });
    }
    file_stream.close();
  }
}

void AocDay16::FindSolution(const std::string &currentValve, int timeLeft, int pressure, unsigned long openedValves)
{
  auto tupl = std::make_tuple(currentValve, timeLeft, openedValves);
  if (sameScenarios.contains(tupl) && sameScenarios[tupl] >= pressure) { return; }

  sameScenarios[tupl] = pressure;

  timeLeft--;
  if (timeLeft == 0) {
    if (pressure > bestPressure) { bestPressure = pressure; }
    return;
  }

  // Open
  // NOLINTNEXTLINE(hicpp-signed-bitwise)
  if (valves.at(currentValve).pressure != 0 && (((openedValves >> valves.at(currentValve).index) & 1UL) == 0)) {
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    openedValves |= 1UL << valves.at(currentValve).index;
    FindSolution(currentValve, timeLeft, pressure + valves.at(currentValve).pressure * timeLeft, openedValves);
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    openedValves &= ~(1UL << valves.at(currentValve).index);
  }

  // Move
  for (const auto &neigh : valves.at(currentValve).tunnels) { FindSolution(neigh, timeLeft, pressure, openedValves); }
}

std::variant<int, double, std::string> AocDay16::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadValvesFromFile(file);
  if (valves.empty()) { return 0; }
  FindSolution("AA", 30, 0, 0);
  return bestPressure;
}

std::variant<int, double, std::string> AocDay16::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return 0;
}
