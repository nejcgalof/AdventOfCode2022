#include <map>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

// includes for each day will go here
//#include "aoc_day_0.h"

/*AocDays::AocDays()
{
  // adding each member to the map goes here
  // m_days[0] = new AocDay0();
}*/

std::shared_ptr<AocDay> AocDays::GetDay(int day) { return days[day]; }
