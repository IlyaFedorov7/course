cmake_minimum_required (VERSION 3.8)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(headers)
add_executable (test "source/hospital.cpp"  "source/main_window.cpp" "headers/main_window.h"  "source/editor.cpp"   "headers/ui_main_window.h" "headers/ui_shifts_modal.h" "headers/shifts_modal.h" "source/shifts_modal.cpp" "headers/ui_call_modal.h" "headers/call_modal.h" "source/call_modal.cpp"    "headers/ui_editor.h" "headers/editor.h")
set(CMAKE_PREFIX_PATH "../msvc2019_64/")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Gui Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Gui Sql REQUIRED)
target_link_libraries(test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Sql)
add_executable(tables_init "source/tables_init.cpp"  )
target_link_libraries(tables_init PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Sql)
