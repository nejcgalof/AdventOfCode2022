#include "day_12/aoc_day_12.hpp"

#include <fstream>
#include <iostream>
#include <tuple>

AocDay12::AocDay12() : AocDay(12) {}

AocDay12::~AocDay12() = default;

void AocDay12::CheckItem(size_t lineCharacter, size_t character)
{
  const size_t current_position = lineCharacter * characters.at(lineCharacter).size() + character;
  if (characters.at(lineCharacter).at(character) == 'S') {
    start = current_position;
    characters.at(lineCharacter).at(character) = 'a';
  } else if (characters.at(lineCharacter).at(character) == 'E') {
    end = current_position;
    characters.at(lineCharacter).at(character) = 'z';
  }
  std::cout << current_position << "=" << characters.at(lineCharacter).at(character) << std::endl;
  const int curr = characters.at(lineCharacter).at(character) - '0';
  std::cout << "curr" << curr << std::endl;
  const int up_index = static_cast<int>(lineCharacter) - 1;
  const int down_index = static_cast<int>(lineCharacter) + 1;
  const int left_index = static_cast<int>(character) - 1;
  const int right_index = static_cast<int>(character) + 1;
  std::vector<size_t> curr_connections;

  if (up_index != -1) {
    const size_t upper_position = static_cast<size_t>(up_index) * characters.at(lineCharacter).size() + character;
    const int upper = characters.at(static_cast<size_t>(up_index)).at(character) - '0';
    std::cout << "curr " << curr << "up " << upper << std::endl;
    if (curr >= upper || upper == curr + 1) { curr_connections.emplace_back(upper_position); }
  }
  if (left_index != -1) {
    const size_t left_position = lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(left_index);
    const int left = characters.at(lineCharacter).at(static_cast<size_t>(left_index)) - '0';
    std::cout << "curr " << curr << "left " << left << std::endl;
    if (curr >= left || left == curr + 1) { curr_connections.emplace_back(left_position); }
  }
  if (down_index != static_cast<int>(characters.size())) {
    const size_t down_position = static_cast<size_t>(down_index) * characters.at(lineCharacter).size() + character;
    const int down = characters.at(static_cast<size_t>(down_index)).at(character) - '0';
    std::cout << "curr " << curr << "down " << down << std::endl;
    if (curr >= down || down == curr + 1) { curr_connections.emplace_back(down_position); }
  }
  if (right_index != static_cast<int>(characters.at(lineCharacter).size())) {
    const size_t right_position =
      lineCharacter * characters.at(lineCharacter).size() + static_cast<size_t>(right_index);
    const int right = characters.at(lineCharacter).at(static_cast<size_t>(right_index)) - '0';
    std::cout << "curr " << curr << "right " << right << std::endl;
    if (curr >= right || right == curr + 1) { curr_connections.emplace_back(right_position); }
  }
  std::cout << "curr_connections" << std::endl;
  for (auto &aaa : curr_connections) { std::cout << aaa << " "; }
  std::cout << std::endl;
  connections.emplace_back(std::make_tuple(current_position, curr_connections));
}

std::variant<int, double, std::string> AocDay12::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) { characters.emplace_back(line.begin(), line.end()); }
  }
  file_stream.close();

  for (size_t line_character = 0; line_character < characters.size(); line_character++) {
    for (size_t character = 0; character < characters.at(line_character).size(); character++) {
      CheckItem(line_character, character);
      std::cout << "////////" << std::endl;
    }
  }
  std::cout << start << "," << end << std::endl;
  for (auto &[item, connec] : connections) {
    std::cout << item << "={";
    for (auto &con : connec) { std::cout << con << " "; }
    std::cout << "}" << std::endl;
  }
  // https://stackoverflow.com/questions/8922060/how-to-trace-the-path-in-a-breadth-first-search
  return 0;
}

std::variant<int, double, std::string> AocDay12::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return 0;
}
