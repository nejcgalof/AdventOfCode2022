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
#include "day_09/aoc_day_09.hpp"
#include "day_10/aoc_day_10.hpp"
#include "day_11/aoc_day_11.hpp"
#include "day_12/aoc_day_12.hpp"
#include "day_13/aoc_day_13.hpp"
#include "day_14/aoc_day_14.hpp"

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
  days[9] = std::make_shared<AocDay09>();
  days[10] = std::make_shared<AocDay10>();
  days[11] = std::make_shared<AocDay11>();
  days[12] = std::make_shared<AocDay12>();
  days[13] = std::make_shared<AocDay13>();
  days[14] = std::make_shared<AocDay14>();
}

std::shared_ptr<AocDay> AocDays::GetDay(int day) { return days[day]; }
