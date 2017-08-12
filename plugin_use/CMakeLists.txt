
cmake_minimum_required (VERSION 2.6)
project (Clock CXX C)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt 4 REQUIRED)
set (QT_USE_QTDESIGNER TRUE)
set (QT_USE_QTGUI TRUE)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
include_directories("/home/apalomer/QtPluginExample/src")

# Create library
QT4_WRAP_CPP(clock_moc src/clock.h)
QT4_WRAP_UI(clock_ui ui/clock.ui)
add_library(clock SHARED src/clock.cpp ${clock_moc} ${clock_ui})
target_link_libraries(clock ${QT_LIBRARIES})

# Use the widget
add_executable(main src/main.cpp)
target_link_libraries(main ${QT_LIBRARYES} clock)
