# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/santos/Documents/stlab/esp32s3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/santos/Documents/stlab/esp32s3/build

# Include any dependencies generated for this target.
include esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/flags.make

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/flags.make
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj: /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt_client.c
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj -MF CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj.d -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj -c /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt_client.c

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.i"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt_client.c > CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.i

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.s"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt_client.c -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.s

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/flags.make
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj: /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_msg.c
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj -MF CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj.d -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj -c /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_msg.c

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.i"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_msg.c > CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.i

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.s"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_msg.c -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.s

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/flags.make
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj: /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_outbox.c
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj -MF CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj.d -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj -c /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_outbox.c

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.i"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_outbox.c > CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.i

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.s"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt_outbox.c -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.s

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/flags.make
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj: /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/platform_esp32_idf.c
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj -MF CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj.d -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj -c /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/platform_esp32_idf.c

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.i"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/platform_esp32_idf.c > CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.i

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.s"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/platform_esp32_idf.c -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.s

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/flags.make
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj: /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt5_msg.c
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj -MF CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj.d -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj -c /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt5_msg.c

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.i"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt5_msg.c > CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.i

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.s"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/lib/mqtt5_msg.c -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.s

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/flags.make
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj: /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt5_client.c
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj -MF CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj.d -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj -c /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt5_client.c

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.i"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt5_client.c > CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.i

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.s"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/mqtt5_client.c -o CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.s

# Object files for target __idf_mqtt
__idf_mqtt_OBJECTS = \
"CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj" \
"CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj" \
"CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj" \
"CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj" \
"CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj" \
"CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj"

# External object files for target __idf_mqtt
__idf_mqtt_EXTERNAL_OBJECTS =

esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt_client.c.obj
esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_msg.c.obj
esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt_outbox.c.obj
esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/platform_esp32_idf.c.obj
esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/lib/mqtt5_msg.c.obj
esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/esp-mqtt/mqtt5_client.c.obj
esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/build.make
esp-idf/mqtt/libmqtt.a: esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libmqtt.a"
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && $(CMAKE_COMMAND) -P CMakeFiles/__idf_mqtt.dir/cmake_clean_target.cmake
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_mqtt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/build: esp-idf/mqtt/libmqtt.a
.PHONY : esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/build

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/clean:
	cd /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt && $(CMAKE_COMMAND) -P CMakeFiles/__idf_mqtt.dir/cmake_clean.cmake
.PHONY : esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/clean

esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/depend:
	cd /home/santos/Documents/stlab/esp32s3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/santos/Documents/stlab/esp32s3 /home/santos/esp/v5.1.2/esp-idf/components/mqtt /home/santos/Documents/stlab/esp32s3/build /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt /home/santos/Documents/stlab/esp32s3/build/esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/mqtt/CMakeFiles/__idf_mqtt.dir/depend

