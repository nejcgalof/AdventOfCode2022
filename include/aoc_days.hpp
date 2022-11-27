#ifndef ADVENTOFCODE_AOC_DAYS_HPP
#define ADVENTOFCODE_AOC_DAYS_HPP

#include "aoc_day.hpp"
#include <map>
#include <memory>

class AocDays
{
protected:
  std::map<int, std::shared_ptr<AocDay>> days;

public:
  AocDays() = default;
  std::shared_ptr<AocDay> GetDay(int day);
};

#endif
