# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/modbus_server_wotai.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/modbus_server_wotai.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/modbus_server_wotai.dir/flags.make

CMakeFiles/modbus_server_wotai.dir/main.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/modbus_server_wotai.dir/main.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/main.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/main.cpp

CMakeFiles/modbus_server_wotai.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/main.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/main.cpp > CMakeFiles/modbus_server_wotai.dir/main.cpp.i

CMakeFiles/modbus_server_wotai.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/main.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/main.cpp -o CMakeFiles/modbus_server_wotai.dir/main.cpp.s

CMakeFiles/modbus_server_wotai.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/main.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/main.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/main.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/main.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/main.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o: ../src/modbusServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/modbusServer.cpp

CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/modbusServer.cpp > CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/modbusServer.cpp -o CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o: ../src/cconfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/cconfig.cpp

CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/cconfig.cpp > CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/cconfig.cpp -o CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/util.cpp

CMakeFiles/modbus_server_wotai.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/util.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/util.cpp > CMakeFiles/modbus_server_wotai.dir/src/util.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/util.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/util.cpp -o CMakeFiles/modbus_server_wotai.dir/src/util.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o: ../src/slavedev.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/slavedev.cpp

CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/slavedev.cpp > CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/slavedev.cpp -o CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o: ../src/jsonparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/jsonparser.cpp

CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/jsonparser.cpp > CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/jsonparser.cpp -o CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o: ../src/slaveManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/slaveManager.cpp

CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/slaveManager.cpp > CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/slaveManager.cpp -o CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o: ../src/misc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/misc.cpp

CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/misc.cpp > CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/misc.cpp -o CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o: ../src/reg_info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_info.cpp

CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_info.cpp > CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_info.cpp -o CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o: ../src/reg_num.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_num.cpp

CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_num.cpp > CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_num.cpp -o CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o


CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o: CMakeFiles/modbus_server_wotai.dir/flags.make
CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o: ../src/reg_all.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o -c /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_all.cpp

CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.i"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_all.cpp > CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.i

CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.s"
	/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++  --sysroot=/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/../aarch64-linux-gnu/libc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/src/reg_all.cpp -o CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.s

CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.requires:

.PHONY : CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.requires

CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.provides: CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.requires
	$(MAKE) -f CMakeFiles/modbus_server_wotai.dir/build.make CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.provides.build
.PHONY : CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.provides

CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.provides.build: CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o


# Object files for target modbus_server_wotai
modbus_server_wotai_OBJECTS = \
"CMakeFiles/modbus_server_wotai.dir/main.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o" \
"CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o"

# External object files for target modbus_server_wotai
modbus_server_wotai_EXTERNAL_OBJECTS =

modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/main.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/build.make
modbus_server_wotai: CMakeFiles/modbus_server_wotai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable modbus_server_wotai"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modbus_server_wotai.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/modbus_server_wotai.dir/build: modbus_server_wotai

.PHONY : CMakeFiles/modbus_server_wotai.dir/build

CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/main.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/modbusServer.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/cconfig.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/util.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/slavedev.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/jsonparser.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/slaveManager.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/misc.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/reg_info.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/reg_num.cpp.o.requires
CMakeFiles/modbus_server_wotai.dir/requires: CMakeFiles/modbus_server_wotai.dir/src/reg_all.cpp.o.requires

.PHONY : CMakeFiles/modbus_server_wotai.dir/requires

CMakeFiles/modbus_server_wotai.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/modbus_server_wotai.dir/cmake_clean.cmake
.PHONY : CMakeFiles/modbus_server_wotai.dir/clean

CMakeFiles/modbus_server_wotai.dir/depend:
	cd /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug /home/huanglingjie/MyProject/tmp/tmp.AEVyctLpWs/cmake-build-debug/CMakeFiles/modbus_server_wotai.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/modbus_server_wotai.dir/depend

