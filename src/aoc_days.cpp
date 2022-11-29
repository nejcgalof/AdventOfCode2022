#include <map>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

// includes for each day will go here
#include "demo/aoc_day_demo.hpp"

AocDays::AocDays()
{
  // adding each member to the map goes here
  days[-1] = std::make_shared<AocDayDemo>();
}

std::shared_ptr<AocDay> AocDays::GetDay(int day) { return days[day]; }
