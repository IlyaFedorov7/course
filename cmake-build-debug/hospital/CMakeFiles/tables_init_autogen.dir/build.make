# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lichk\source\repos\hospital

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lichk\source\repos\hospital\cmake-build-debug

# Utility rule file for tables_init_autogen.

# Include the progress variables for this target.
include hospital\CMakeFiles\tables_init_autogen.dir\progress.make

hospital\CMakeFiles\tables_init_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\lichk\source\repos\hospital\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target tables_init"
	cd C:\Users\lichk\source\repos\hospital\cmake-build-debug\hospital
	echo >nul && "C:\Program Files\JetBrains\CLion 2020.2.2\bin\cmake\win\bin\cmake.exe" -E cmake_autogen C:/Users/lichk/source/repos/hospital/cmake-build-debug/hospital/CMakeFiles/tables_init_autogen.dir/AutogenInfo.json Debug
	cd C:\Users\lichk\source\repos\hospital\cmake-build-debug

tables_init_autogen: hospital\CMakeFiles\tables_init_autogen
tables_init_autogen: hospital\CMakeFiles\tables_init_autogen.dir\build.make

.PHONY : tables_init_autogen

# Rule to build all files generated by this target.
hospital\CMakeFiles\tables_init_autogen.dir\build: tables_init_autogen

.PHONY : hospital\CMakeFiles\tables_init_autogen.dir\build

hospital\CMakeFiles\tables_init_autogen.dir\clean:
	cd C:\Users\lichk\source\repos\hospital\cmake-build-debug\hospital
	$(CMAKE_COMMAND) -P CMakeFiles\tables_init_autogen.dir\cmake_clean.cmake
	cd C:\Users\lichk\source\repos\hospital\cmake-build-debug
.PHONY : hospital\CMakeFiles\tables_init_autogen.dir\clean

hospital\CMakeFiles\tables_init_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\lichk\source\repos\hospital C:\Users\lichk\source\repos\hospital\hospital C:\Users\lichk\source\repos\hospital\cmake-build-debug C:\Users\lichk\source\repos\hospital\cmake-build-debug\hospital C:\Users\lichk\source\repos\hospital\cmake-build-debug\hospital\CMakeFiles\tables_init_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : hospital\CMakeFiles\tables_init_autogen.dir\depend

