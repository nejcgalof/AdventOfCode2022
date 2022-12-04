#include "day_04/aoc_day_04.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <tuple>
#include <vector>

AocDay04::AocDay04() : AocDay(4) {}

AocDay04::~AocDay04() = default;

std::tuple<int, int> AocDay04::GetMinAndMax(const std::string &stringRange)
{
  const size_t pos = stringRange.find('-');
  return std::tuple<int, int>{ std::stoi(stringRange.substr(0, pos)), std::stoi(stringRange.substr(pos + 1)) };
}

std::variant<int, double, std::string> AocDay04::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int num_fully_contains = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      const size_t pos = line.find(',');
      auto [first_elf_min, first_elf_max] = GetMinAndMax(line.substr(0, pos));
      auto [second_elf_min, second_elf_max] = GetMinAndMax(line.substr(pos + 1));

      if ((first_elf_min <= second_elf_min && first_elf_max >= second_elf_max)
          || (second_elf_min <= first_elf_min && second_elf_max >= first_elf_max)) {
        num_fully_contains++;
      }
    }
    file_stream.close();
  }
  return num_fully_contains;
}

std::variant<int, double, std::string> AocDay04::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int num_contains = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      const size_t pos = line.find(',');
      auto [first_elf_min, first_elf_max] = GetMinAndMax(line.substr(0, pos));
      auto [second_elf_min, second_elf_max] = GetMinAndMax(line.substr(pos + 1));
      std::vector<int> all_min_max{ first_elf_min, first_elf_max, second_elf_min, second_elf_max };
      const auto [smallest, biggest] = std::ranges::minmax_element(all_min_max);

      if (((std::abs(*biggest - *smallest) + 1) - std::abs(first_elf_min - second_elf_min)
            - std::abs(first_elf_max - second_elf_max))
          > 0) {
        num_contains++;
      }
    }
    file_stream.close();
  }
  return num_contains;
}
