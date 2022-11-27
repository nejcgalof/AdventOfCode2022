#ifndef ADVENTOFCODE_AOC_DAY_HPP
#define ADVENTOFCODE_AOC_DAY_HPP

#include <string>
#include <vector>

class AocDay
{
protected:
  int day;

public:
  explicit AocDay(int inputDay);
  virtual ~AocDay();
  virtual std::string Part1([[maybe_unused]] const std::string &filename,
    [[maybe_unused]] const std::vector<std::string> &extraArgs);
  virtual std::string Part2([[maybe_unused]] const std::string &filename,
    [[maybe_unused]] const std::vector<std::string> &extraArgs);
};

#endif
