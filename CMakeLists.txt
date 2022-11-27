cmake_minimum_required(VERSION 3.23)

# Not ideal to use this global variable, but necessary to make sure
# that tooling and projects use the same version
set(CMAKE_CXX_STANDARD 20)

# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

# Note: by default ENABLE_DEVELOPER_MODE is True
# This means that all analysis (sanitizers, static analysis)
# is enabled and all warnings are treated as errors
# if you want to switch this behavior, change TRUE to FALSE
set(ENABLE_DEVELOPER_MODE
    TRUE
    CACHE BOOL "Enable 'developer mode'")

# Change this to false if you want to disable warnings_as_errors in developer mode
set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

# Add project_options v0.24.0
# https://github.com/aminya/project_options
include(FetchContent)
FetchContent_Declare(_project_options URL https://github.com/aminya/project_options/archive/refs/tags/v0.26.1.zip)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)

# uncomment to enable vcpkg:
# install vcpkg dependencies: - should be called before defining project()
# run_vcpkg()

# Set the project name and language
project(
  AdventOfCode2022
  VERSION 0.0.1
  DESCRIPTION ""
  LANGUAGES CXX C)

# For easier find important files inside binary dir
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(PROJECT_IS_TOP_LEVEL)
  include(CTest)
endif()

execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  OUTPUT_VARIABLE GIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE)

include(${_project_options_SOURCE_DIR}/src/DynamicProjectOptions.cmake)

# defaulted_project_options sets recommended defaults and provides user and developer
# modes and full GUI support for choosing options at configure time

# for more flexibility, look into project_options() macro

# Any default can be overridden
# set(<feature_name>_DEFAULT <value>) - set default for both user and developer modes
# set(<feature_name>_DEVELOPER_DEFAULT <value>) - set default for developer mode
# set(<feature_name>_USER_DEFAULT <value>) - set default for user mode

# Initialize project_options variable related to this project
# This overwrites `project_options` and sets `project_warnings`
# uncomment the options to enable them:
set(PCH_HEADERS <vector> <string>)
# set(ENABLE_COVERAGE "ENABLE_COVERAGE")
# if(${ENABLE_COVERAGE})
#   set(COVERAGE_ARGS REPORTER xml)
# endif()

dynamic_project_options(
  # Note: PCH is disabled by default in developer mode because these headers become
  # globally included and they can mask other errors
  PCH_HEADERS
  ${PCH_HEADERS}
  ENABLE_CONAN
  # ENABLE_SANITIZER_ADDRESS
  # ENABLE_SANITIZER_UNDEFINED_BEHAVIOR
  # ENABLE_SANITIZER_THREAD
  # ENABLE_SANITIZER_MEMORY
  # ENABLE_INCLUDE_WHAT_YOU_USE
  # ENABLE_COVERAGE
  # ENABLE_BUILD_WITH_TIME_TRACE # Only Clang. Get info, where compiler spend most of the time. .json file located in Folder CMakeFiles, open with chrome://tracing/
  # ${ENABLE_COVERAGE}
  # ENABLE_DOXYGEN
  # DOXYGEN_THEME
  # "${CMAKE_CURRENT_LIST_DIR}/css/my_custom_theme.css"
  # ENABLE_COVERAGE
  # CONAN_OPTIONS    # Extra options to pass to conan
  # MSVC_WARNINGS    # Override the defaults for the MSVC warnings
  # CLANG_WARNINGS   # Override the defaults for the CLANG warnings
  # GCC_WARNINGS     # Override the defaults for the GCC warnings
  CPPCHECK_OPTIONS # Unhelpful CppCheck warnings
  --enable=style,performance,warning,portability
  --inline-suppr
  # We cannot act on a bug/missing feature of cppcheck
  --suppress=cppcheckError
  --suppress=internalAstError
  # if a file does not have an internalAstError, we get an unmatchedSuppression error
  --suppress=unmatchedSuppression
  --suppress=passedByValue
  --suppress=syntaxError
  --inconclusive)

target_compile_features(project_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})
add_library(AdventOfCode2022::project_options INTERFACE IMPORTED)
add_library(AdventOfCode2022::project_warnings INTERFACE IMPORTED)

# Configure files based on CMake configuration options
add_subdirectory(configured_files)

# Adding the src:
add_subdirectory(src)

# Adding the tests:
option(ENABLE_TESTING "Enable the tests" ${PROJECT_IS_TOP_LEVEL})
if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test) #TODO
endif()
