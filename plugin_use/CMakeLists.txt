
cmake_minimum_required (VERSION 3.0)
project (ClockDay CXX C)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package(Clock REQUIRED)
include_directories(${Clock_INCLUDE_DIRS})

# Create library
add_library(clockday SHARED src/clockday.cpp src/clockday.ui)
target_link_libraries(clockday Qt5::Core Qt5::Widgets Qt5::Gui ${Clock_LIBRARIES})

# Use the widget
add_executable(main src/main.cpp)
target_link_libraries(main Qt5::Core Qt5::Widgets Qt5::Gui clockday)
