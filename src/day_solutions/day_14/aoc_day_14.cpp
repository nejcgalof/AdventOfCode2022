#include "day_14/aoc_day_14.hpp"

#include <algorithm>
#include <cstddef>
#include <ext/alloc_traits.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>

AocDay14::AocDay14() : AocDay(14) {}

AocDay14::~AocDay14() = default;

void AocDay14::UpdateMaxY(const Block &block) { maxY = std::max(maxY, block.y); }

void AocDay14::CreateBlocksBetweenX(const Block &from, const Block &target)
{
  if (from.x < target.x) {
    for (auto path_move = from.x; path_move < target.x; path_move++) {
      Block intermediate_block;
      intermediate_block.x = path_move;
      intermediate_block.y = target.y;
      solidMaterialsMap[intermediate_block.x][intermediate_block.y] = intermediate_block;
    }
  } else {
    for (auto path_move = from.x; path_move > target.x; path_move--) {
      Block intermediate_block;
      intermediate_block.x = path_move;
      intermediate_block.y = target.y;
      solidMaterialsMap[intermediate_block.x][intermediate_block.y] = intermediate_block;
    }
  }
}

void AocDay14::CreateBlocksBetweenY(const Block &from, const Block &target)
{
  if (from.y < target.y) {
    for (auto path_move = from.y; path_move < target.y; path_move++) {
      Block intermediate_block;
      intermediate_block.y = path_move;
      intermediate_block.x = target.x;
      solidMaterialsMap[intermediate_block.x][intermediate_block.y] = intermediate_block;
    }
  } else {
    for (auto path_move = from.y; path_move > target.y; path_move--) {
      Block intermediate_block;
      intermediate_block.y = path_move;
      intermediate_block.x = target.x;
      solidMaterialsMap[intermediate_block.x][intermediate_block.y] = intermediate_block;
    }
  }
}

void AocDay14::GenerateRockPathFromBlocks(std::vector<Block> blocksFromRock)
{
  for (size_t iter = 1; iter < blocksFromRock.size(); iter++) {
    if (blocksFromRock.at(iter - 1).x != blocksFromRock.at(iter).x) {
      CreateBlocksBetweenX(blocksFromRock.at(iter - 1), blocksFromRock.at(iter));
    } else {
      CreateBlocksBetweenY(blocksFromRock.at(iter - 1), blocksFromRock.at(iter));
    }
  }
  const Block end_block = blocksFromRock.at(blocksFromRock.size() - 1);
  solidMaterialsMap[end_block.x][end_block.y] = end_block;
}

AocDay14::Block AocDay14::GetBlockFromString(const std::string &blockString)
{
  const auto pos = blockString.find(',');
  Block block;
  block.x = std::stoi(blockString.substr(0, pos));
  block.y = std::stoi(blockString.substr(pos + 1));
  UpdateMaxY(block); // I know this is the corner (limit) blocks - one of them have maxY
  return block;
}

void AocDay14::ReadBlocksFromFile(const std::string &file)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      std::vector<Block> blocks_from_rock;
      const std::string delimiter = " -> ";
      size_t pos = 0;
      std::string token;
      while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        blocks_from_rock.emplace_back(GetBlockFromString(token));
        line.erase(0, pos + delimiter.length());
      }
      blocks_from_rock.emplace_back(GetBlockFromString(line));
      GenerateRockPathFromBlocks(blocks_from_rock);
    }
    file_stream.close();
  }
}

int AocDay14::FallingSand()
{
  int num_sand = 0;
  if (solidMaterialsMap.empty()) { return num_sand; }
  Block sand;
  sand.x = 500;
  sand.y = 0;
  while (sand.y <= maxY) {
    if (!(solidMaterialsMap.find(sand.x) != solidMaterialsMap.end()
          && solidMaterialsMap[sand.x].find(sand.y + 1) != solidMaterialsMap[sand.x].end())) {
      sand.y += 1;
      continue;
    }
    if (!(solidMaterialsMap.find(sand.x - 1) != solidMaterialsMap.end()
          && solidMaterialsMap[sand.x - 1].find(sand.y + 1) != solidMaterialsMap[sand.x - 1].end())) {
      sand.y += 1;
      sand.x -= 1;
      continue;
    }
    if (!(solidMaterialsMap.find(sand.x + 1) != solidMaterialsMap.end()
          && solidMaterialsMap[sand.x + 1].find(sand.y + 1) != solidMaterialsMap[sand.x + 1].end())) {
      sand.y += 1;
      sand.x += 1;
      continue;
    }
    solidMaterialsMap[sand.x][sand.y] = sand;
    sand.x = 500;
    sand.y = 0;
    num_sand++;
  }
  return num_sand;
}

int AocDay14::FallingSandFull()
{
  int num_sand = 0;
  if (solidMaterialsMap.empty()) { return num_sand; }
  Block sand;
  sand.x = 500;
  sand.y = 0;
  while (true) {
    if (sand.y + 1 == maxY) {
      solidMaterialsMap[sand.x][sand.y] = sand;
      sand.x = 500;
      sand.y = 0;
      num_sand++;
      continue;
    }
    if (!(solidMaterialsMap.find(sand.x) != solidMaterialsMap.end()
          && solidMaterialsMap[sand.x].find(sand.y + 1) != solidMaterialsMap[sand.x].end())) {
      sand.y += 1;
      continue;
    }
    if (!(solidMaterialsMap.find(sand.x - 1) != solidMaterialsMap.end()
          && solidMaterialsMap[sand.x - 1].find(sand.y + 1) != solidMaterialsMap[sand.x - 1].end())) {
      sand.y += 1;
      sand.x -= 1;
      continue;
    }
    if (!(solidMaterialsMap.find(sand.x + 1) != solidMaterialsMap.end()
          && solidMaterialsMap[sand.x + 1].find(sand.y + 1) != solidMaterialsMap[sand.x + 1].end())) {
      sand.y += 1;
      sand.x += 1;
      continue;
    }
    if (sand.x == 500 && sand.y == 0) { return num_sand + 1; }
    solidMaterialsMap[sand.x][sand.y] = sand;
    sand.x = 500;
    sand.y = 0;
    num_sand++;
  }
  return num_sand;
}

std::variant<int, double, std::string> AocDay14::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadBlocksFromFile(file);
  return FallingSand();
}

std::variant<int, double, std::string> AocDay14::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  ReadBlocksFromFile(file);
  maxY += 2;
  return FallingSandFull();
}
