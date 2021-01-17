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

install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION $<TARGET_FILE_DIR:test>)
install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION $<TARGET_FILE_DIR:test>)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION $<TARGET_FILE_DIR:test>)
install(FILES $<TARGET_FILE:Qt5::Sql> DESTINATION $<TARGET_FILE_DIR:test>)

install(FILES $<TARGET_FILE:Qt5::QSQLiteDriverPlugin> DESTINATION $<TARGET_FILE_DIR:test>/sqldrivers)
install(FILES $<TARGET_FILE:Qt5::QWindowsIntegrationPlugin> DESTINATION $<TARGET_FILE_DIR:test>/platforms)
install(FILES $<TARGET_FILE:Qt5::QWindowsDirect2DIntegrationPlugin> DESTINATION $<TARGET_FILE_DIR:test>/platforms)
file(COPY ${PROJECT_SOURCE_DIR}/hospital/data.db DESTINATION ${CMAKE_BINARY_DIR}/hospital)
