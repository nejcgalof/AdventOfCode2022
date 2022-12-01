#include "day_01/aoc_day_01.hpp"

#include <fstream>
#include <numeric>

AocDay01::AocDay01() : AocDay(1) {}

AocDay01::~AocDay01() = default;

std::variant<int, double, std::string> AocDay01::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int max_calories = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    int current_elf_calories = 0;
    std::string line;
    while (std::getline(file_stream, line)) {
      if (line.empty()) {
        if (max_calories < current_elf_calories) { max_calories = current_elf_calories; }
        current_elf_calories = 0;
      } else {
        current_elf_calories += std::stoi(line);
      }
    }
    file_stream.close();
  }
  return max_calories;
}

std::variant<int, double, std::string> AocDay01::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  std::vector<int> calories;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    int current_elf_calories = 0;
    std::string line;
    while (std::getline(file_stream, line)) {
      if (line.empty()) {
        calories.emplace_back(current_elf_calories);
        current_elf_calories = 0;
      } else {
        current_elf_calories += std::stoi(line);
      }
    }
    if (current_elf_calories != 0) { calories.emplace_back(current_elf_calories); }
    file_stream.close();
  }
  std::sort(calories.begin(), calories.end(), std::greater<>());
  return calories.empty() ? 0 : std::accumulate(calories.begin(), std::next(calories.begin(), 3), 0);
}
