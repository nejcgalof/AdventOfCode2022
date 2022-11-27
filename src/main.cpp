#include <CLI/CLI.hpp>
#include <fmt/core.h>
#include <internal_use_only/config.hpp>
#include <optional>
#include <sstream>
#include <string_view>

// NOLINTNEXTLINE(bugprone-exception-escape)
int main(int argc, const char **argv)
{
  fmt::print("{}\n", "Welcome to AdventOfCode2022");
  CLI::App app{ fmt::format("{} version {}", adventOfCode::cmake::project_name, adventOfCode::cmake::project_version) };

  int day = 0; // Start with 1
  app.add_option("-d,--day", day, "Select the day");
  int part = 0; // Start with 1
  app.add_option("-p,--part", part, "Select part");
  bool show_version = false;
  app.add_flag("--version", show_version, "Show version information");

  CLI11_PARSE(app, argc, argv);

  if (show_version) {
    fmt::print("{}\n", adventOfCode::cmake::project_version);
  } else if (day != 0 && part != 0) {
    // Call right day and part
  } else {
    fmt::print("Missing arguments (day and part)!\n");
  }
  return 0;
}
