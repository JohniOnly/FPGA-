# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/johni/GitControl/yrr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/johni/GitControl/yrr/build

# Include any dependencies generated for this target.
include CMakeFiles/Scaler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Scaler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Scaler.dir/flags.make

CMakeFiles/Scaler.dir/main.c.o: CMakeFiles/Scaler.dir/flags.make
CMakeFiles/Scaler.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johni/GitControl/yrr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Scaler.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Scaler.dir/main.c.o   -c /home/johni/GitControl/yrr/main.c

CMakeFiles/Scaler.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Scaler.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/johni/GitControl/yrr/main.c > CMakeFiles/Scaler.dir/main.c.i

CMakeFiles/Scaler.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Scaler.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/johni/GitControl/yrr/main.c -o CMakeFiles/Scaler.dir/main.c.s

CMakeFiles/Scaler.dir/src/bicubic.c.o: CMakeFiles/Scaler.dir/flags.make
CMakeFiles/Scaler.dir/src/bicubic.c.o: ../src/bicubic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johni/GitControl/yrr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Scaler.dir/src/bicubic.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Scaler.dir/src/bicubic.c.o   -c /home/johni/GitControl/yrr/src/bicubic.c

CMakeFiles/Scaler.dir/src/bicubic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Scaler.dir/src/bicubic.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/johni/GitControl/yrr/src/bicubic.c > CMakeFiles/Scaler.dir/src/bicubic.c.i

CMakeFiles/Scaler.dir/src/bicubic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Scaler.dir/src/bicubic.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/johni/GitControl/yrr/src/bicubic.c -o CMakeFiles/Scaler.dir/src/bicubic.c.s

CMakeFiles/Scaler.dir/src/bmp.c.o: CMakeFiles/Scaler.dir/flags.make
CMakeFiles/Scaler.dir/src/bmp.c.o: ../src/bmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/johni/GitControl/yrr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Scaler.dir/src/bmp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Scaler.dir/src/bmp.c.o   -c /home/johni/GitControl/yrr/src/bmp.c

CMakeFiles/Scaler.dir/src/bmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Scaler.dir/src/bmp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/johni/GitControl/yrr/src/bmp.c > CMakeFiles/Scaler.dir/src/bmp.c.i

CMakeFiles/Scaler.dir/src/bmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Scaler.dir/src/bmp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/johni/GitControl/yrr/src/bmp.c -o CMakeFiles/Scaler.dir/src/bmp.c.s

# Object files for target Scaler
Scaler_OBJECTS = \
"CMakeFiles/Scaler.dir/main.c.o" \
"CMakeFiles/Scaler.dir/src/bicubic.c.o" \
"CMakeFiles/Scaler.dir/src/bmp.c.o"

# External object files for target Scaler
Scaler_EXTERNAL_OBJECTS =

Scaler: CMakeFiles/Scaler.dir/main.c.o
Scaler: CMakeFiles/Scaler.dir/src/bicubic.c.o
Scaler: CMakeFiles/Scaler.dir/src/bmp.c.o
Scaler: CMakeFiles/Scaler.dir/build.make
Scaler: src/librela_l.a
Scaler: CMakeFiles/Scaler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/johni/GitControl/yrr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Scaler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Scaler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Scaler.dir/build: Scaler

.PHONY : CMakeFiles/Scaler.dir/build

CMakeFiles/Scaler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Scaler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Scaler.dir/clean

CMakeFiles/Scaler.dir/depend:
	cd /home/johni/GitControl/yrr/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/johni/GitControl/yrr /home/johni/GitControl/yrr /home/johni/GitControl/yrr/build /home/johni/GitControl/yrr/build /home/johni/GitControl/yrr/build/CMakeFiles/Scaler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Scaler.dir/depend

