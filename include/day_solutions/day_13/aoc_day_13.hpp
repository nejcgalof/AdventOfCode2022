#ifndef ADVENTOFCODE_AOC_DAY_13_HPP
#define ADVENTOFCODE_AOC_DAY_13_HPP

#include <memory>
#include <stddef.h>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay13 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  struct List
  {
    List *parent{ nullptr };
    std::vector<std::variant<std::unique_ptr<List>, int>> packetData;
  };

  struct Packet
  {
    bool isDividerPacket{ false };
    std::vector<int> numbers;
    int numNested{ 0 };
  };

  size_t ParseSequence(List *item, std::string line);
  static int ComparePackets(List *firstPacket, List *secondPacket);
  static int CheckEmptiness(List *firstPacket, List *secondPacket);
  static int CheckNullptr(List *firstPacket, List *secondPacket);

  static void Sort(std::vector<Packet> &packets);
  static int FindPositionOfDividerPacketsAndMultiply(std::vector<Packet> &packets);

public:
  AocDay13();
  ~AocDay13() override;
};

#endif
