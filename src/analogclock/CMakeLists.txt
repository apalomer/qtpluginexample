

# Create library
QT4_WRAP_CPP(analogclock_moc analogclock.h)
add_library(analogclock SHARED analogclock.cpp ${analogclock_moc})
target_link_libraries(analogclock ${QT_LIBRARIES})

# the name of the plugin module is the same name as used in the macro Q_EXPORT_PLUGIN2 in the file mywidgetdesignerfactory.cpp
QT4_WRAP_CPP(analogclockplugin_moc analogclockplugin.h)
add_library( analogclockplugin SHARED analogclockplugin.cpp ${analogclockplugin_moc})
target_link_libraries( analogclockplugin
  analogclock
  ${QT_LIBRARIES}
)
install(TARGETS analogclock analogclockplugin DESTINATION ${INSTALL_QTPLUGINS_DIR})

#if this is done befor the previous command the header files ar copied to qt pluguins as well
set_target_properties(analogclock PROPERTIES
  PUBLIC_HEADER "analogclock.h")

install(TARGETS analogclock
  # IMPORTANT: Add analogclock foo library to the "export-set"
  EXPORT ClockTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/analogclock" COMPONENT dev)


