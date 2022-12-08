#include "day_06/aoc_day_06.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

AocDay06::AocDay06() : AocDay(6) {}

AocDay06::~AocDay06() = default;

bool AocDay06::IsStringContainsUniqueCharacters(std::string inputString)
{
  std::sort(inputString.begin(), inputString.end());
  for (size_t i = 0; i < inputString.length() - 1; i++) {
    if (inputString[i] == inputString[i + 1]) { return true; }
  }
  return false;
}

int AocDay06::TuningTrouble(const std::string &file, size_t startOfMsgMarker)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string datastream_buffer((std::istreambuf_iterator<char>(file_stream)), std::istreambuf_iterator<char>());

    for (size_t i = 0; i < datastream_buffer.size(); i++) {
      if (!IsStringContainsUniqueCharacters(datastream_buffer.substr(i, startOfMsgMarker))) {
        return static_cast<int>(i + startOfMsgMarker);
      }
    }
    file_stream.close();
  }
  return 0;
}

std::variant<int, double, std::string> AocDay06::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return TuningTrouble(file, 4);
}

std::variant<int, double, std::string> AocDay06::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return TuningTrouble(file, 14);
}
