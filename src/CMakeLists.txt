
# Library
add_subdirectory(abstractclock)
add_subdirectory(clock)
add_subdirectory(analogclock)
add_subdirectory(digitalclock)

# Library version
configure_file(clockversion.h.in "${CMAKE_CURRENT_BINARY_DIR}/clockversion.h" @ONLY)

# Test
add_library(testclocklib SHARED testclocklib.cpp)
target_link_libraries(testclocklib ${QT_LIBRARIES} clock)
set_target_properties(testclocklib PROPERTIES
  PUBLIC_HEADER "testclocklib.h;clock/clock.h;${CMAKE_CURRENT_BINARY_DIR}/clockversion.h")
set(PROJECT_LIBS ${PROJECT_LIBS} testclocklib PARENT_SCOPE)

# Use the widget
add_executable(clockWindow main.cpp)
target_link_libraries(clockWindow ${QT_LIBRARYES} clock)
set_target_properties(clockWindow PROPERTIES
  PUBLIC_HEADER "clock/clock.h;${CMAKE_CURRENT_BINARY_DIR}/clockversion.h")
set(PROJECT_BINS ${PROJECT_BINS} clockWindow PARENT_SCOPE)

install(TARGETS clockWindow testclocklib
  # IMPORTANT: Add the clock executable to the "export-set"
  EXPORT ClockTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}" COMPONENT dev)
