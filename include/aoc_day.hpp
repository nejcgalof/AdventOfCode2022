#ifndef ADVENTOFCODE_AOC_DAY_HPP
#define ADVENTOFCODE_AOC_DAY_HPP

#include <string>
#include <variant>
#include <vector>

class AocDay
{
private:
  int day;
  virtual std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs);
  virtual std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs);

public:
  explicit AocDay(int inputDay);
  virtual ~AocDay();
  std::variant<int, double, std::string> SolvePart(int part,
    [[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs);
};

#endif
