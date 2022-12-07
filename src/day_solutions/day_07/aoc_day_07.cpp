#include "day_07/aoc_day_07.hpp"

#include <algorithm>
#include <fstream>
#include <map>
#include <numeric>
#include <vector>

AocDay07::AocDay07() : AocDay(7) {}

AocDay07::~AocDay07() = default;

int AocDay07::FindSmallestDirToFree()
{
  if (fileStructure.empty()) { return 0; }
  int all_dir_size = std::accumulate(
    fileStructure.at("/").begin(), fileStructure.at("/").end(), 0, [](auto sum, auto dir) { return sum + dir.second; });
  int smallest_dir_size = all_dir_size;
  for (const auto &[directory, subdirectories] : fileStructure) {
    int current_dir_size = std::accumulate(
      fileStructure.at(directory).begin(), fileStructure.at(directory).end(), 0, [](auto sum, auto dir) {
        return sum + dir.second;
      });
    if ((30000000 - (70000000 - all_dir_size)) < current_dir_size && current_dir_size < smallest_dir_size) {
      smallest_dir_size = current_dir_size;
    }
  }
  return smallest_dir_size;
}

int AocDay07::SumOfSmallDirs(int limitSize) const
{
  int sum_small_directories = 0;
  for (const auto &[directory, subdirectories] : fileStructure) {
    const auto sum_subdirectories = std::accumulate(
      subdirectories.begin(), subdirectories.end(), 0, [](auto sum, auto dir) { return sum + dir.second; });
    sum_small_directories += (sum_subdirectories < limitSize) ? sum_subdirectories : 0;
  }
  return sum_small_directories;
}

int AocDay07::CalculateCurrentFileStructure(const std::string &currentFile)
{
  return std::accumulate(
    fileStructure.at(currentFile).begin(), fileStructure.at(currentFile).end(), 0, [this](auto sum, auto &dir) {
      dir.second = (dir.second == -1) ? CalculateCurrentFileStructure(dir.first) : dir.second;
      return sum + dir.second;
    });
}

void AocDay07::CalculateDirSize()
{
  for (const auto &[directory, subdirectories] : fileStructure) { CalculateCurrentFileStructure(directory); }
}

void AocDay07::GenerateFileStructureFromReadedTerminal(const std::string &file)
{
  fileStructure.clear();
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    std::string current_path;
    while (std::getline(file_stream, line)) {
      if (line.at(0) == '$') {
        line = line.substr(2, line.length());
        if (line.substr(0, 2) == "cd") {
          const size_t pos = line.find(' ');
          auto current_dir_name = line.substr(pos + 1);
          if (current_dir_name == "/") {
            current_path = "/";
          } else if (current_dir_name == "..") {
            current_path = current_path.substr(0, current_path.find_last_of('/'));
          } else {
            current_path += "/" + current_dir_name;
          }
        }
      } else {
        if (line.substr(0, 3) == "dir") {
          const size_t pos = line.find(' ');
          fileStructure[current_path].emplace_back(std::make_pair(current_path + "/" + line.substr(pos + 1), -1));
        } else {
          const size_t pos = line.find(' ');
          fileStructure[current_path].emplace_back(
            std::make_pair(line.substr(pos + 1), std::stoi(line.substr(0, pos))));
        }
      }
    }
    file_stream.close();
  }
}

std::variant<int, double, std::string> AocDay07::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  GenerateFileStructureFromReadedTerminal(file);
  CalculateDirSize();
  return SumOfSmallDirs(100000);
}

std::variant<int, double, std::string> AocDay07::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  GenerateFileStructureFromReadedTerminal(file);
  CalculateDirSize();
  return FindSmallestDirToFree();
}
