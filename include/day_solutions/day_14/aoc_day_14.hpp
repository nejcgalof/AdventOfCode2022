#ifndef ADVENTOFCODE_AOC_DAY_14_HPP
#define ADVENTOFCODE_AOC_DAY_14_HPP

#include <memory>
#include <stddef.h>
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
  std::vector<Block> solidMaterials;

  void PrintSolidMaterials() const;
  void CreateBlocksBetweenX(const Block &from, const Block &target);
  void CreateBlocksBetweenY(const Block &from, const Block &target);
  void GenerateRockPathFromBlocks(std::vector<Block> blocksFromRock);
  void UpdateMaxY(const Block &block);
  Block GetBlockFromString(const std::string &blockString);
  int ReadBlocksFromFile(const std::string &file);

public:
  AocDay14();
  ~AocDay14() override;
};

#endif
