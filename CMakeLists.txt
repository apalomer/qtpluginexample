
cmake_minimum_required (VERSION 2.6)
project (AnalogClock CXX C)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})

FIND_PACKAGE(Qt 4 REQUIRED)
set (QT_USE_QTDESIGNER TRUE)
set (QT_USE_QTGUI TRUE)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)
ADD_DEFINITIONS(-DQDESIGNER_EXPORT_WIDGETS)
ADD_DEFINITIONS(-DQT_SCRIPT_LIB)
ADD_DEFINITIONS(-DQT_XML_LIB)
ADD_DEFINITIONS(-DQT_GUI_LIB)
ADD_DEFINITIONS(-DQT_CORE_LIB)

set(PLUGIN_INSTALL_DIR /usr/lib/x86_64-linux-gnu/qt5/plugins/designer/)
set (includeDirs ${includeDirs}
    ${customwidgetplugin_SOURCE_DIR/src}
)
include_directories (${customwidgetplugin_SOURCE_DIR} ${includeDirs})


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

# Use the widget
add_executable(main src/main.cpp)
target_link_libraries(main ${QT_LIBRARYES} analogclock)

install( TARGETS analogclockplugin  DESTINATION ${PLUGIN_INSTALL_DIR} )
message(STATUS "PLUGIN_INSTALL_DIR: ${PLUGIN_INSTALL_DIR}")

