#include "day_01/aoc_day_01.hpp"

#include <algorithm>
#include <fstream>
#include <functional>
#include <iterator>
#include <numeric>

AocDay01::AocDay01() : AocDay(1) {}

AocDay01::~AocDay01() = default;

std::vector<int> AocDay01::DescSortedElfCaloriesFromFile(const std::string &fileName)
{
  std::vector<int> elf_calories;
  std::ifstream file(fileName);
  if (file.is_open()) {
    int current_elf_calories = 0;
    std::string line;
    while (std::getline(file, line)) {
      if (line.empty()) {
        elf_calories.emplace_back(current_elf_calories);
        current_elf_calories = 0;
      } else {
        current_elf_calories += std::stoi(line);
      }
    }
    if (current_elf_calories != 0) { elf_calories.emplace_back(current_elf_calories); }
    file.close();
  }
  std::sort(elf_calories.begin(), elf_calories.end(), std::greater<>());
  return elf_calories;
}

std::variant<int, double, std::string> AocDay01::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  const auto &calories = DescSortedElfCaloriesFromFile(file);
  return calories.empty() ? 0 : calories.front(); // Biggest
}

std::variant<int, double, std::string> AocDay01::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  const auto &calories = DescSortedElfCaloriesFromFile(file);
  return calories.empty()
           ? 0
           : std::accumulate(calories.begin(), std::next(calories.begin(), 3), 0); // Sum of the three biggest
}
