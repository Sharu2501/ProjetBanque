# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sarusman/desktop/ProjetBanque

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sarusman/desktop/ProjetBanque/build

# Include any dependencies generated for this target.
include CMakeFiles/ProjetC__.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProjetC__.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetC__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetC__.dir/flags.make

CMakeFiles/ProjetC__.dir/codegen:
.PHONY : CMakeFiles/ProjetC__.dir/codegen

CMakeFiles/ProjetC__.dir/source/Bank.cpp.o: CMakeFiles/ProjetC__.dir/flags.make
CMakeFiles/ProjetC__.dir/source/Bank.cpp.o: /Users/sarusman/desktop/ProjetBanque/source/Bank.cpp
CMakeFiles/ProjetC__.dir/source/Bank.cpp.o: CMakeFiles/ProjetC__.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sarusman/desktop/ProjetBanque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjetC__.dir/source/Bank.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjetC__.dir/source/Bank.cpp.o -MF CMakeFiles/ProjetC__.dir/source/Bank.cpp.o.d -o CMakeFiles/ProjetC__.dir/source/Bank.cpp.o -c /Users/sarusman/desktop/ProjetBanque/source/Bank.cpp

CMakeFiles/ProjetC__.dir/source/Bank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProjetC__.dir/source/Bank.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sarusman/desktop/ProjetBanque/source/Bank.cpp > CMakeFiles/ProjetC__.dir/source/Bank.cpp.i

CMakeFiles/ProjetC__.dir/source/Bank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProjetC__.dir/source/Bank.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sarusman/desktop/ProjetBanque/source/Bank.cpp -o CMakeFiles/ProjetC__.dir/source/Bank.cpp.s

CMakeFiles/ProjetC__.dir/source/Account.cpp.o: CMakeFiles/ProjetC__.dir/flags.make
CMakeFiles/ProjetC__.dir/source/Account.cpp.o: /Users/sarusman/desktop/ProjetBanque/source/Account.cpp
CMakeFiles/ProjetC__.dir/source/Account.cpp.o: CMakeFiles/ProjetC__.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sarusman/desktop/ProjetBanque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProjetC__.dir/source/Account.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjetC__.dir/source/Account.cpp.o -MF CMakeFiles/ProjetC__.dir/source/Account.cpp.o.d -o CMakeFiles/ProjetC__.dir/source/Account.cpp.o -c /Users/sarusman/desktop/ProjetBanque/source/Account.cpp

CMakeFiles/ProjetC__.dir/source/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProjetC__.dir/source/Account.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sarusman/desktop/ProjetBanque/source/Account.cpp > CMakeFiles/ProjetC__.dir/source/Account.cpp.i

CMakeFiles/ProjetC__.dir/source/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProjetC__.dir/source/Account.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sarusman/desktop/ProjetBanque/source/Account.cpp -o CMakeFiles/ProjetC__.dir/source/Account.cpp.s

CMakeFiles/ProjetC__.dir/Menu.cpp.o: CMakeFiles/ProjetC__.dir/flags.make
CMakeFiles/ProjetC__.dir/Menu.cpp.o: /Users/sarusman/desktop/ProjetBanque/Menu.cpp
CMakeFiles/ProjetC__.dir/Menu.cpp.o: CMakeFiles/ProjetC__.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sarusman/desktop/ProjetBanque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProjetC__.dir/Menu.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjetC__.dir/Menu.cpp.o -MF CMakeFiles/ProjetC__.dir/Menu.cpp.o.d -o CMakeFiles/ProjetC__.dir/Menu.cpp.o -c /Users/sarusman/desktop/ProjetBanque/Menu.cpp

CMakeFiles/ProjetC__.dir/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProjetC__.dir/Menu.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sarusman/desktop/ProjetBanque/Menu.cpp > CMakeFiles/ProjetC__.dir/Menu.cpp.i

CMakeFiles/ProjetC__.dir/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProjetC__.dir/Menu.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sarusman/desktop/ProjetBanque/Menu.cpp -o CMakeFiles/ProjetC__.dir/Menu.cpp.s

# Object files for target ProjetC__
ProjetC___OBJECTS = \
"CMakeFiles/ProjetC__.dir/source/Bank.cpp.o" \
"CMakeFiles/ProjetC__.dir/source/Account.cpp.o" \
"CMakeFiles/ProjetC__.dir/Menu.cpp.o"

# External object files for target ProjetC__
ProjetC___EXTERNAL_OBJECTS =

ProjetC__: CMakeFiles/ProjetC__.dir/source/Bank.cpp.o
ProjetC__: CMakeFiles/ProjetC__.dir/source/Account.cpp.o
ProjetC__: CMakeFiles/ProjetC__.dir/Menu.cpp.o
ProjetC__: CMakeFiles/ProjetC__.dir/build.make
ProjetC__: CMakeFiles/ProjetC__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/sarusman/desktop/ProjetBanque/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ProjetC__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjetC__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetC__.dir/build: ProjetC__
.PHONY : CMakeFiles/ProjetC__.dir/build

CMakeFiles/ProjetC__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjetC__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjetC__.dir/clean

CMakeFiles/ProjetC__.dir/depend:
	cd /Users/sarusman/desktop/ProjetBanque/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sarusman/desktop/ProjetBanque /Users/sarusman/desktop/ProjetBanque /Users/sarusman/desktop/ProjetBanque/build /Users/sarusman/desktop/ProjetBanque/build /Users/sarusman/desktop/ProjetBanque/build/CMakeFiles/ProjetC__.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ProjetC__.dir/depend

