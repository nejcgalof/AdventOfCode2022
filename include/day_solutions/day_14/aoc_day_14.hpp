#ifndef ADVENTOFCODE_AOC_DAY_14_HPP
#define ADVENTOFCODE_AOC_DAY_14_HPP

#include <map>
#include <string>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay14 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  struct Block
  {
    int x{ 0 };
    int y{ 0 };
  };

  int maxY{ 0 };
  std::map<int, std::map<int, Block>> solidMaterialsMap; // Duplicate data, but ready, if Block have another properties

  void CreateBlocksBetweenX(const Block &from, const Block &target);
  void CreateBlocksBetweenY(const Block &from, const Block &target);
  void GenerateRockPathFromBlocks(std::vector<Block> blocksFromRock);
  void UpdateMaxY(const Block &block);
  Block GetBlockFromString(const std::string &blockString);
  void ReadBlocksFromFile(const std::string &file);
  int FallingSand();
  int FallingSandFull();

public:
  AocDay14();
  ~AocDay14() override;
};

#endif
