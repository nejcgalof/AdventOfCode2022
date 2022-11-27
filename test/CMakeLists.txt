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
find_package(fmt CONFIG REQUIRED)
include(Catch)

add_library(catch_main OBJECT catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)
target_link_libraries(catch_main PRIVATE AdventOfCode2022::project_options)

file(GLOB_RECURSE ALL_SRC_DAYS "../src/day_solutions/*.cpp")
add_executable(
  tests
  tests.cpp
  ../src/aoc_day.cpp
  ../src/aoc_days.cpp
  ${ALL_SRC_DAYS})

target_link_libraries(
  tests
  PRIVATE AdventOfCode2022::project_warnings
          AdventOfCode2022::project_options
          catch_main
          fmt::fmt)
target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/include/day_solutions"
                                        "${CMAKE_BINARY_DIR}/configured_files/include")

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests
  TEST_PREFIX
  "unittests."
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "unittests."
  OUTPUT_SUFFIX
  .xml)
