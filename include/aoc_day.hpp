#ifndef ADVENTOFCODE_AOC_DAY_HPP
#define ADVENTOFCODE_AOC_DAY_HPP

#include <map>
#include <string>
#include <variant>
#include <vector>

class AocDay
{
protected:
  int day;

public:
  explicit AocDay(int inputDay);
  virtual ~AocDay();
  virtual std::variant<int, double, std::string> Part1(
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs);
  virtual std::variant<int, double, std::string> Part2(
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs);
};

#endif
