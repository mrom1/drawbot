cmake_minimum_required(VERSION 3.14)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

project(drawbot C CXX)

print_board_list()
print_programmer_list()

set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0) # Default Port, when not specified
register_hardware_platform(${ARDUINO_SDK_PATH}/hardware/arduino/avr)

set(drawbot_lib_SRCS ../drawbot.cpp ArduinoSerial.cpp gcode.cpp A4988.cpp)
set(drawbot_lib_HDRS config.h ../drawbot.h ../protocol.h ../serial.h ../stepper.h ArduinoSerial.h gcode.h A4988.h)
set(drawbot_lib_BOARD uno)

generate_arduino_library(drawbot_lib)

set(drawbot_SRCS main.cpp)
set(drawbot_LIBS drawbot_lib)
set(drawbot_BOARD uno)

generate_arduino_firmware(drawbot)
