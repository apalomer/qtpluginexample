

# Create library
QT4_WRAP_CPP(clock_moc clock.h)
add_library(clock SHARED clock.cpp ${clock_moc})
target_link_libraries(clock ${QT_LIBRARIES} analogclock digitalclock)

# the name of the plugin module is the same name as used in the macro Q_EXPORT_PLUGIN2 in the file mywidgetdesignerfactory.cpp
QT4_WRAP_CPP(clockplugin_moc clockplugin.h)
add_library( clockplugin SHARED clockplugin.cpp ${clockplugin_moc})
target_link_libraries( clockplugin
  clock
  ${QT_LIBRARIES}
)
install(TARGETS clockplugin DESTINATION ${INSTALL_QTPLUGINS_DIR})

#if this is done befor the previous command the header files ar copied to qt pluguins as well
set_target_properties(clock PROPERTIES
  PUBLIC_HEADER "clock.h;../analogclock/analogclock.h;../digitalclock/digitalclock.h")

install(TARGETS clock
  # IMPORTANT: Add clock foo library to the "export-set"
  EXPORT ClockTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/clock" COMPONENT dev)
