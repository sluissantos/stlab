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
include CMakeFiles/revolog5g.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/revolog5g.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/revolog5g.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/revolog5g.elf.dir/flags.make

project_elf_src_esp32s3.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating project_elf_src_esp32s3.c"
	/usr/bin/cmake -E touch /home/santos/Documents/stlab/esp32s3/build/project_elf_src_esp32s3.c

broker_ca.pem.S: /home/santos/esp/v5.1.2/esp-idf/tools/cmake/scripts/data_file_embed_asm.cmake
broker_ca.pem.S: ../certificates/mqtt_broker/broker_ca.pem
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating broker_ca.pem.S"
	/usr/bin/cmake -D DATA_FILE=/home/santos/Documents/stlab/esp32s3/certificates/mqtt_broker/broker_ca.pem -D SOURCE_FILE=/home/santos/Documents/stlab/esp32s3/build/broker_ca.pem.S -D FILE_TYPE=TEXT -P /home/santos/esp/v5.1.2/esp-idf/tools/cmake/scripts/data_file_embed_asm.cmake

root_ca.pem.S: /home/santos/esp/v5.1.2/esp-idf/tools/cmake/scripts/data_file_embed_asm.cmake
root_ca.pem.S: ../certificates/firmware_upgrade/root_ca.pem
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating root_ca.pem.S"
	/usr/bin/cmake -D DATA_FILE=/home/santos/Documents/stlab/esp32s3/certificates/firmware_upgrade/root_ca.pem -D SOURCE_FILE=/home/santos/Documents/stlab/esp32s3/build/root_ca.pem.S -D FILE_TYPE=TEXT -P /home/santos/esp/v5.1.2/esp-idf/tools/cmake/scripts/data_file_embed_asm.cmake

CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj: CMakeFiles/revolog5g.elf.dir/flags.make
CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj: project_elf_src_esp32s3.c
CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj: CMakeFiles/revolog5g.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj -MF CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj.d -o CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj -c /home/santos/Documents/stlab/esp32s3/build/project_elf_src_esp32s3.c

CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.i"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/santos/Documents/stlab/esp32s3/build/project_elf_src_esp32s3.c > CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.i

CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.s"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/santos/Documents/stlab/esp32s3/build/project_elf_src_esp32s3.c -o CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.s

CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.obj: CMakeFiles/revolog5g.elf.dir/flags.make
CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.obj: broker_ca.pem.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building ASM object CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.obj"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.obj -c /home/santos/Documents/stlab/esp32s3/build/broker_ca.pem.S

CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing ASM source to CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.i"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /home/santos/Documents/stlab/esp32s3/build/broker_ca.pem.S > CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.i

CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling ASM source to assembly CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.s"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /home/santos/Documents/stlab/esp32s3/build/broker_ca.pem.S -o CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.s

CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.obj: CMakeFiles/revolog5g.elf.dir/flags.make
CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.obj: root_ca.pem.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building ASM object CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.obj"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.obj -c /home/santos/Documents/stlab/esp32s3/build/root_ca.pem.S

CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing ASM source to CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.i"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /home/santos/Documents/stlab/esp32s3/build/root_ca.pem.S > CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.i

CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling ASM source to assembly CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.s"
	/home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /home/santos/Documents/stlab/esp32s3/build/root_ca.pem.S -o CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.s

# Object files for target revolog5g.elf
revolog5g_elf_OBJECTS = \
"CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj" \
"CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.obj" \
"CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.obj"

# External object files for target revolog5g.elf
revolog5g_elf_EXTERNAL_OBJECTS =

revolog5g.elf: CMakeFiles/revolog5g.elf.dir/project_elf_src_esp32s3.c.obj
revolog5g.elf: CMakeFiles/revolog5g.elf.dir/broker_ca.pem.S.obj
revolog5g.elf: CMakeFiles/revolog5g.elf.dir/root_ca.pem.S.obj
revolog5g.elf: CMakeFiles/revolog5g.elf.dir/build.make
revolog5g.elf: esp-idf/xtensa/libxtensa.a
revolog5g.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
revolog5g.elf: esp-idf/efuse/libefuse.a
revolog5g.elf: esp-idf/driver/libdriver.a
revolog5g.elf: esp-idf/esp_pm/libesp_pm.a
revolog5g.elf: esp-idf/mbedtls/libmbedtls.a
revolog5g.elf: esp-idf/esp_app_format/libesp_app_format.a
revolog5g.elf: esp-idf/bootloader_support/libbootloader_support.a
revolog5g.elf: esp-idf/esp_partition/libesp_partition.a
revolog5g.elf: esp-idf/app_update/libapp_update.a
revolog5g.elf: esp-idf/esp_mm/libesp_mm.a
revolog5g.elf: esp-idf/spi_flash/libspi_flash.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/esp_system/libesp_system.a
revolog5g.elf: esp-idf/esp_rom/libesp_rom.a
revolog5g.elf: esp-idf/hal/libhal.a
revolog5g.elf: esp-idf/log/liblog.a
revolog5g.elf: esp-idf/heap/libheap.a
revolog5g.elf: esp-idf/soc/libsoc.a
revolog5g.elf: esp-idf/esp_hw_support/libesp_hw_support.a
revolog5g.elf: esp-idf/freertos/libfreertos.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_common/libesp_common.a
revolog5g.elf: esp-idf/esp_timer/libesp_timer.a
revolog5g.elf: esp-idf/app_trace/libapp_trace.a
revolog5g.elf: esp-idf/esp_event/libesp_event.a
revolog5g.elf: esp-idf/nvs_flash/libnvs_flash.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/vfs/libvfs.a
revolog5g.elf: esp-idf/lwip/liblwip.a
revolog5g.elf: esp-idf/esp_netif/libesp_netif.a
revolog5g.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
revolog5g.elf: esp-idf/esp_coex/libesp_coex.a
revolog5g.elf: esp-idf/esp_wifi/libesp_wifi.a
revolog5g.elf: esp-idf/bt/libbt.a
revolog5g.elf: esp-idf/unity/libunity.a
revolog5g.elf: esp-idf/cmock/libcmock.a
revolog5g.elf: esp-idf/console/libconsole.a
revolog5g.elf: esp-idf/http_parser/libhttp_parser.a
revolog5g.elf: esp-idf/esp-tls/libesp-tls.a
revolog5g.elf: esp-idf/esp_adc/libesp_adc.a
revolog5g.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
revolog5g.elf: esp-idf/esp_hid/libesp_hid.a
revolog5g.elf: esp-idf/tcp_transport/libtcp_transport.a
revolog5g.elf: esp-idf/esp_http_client/libesp_http_client.a
revolog5g.elf: esp-idf/esp_http_server/libesp_http_server.a
revolog5g.elf: esp-idf/esp_https_ota/libesp_https_ota.a
revolog5g.elf: esp-idf/esp_lcd/libesp_lcd.a
revolog5g.elf: esp-idf/protobuf-c/libprotobuf-c.a
revolog5g.elf: esp-idf/protocomm/libprotocomm.a
revolog5g.elf: esp-idf/esp_local_ctrl/libesp_local_ctrl.a
revolog5g.elf: esp-idf/espcoredump/libespcoredump.a
revolog5g.elf: esp-idf/wear_levelling/libwear_levelling.a
revolog5g.elf: esp-idf/sdmmc/libsdmmc.a
revolog5g.elf: esp-idf/fatfs/libfatfs.a
revolog5g.elf: esp-idf/json/libjson.a
revolog5g.elf: esp-idf/mqtt/libmqtt.a
revolog5g.elf: esp-idf/perfmon/libperfmon.a
revolog5g.elf: esp-idf/spiffs/libspiffs.a
revolog5g.elf: esp-idf/touch_element/libtouch_element.a
revolog5g.elf: esp-idf/ulp/libulp.a
revolog5g.elf: esp-idf/usb/libusb.a
revolog5g.elf: esp-idf/wifi_provisioning/libwifi_provisioning.a
revolog5g.elf: esp-idf/uart/libuart.a
revolog5g.elf: esp-idf/storage/libstorage.a
revolog5g.elf: esp-idf/mqtts/libmqtts.a
revolog5g.elf: esp-idf/xpower/libxpower.a
revolog5g.elf: esp-idf/gsm/libgsm.a
revolog5g.elf: esp-idf/communication/libcommunication.a
revolog5g.elf: esp-idf/devices/libdevices.a
revolog5g.elf: esp-idf/wifi/libwifi.a
revolog5g.elf: esp-idf/main/libmain.a
revolog5g.elf: esp-idf/app_trace/libapp_trace.a
revolog5g.elf: esp-idf/unity/libunity.a
revolog5g.elf: esp-idf/wear_levelling/libwear_levelling.a
revolog5g.elf: esp-idf/sdmmc/libsdmmc.a
revolog5g.elf: esp-idf/protocomm/libprotocomm.a
revolog5g.elf: esp-idf/bt/libbt.a
revolog5g.elf: esp-idf/console/libconsole.a
revolog5g.elf: esp-idf/protobuf-c/libprotobuf-c.a
revolog5g.elf: esp-idf/json/libjson.a
revolog5g.elf: esp-idf/wifi/libwifi.a
revolog5g.elf: esp-idf/storage/libstorage.a
revolog5g.elf: esp-idf/mqtts/libmqtts.a
revolog5g.elf: esp-idf/gsm/libgsm.a
revolog5g.elf: esp-idf/communication/libcommunication.a
revolog5g.elf: esp-idf/devices/libdevices.a
revolog5g.elf: esp-idf/storage/libstorage.a
revolog5g.elf: esp-idf/mqtts/libmqtts.a
revolog5g.elf: esp-idf/gsm/libgsm.a
revolog5g.elf: esp-idf/communication/libcommunication.a
revolog5g.elf: esp-idf/devices/libdevices.a
revolog5g.elf: esp-idf/mqtt/libmqtt.a
revolog5g.elf: esp-idf/xpower/libxpower.a
revolog5g.elf: esp-idf/uart/libuart.a
revolog5g.elf: esp-idf/xtensa/libxtensa.a
revolog5g.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
revolog5g.elf: esp-idf/efuse/libefuse.a
revolog5g.elf: esp-idf/driver/libdriver.a
revolog5g.elf: esp-idf/esp_pm/libesp_pm.a
revolog5g.elf: esp-idf/mbedtls/libmbedtls.a
revolog5g.elf: esp-idf/esp_app_format/libesp_app_format.a
revolog5g.elf: esp-idf/bootloader_support/libbootloader_support.a
revolog5g.elf: esp-idf/esp_partition/libesp_partition.a
revolog5g.elf: esp-idf/app_update/libapp_update.a
revolog5g.elf: esp-idf/esp_mm/libesp_mm.a
revolog5g.elf: esp-idf/spi_flash/libspi_flash.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/esp_system/libesp_system.a
revolog5g.elf: esp-idf/esp_rom/libesp_rom.a
revolog5g.elf: esp-idf/hal/libhal.a
revolog5g.elf: esp-idf/log/liblog.a
revolog5g.elf: esp-idf/heap/libheap.a
revolog5g.elf: esp-idf/soc/libsoc.a
revolog5g.elf: esp-idf/esp_hw_support/libesp_hw_support.a
revolog5g.elf: esp-idf/freertos/libfreertos.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_common/libesp_common.a
revolog5g.elf: esp-idf/esp_timer/libesp_timer.a
revolog5g.elf: esp-idf/esp_event/libesp_event.a
revolog5g.elf: esp-idf/nvs_flash/libnvs_flash.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/vfs/libvfs.a
revolog5g.elf: esp-idf/lwip/liblwip.a
revolog5g.elf: esp-idf/esp_netif/libesp_netif.a
revolog5g.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
revolog5g.elf: esp-idf/esp_coex/libesp_coex.a
revolog5g.elf: esp-idf/esp_wifi/libesp_wifi.a
revolog5g.elf: esp-idf/http_parser/libhttp_parser.a
revolog5g.elf: esp-idf/esp-tls/libesp-tls.a
revolog5g.elf: esp-idf/esp_adc/libesp_adc.a
revolog5g.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
revolog5g.elf: esp-idf/tcp_transport/libtcp_transport.a
revolog5g.elf: esp-idf/esp_http_client/libesp_http_client.a
revolog5g.elf: esp-idf/esp_http_server/libesp_http_server.a
revolog5g.elf: esp-idf/esp_https_ota/libesp_https_ota.a
revolog5g.elf: esp-idf/ulp/libulp.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_coex/lib/esp32s3/libcoexist.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libcore.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libespnow.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libmesh.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libnet80211.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libpp.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libsmartconfig.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libwapi.a
revolog5g.elf: esp-idf/xtensa/libxtensa.a
revolog5g.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
revolog5g.elf: esp-idf/efuse/libefuse.a
revolog5g.elf: esp-idf/driver/libdriver.a
revolog5g.elf: esp-idf/esp_pm/libesp_pm.a
revolog5g.elf: esp-idf/mbedtls/libmbedtls.a
revolog5g.elf: esp-idf/esp_app_format/libesp_app_format.a
revolog5g.elf: esp-idf/bootloader_support/libbootloader_support.a
revolog5g.elf: esp-idf/esp_partition/libesp_partition.a
revolog5g.elf: esp-idf/app_update/libapp_update.a
revolog5g.elf: esp-idf/esp_mm/libesp_mm.a
revolog5g.elf: esp-idf/spi_flash/libspi_flash.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/esp_system/libesp_system.a
revolog5g.elf: esp-idf/esp_rom/libesp_rom.a
revolog5g.elf: esp-idf/hal/libhal.a
revolog5g.elf: esp-idf/log/liblog.a
revolog5g.elf: esp-idf/heap/libheap.a
revolog5g.elf: esp-idf/soc/libsoc.a
revolog5g.elf: esp-idf/esp_hw_support/libesp_hw_support.a
revolog5g.elf: esp-idf/freertos/libfreertos.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_common/libesp_common.a
revolog5g.elf: esp-idf/esp_timer/libesp_timer.a
revolog5g.elf: esp-idf/esp_event/libesp_event.a
revolog5g.elf: esp-idf/nvs_flash/libnvs_flash.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/vfs/libvfs.a
revolog5g.elf: esp-idf/lwip/liblwip.a
revolog5g.elf: esp-idf/esp_netif/libesp_netif.a
revolog5g.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
revolog5g.elf: esp-idf/esp_coex/libesp_coex.a
revolog5g.elf: esp-idf/esp_wifi/libesp_wifi.a
revolog5g.elf: esp-idf/http_parser/libhttp_parser.a
revolog5g.elf: esp-idf/esp-tls/libesp-tls.a
revolog5g.elf: esp-idf/esp_adc/libesp_adc.a
revolog5g.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
revolog5g.elf: esp-idf/tcp_transport/libtcp_transport.a
revolog5g.elf: esp-idf/esp_http_client/libesp_http_client.a
revolog5g.elf: esp-idf/esp_http_server/libesp_http_server.a
revolog5g.elf: esp-idf/esp_https_ota/libesp_https_ota.a
revolog5g.elf: esp-idf/ulp/libulp.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_coex/lib/esp32s3/libcoexist.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libcore.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libespnow.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libmesh.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libnet80211.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libpp.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libsmartconfig.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libwapi.a
revolog5g.elf: esp-idf/xtensa/libxtensa.a
revolog5g.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
revolog5g.elf: esp-idf/efuse/libefuse.a
revolog5g.elf: esp-idf/driver/libdriver.a
revolog5g.elf: esp-idf/esp_pm/libesp_pm.a
revolog5g.elf: esp-idf/mbedtls/libmbedtls.a
revolog5g.elf: esp-idf/esp_app_format/libesp_app_format.a
revolog5g.elf: esp-idf/bootloader_support/libbootloader_support.a
revolog5g.elf: esp-idf/esp_partition/libesp_partition.a
revolog5g.elf: esp-idf/app_update/libapp_update.a
revolog5g.elf: esp-idf/esp_mm/libesp_mm.a
revolog5g.elf: esp-idf/spi_flash/libspi_flash.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/esp_system/libesp_system.a
revolog5g.elf: esp-idf/esp_rom/libesp_rom.a
revolog5g.elf: esp-idf/hal/libhal.a
revolog5g.elf: esp-idf/log/liblog.a
revolog5g.elf: esp-idf/heap/libheap.a
revolog5g.elf: esp-idf/soc/libsoc.a
revolog5g.elf: esp-idf/esp_hw_support/libesp_hw_support.a
revolog5g.elf: esp-idf/freertos/libfreertos.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_common/libesp_common.a
revolog5g.elf: esp-idf/esp_timer/libesp_timer.a
revolog5g.elf: esp-idf/esp_event/libesp_event.a
revolog5g.elf: esp-idf/nvs_flash/libnvs_flash.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/vfs/libvfs.a
revolog5g.elf: esp-idf/lwip/liblwip.a
revolog5g.elf: esp-idf/esp_netif/libesp_netif.a
revolog5g.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
revolog5g.elf: esp-idf/esp_coex/libesp_coex.a
revolog5g.elf: esp-idf/esp_wifi/libesp_wifi.a
revolog5g.elf: esp-idf/http_parser/libhttp_parser.a
revolog5g.elf: esp-idf/esp-tls/libesp-tls.a
revolog5g.elf: esp-idf/esp_adc/libesp_adc.a
revolog5g.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
revolog5g.elf: esp-idf/tcp_transport/libtcp_transport.a
revolog5g.elf: esp-idf/esp_http_client/libesp_http_client.a
revolog5g.elf: esp-idf/esp_http_server/libesp_http_server.a
revolog5g.elf: esp-idf/esp_https_ota/libesp_https_ota.a
revolog5g.elf: esp-idf/ulp/libulp.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_coex/lib/esp32s3/libcoexist.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libcore.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libespnow.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libmesh.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libnet80211.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libpp.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libsmartconfig.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libwapi.a
revolog5g.elf: esp-idf/xtensa/libxtensa.a
revolog5g.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
revolog5g.elf: esp-idf/efuse/libefuse.a
revolog5g.elf: esp-idf/driver/libdriver.a
revolog5g.elf: esp-idf/esp_pm/libesp_pm.a
revolog5g.elf: esp-idf/mbedtls/libmbedtls.a
revolog5g.elf: esp-idf/esp_app_format/libesp_app_format.a
revolog5g.elf: esp-idf/bootloader_support/libbootloader_support.a
revolog5g.elf: esp-idf/esp_partition/libesp_partition.a
revolog5g.elf: esp-idf/app_update/libapp_update.a
revolog5g.elf: esp-idf/esp_mm/libesp_mm.a
revolog5g.elf: esp-idf/spi_flash/libspi_flash.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/esp_system/libesp_system.a
revolog5g.elf: esp-idf/esp_rom/libesp_rom.a
revolog5g.elf: esp-idf/hal/libhal.a
revolog5g.elf: esp-idf/log/liblog.a
revolog5g.elf: esp-idf/heap/libheap.a
revolog5g.elf: esp-idf/soc/libsoc.a
revolog5g.elf: esp-idf/esp_hw_support/libesp_hw_support.a
revolog5g.elf: esp-idf/freertos/libfreertos.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_common/libesp_common.a
revolog5g.elf: esp-idf/esp_timer/libesp_timer.a
revolog5g.elf: esp-idf/esp_event/libesp_event.a
revolog5g.elf: esp-idf/nvs_flash/libnvs_flash.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/vfs/libvfs.a
revolog5g.elf: esp-idf/lwip/liblwip.a
revolog5g.elf: esp-idf/esp_netif/libesp_netif.a
revolog5g.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
revolog5g.elf: esp-idf/esp_coex/libesp_coex.a
revolog5g.elf: esp-idf/esp_wifi/libesp_wifi.a
revolog5g.elf: esp-idf/http_parser/libhttp_parser.a
revolog5g.elf: esp-idf/esp-tls/libesp-tls.a
revolog5g.elf: esp-idf/esp_adc/libesp_adc.a
revolog5g.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
revolog5g.elf: esp-idf/tcp_transport/libtcp_transport.a
revolog5g.elf: esp-idf/esp_http_client/libesp_http_client.a
revolog5g.elf: esp-idf/esp_http_server/libesp_http_server.a
revolog5g.elf: esp-idf/esp_https_ota/libesp_https_ota.a
revolog5g.elf: esp-idf/ulp/libulp.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_coex/lib/esp32s3/libcoexist.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libcore.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libespnow.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libmesh.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libnet80211.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libpp.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libsmartconfig.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libwapi.a
revolog5g.elf: esp-idf/xtensa/libxtensa.a
revolog5g.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
revolog5g.elf: esp-idf/efuse/libefuse.a
revolog5g.elf: esp-idf/driver/libdriver.a
revolog5g.elf: esp-idf/esp_pm/libesp_pm.a
revolog5g.elf: esp-idf/mbedtls/libmbedtls.a
revolog5g.elf: esp-idf/esp_app_format/libesp_app_format.a
revolog5g.elf: esp-idf/bootloader_support/libbootloader_support.a
revolog5g.elf: esp-idf/esp_partition/libesp_partition.a
revolog5g.elf: esp-idf/app_update/libapp_update.a
revolog5g.elf: esp-idf/esp_mm/libesp_mm.a
revolog5g.elf: esp-idf/spi_flash/libspi_flash.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/esp_system/libesp_system.a
revolog5g.elf: esp-idf/esp_rom/libesp_rom.a
revolog5g.elf: esp-idf/hal/libhal.a
revolog5g.elf: esp-idf/log/liblog.a
revolog5g.elf: esp-idf/heap/libheap.a
revolog5g.elf: esp-idf/soc/libsoc.a
revolog5g.elf: esp-idf/esp_hw_support/libesp_hw_support.a
revolog5g.elf: esp-idf/freertos/libfreertos.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_common/libesp_common.a
revolog5g.elf: esp-idf/esp_timer/libesp_timer.a
revolog5g.elf: esp-idf/esp_event/libesp_event.a
revolog5g.elf: esp-idf/nvs_flash/libnvs_flash.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/vfs/libvfs.a
revolog5g.elf: esp-idf/lwip/liblwip.a
revolog5g.elf: esp-idf/esp_netif/libesp_netif.a
revolog5g.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
revolog5g.elf: esp-idf/esp_coex/libesp_coex.a
revolog5g.elf: esp-idf/esp_wifi/libesp_wifi.a
revolog5g.elf: esp-idf/http_parser/libhttp_parser.a
revolog5g.elf: esp-idf/esp-tls/libesp-tls.a
revolog5g.elf: esp-idf/esp_adc/libesp_adc.a
revolog5g.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
revolog5g.elf: esp-idf/tcp_transport/libtcp_transport.a
revolog5g.elf: esp-idf/esp_http_client/libesp_http_client.a
revolog5g.elf: esp-idf/esp_http_server/libesp_http_server.a
revolog5g.elf: esp-idf/esp_https_ota/libesp_https_ota.a
revolog5g.elf: esp-idf/ulp/libulp.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_coex/lib/esp32s3/libcoexist.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libcore.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libespnow.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libmesh.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libnet80211.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libpp.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libsmartconfig.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libwapi.a
revolog5g.elf: esp-idf/xtensa/libxtensa.a
revolog5g.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
revolog5g.elf: esp-idf/efuse/libefuse.a
revolog5g.elf: esp-idf/driver/libdriver.a
revolog5g.elf: esp-idf/esp_pm/libesp_pm.a
revolog5g.elf: esp-idf/mbedtls/libmbedtls.a
revolog5g.elf: esp-idf/esp_app_format/libesp_app_format.a
revolog5g.elf: esp-idf/bootloader_support/libbootloader_support.a
revolog5g.elf: esp-idf/esp_partition/libesp_partition.a
revolog5g.elf: esp-idf/app_update/libapp_update.a
revolog5g.elf: esp-idf/esp_mm/libesp_mm.a
revolog5g.elf: esp-idf/spi_flash/libspi_flash.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/esp_system/libesp_system.a
revolog5g.elf: esp-idf/esp_rom/libesp_rom.a
revolog5g.elf: esp-idf/hal/libhal.a
revolog5g.elf: esp-idf/log/liblog.a
revolog5g.elf: esp-idf/heap/libheap.a
revolog5g.elf: esp-idf/soc/libsoc.a
revolog5g.elf: esp-idf/esp_hw_support/libesp_hw_support.a
revolog5g.elf: esp-idf/freertos/libfreertos.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_common/libesp_common.a
revolog5g.elf: esp-idf/esp_timer/libesp_timer.a
revolog5g.elf: esp-idf/esp_event/libesp_event.a
revolog5g.elf: esp-idf/nvs_flash/libnvs_flash.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/vfs/libvfs.a
revolog5g.elf: esp-idf/lwip/liblwip.a
revolog5g.elf: esp-idf/esp_netif/libesp_netif.a
revolog5g.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
revolog5g.elf: esp-idf/esp_coex/libesp_coex.a
revolog5g.elf: esp-idf/esp_wifi/libesp_wifi.a
revolog5g.elf: esp-idf/http_parser/libhttp_parser.a
revolog5g.elf: esp-idf/esp-tls/libesp-tls.a
revolog5g.elf: esp-idf/esp_adc/libesp_adc.a
revolog5g.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
revolog5g.elf: esp-idf/tcp_transport/libtcp_transport.a
revolog5g.elf: esp-idf/esp_http_client/libesp_http_client.a
revolog5g.elf: esp-idf/esp_http_server/libesp_http_server.a
revolog5g.elf: esp-idf/esp_https_ota/libesp_https_ota.a
revolog5g.elf: esp-idf/ulp/libulp.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/everest/libeverest.a
revolog5g.elf: esp-idf/mbedtls/mbedtls/3rdparty/p256-m/libp256m.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_coex/lib/esp32s3/libcoexist.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libcore.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libespnow.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libmesh.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libnet80211.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libpp.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libsmartconfig.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/lib/esp32s3/libwapi.a
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/xtensa/esp32s3/libxt_hal.a
revolog5g.elf: esp-idf/newlib/libnewlib.a
revolog5g.elf: esp-idf/pthread/libpthread.a
revolog5g.elf: esp-idf/cxx/libcxx.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/esp_phy/libesp_phy.a
revolog5g.elf: esp-idf/esp_system/ld/memory.ld
revolog5g.elf: esp-idf/esp_system/ld/sections.ld
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.ld
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.api.ld
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.libgcc.ld
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.newlib.ld
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/esp_rom/esp32s3/ld/esp32s3.rom.version.ld
revolog5g.elf: /home/santos/esp/v5.1.2/esp-idf/components/soc/esp32s3/ld/esp32s3.peripherals.ld
revolog5g.elf: CMakeFiles/revolog5g.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/santos/Documents/stlab/esp32s3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable revolog5g.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/revolog5g.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/revolog5g.elf.dir/build: revolog5g.elf
.PHONY : CMakeFiles/revolog5g.elf.dir/build

CMakeFiles/revolog5g.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/revolog5g.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/revolog5g.elf.dir/clean

CMakeFiles/revolog5g.elf.dir/depend: broker_ca.pem.S
CMakeFiles/revolog5g.elf.dir/depend: project_elf_src_esp32s3.c
CMakeFiles/revolog5g.elf.dir/depend: root_ca.pem.S
	cd /home/santos/Documents/stlab/esp32s3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/santos/Documents/stlab/esp32s3 /home/santos/Documents/stlab/esp32s3 /home/santos/Documents/stlab/esp32s3/build /home/santos/Documents/stlab/esp32s3/build /home/santos/Documents/stlab/esp32s3/build/CMakeFiles/revolog5g.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/revolog5g.elf.dir/depend
