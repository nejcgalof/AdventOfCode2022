#ifndef ADVENTOFCODE_AOC_DAY_11_HPP
#define ADVENTOFCODE_AOC_DAY_11_HPP

#include <stddef.h>
#include <string>
#include <tuple>
#include <variant>
#include <vector>

#include "aoc_day.hpp"

class AocDay11 : public AocDay
{
private:
  std::variant<int, double, std::string> Part1([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;
  std::variant<int, double, std::string> Part2([[maybe_unused]] const std::string &file,
    [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs) override;

  struct Monkey
  {
    int id;
    std::vector<unsigned long> items;
    int throwDivisibleTrue;
    int throwDivisibleFalse;
    unsigned long divisible;
    std::tuple<std::string, std::string> operation;
  };

  static void ParseLine(Monkey &monkey, std::string &line);
  void PlayRounds(size_t rounds);
  void MonkeyMove(Monkey &monkey);
  unsigned long CalculateLcmOnDivisibles();
  double MonkeyInTheMiddle(const std::string &file, bool modeFix, size_t rounds);

  std::vector<Monkey> monkeys;
  std::vector<double> monkeysInspectedItemsCounter;
  unsigned long devideNumber;

public:
  AocDay11();
  ~AocDay11() override;
};

#endif
