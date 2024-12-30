# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)
set(EXTRA_COMPONENT_DIRS "extra_components")
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(revolog5g)

target_add_binary_data(revolog5g.elf "certificates/mqtt_broker/broker_ca.pem" TEXT)
target_add_binary_data(revolog5g.elf "certificates/firmware_upgrade/root_ca.pem" TEXT)
