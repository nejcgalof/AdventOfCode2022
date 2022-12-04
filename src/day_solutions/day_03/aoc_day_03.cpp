#include "day_03/aoc_day_03.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <vector>

AocDay03::AocDay03() : AocDay(3) {}

AocDay03::~AocDay03() = default;

std::string AocDay03::FindAllSameCharactersInTwoVectors(std::string first, std::string second)
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
  return std::string{ intersection_between_vectors.begin(), intersection_between_vectors.end() };
}

int AocDay03::CalculatePriorityValue(const std::string &characters)
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
      items_sum += CalculatePriorityValue(
        FindAllSameCharactersInTwoVectors(line.substr(0, line.length() / 2), line.substr(line.length() / 2)));
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
    std::vector<std::string> readed_lines;
    std::string line;
    while (std::getline(file_stream, line)) {
      readed_lines.emplace_back(line);
      if (readed_lines.size() == 3) {
        items_sum += CalculatePriorityValue(FindAllSameCharactersInTwoVectors(
          FindAllSameCharactersInTwoVectors(readed_lines.at(0), readed_lines.at(1)), readed_lines.at(2)));
        readed_lines.clear();
      }
    }
  }
  return items_sum;
}
