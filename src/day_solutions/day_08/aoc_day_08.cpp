#include "day_08/aoc_day_08.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iterator>
#include <memory>
#include <vector>

AocDay08::AocDay08() : AocDay(8) {}

AocDay08::~AocDay08() = default;

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
std::tuple<bool, int> AocDay08::CheckTop(const size_t row, const size_t col)
{
  for (size_t curr_row = row; curr_row-- > 0;) {
    if (trees.at(curr_row).at(col) >= trees.at(row).at(col)) { return std::tuple<bool, int>{ false, row - curr_row }; }
  }
  return std::tuple<bool, int>{ true, (row == 0) ? 0 : row };
}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
std::tuple<bool, int> AocDay08::CheckBottom(const size_t row, const size_t col)
{
  for (size_t curr_row = row + 1; curr_row < trees.size(); curr_row++) {
    if (trees.at(curr_row).at(col) >= trees.at(row).at(col)) { return std::tuple<bool, int>{ false, curr_row - row }; }
  }
  return std::tuple<bool, int>{ true, (row == trees.size() - 1) ? 0 : trees.size() - 1 - row };
}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
std::tuple<bool, int> AocDay08::CheckLeft(const size_t row, const size_t col)
{
  for (size_t curr_col = col; curr_col-- > 0;) {
    if (trees.at(row).at(curr_col) >= trees.at(row).at(col)) { return std::tuple<bool, int>{ false, col - curr_col }; }
  }
  return std::tuple<bool, int>{ true, (col == 0) ? 0 : col };
}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
std::tuple<bool, int> AocDay08::CheckRight(const size_t row, const size_t col)
{
  for (size_t curr_col = col + 1; curr_col < trees.at(row).size(); curr_col++) {
    if (trees.at(row).at(curr_col) >= trees.at(row).at(col)) { return std::tuple<bool, int>{ false, curr_col - col }; }
  }
  return std::tuple<bool, int>{ true, (col == trees.at(row).size() - 1) ? 0 : trees.at(row).size() - 1 - col };
}

void AocDay08::GenerateTreesFromFile(const std::string &file)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      std::vector<int> tree_line;
      std::transform(
        line.begin(), line.end(), std::back_inserter(tree_line), [](const auto &character) { return character - '0'; });
      trees.emplace_back(tree_line);
    }
    file_stream.close();
  }
}

std::variant<int, double, std::string> AocDay08::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  GenerateTreesFromFile(file);

  int num_visible_trees = 0;
  for (size_t row = 0; row < trees.size(); row++) {
    for (size_t col = 0; col < trees.at(row).size(); col++) {
      num_visible_trees += static_cast<int>(std::get<0>(CheckTop(row, col)) || std::get<0>(CheckBottom(row, col))
                                            || std::get<0>(CheckLeft(row, col)) || std::get<0>(CheckRight(row, col)));
    }
  }
  return num_visible_trees;
}

std::variant<int, double, std::string> AocDay08::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  GenerateTreesFromFile(file);

  int highest_scenic_score = 0;
  for (size_t row = 0; row < trees.size(); row++) {
    for (size_t col = 0; col < trees.at(row).size(); col++) {
      const auto scenic_score = std::get<1>(CheckTop(row, col)) * std::get<1>(CheckBottom(row, col))
                                * std::get<1>(CheckLeft(row, col)) * std::get<1>(CheckRight(row, col));
      if (scenic_score > highest_scenic_score) { highest_scenic_score = scenic_score; }
    }
  }
  return highest_scenic_score;
}
