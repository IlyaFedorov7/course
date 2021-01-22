cmake_minimum_required (VERSION 3.8)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(headers)
add_executable (test "source/hospital.cpp"  "source/main_window.cpp" "headers/main_window.h"  "source/editor.cpp" "headers/ui_shifts_modal.h" "headers/shifts_modal.h" "source/shifts_modal.cpp" "headers/ui_call_modal.h" "headers/call_modal.h" "source/call_modal.cpp"    "headers/ui_editor.h" "headers/editor.h")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Gui Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Gui Sql REQUIRED)
target_link_libraries(test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Sql)
#add_executable(tables_init "source/tables_init.cpp"  )
#target_link_libraries(tables_init PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Sql)

install(TARGETS test DESTINATION bin)

install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION bin)
install(FILES $<TARGET_FILE:Qt5::Sql> DESTINATION bin)

install(FILES $<TARGET_FILE:Qt5::QSQLiteDriverPlugin> DESTINATION bin/sqldrivers)
install(FILES $<TARGET_FILE:Qt5::QWindowsIntegrationPlugin> DESTINATION bin/platforms)
install(FILES $<TARGET_FILE:Qt5::QWindowsDirect2DIntegrationPlugin> DESTINATION bin/platforms)
install(FILES ${PROJECT_SOURCE_DIR}/hospital/data.db DESTINATION bin)
