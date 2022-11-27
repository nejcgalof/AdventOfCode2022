#include <CLI/CLI.hpp>
#include <fmt/core.h>
#include <internal_use_only/config.hpp>
#include <variant>

#include "aoc_day.hpp"
#include "aoc_days.hpp"

// NOLINTNEXTLINE(bugprone-exception-escape)
int main(int argc, const char **argv)
{
  fmt::print("{}\n", "Welcome to AdventOfCode2022");
  CLI::App app{ fmt::format("{} version {}", adventOfCode::cmake::project_name, adventOfCode::cmake::project_version) };

  int day = 0; // Start with 1
  app.add_option("-d,--day", day, "Select the day");
  int part = 0; // Start with 1
  app.add_option("-p,--part", part, "Select part");
  std::vector<std::variant<int, double, std::string>> arguments;
  app.add_option<std::vector<std::variant<int, double, std::string>>>(
    "-a,--arguments", arguments, "Add additional arguments for that day");

  CLI11_PARSE(app, argc, argv);

  AocDays days;

  if (day != 0 && part != 0) {
    auto aoc_day = days.GetDay(day);
    if (aoc_day == nullptr) {
      fmt::print("Solution from day {} not exist!\n", day);
      return 0;
    }
    if (part == 1) {
      aoc_day->Part1(arguments);
    } else if (part == 2) {
      aoc_day->Part2(arguments);
    } else {
      fmt::print("Wrong part number!\n");
    }
  } else {
    fmt::print("Missing arguments (day and part)!\n");
  }
  return 0;
}
