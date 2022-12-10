#include "day_10/aoc_day_10.hpp"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

AocDay10::AocDay10() : AocDay(9), registerValue(1), cycle(0), crtPos(1) {}

AocDay10::~AocDay10() = default;

void AocDay10::ExecuteCycle(int &sumSignalStrength)
{
  cycle++;
  if (cycle % 20 == 0 && (cycle / 20) % 2 != 0) { sumSignalStrength += registerValue * cycle; }
}

void AocDay10::ExecuteCycle(std::string &crtScreen)
{
  int something = 0;
  ExecuteCycle(something);
  Draw(crtScreen);
}

void AocDay10::Draw(std::string &crtScreen)
{

  if (crtPos >= registerValue && crtPos <= registerValue + 2) {
    crtScreen += "#";
  } else {
    crtScreen += ".";
  }
  crtPos++;
  if (crtPos == 41) {
    crtScreen += "\n";
    crtPos = 1;
  }
}

std::variant<int, double, std::string> AocDay10::Part1([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  int sum_signal_strength = 0;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    registerValue = 1;
    cycle = 0;
    std::string line;
    while (std::getline(file_stream, line)) {
      if (line == "noop") {
        ExecuteCycle(sum_signal_strength);
      } else {
        const size_t pos_space = line.find(' ');
        const auto instruction = line.substr(0, pos_space);
        if (instruction == "addx") {
          ExecuteCycle(sum_signal_strength);
          ExecuteCycle(sum_signal_strength);
          registerValue += stoi(line.substr(pos_space + 1));
        }
      }
    }
    file_stream.close();
  }
  return sum_signal_strength;
}

std::variant<int, double, std::string> AocDay10::Part2([[maybe_unused]] const std::string &file,
  [[maybe_unused]] const std::vector<std::variant<int, double, std::string>> &extraArgs)
{
  std::string crt_screen;
  std::ifstream file_stream(file);
  if (file_stream.is_open()) {
    registerValue = 1;
    cycle = 0;
    std::string line;
    while (std::getline(file_stream, line)) {
      if (line == "noop") {
        ExecuteCycle(crt_screen);
      } else {
        const size_t pos_space = line.find(' ');
        const auto instruction = line.substr(0, pos_space);
        if (instruction == "addx") {
          ExecuteCycle(crt_screen);
          ExecuteCycle(crt_screen);
          registerValue += stoi(line.substr(pos_space + 1));
        }
      }
    }
    file_stream.close();
  }
  return crt_screen;
}
