# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\compteadmin\Desktop\projet\projet-rush-hour

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build

# Include any dependencies generated for this target.
include CMakeFiles/rush-hour.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rush-hour.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rush-hour.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rush-hour.dir/flags.make

CMakeFiles/rush-hour.dir/codegen:
.PHONY : CMakeFiles/rush-hour.dir/codegen

CMakeFiles/rush-hour.dir/src/generate.cpp.obj: CMakeFiles/rush-hour.dir/flags.make
CMakeFiles/rush-hour.dir/src/generate.cpp.obj: CMakeFiles/rush-hour.dir/includes_CXX.rsp
CMakeFiles/rush-hour.dir/src/generate.cpp.obj: C:/Users/compteadmin/Desktop/projet/projet-rush-hour/src/generate.cpp
CMakeFiles/rush-hour.dir/src/generate.cpp.obj: CMakeFiles/rush-hour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rush-hour.dir/src/generate.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rush-hour.dir/src/generate.cpp.obj -MF CMakeFiles\rush-hour.dir\src\generate.cpp.obj.d -o CMakeFiles\rush-hour.dir\src\generate.cpp.obj -c C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\generate.cpp

CMakeFiles/rush-hour.dir/src/generate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rush-hour.dir/src/generate.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\generate.cpp > CMakeFiles\rush-hour.dir\src\generate.cpp.i

CMakeFiles/rush-hour.dir/src/generate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rush-hour.dir/src/generate.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\generate.cpp -o CMakeFiles\rush-hour.dir\src\generate.cpp.s

CMakeFiles/rush-hour.dir/src/interface.cpp.obj: CMakeFiles/rush-hour.dir/flags.make
CMakeFiles/rush-hour.dir/src/interface.cpp.obj: CMakeFiles/rush-hour.dir/includes_CXX.rsp
CMakeFiles/rush-hour.dir/src/interface.cpp.obj: C:/Users/compteadmin/Desktop/projet/projet-rush-hour/src/interface.cpp
CMakeFiles/rush-hour.dir/src/interface.cpp.obj: CMakeFiles/rush-hour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rush-hour.dir/src/interface.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rush-hour.dir/src/interface.cpp.obj -MF CMakeFiles\rush-hour.dir\src\interface.cpp.obj.d -o CMakeFiles\rush-hour.dir\src\interface.cpp.obj -c C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\interface.cpp

CMakeFiles/rush-hour.dir/src/interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rush-hour.dir/src/interface.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\interface.cpp > CMakeFiles\rush-hour.dir\src\interface.cpp.i

CMakeFiles/rush-hour.dir/src/interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rush-hour.dir/src/interface.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\interface.cpp -o CMakeFiles\rush-hour.dir\src\interface.cpp.s

CMakeFiles/rush-hour.dir/src/main.cpp.obj: CMakeFiles/rush-hour.dir/flags.make
CMakeFiles/rush-hour.dir/src/main.cpp.obj: CMakeFiles/rush-hour.dir/includes_CXX.rsp
CMakeFiles/rush-hour.dir/src/main.cpp.obj: C:/Users/compteadmin/Desktop/projet/projet-rush-hour/src/main.cpp
CMakeFiles/rush-hour.dir/src/main.cpp.obj: CMakeFiles/rush-hour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rush-hour.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rush-hour.dir/src/main.cpp.obj -MF CMakeFiles\rush-hour.dir\src\main.cpp.obj.d -o CMakeFiles\rush-hour.dir\src\main.cpp.obj -c C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\main.cpp

CMakeFiles/rush-hour.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rush-hour.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\main.cpp > CMakeFiles\rush-hour.dir\src\main.cpp.i

CMakeFiles/rush-hour.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rush-hour.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\main.cpp -o CMakeFiles\rush-hour.dir\src\main.cpp.s

CMakeFiles/rush-hour.dir/src/move.cpp.obj: CMakeFiles/rush-hour.dir/flags.make
CMakeFiles/rush-hour.dir/src/move.cpp.obj: CMakeFiles/rush-hour.dir/includes_CXX.rsp
CMakeFiles/rush-hour.dir/src/move.cpp.obj: C:/Users/compteadmin/Desktop/projet/projet-rush-hour/src/move.cpp
CMakeFiles/rush-hour.dir/src/move.cpp.obj: CMakeFiles/rush-hour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/rush-hour.dir/src/move.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rush-hour.dir/src/move.cpp.obj -MF CMakeFiles\rush-hour.dir\src\move.cpp.obj.d -o CMakeFiles\rush-hour.dir\src\move.cpp.obj -c C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\move.cpp

CMakeFiles/rush-hour.dir/src/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rush-hour.dir/src/move.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\move.cpp > CMakeFiles\rush-hour.dir\src\move.cpp.i

CMakeFiles/rush-hour.dir/src/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rush-hour.dir/src/move.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\move.cpp -o CMakeFiles\rush-hour.dir\src\move.cpp.s

CMakeFiles/rush-hour.dir/src/solve.cpp.obj: CMakeFiles/rush-hour.dir/flags.make
CMakeFiles/rush-hour.dir/src/solve.cpp.obj: CMakeFiles/rush-hour.dir/includes_CXX.rsp
CMakeFiles/rush-hour.dir/src/solve.cpp.obj: C:/Users/compteadmin/Desktop/projet/projet-rush-hour/src/solve.cpp
CMakeFiles/rush-hour.dir/src/solve.cpp.obj: CMakeFiles/rush-hour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/rush-hour.dir/src/solve.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rush-hour.dir/src/solve.cpp.obj -MF CMakeFiles\rush-hour.dir\src\solve.cpp.obj.d -o CMakeFiles\rush-hour.dir\src\solve.cpp.obj -c C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\solve.cpp

CMakeFiles/rush-hour.dir/src/solve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rush-hour.dir/src/solve.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\solve.cpp > CMakeFiles\rush-hour.dir\src\solve.cpp.i

CMakeFiles/rush-hour.dir/src/solve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rush-hour.dir/src/solve.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\solve.cpp -o CMakeFiles\rush-hour.dir\src\solve.cpp.s

CMakeFiles/rush-hour.dir/src/type.cpp.obj: CMakeFiles/rush-hour.dir/flags.make
CMakeFiles/rush-hour.dir/src/type.cpp.obj: CMakeFiles/rush-hour.dir/includes_CXX.rsp
CMakeFiles/rush-hour.dir/src/type.cpp.obj: C:/Users/compteadmin/Desktop/projet/projet-rush-hour/src/type.cpp
CMakeFiles/rush-hour.dir/src/type.cpp.obj: CMakeFiles/rush-hour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/rush-hour.dir/src/type.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rush-hour.dir/src/type.cpp.obj -MF CMakeFiles\rush-hour.dir\src\type.cpp.obj.d -o CMakeFiles\rush-hour.dir\src\type.cpp.obj -c C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\type.cpp

CMakeFiles/rush-hour.dir/src/type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rush-hour.dir/src/type.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\type.cpp > CMakeFiles\rush-hour.dir\src\type.cpp.i

CMakeFiles/rush-hour.dir/src/type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rush-hour.dir/src/type.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\type.cpp -o CMakeFiles\rush-hour.dir\src\type.cpp.s

CMakeFiles/rush-hour.dir/src/selection.cpp.obj: CMakeFiles/rush-hour.dir/flags.make
CMakeFiles/rush-hour.dir/src/selection.cpp.obj: CMakeFiles/rush-hour.dir/includes_CXX.rsp
CMakeFiles/rush-hour.dir/src/selection.cpp.obj: C:/Users/compteadmin/Desktop/projet/projet-rush-hour/src/selection.cpp
CMakeFiles/rush-hour.dir/src/selection.cpp.obj: CMakeFiles/rush-hour.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/rush-hour.dir/src/selection.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rush-hour.dir/src/selection.cpp.obj -MF CMakeFiles\rush-hour.dir\src\selection.cpp.obj.d -o CMakeFiles\rush-hour.dir\src\selection.cpp.obj -c C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\selection.cpp

CMakeFiles/rush-hour.dir/src/selection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rush-hour.dir/src/selection.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\selection.cpp > CMakeFiles\rush-hour.dir\src\selection.cpp.i

CMakeFiles/rush-hour.dir/src/selection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rush-hour.dir/src/selection.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\compteadmin\Desktop\projet\projet-rush-hour\src\selection.cpp -o CMakeFiles\rush-hour.dir\src\selection.cpp.s

# Object files for target rush-hour
rush__hour_OBJECTS = \
"CMakeFiles/rush-hour.dir/src/generate.cpp.obj" \
"CMakeFiles/rush-hour.dir/src/interface.cpp.obj" \
"CMakeFiles/rush-hour.dir/src/main.cpp.obj" \
"CMakeFiles/rush-hour.dir/src/move.cpp.obj" \
"CMakeFiles/rush-hour.dir/src/solve.cpp.obj" \
"CMakeFiles/rush-hour.dir/src/type.cpp.obj" \
"CMakeFiles/rush-hour.dir/src/selection.cpp.obj"

# External object files for target rush-hour
rush__hour_EXTERNAL_OBJECTS =

rush-hour.exe: CMakeFiles/rush-hour.dir/src/generate.cpp.obj
rush-hour.exe: CMakeFiles/rush-hour.dir/src/interface.cpp.obj
rush-hour.exe: CMakeFiles/rush-hour.dir/src/main.cpp.obj
rush-hour.exe: CMakeFiles/rush-hour.dir/src/move.cpp.obj
rush-hour.exe: CMakeFiles/rush-hour.dir/src/solve.cpp.obj
rush-hour.exe: CMakeFiles/rush-hour.dir/src/type.cpp.obj
rush-hour.exe: CMakeFiles/rush-hour.dir/src/selection.cpp.obj
rush-hour.exe: CMakeFiles/rush-hour.dir/build.make
rush-hour.exe: C:/msys64/ucrt64/lib/libsfml-graphics.dll.a
rush-hour.exe: C:/msys64/ucrt64/lib/libsfml-window.dll.a
rush-hour.exe: C:/msys64/ucrt64/lib/libsfml-system.dll.a
rush-hour.exe: CMakeFiles/rush-hour.dir/linkLibs.rsp
rush-hour.exe: CMakeFiles/rush-hour.dir/objects1.rsp
rush-hour.exe: CMakeFiles/rush-hour.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable rush-hour.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rush-hour.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rush-hour.dir/build: rush-hour.exe
.PHONY : CMakeFiles/rush-hour.dir/build

CMakeFiles/rush-hour.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rush-hour.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rush-hour.dir/clean

CMakeFiles/rush-hour.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\compteadmin\Desktop\projet\projet-rush-hour C:\Users\compteadmin\Desktop\projet\projet-rush-hour C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build C:\Users\compteadmin\Desktop\projet\projet-rush-hour\build\CMakeFiles\rush-hour.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rush-hour.dir/depend

