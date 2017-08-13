
# Library
add_subdirectory(analogclock)
add_subdirectory(digitalclock)
add_subdirectory(clock)

# Library version
configure_file(clockversion.h.in "${CMAKE_CURRENT_BINARY_DIR}/clockversion.h" @ONLY)

# Use the widget
add_executable(clockWindow main.cpp)
target_link_libraries(clockWindow ${QT_LIBRARYES} clock)
set_target_properties(clockWindow PROPERTIES
  PUBLIC_HEADER "clock/clock.h;${CMAKE_CURRENT_BINARY_DIR}/clockversion.h")

install(TARGETS clockWindow
  # IMPORTANT: Add the clock executable to the "export-set"
  EXPORT ClockTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}" COMPONENT dev)
