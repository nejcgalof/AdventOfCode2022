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
    if (line.at(character) == '[') {
      auto children = std::make_unique<List>();
      children->parent = item;
      character += ParseSequence(children.get(), line.substr(character + 1));
      item->packetData.emplace_back(std::move(children));
    } else if (line.at(character) == ']') {
      return character + 1;
    } else if (line.at(character) == ',') {
      continue;
    } else {
      auto subs = line.substr(character);
      item->packetData.emplace_back(std::stoi(line.substr(character, subs.find_first_not_of("0123456789"))));
      character += subs.find_first_not_of("0123456789") - 1;
    }
  }
  return line.length();
}

int AocDay13::CheckEmptiness(List *firstPacket, List *secondPacket)
{
  if (firstPacket->packetData.empty() && secondPacket->packetData.empty()) { return -1; }
  if (firstPacket->packetData.empty()) {
    return 1;
  } else if (secondPacket->packetData.empty()) {
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
  const int nullness = CheckNullptr(firstPacket, secondPacket);
  if (nullness >= 0) { return nullness; }
  const int check_emptiness = CheckEmptiness(firstPacket, secondPacket);
  if (check_emptiness == -1) {
    auto *first_parent = firstPacket->parent;
    auto *second_parent = secondPacket->parent;
    const int parent_nullness = CheckNullptr(first_parent, second_parent);
    if (parent_nullness >= 0) { return parent_nullness; }
    if (!first_parent->packetData.empty()) { first_parent->packetData.erase(first_parent->packetData.begin()); }
    if (!second_parent->packetData.empty()) { second_parent->packetData.erase(second_parent->packetData.begin()); }
    return ComparePackets(first_parent, second_parent);
  } else if (check_emptiness >= 0) {
    return check_emptiness;
  }

  if (std::holds_alternative<std::unique_ptr<List>>(firstPacket->packetData.at(0))
      && std::holds_alternative<std::unique_ptr<List>>(secondPacket->packetData.at(0))) {
    return ComparePackets(std::get<std::unique_ptr<List>>(firstPacket->packetData.at(0)).get(),
      std::get<std::unique_ptr<List>>(secondPacket->packetData.at(0)).get());
  } else if (std::holds_alternative<int>(firstPacket->packetData.at(0))
             && std::holds_alternative<int>(secondPacket->packetData.at(0))) {
    auto first_number = std::get<int>(firstPacket->packetData.at(0));
    auto second_number = std::get<int>(secondPacket->packetData.at(0));
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
    if (std::holds_alternative<int>(firstPacket->packetData.at(0))) {
      auto new_one = std::make_unique<List>();
      new_one->packetData.emplace_back(std::move(firstPacket->packetData.at(0)));
      firstPacket->packetData.at(0) = std::move(new_one);
    } else if (std::holds_alternative<int>(secondPacket->packetData.at(0))) {
      auto new_one = std::make_unique<List>();
      new_one->packetData.emplace_back(std::move(secondPacket->packetData.at(0)));
      secondPacket->packetData.at(0) = std::move(new_one);
    }
    return ComparePackets(firstPacket, secondPacket);
  }
  return 0;
}

void AocDay13::Sort(std::vector<Packet> &packets)
{
  std::sort(packets.begin(), packets.end(), [](const auto &first, const auto &second) {
    for (std::size_t i = 0; i < first.numbers.size(); i++) {
      if (i >= second.numbers.size()) { return false; }
      if (first.numbers.at(i) > second.numbers.at(i)) {
        return false;
      } else if (first.numbers.at(i) == second.numbers.at(i)) {
        continue;
      } else {
        return true;
      }
    }
    return !(first.numbers.size() == second.numbers.size() && first.numNested > second.numNested);
  });
}

int AocDay13::FindPositionOfDividerPacketsAndMultiply(std::vector<Packet> &packets)
{
  int mult = 1;
  for (size_t i = 0; i < packets.size(); i++) {
    if (packets.at(i).isDividerPacket) { mult *= static_cast<int>(i + 1); }
  }
  return mult;
}

void AocDay13::GeneratePacketsFromFile(const std::string &file, std::vector<Packet> &packets)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      if (line.empty()) { continue; }
      Packet item;
      for (size_t character = 0; character < line.length(); character++) {
        if (line.at(character) == '[') {
          item.numNested++;
        } else if (line.at(character) == ',' && line.at(character - 1) == ']') {
          item.numbers.emplace_back(-1); // Indicator for endlist in list
          continue;
        } else if (line.at(character) == ']' || line.at(character) == ',') {
          continue;
        } else {
          auto subs = line.substr(character);
          item.numbers.emplace_back(std::stoi(line.substr(character, subs.find_first_not_of("0123456789"))));
          character += subs.find_first_not_of("0123456789") - 1;
        }
      }
      packets.emplace_back(item);
    }
    file_stream.close();
  }
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
      const size_t move = pairs * 2;
      if (ComparePackets(packets.at(move).get(), packets.at(move + 1).get()) == 1) {
        result += static_cast<int>(pairs + 1);
      }
    }
  }
  return result;
}

std::variant<int, double, std::string> AocDay13::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  std::vector<Packet> packets;
  GeneratePacketsFromFile(file, packets);
  if (packets.empty()) { return 0; }

  Packet first_divider_packet;
  first_divider_packet.isDividerPacket = true;
  first_divider_packet.numNested = 2;
  first_divider_packet.numbers.emplace_back(2);
  packets.emplace_back(first_divider_packet);

  Packet second_divider_packet;
  second_divider_packet.isDividerPacket = true;
  second_divider_packet.numNested = 2;
  second_divider_packet.numbers.emplace_back(6);
  packets.emplace_back(second_divider_packet);

  Sort(packets);
  return FindPositionOfDividerPacketsAndMultiply(packets);
}
