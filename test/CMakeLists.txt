cmake_minimum_required(VERSION 3.23)

project(Tests LANGUAGES CXX)

if(PROJECT_IS_TOP_LEVEL OR TEST_INSTALLED_VERSION)
  enable_testing()

  find_package(DemoProject CONFIG REQUIRED)

  if(NOT TARGET DemoProject::project_options)
    message(FATAL_ERROR "Requiered config package not found!")
    return()
  endif()
endif()

find_package(Catch2 CONFIG REQUIRED)
include(Catch)

add_library(catch_main OBJECT catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)
target_link_libraries(catch_main PRIVATE AdventOfCode2022::project_options)

file(GLOB_RECURSE ALL_SRC_DAYS "../src/day_solutions/*.cpp")
file(GLOB_RECURSE ALL_SRC_DAYS_TESTS "./day_solutions/*.cpp")
add_executable(
  tests
  aoc_day_tests.cpp
  ../src/aoc_day.cpp
  ../src/aoc_days.cpp
  ${ALL_SRC_DAYS}
  ${ALL_SRC_DAYS_TESTS})

target_link_libraries(tests PRIVATE AdventOfCode2022::project_warnings AdventOfCode2022::project_options catch_main)
target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/include/day_solutions"
                                        "${CMAKE_BINARY_DIR}/configured_files/include")

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests
  TEST_PREFIX
  "AdventOfCode2022tests."
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "AdventOfCode2022tests."
  OUTPUT_SUFFIX
  .xml)
