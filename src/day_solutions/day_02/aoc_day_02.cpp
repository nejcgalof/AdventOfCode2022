#include "day_02/aoc_day_02.hpp"

#include <cstddef>
#include <fstream>
#include <map>

AocDay02::AocDay02()
  : AocDay(2), kShapeScore({ { "X", 1 }, { "Y", 2 }, { "Z", 3 } }),
    kYourShapeValue({ { "X", 0 }, { "Y", 1 }, { "Z", 2 } }), kEnemyShapeValue({ { "A", 0 }, { "B", 1 }, { "C", 2 } }),
    kMatchScore({ /*Draw*/ { 0, 3 }, /*Win*/ { 1, 6 }, /*Lose*/ { 2, 0 } }),

    kLostHand({ { "A", "Z" }, { "B", "X" }, { "C", "Y" } }), kWinHand({ { "A", "Y" }, { "B", "Z" }, { "C", "X" } }),
    kDrawHand({ { "A", "X" }, { "B", "Y" }, { "C", "Z" } })
{}

AocDay02::~AocDay02() = default;

std::variant<int, double, std::string> AocDay02::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int score = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      size_t pos = line.find(' ');
      std::string enemy_hand = line.substr(0, pos);
      std::string your_hand = line.substr(pos + 1);
      // https://codereview.stackexchange.com/a/268733/59192
      score += kShapeScore.at(your_hand)
               + kMatchScore.at((kYourShapeValue.at(your_hand) - kEnemyShapeValue.at(enemy_hand) + 3) % 3);
    }
    file_stream.close();
  }
  return score;
}

std::variant<int, double, std::string> AocDay02::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int score = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      size_t pos = line.find(' ');
      std::string enemy_hand = line.substr(0, pos);
      std::string your_hand = line.substr(pos + 1);
      if (your_hand == "X") {
        your_hand = kLostHand.at(enemy_hand);
      } else if (your_hand == "Z") {
        your_hand = kWinHand.at(enemy_hand);
      } else {
        your_hand = kDrawHand.at(enemy_hand);
      }
      // https://codereview.stackexchange.com/a/268733/59192
      score += kShapeScore.at(your_hand)
               + kMatchScore.at((kYourShapeValue.at(your_hand) - kEnemyShapeValue.at(enemy_hand) + 3) % 3);
    }
    file_stream.close();
  }
  return score;
}
