
cmake_minimum_required (VERSION 2.6)
project (AnalogClock CXX C)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})

FIND_PACKAGE(Qt 4 REQUIRED)
set (QT_USE_QTDESIGNER TRUE)
set (QT_USE_QTGUI TRUE)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

# Create library
QT4_WRAP_CPP(analogclock_moc src/analogclock.h)
add_library(analogclock SHARED src/analogclock.cpp ${analogclock_moc})
target_link_libraries(analogclock ${QT_LIBRARIES})

# the name of the plugin module is the same name as used in the macro Q_EXPORT_PLUGIN2 in the file mywidgetdesignerfactory.cpp
QT4_WRAP_CPP(analogclockplugin_moc src/analogclockplugin.h)
add_library( analogclockplugin SHARED src/analogclockplugin.cpp ${analogclockplugin_moc})
target_link_libraries( analogclockplugin
  analogclock
  ${QT_LIBRARIES}
  # other needed libs
)
set_target_properties(analogclockplugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY designer)

# Create library
QT4_WRAP_CPP(digitalclock_moc src/digitalclock.h)
add_library(digitalclock SHARED src/digitalclock.cpp ${digitalclock_moc})
target_link_libraries(digitalclock ${QT_LIBRARIES})

# the name of the plugin module is the same name as used in the macro Q_EXPORT_PLUGIN2 in the file mywidgetdesignerfactory.cpp
QT4_WRAP_CPP(digitalclockplugin_moc src/digitalclockplugin.h)
add_library( digitalclockplugin SHARED src/digitalclockplugin.cpp ${digitalclockplugin_moc})
target_link_libraries( digitalclockplugin
  digitalclock
  ${QT_LIBRARIES}
  # other needed libs
)
set_target_properties(digitalclockplugin PROPERTIES LIBRARY_OUTPUT_DIRECTORY designer)

# Use the widget
add_executable(main src/main.cpp)
target_link_libraries(main ${QT_LIBRARYES} analogclock digitalclock)

#
get_target_property(analogclock_output analogclockplugin LIBRARY_OUTPUT_DIRECTORY)
message(STATUS "To load the plugins into desinger-qt4 set QT_PLUGIN_PATH=$QT_PLUGIN_PATH:${CMAKE_CURRENT_BINARY_DIR}/${analogclock_output}")
