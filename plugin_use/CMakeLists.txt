
cmake_minimum_required (VERSION 2.6)
project (ClockDay CXX C)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt 4 REQUIRED)
set (QT_USE_QTDESIGNER TRUE)
set (QT_USE_QTGUI TRUE)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

find_package(Clock REQUIRED)
include_directories(${Clock_INCLUDE_DIRS})

# Create library
QT4_WRAP_CPP(clockday_moc src/clockday.h)
QT4_WRAP_UI(clockday_ui ui/clockday.ui)
add_library(clockday SHARED src/clockday.cpp ${clockday_moc} ${clockday_ui})
target_link_libraries(clockday ${QT_LIBRARIES} ${Clock_LIBRARIES})

# Use the widget
add_executable(main src/main.cpp)
target_link_libraries(main ${QT_LIBRARYES} clockday)
