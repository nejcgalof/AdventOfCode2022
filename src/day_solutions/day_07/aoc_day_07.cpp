#include "day_07/aoc_day_07.hpp"

#include <algorithm>
#include <fstream>
#include <map>
#include <numeric>
#include <vector>

AocDay07::AocDay07() : AocDay(7) {}

AocDay07::~AocDay07() = default;

int AocDay07::FindSmallestDirToFree(
  const std::map<const std::string, std::vector<std::pair<const std::string, int>>> &fileStructure)
{
  int all_dir_size = 0;
  std::for_each(fileStructure.at("/").begin(), fileStructure.at("/").end(), [&all_dir_size](const auto &p) {
    all_dir_size += p.second;
  });
  int smallest_dir_size = all_dir_size;
  for (auto const &[key, val] : fileStructure) {
    int current_dir_size = 0;
    std::for_each(fileStructure.at(key).begin(), fileStructure.at(key).end(), [&current_dir_size](const auto &p) {
      current_dir_size += p.second;
    });
    if ((30000000 - (70000000 - all_dir_size)) < current_dir_size && current_dir_size < smallest_dir_size) {
      smallest_dir_size = current_dir_size;
    }
  }
  return smallest_dir_size;
}

int AocDay07::CalculateCurrentFileStructure(
  std::map<const std::string, std::vector<std::pair<const std::string, int>>> &fileStructure,
  const std::string &currentFile)
{
  int sum_dir = 0;
  for (auto &[key2, val2] : fileStructure.at(currentFile)) {
    if (val2 == -1) {
      auto sum_of_subdir = CalculateCurrentFileStructure(fileStructure, key2);
      val2 = sum_of_subdir;
      sum_dir += sum_of_subdir;
    } else {
      sum_dir += val2;
    }
  }
  return sum_dir;
}

int AocDay07::CalculateFileStructure(
  std::map<const std::string, std::vector<std::pair<const std::string, int>>> &fileStructure)
{
  int sum_small_directories = 0;
  for (const auto &[key, val] : fileStructure) {
    auto sum = CalculateCurrentFileStructure(fileStructure, key);
    sum_small_directories += (sum < 100000) ? sum : 0;
  }
  return sum_small_directories;
}

std::variant<int, double, std::string> AocDay07::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int sum_small_directories = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    std::string current_path;
    std::map<const std::string, std::vector<std::pair<const std::string, int>>> file_structure;
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
          file_structure[current_path].emplace_back(std::make_pair(current_path + "/" + line.substr(pos + 1), -1));
        } else {
          const size_t pos = line.find(' ');
          file_structure[current_path].emplace_back(
            std::make_pair(line.substr(pos + 1), std::stoi(line.substr(0, pos))));
        }
      }
    }
    // PrintFileStructure(file_structure);
    sum_small_directories = CalculateFileStructure(file_structure);
    // PrintFileStructure(file_structure);
    file_stream.close();
  }
  return sum_small_directories;
}

std::variant<int, double, std::string> AocDay07::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int smallest_directory_size = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    std::string current_path;
    std::map<const std::string, std::vector<std::pair<const std::string, int>>> file_structure;
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
          file_structure[current_path].emplace_back(std::make_pair(current_path + "/" + line.substr(pos + 1), -1));
        } else {
          const size_t pos = line.find(' ');
          file_structure[current_path].emplace_back(
            std::make_pair(line.substr(pos + 1), std::stoi(line.substr(0, pos))));
        }
      }
    }
    CalculateFileStructure(file_structure);
    smallest_directory_size = FindSmallestDirToFree(file_structure);

    file_stream.close();
  }
  return smallest_directory_size;
}
