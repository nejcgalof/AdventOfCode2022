#include "day_05/aoc_day_05.hpp"

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <fstream>
#include <iterator>
#include <memory>
#include <sstream>
#include <variant>
#include <vector>

AocDay05::AocDay05() : AocDay(5) {}

AocDay05::~AocDay05() = default;

void AocDay05::ModifyStartingStacksFromReadedLine(std::string line, std::vector<std::vector<char>> &stacks)
{
  size_t index = 0;
  while ((index = line.find('[', index)) != std::string::npos) {
    stacks.at(index / 4).emplace_back(line.at(index + 1));
    index += 1;
  }
}

void AocDay05::MakeMoveFromReadedLine(const std::string &line,
  std::vector<std::vector<char>> &stacks,
  bool move_same_order)
{
  std::vector<size_t> numbers;
  std::string word;
  std::istringstream iss(line);
  while (std::getline(iss, word, ' ')) {
    if (std::all_of(word.begin(), word.end(), [](char ch) { return std::isdigit(static_cast<unsigned char>(ch)); })) {
      numbers.emplace_back(std::stoi(word));
    }
  }
  auto &from_stack = stacks.at(numbers.at(1) - 1);
  auto &to_stack = stacks.at(numbers.at(2) - 1);
  if (move_same_order) {
    to_stack.insert(to_stack.begin(),
      std::make_move_iterator(from_stack.begin()),
      std::make_move_iterator(from_stack.begin() + static_cast<long>(numbers.at(0))));
  } else {
    to_stack.insert(to_stack.begin(),
      std::make_reverse_iterator(from_stack.begin() + static_cast<long>(numbers.at(0))),
      std::make_reverse_iterator(from_stack.begin()));
  }
  from_stack.erase(from_stack.begin(), from_stack.begin() + static_cast<long>(numbers.at(0)));
}

std::string AocDay05::SupplyStacks(const std::string &file, bool move_same_order)
{
  std::string top_crates;
  std::ifstream file_stream(file);
  std::vector<std::vector<char>> stacks;
  if (file_stream.is_open()) {
    bool moving_mode = false;
    std::string line;
    while (std::getline(file_stream, line)) {
      // Empty line - mode switch between ModifyStartingStacksFromReadedLine and MakeMoveFromReadedLine
      if (line.empty()) {
        moving_mode = true;
        continue;
      }

      if (moving_mode) {
        MakeMoveFromReadedLine(line, stacks, move_same_order);
      } else {
        // In the first interation we resize the stacks
        if (stacks.empty()) { stacks.resize((line.length() + 1) / 4); }
        ModifyStartingStacksFromReadedLine(line, stacks);
      }
    }
    file_stream.close();
  }
  std::for_each(stacks.begin(), stacks.end(), [&](const auto &stack) { top_crates += stack.front(); });
  return top_crates;
}

std::variant<int, double, std::string> AocDay05::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return SupplyStacks(file, false);
}

std::variant<int, double, std::string> AocDay05::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return SupplyStacks(file, true);
}
