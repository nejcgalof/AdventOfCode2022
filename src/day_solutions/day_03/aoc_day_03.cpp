#include "day_03/aoc_day_03.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iterator>
#include <vector>

AocDay03::AocDay03() : AocDay(3) {}

AocDay03::~AocDay03() = default;

std::variant<int, double, std::string> AocDay03::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  constexpr int kStartUpperCase = 27;
  constexpr int kStartLowerCase = 1;
  constexpr int kAsciiUpperA = static_cast<int>('A');
  constexpr int kAsciiLowerA = static_cast<int>('a');

  int items_sum = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      const std::string first_half_str = line.substr(0, line.length() / 2);
      std::vector<char> v_first_half(first_half_str.begin(), first_half_str.end());

      const std::string second_half_str = line.substr(line.length() / 2);
      std::vector<char> v_second_half(second_half_str.begin(), second_half_str.end());

      // Find the same characters between two halfs
      std::vector<char> intersection_between_halfs;
      // Sort is needed for set_intersection
      std::sort(v_first_half.begin(), v_first_half.end());
      std::sort(v_second_half.begin(), v_second_half.end());
      std::set_intersection(v_first_half.begin(),
        v_first_half.end(),
        v_second_half.begin(),
        v_second_half.end(),
        std::back_inserter(intersection_between_halfs));
      // Remove duplicates from intersection vector
      intersection_between_halfs.erase(
        unique(intersection_between_halfs.begin(), intersection_between_halfs.end()), intersection_between_halfs.end());

      for (const auto &item : intersection_between_halfs) {
        items_sum += (static_cast<bool>(std::isupper(item))) ? static_cast<int>(item) - kAsciiUpperA + kStartUpperCase
                                                             : static_cast<int>(item) - kAsciiLowerA + kStartLowerCase;
      }
    }
  }
  return items_sum;
}

std::variant<int, double, std::string> AocDay03::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  constexpr int kStartUpperCase = 27;
  constexpr int kStartLowerCase = 1;
  constexpr int kAsciiUpperA = static_cast<int>('A');
  constexpr int kAsciiLowerA = static_cast<int>('a');

  int items_sum = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::vector<std::vector<char>> lines_of_chars;
    std::string line;
    while (std::getline(file_stream, line)) {
      lines_of_chars.emplace_back(line.begin(), line.end());

      if (lines_of_chars.size() == 3) {
        std::vector<char> intersection_between_first_two;
        // Sort is needed for set_intersection
        std::sort(lines_of_chars.at(0).begin(), lines_of_chars.at(0).end());
        std::sort(lines_of_chars.at(1).begin(), lines_of_chars.at(1).end());
        std::set_intersection(lines_of_chars.at(0).begin(),
          lines_of_chars.at(0).end(),
          lines_of_chars.at(1).begin(),
          lines_of_chars.at(1).end(),
          std::back_inserter(intersection_between_first_two));
        // Remove duplicates from intersection vector
        intersection_between_first_two.erase(
          unique(intersection_between_first_two.begin(), intersection_between_first_two.end()),
          intersection_between_first_two.end());

        std::vector<char> intersection_between_first_two_and_three;
        // Sort is needed for set_intersection
        std::sort(intersection_between_first_two.begin(), intersection_between_first_two.end());
        std::sort(lines_of_chars.at(2).begin(), lines_of_chars.at(2).end());
        std::set_intersection(intersection_between_first_two.begin(),
          intersection_between_first_two.end(),
          lines_of_chars.at(2).begin(),
          lines_of_chars.at(2).end(),
          std::back_inserter(intersection_between_first_two_and_three));
        // Remove duplicates from intersection vector
        intersection_between_first_two_and_three.erase(
          unique(intersection_between_first_two_and_three.begin(), intersection_between_first_two_and_three.end()),
          intersection_between_first_two_and_three.end());

        for (const auto &item : intersection_between_first_two_and_three) {
          items_sum += (static_cast<bool>(std::isupper(item)))
                         ? static_cast<int>(item) - kAsciiUpperA + kStartUpperCase
                         : static_cast<int>(item) - kAsciiLowerA + kStartLowerCase;
        }
        lines_of_chars.clear();
      }
    }
  }
  return items_sum;
}
