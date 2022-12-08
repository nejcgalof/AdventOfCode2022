#include <map>

#include "aoc_days.hpp"

// includes for each day will go here
#include "demo/aoc_day_demo.hpp"

#include "day_01/aoc_day_01.hpp"
#include "day_02/aoc_day_02.hpp"
#include "day_03/aoc_day_03.hpp"
#include "day_04/aoc_day_04.hpp"
#include "day_05/aoc_day_05.hpp"
#include "day_06/aoc_day_06.hpp"
#include "day_07/aoc_day_07.hpp"
#include "day_08/aoc_day_08.hpp"

class AocDay;

AocDays::AocDays()
{
  // Adding each member to the map goes here
  days[-1] = std::make_shared<AocDayDemo>();
  days[1] = std::make_shared<AocDay01>();
  days[2] = std::make_shared<AocDay02>();
  days[3] = std::make_shared<AocDay03>();
  days[4] = std::make_shared<AocDay04>();
  days[5] = std::make_shared<AocDay05>();
  days[6] = std::make_shared<AocDay06>();
  days[7] = std::make_shared<AocDay07>();
  days[8] = std::make_shared<AocDay08>();
}

std::shared_ptr<AocDay> AocDays::GetDay(int day) { return days[day]; }
