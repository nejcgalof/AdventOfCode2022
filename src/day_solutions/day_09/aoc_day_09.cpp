#include "day_09/aoc_day_09.hpp"

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iterator>
#include <memory>
#include <vector>

AocDay09::AocDay09() : AocDay(9) {}

AocDay09::~AocDay09() = default;

void AocDay09::MoveKnot(pos &currentKnot, const pos &previousKnot)
{
  if ((currentKnot.x - previousKnot.x) == 2) {
    if (currentKnot.y > previousKnot.y) {
      currentKnot.y--;
    } else if (currentKnot.y < previousKnot.y) {
      currentKnot.y++;
    }
    currentKnot.x--;
  } else if ((currentKnot.x - previousKnot.x) == -2) {
    if (currentKnot.y > previousKnot.y) {
      currentKnot.y--;
    } else if (currentKnot.y < previousKnot.y) {
      currentKnot.y++;
    }
    currentKnot.x++;
  }
  if ((currentKnot.y - previousKnot.y) == 2) {
    if (currentKnot.x > previousKnot.x) {
      currentKnot.x--;
    } else if (currentKnot.x < previousKnot.x) {
      currentKnot.x++;
    }
    currentKnot.y--;
  } else if ((currentKnot.y - previousKnot.y) == -2) {
    if (currentKnot.x > previousKnot.x) {
      currentKnot.x--;
    } else if (currentKnot.x < previousKnot.x) {
      currentKnot.x++;
    }
    currentKnot.y++;
  }
}

void AocDay09::MoveKnots(const std::string &direction)
{
  for (size_t i = 0; i < knots.size(); i++) {
    if (i == 0) {
      MoveHeadByDirection(direction);
      continue;
    }
    MoveKnot(knots.at(i), knots.at(i - 1));
    if (i + 1 == knots.size()) { SaveTailPosition(knots.at(i)); }
  }
}

void AocDay09::MoveHeadByDirection(const std::string &direction)
{
  if (direction == "U") {
    knots.at(0).y++;
  } else if (direction == "D") {
    knots.at(0).y--;
  } else if (direction == "R") {
    knots.at(0).x++;
  } else if (direction == "L") {
    knots.at(0).x--;
  }
}

void AocDay09::SaveTailPosition(const pos &tailKnot) { uniquePositions.emplace(tailKnot.x, tailKnot.y); }

int AocDay09::ReadFileAndMoveKnotsAndReturnTailVisitPositions(const std::string &file, const size_t numKnots)
{
  uniquePositions.clear();
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    knots = std::vector<pos>(numKnots, { 0, 0 });

    while (std::getline(file_stream, line)) {
      const size_t pos_space = line.find(' ');
      const auto direction = line.substr(0, pos_space);
      const size_t moves = static_cast<size_t>(stoi(line.substr(pos_space + 1)));

      for (size_t move = 0; move < moves; move++) { MoveKnots(direction); }
    }
    file_stream.close();
  }
  return static_cast<int>(uniquePositions.size());
}

std::variant<int, double, std::string> AocDay09::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return ReadFileAndMoveKnotsAndReturnTailVisitPositions(file, 2);
}

std::variant<int, double, std::string> AocDay09::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return ReadFileAndMoveKnotsAndReturnTailVisitPositions(file, 10);
}
