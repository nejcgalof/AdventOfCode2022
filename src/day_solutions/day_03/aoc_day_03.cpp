#include "day_03/aoc_day_03.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <vector>

AocDay03::AocDay03() : AocDay(3) {}

AocDay03::~AocDay03() = default;

std::vector<char> AocDay03::FindAllSameCharactersInTwoVectors(std::vector<char> first, std::vector<char> second)
{
  std::vector<char> intersection_between_vectors;
  // Sort is needed for set_intersection
  std::sort(first.begin(), first.end());
  std::sort(second.begin(), second.end());
  std::set_intersection(
    first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(intersection_between_vectors));
  // Remove duplicates from intersection vector
  intersection_between_vectors.erase(unique(intersection_between_vectors.begin(), intersection_between_vectors.end()),
    intersection_between_vectors.end());
  return intersection_between_vectors;
}

int AocDay03::CalculatePriorityValue(const std::vector<char> &characters)
{
  int priority = 0;
  for (const auto &item : characters) {
    priority += (static_cast<bool>(std::isupper(item))) ? static_cast<int>(item) - kAsciiUpperA + kStartUpperCase
                                                        : static_cast<int>(item) - kAsciiLowerA + kStartLowerCase;
  }
  return priority;
}

std::variant<int, double, std::string> AocDay03::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int items_sum = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      const std::string first_half_str = line.substr(0, line.length() / 2);
      std::vector<char> v_first_half(first_half_str.begin(), first_half_str.end());

      const std::string second_half_str = line.substr(line.length() / 2);
      std::vector<char> v_second_half(second_half_str.begin(), second_half_str.end());

      items_sum += CalculatePriorityValue(FindAllSameCharactersInTwoVectors(v_first_half, v_second_half));
    }
  }
  return items_sum;
}

std::variant<int, double, std::string> AocDay03::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int items_sum = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::vector<std::vector<char>> lines_of_chars;
    std::string line;
    while (std::getline(file_stream, line)) {
      lines_of_chars.emplace_back(line.begin(), line.end());

      if (lines_of_chars.size() == 3) {
        items_sum += CalculatePriorityValue(FindAllSameCharactersInTwoVectors(
          FindAllSameCharactersInTwoVectors(lines_of_chars.at(0), lines_of_chars.at(1)), lines_of_chars.at(2)));
        lines_of_chars.clear();
      }
    }
  }
  return items_sum;
}
