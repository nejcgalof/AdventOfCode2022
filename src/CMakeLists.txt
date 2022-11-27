find_package(fmt CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)

add_executable(AdventOfCode2022 main.cpp)

target_link_libraries(AdventOfCode2022 project_options project_warnings CLI11::CLI11 fmt::fmt)
target_include_directories(AdventOfCode2022 PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_BINARY_DIR}/configured_files/include")
