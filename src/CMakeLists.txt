add_library(demo SHARED lib.cpp)
target_link_libraries(demo project_options project_warnings)
target_include_directories(demo PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_BINARY_DIR}/configured_files/include")
