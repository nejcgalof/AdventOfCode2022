#ifndef ADVENTOFCODE_AOC_DAYS_HPP
#define ADVENTOFCODE_AOC_DAYS_HPP

#include <map>
#include <memory>

class AocDay;

class AocDays
{
protected:
  std::map<int, std::shared_ptr<AocDay>> days;

public:
  AocDays();
  std::shared_ptr<AocDay> GetDay(int day);
};

#endif
