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
target_link_libraries(catch_main PRIVATE DemoLibrary::project_options)

add_executable(tests tests.cpp)
target_link_libraries(
  tests
  PRIVATE DemoLibrary::project_warnings
          DemoLibrary::project_options
          catch_main
          demo)

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
