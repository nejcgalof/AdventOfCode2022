#include <map>

#include "aoc_days.hpp"

// includes for each day will go here
#include "demo/aoc_day_demo.hpp"

#include "day_01/aoc_day_01.hpp"
#include "day_02/aoc_day_02.hpp"
#include "day_03/aoc_day_03.hpp"

class AocDay;

AocDays::AocDays()
{
  // adding each member to the map goes here
  days[-1] = std::make_shared<AocDayDemo>();
  days[1] = std::make_shared<AocDay01>();
  days[2] = std::make_shared<AocDay02>();
  days[3] = std::make_shared<AocDay03>();
}

std::shared_ptr<AocDay> AocDays::GetDay(int day) { return days[day]; }
