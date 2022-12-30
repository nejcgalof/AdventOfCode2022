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
      valves.insert({ valve.name, valve });
    }
    file_stream.close();
  }
}

void AocDay16::FindSolution(const std::string &currentValve,
  int timeLeft,
  int pressure,
  std::set<std::string> openedValves)
{
  auto same_scenario = sameScenarios.find(std::make_tuple(currentValve, timeLeft, openedValves));
  if (same_scenario == sameScenarios.end()) {
    sameScenarios[std::make_tuple(currentValve, timeLeft, openedValves)] = pressure;
  } else {
    if (sameScenarios[std::make_tuple(currentValve, timeLeft, openedValves)] < pressure) {
      sameScenarios[std::make_tuple(currentValve, timeLeft, openedValves)] = pressure;
    } else {
      return;
    }
  }

  timeLeft--;
  if (timeLeft == 0) {
    if (pressure > bestPressure) { bestPressure = pressure; }
    return;
  }

  // Open
  if (!openedValves.contains(currentValve) && valves.at(currentValve).pressure != 0) {
    openedValves.insert(currentValve);
    FindSolution(currentValve, timeLeft, pressure + valves.at(currentValve).pressure * timeLeft, openedValves);
    openedValves.erase(currentValve);
  }

  // Move
  for (const auto &neigh : valves.at(currentValve).tunnels) { FindSolution(neigh, timeLeft, pressure, openedValves); }
}

std::variant<int, double, std::string> AocDay16::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadValvesFromFile(file);
  FindSolution("AA", 30, 0, {});
  return bestPressure;
}

std::variant<int, double, std::string> AocDay16::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return 0;
}
