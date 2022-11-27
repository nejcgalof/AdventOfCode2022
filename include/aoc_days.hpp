#ifndef ADVENTOFCODE_AOC_DAYS_HPP
#define ADVENTOFCODE_AOC_DAYS_HPP

#include "aoc_day.hpp"
#include <map>

class AocDays
{
protected:
  std::map<int, AocDay *> days;

public:
  AocDays() = default;
  AocDay *GetDay(int day);
};

#endif
