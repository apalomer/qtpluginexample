

# Create library
QT4_WRAP_CPP(abstractclock_moc abstractclock.h)
add_library(abstractclock SHARED abstractclock.cpp ${abstractclock_moc})
target_link_libraries(abstractclock ${QT_LIBRARIES})
set(PROJECT_LIBS ${PROJECT_LIBS} abstractclock PARENT_SCOPE)

#if this is done befor the previous command the header files ar copied to qt pluguins as well
set_target_properties(abstractclock PROPERTIES
  PUBLIC_HEADER "abstractclock.h")

install(TARGETS abstractclock
  # IMPORTANT: Add abstractclock foo library to the "export-set"
  EXPORT ClockTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/abstractclock" COMPONENT dev)
