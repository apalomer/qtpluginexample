
cmake_minimum_required (VERSION 2.6)
project (ClockDay CXX C)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Clock REQUIRED)
include_directories(${Clock_INCLUDE_DIRS})

# Use the widget
add_executable(main src/main.cpp)
target_link_libraries(main ${Clock_LIBRARIES})
