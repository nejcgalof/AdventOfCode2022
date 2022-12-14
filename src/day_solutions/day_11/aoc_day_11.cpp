#include "day_11/aoc_day_11.hpp"

#include <algorithm>
#include <fstream>
#include <functional>
#include <iterator>
#include <memory>
#include <numeric>
#include <sstream>

AocDay11::AocDay11() : AocDay(11), devideNumber(3) {}

AocDay11::~AocDay11() = default;

void AocDay11::ParseLine(Monkey &monkey, std::string &line)
{
  const size_t pos_start = line.find(':');
  auto first_half = line.substr(0, pos_start);
  auto second_half = line.substr(pos_start + 2);
  if (first_half == "  Starting items") {
    second_half.erase(std::remove(second_half.begin(), second_half.end(), ','), second_half.end());
    std::stringstream stream_items(second_half);
    std::string item;
    while (std::getline(stream_items, item, ' ')) { monkey.items.emplace_back(std::stol(item)); }
  } else if (first_half == "  Operation") {
    monkey.operation = { second_half.substr(10, 1), second_half.substr(12) }; // new = old (this) (this)
  } else if (first_half == "  Test") {
    monkey.divisible = std::stoul(second_half.substr(13)); // divisible by (this)
  } else if (first_half == "    If true") {
    monkey.throwDivisibleTrue = std::stoi(second_half.substr(16));
  } else if (first_half == "    If false") {
    monkey.throwDivisibleFalse = std::stoi(second_half.substr(16));
  }
}

void AocDay11::PlayRounds(size_t rounds)
{
  for (size_t round = 0; round < rounds; round++) {
    for (auto &monkey : monkeys) { MonkeyMove(monkey); }
  }
}

void AocDay11::MonkeyMove(Monkey &monkey)
{
  for (auto &item : monkey.items) {
    monkeysInspectedItemsCounter.at(static_cast<size_t>(monkey.id))++;
    if (std::get<0>(monkey.operation) == "+") {
      item += (std::get<1>(monkey.operation) == "old") ? item : std::stoul(std::get<1>(monkey.operation));
    } else if (std::get<0>(monkey.operation) == "-") {
      item -= (std::get<1>(monkey.operation) == "old") ? item : std::stoul(std::get<1>(monkey.operation));
    } else if (std::get<0>(monkey.operation) == "*") {
      item *= (std::get<1>(monkey.operation) == "old") ? item : std::stoul(std::get<1>(monkey.operation));
    } else if (std::get<0>(monkey.operation) == "/") {
      item /= (std::get<1>(monkey.operation) == "old") ? item : std::stoul(std::get<1>(monkey.operation));
    }

    if (devideNumber == 3) {
      item /= devideNumber;
    } else {
      item %= devideNumber;
    }

    if (item % monkey.divisible == 0) {
      monkeys.at(static_cast<size_t>(monkey.throwDivisibleTrue)).items.emplace_back(item);
    } else {
      monkeys.at(static_cast<size_t>(monkey.throwDivisibleFalse)).items.emplace_back(item);
    }
  }
  monkey.items.clear();
}

unsigned long AocDay11::CalculateLcmOnDivisibles()
{
  std::vector<unsigned long> all_divisibles;
  std::transform(monkeys.begin(), monkeys.end(), std::back_inserter(all_divisibles), [](const auto &monkey) {
    return monkey.divisible;
  });
  return std::accumulate(
    all_divisibles.begin(), all_divisibles.end(), 1UL, [](auto first, auto second) { return std::lcm(first, second); });
}

double AocDay11::MonkeyInTheMiddle(const std::string &file, bool modeFix, size_t rounds)
{
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    std::string line;
    while (std::getline(file_stream, line)) {
      if (line.rfind("Monkey", 0) == 0) {
        Monkey monkey;
        monkey.id = stoi(line.substr(line.find(' ') + 1));
        monkeysInspectedItemsCounter.emplace_back(0);

        while (std::getline(file_stream, line)) {
          if (line.empty()) { break; }
          ParseLine(monkey, line);
        }
        monkeys.emplace_back(monkey);
      }
    }
    devideNumber = modeFix ? 3 : CalculateLcmOnDivisibles();
    PlayRounds(rounds);
    std::sort(monkeysInspectedItemsCounter.begin(), monkeysInspectedItemsCounter.end(), std::greater<>());
    return monkeysInspectedItemsCounter.at(0) * monkeysInspectedItemsCounter.at(1);
  }
  file_stream.close();
  return 0.0;
}

std::variant<int, double, std::string> AocDay11::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return MonkeyInTheMiddle(file, true, 20);
}

std::variant<int, double, std::string> AocDay11::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  return MonkeyInTheMiddle(file, false, 10000);
}
