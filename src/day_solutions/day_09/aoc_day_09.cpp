#include "day_09/aoc_day_09.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iterator>
#include <memory>
#include <vector>

AocDay09::AocDay09() : AocDay(9) {}

AocDay09::~AocDay09() = default;

void AocDay09::MoveTail(pos &tail, const pos &head)
{
  if ((tail.x - head.x) == 2) {
    if (tail.y > head.y) {
      tail.y--;
    } else if (tail.y < head.y) {
      tail.y++;
    }
    tail.x--;
  } else if ((tail.x - head.x) == -2) {
    if (tail.y > head.y) {
      tail.y--;
    } else if (tail.y < head.y) {
      tail.y++;
    }
    tail.x++;
  }
  if ((tail.y - head.y) == 2) {
    if (tail.x > head.x) {
      tail.x--;
    } else if (tail.x < head.x) {
      tail.x++;
    }
    tail.y--;
  } else if ((tail.y - head.y) == -2) {
    if (tail.x > head.x) {
      tail.x--;
    } else if (tail.x < head.x) {
      tail.x++;
    }
    tail.y++;
  }
  uniquePositions.emplace(tail.x, tail.y);
}

std::variant<int, double, std::string> AocDay09::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  uniquePositions.clear();
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    pos tail{ 0, 0 };
    pos head{ 0, 0 };

    while (std::getline(file_stream, line)) {
      const size_t pos_space = line.find(' ');
      const auto direction = line.substr(0, pos_space);
      const size_t moves = static_cast<size_t>(stoi(line.substr(pos_space + 1)));

      for (size_t move = 0; move < moves; move++) {
        if (direction == "U") {
          head.y++;
        } else if (direction == "D") {
          head.y--;
        } else if (direction == "R") {
          head.x++;
        } else if (direction == "L") {
          head.x--;
        }
        MoveTail(tail, head);
      }
    }
    file_stream.close();
  }
  return static_cast<int>(uniquePositions.size());
}

std::variant<int, double, std::string> AocDay09::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return 0;
}
