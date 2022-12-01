#include <map>

#include "aoc_days.hpp"

// includes for each day will go here
#include "demo/aoc_day_demo.hpp"

#include "day_01/aoc_day_01.hpp"

class AocDay;

AocDays::AocDays()
{
  // adding each member to the map goes here
  days[-1] = std::make_shared<AocDayDemo>();
  days[1] = std::make_shared<AocDay01>();
}

std::shared_ptr<AocDay> AocDays::GetDay(int day) { return days[day]; }
