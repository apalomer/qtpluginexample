# Create library
QT4_WRAP_CPP(digitalclock_moc digitalclock.h)
add_library(digitalclock SHARED digitalclock.cpp ${digitalclock_moc})
target_link_libraries(digitalclock ${QT_LIBRARIES})
set(PROJECT_LIBS ${PROJECT_LIBS} digitalclock PARENT_SCOPE)

# the name of the plugin module is the same name as used in the macro Q_EXPORT_PLUGIN2 in the file mywidgetdesignerfactory.cpp
QT4_WRAP_CPP(digitalclockplugin_moc digitalclockplugin.h)
add_library( digitalclockplugin SHARED digitalclockplugin.cpp ${digitalclockplugin_moc})
target_link_libraries( digitalclockplugin
  digitalclock
  ${QT_LIBRARIES}
)
install(TARGETS digitalclockplugin DESTINATION ${INSTALL_QTPLUGINS_DIR})

#if this is done befor the previous command the header files ar copied to qt pluguins as well
set_target_properties(digitalclock PROPERTIES
  PUBLIC_HEADER "digitalclock.h")

install(TARGETS digitalclock
  # IMPORTANT: Add the digitalclock library to the "export-set"
  EXPORT ClockTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/digitalclock" COMPONENT dev)

