#include "day_13/aoc_day_13.hpp"

#include <algorithm>
#include <ext/alloc_traits.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <type_traits>
#include <utility>

AocDay13::AocDay13() : AocDay(13) {}

AocDay13::~AocDay13() = default;

size_t AocDay13::ParseSequence(List *item, std::string line)
{
  for (size_t character = 0; character < line.length(); character++) {
    // std::cout << "Character: " << line.at(character) << std::endl;
    if (line.at(character) == '[') {
      std::cout << "Start" << std::endl;
      auto children = std::make_unique<List>();
      children->parent = item;
      character += ParseSequence(children.get(), line.substr(character + 1));
      // std::cout << "Berem: " << children->packetData.size() << std::endl;
      item->packetData.emplace_back(std::move(children));
    } else if (line.at(character) == ']') {
      std::cout << "End" << std::endl;
      return character + 1;
    } else if (line.at(character) == ',') {
      continue;
    } else {
      auto subs = line.substr(character);
      item->packetData.emplace_back(std::stoi(line.substr(character, subs.find_first_not_of("0123456789"))));
      std::cout << "Char: " << line.substr(character, subs.find_first_not_of("0123456789")) << std::endl;
      character += subs.find_first_not_of("0123456789") - 1;
    }
  }
  // std::cout << "Poglejmo: " << item->packetData.size() << std::endl;
  return line.length();
}

int AocDay13::CheckEmptiness(List *firstPacket, List *secondPacket)
{
  if (firstPacket->packetData.empty() && secondPacket->packetData.empty()) {
    // std::cout << "both packets are empty" << std::endl;
    return -1;
  }
  if (firstPacket->packetData.empty()) {
    // std::cout << "first packet are empty" << std::endl;
    return 1;
  } else if (secondPacket->packetData.empty()) {
    // std::cout << "second packet are empty" << std::endl;
    return 0;
  }
  return -2;
}

int AocDay13::CheckNullptr(List *firstPacket, List *secondPacket)
{
  if (firstPacket == nullptr || secondPacket == nullptr) {
    if (secondPacket != nullptr) { return 0; }
    return 1;
  }
  return -1;
}

int AocDay13::ComparePackets(List *firstPacket, List *secondPacket)
{
  int nullness = CheckNullptr(firstPacket, secondPacket);
  if (nullness >= 0) { return nullness; }
  // std::cout << "ComparePackets" << std::endl;
  const int check_emptiness = CheckEmptiness(firstPacket, secondPacket);
  if (check_emptiness == -1) {
    // std::cout << "Move out" << std::endl;
    // std::cout << "Size first parent: " << firstPacket->parent->packetData.size() << std::endl;
    auto *first_parent = firstPacket->parent;
    auto *second_parent = secondPacket->parent;
    int parent_nullness = CheckNullptr(first_parent, second_parent);
    if (parent_nullness >= 0) { return parent_nullness; }
    if (!first_parent->packetData.empty()) { first_parent->packetData.erase(first_parent->packetData.begin()); }
    if (!second_parent->packetData.empty()) { second_parent->packetData.erase(second_parent->packetData.begin()); }
    return ComparePackets(first_parent, second_parent);
  } else if (check_emptiness >= 0) {
    return check_emptiness;
  }

  if (std::holds_alternative<std::unique_ptr<List>>(firstPacket->packetData.at(0))
      && std::holds_alternative<std::unique_ptr<List>>(secondPacket->packetData.at(0))) {
    // std::cout << "both values are lists" << std::endl;
    return ComparePackets(std::get<std::unique_ptr<List>>(firstPacket->packetData.at(0)).get(),
      std::get<std::unique_ptr<List>>(secondPacket->packetData.at(0)).get());
  } else if (std::holds_alternative<int>(firstPacket->packetData.at(0))
             && std::holds_alternative<int>(secondPacket->packetData.at(0))) {
    // std::cout << "both values are integers" << std::endl;
    auto first_number = std::get<int>(firstPacket->packetData.at(0));
    auto second_number = std::get<int>(secondPacket->packetData.at(0));
    std::cout << "compare: " << first_number << " " << second_number << std::endl;
    if (first_number < second_number) {
      return 1;
    } else if (first_number > second_number) {
      return 0;
    } else {
      firstPacket->packetData.erase(firstPacket->packetData.begin());
      secondPacket->packetData.erase(secondPacket->packetData.begin());
      return ComparePackets(firstPacket, secondPacket);
    }
  } else {
    // std::cout << "Mixed type" << std::endl;
    if (std::holds_alternative<int>(firstPacket->packetData.at(0))) {
      // std::cout << "First is int" << std::endl;
      auto new_one = std::make_unique<List>();
      new_one->packetData.emplace_back(std::move(firstPacket->packetData.at(0)));
      firstPacket->packetData.at(0) = std::move(new_one);
    } else if (std::holds_alternative<int>(secondPacket->packetData.at(0))) {
      // std::cout << "Second is int" << std::endl;
      auto new_one = std::make_unique<List>();
      new_one->packetData.emplace_back(std::move(secondPacket->packetData.at(0)));
      secondPacket->packetData.at(0) = std::move(new_one);
    }
    return ComparePackets(firstPacket, secondPacket);
    // topPriorityRules.erase(topPriorityRules.begin());
  }
  return 0;
}

std::variant<int, double, std::string> AocDay13::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int result = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    std::vector<std::unique_ptr<List>> packets;
    while (std::getline(file_stream, line)) {
      if (line.empty()) { continue; }
      auto packet = std::make_unique<List>();
      ParseSequence(packet.get(), line);
      packets.emplace_back(std::move(packet));
    }
    file_stream.close();

    for (size_t pairs = 0; pairs < packets.size() / 2; pairs++) {
      size_t move = pairs * 2;
      int res = ComparePackets(packets.at(move).get(), packets.at(move + 1).get());
      std::cout << "Result: " << res << std::endl;
      if (res == 1) { result += static_cast<int>(pairs + 1); }
    }
  }

  return result;
}

std::variant<int, double, std::string> AocDay13::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return 0;
}
