#include "day_12/aoc_day_12.hpp"

#include <fstream>
#include <iostream>
#include <queue>
#include <tuple>

AocDay12::AocDay12() : AocDay(12) {}

AocDay12::~AocDay12() = default;

void AocDay12::CheckItem(size_t lineCharacter, size_t character)
{
  const size_t current_position = lineCharacter * characters.at(lineCharacter).size() + character;
  const int curr = characters.at(lineCharacter).at(character) - '0';

  const int up_index = static_cast<int>(lineCharacter) - 1;
  const int down_index = static_cast<int>(lineCharacter) + 1;
  const int left_index = static_cast<int>(character) - 1;
  const int right_index = static_cast<int>(character) + 1;
  std::vector<size_t> curr_connections;

  if (right_index != static_cast<int>(characters.at(lineCharacter).size())) {
    const size_t right_position =
      lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(right_index);
    const int right = characters.at(lineCharacter).at(static_cast<size_t>(right_index)) - '0';
    if (curr >= right || right == curr + 1) { curr_connections.emplace_back(right_position); }
  }
  if (up_index != -1) {
    const size_t upper_position = static_cast<size_t>(up_index) * characters.at(lineCharacter).size() + character;
    const int upper = characters.at(static_cast<size_t>(up_index)).at(character) - '0';
    if (curr >= upper || upper == curr + 1) { curr_connections.emplace_back(upper_position); }
  }
  if (left_index != -1) {
    const size_t left_position = lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(left_index);
    const int left = characters.at(lineCharacter).at(static_cast<size_t>(left_index)) - '0';
    if (curr >= left || left == curr + 1) { curr_connections.emplace_back(left_position); }
  }
  if (down_index != static_cast<int>(characters.size())) {
    const size_t down_position = static_cast<size_t>(down_index) * characters.at(lineCharacter).size() + character;
    const int down = characters.at(static_cast<size_t>(down_index)).at(character) - '0';
    if (curr >= down || down == curr + 1) { curr_connections.emplace_back(down_position); }
  }
  connectionMap[current_position] = curr_connections;
}

void AocDay12::CheckItem2(size_t lineCharacter, size_t character)
{
  const size_t current_position = lineCharacter * characters.at(lineCharacter).size() + character;
  const int curr = characters.at(lineCharacter).at(character) - '0';

  const int up_index = static_cast<int>(lineCharacter) - 1;
  const int down_index = static_cast<int>(lineCharacter) + 1;
  const int left_index = static_cast<int>(character) - 1;
  const int right_index = static_cast<int>(character) + 1;
  std::vector<size_t> curr_connections;

  if (right_index != static_cast<int>(characters.at(lineCharacter).size())) {
    const size_t right_position =
      lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(right_index);
    const int right = characters.at(lineCharacter).at(static_cast<size_t>(right_index)) - '0';
    if (curr <= right || right == curr - 1) { curr_connections.emplace_back(right_position); }
  }
  if (up_index != -1) {
    const size_t upper_position = static_cast<size_t>(up_index) * characters.at(lineCharacter).size() + character;
    const int upper = characters.at(static_cast<size_t>(up_index)).at(character) - '0';
    if (curr <= upper || upper == curr - 1) { curr_connections.emplace_back(upper_position); }
  }
  if (left_index != -1) {
    const size_t left_position = lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(left_index);
    const int left = characters.at(lineCharacter).at(static_cast<size_t>(left_index)) - '0';
    if (curr <= left || left == curr - 1) { curr_connections.emplace_back(left_position); }
  }
  if (down_index != static_cast<int>(characters.size())) {
    const size_t down_position = static_cast<size_t>(down_index) * characters.at(lineCharacter).size() + character;
    const int down = characters.at(static_cast<size_t>(down_index)).at(character) - '0';
    if (curr <= down || down == curr - 1) { curr_connections.emplace_back(down_position); }
  }
  connectionMap[current_position] = curr_connections;
}

int AocDay12::BFS()
{
  std::vector<bool> visited(characters.size() * characters.at(0).size(), false);
  std::queue<std::pair<size_t, size_t>> queue;
  queue.push(std::make_pair(start, 0));
  while (!queue.empty()) {
    const auto &[node, size] = queue.front();
    if (!visited.at(node)) {
      visited.at(node) = true;
    } else {
      queue.pop();
      continue;
    }
    if (std::find(end.begin(), end.end(), node) != end.end()) { return static_cast<int>(size); }
    for (const auto &adjacent : connectionMap.at(node)) {
      if (!visited.at(adjacent)) { queue.push(std::make_pair(adjacent, size + 1)); }
    }
    queue.pop();
  }

  return 0;
}

std::variant<int, double, std::string> AocDay12::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) { characters.emplace_back(line.begin(), line.end()); }
  } else {
    return 0;
  }
  file_stream.close();

  // Modify start and end
  for (size_t line_character = 0; line_character < characters.size(); line_character++) {
    for (size_t character = 0; character < characters.at(line_character).size(); character++) {
      const size_t current_position = line_character * characters.at(line_character).size() + character;
      if (characters.at(line_character).at(character) == 'S') {
        start = current_position;
        characters.at(line_character).at(character) = 'a';
      } else if (characters.at(line_character).at(character) == 'E') {
        end.emplace_back(current_position);
        characters.at(line_character).at(character) = 'z';
      }
    }
  }

  connectionMap.resize(characters.size() * characters.at(0).size());

  for (size_t line_character = 0; line_character < characters.size(); line_character++) {
    for (size_t character = 0; character < characters.at(line_character).size(); character++) {
      CheckItem(line_character, character);
    }
  }

  // https://stackoverflow.com/questions/8922060/how-to-trace-the-path-in-a-breadth-first-search
  return BFS();
}

std::variant<int, double, std::string> AocDay12::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) { characters.emplace_back(line.begin(), line.end()); }
  } else {
    return 0;
  }
  file_stream.close();

  // Modify start and end
  for (size_t line_character = 0; line_character < characters.size(); line_character++) {
    for (size_t character = 0; character < characters.at(line_character).size(); character++) {
      const size_t current_position = line_character * characters.at(line_character).size() + character;
      if (characters.at(line_character).at(character) == 'S') {
        characters.at(line_character).at(character) = 'a';
      } else if (characters.at(line_character).at(character) == 'E') {
        start = current_position;
        characters.at(line_character).at(character) = 'z';
      }
      if (characters.at(line_character).at(character) == 'a') { end.emplace_back(current_position); }
    }
  }

  connectionMap.resize(characters.size() * characters.at(0).size());

  for (size_t line_character = 0; line_character < characters.size(); line_character++) {
    for (size_t character = 0; character < characters.at(line_character).size(); character++) {
      CheckItem2(line_character, character);
    }
  }
  // https://stackoverflow.com/questions/8922060/how-to-trace-the-path-in-a-breadth-first-search
  return BFS();
}
