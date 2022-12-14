#include "day_12/aoc_day_12.hpp"

#include <fstream>
#include <iostream>
#include <queue>
#include <tuple>

AocDay12::AocDay12() : AocDay(12) {}

AocDay12::~AocDay12() = default;

void AocDay12::CheckUp(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections)
{
  const int curr = characters.at(lineCharacter).at(character) - '0';
  const int up_index = static_cast<int>(lineCharacter) - 1;
  if (up_index != -1) {
    const size_t upper_position = static_cast<size_t>(up_index) * characters.at(lineCharacter).size() + character;
    const int upper = characters.at(static_cast<size_t>(up_index)).at(character) - '0';
    const bool check = !reverse ? (curr >= upper || upper == curr + 1) : (curr <= upper || upper == curr - 1);
    if (check) { currConnections.emplace_back(upper_position); }
  }
}

void AocDay12::CheckDown(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections)
{
  const int curr = characters.at(lineCharacter).at(character) - '0';
  const int down_index = static_cast<int>(lineCharacter) + 1;
  if (down_index != static_cast<int>(characters.size())) {
    const size_t down_position = static_cast<size_t>(down_index) * characters.at(lineCharacter).size() + character;
    const int down = characters.at(static_cast<size_t>(down_index)).at(character) - '0';
    const bool check = !reverse ? (curr >= down || down == curr + 1) : (curr <= down || down == curr - 1);
    if (check) { currConnections.emplace_back(down_position); }
  }
}

void AocDay12::CheckLeft(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections)
{
  const int curr = characters.at(lineCharacter).at(character) - '0';
  const int left_index = static_cast<int>(character) - 1;
  if (left_index != -1) {
    const size_t left_position = lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(left_index);
    const int left = characters.at(lineCharacter).at(static_cast<size_t>(left_index)) - '0';
    const bool check = !reverse ? (curr >= left || left == curr + 1) : (curr <= left || left == curr - 1);
    if (check) { currConnections.emplace_back(left_position); }
  }
}

void AocDay12::CheckRight(bool reverse, size_t lineCharacter, size_t character, std::vector<size_t> &currConnections)
{
  const int curr = characters.at(lineCharacter).at(character) - '0';
  const int right_index = static_cast<int>(character) + 1;
  if (right_index != static_cast<int>(characters.at(lineCharacter).size())) {
    const size_t right_position =
      lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(right_index);
    const int right = characters.at(lineCharacter).at(static_cast<size_t>(right_index)) - '0';
    const bool check = !reverse ? (curr >= right || right == curr + 1) : (curr <= right || right == curr - 1);
    if (check) { currConnections.emplace_back(right_position); }
  }
}

void AocDay12::CheckItem(bool reverse, size_t lineCharacter, size_t character)
{

  const size_t current_position = lineCharacter * characters.at(lineCharacter).size() + character;
  std::vector<size_t> curr_connections;

  CheckRight(reverse, lineCharacter, character, curr_connections);
  CheckUp(reverse, lineCharacter, character, curr_connections);
  CheckLeft(reverse, lineCharacter, character, curr_connections);
  CheckDown(reverse, lineCharacter, character, curr_connections);
  connectionMap[current_position] = curr_connections;
}

void AocDay12::ModifyStartEnd(bool reverse, size_t lineCharacter, size_t character)
{
  const size_t current_position = lineCharacter * characters.at(lineCharacter).size() + character;
  if (reverse) {
    if (characters.at(lineCharacter).at(character) == 'S') {
      characters.at(lineCharacter).at(character) = 'a';
    } else if (characters.at(lineCharacter).at(character) == 'E') {
      start = current_position;
      characters.at(lineCharacter).at(character) = 'z';
    }
    if (characters.at(lineCharacter).at(character) == 'a') { end.emplace_back(current_position); }
  } else {
    if (characters.at(lineCharacter).at(character) == 'S') {
      start = current_position;
      characters.at(lineCharacter).at(character) = 'a';
    } else if (characters.at(lineCharacter).at(character) == 'E') {
      end.emplace_back(current_position);
      characters.at(lineCharacter).at(character) = 'z';
    }
  }
}

void AocDay12::ModifyStartEndAndCheckItems(bool reverse)
{
  connectionMap.resize(characters.size() * characters.at(0).size());
  for (size_t line_character = 0; line_character < characters.size(); line_character++) {
    for (size_t character = 0; character < characters.at(line_character).size(); character++) {
      ModifyStartEnd(reverse, line_character, character);
    }
  }
  for (size_t line_character = 0; line_character < characters.size(); line_character++) {
    for (size_t character = 0; character < characters.at(line_character).size(); character++) {
      CheckItem(reverse, line_character, character);
    }
  }
}

int AocDay12::BFS()
{
  std::vector<bool> visited(characters.size() * characters.at(0).size(), false);
  std::queue<std::pair<size_t, size_t>> queue;
  queue.push(std::make_pair(start, 0));
  while (!queue.empty()) {
    const auto &[node, size] = queue.front();
    if (visited.at(node)) {
      queue.pop();
      continue;
    }
    visited.at(node) = true;
    if (std::find(end.begin(), end.end(), node) != end.end()) { return static_cast<int>(size); }
    for (const auto &adjacent : connectionMap.at(node)) {
      if (!visited.at(adjacent)) { queue.push(std::make_pair(adjacent, size + 1)); }
    }
    queue.pop();
  }
  return 0;
}

// https://stackoverflow.com/questions/8922060/how-to-trace-the-path-in-a-breadth-first-search
int AocDay12::HillClimbingProblemFromFile(const std::string &file, bool reverse)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) { characters.emplace_back(line.begin(), line.end()); }
    file_stream.close();
  } else {
    return 0;
  }

  ModifyStartEndAndCheckItems(reverse);
  return BFS();
}

std::variant<int, double, std::string> AocDay12::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return HillClimbingProblemFromFile(file, false);
}

std::variant<int, double, std::string> AocDay12::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return HillClimbingProblemFromFile(file, true);
}
