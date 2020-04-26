# Select platform and installation for extra arduino files AND toolchain (compiler...)
SET(PLATFORM_ARCHITECTURE "STM32F1")
# Must be named arduino
#  else the cmake code will look for ARDUINO
# while the name will be the name of the folder
IF(NOT DEFINED CONFIGURATION)
    SET(CONFIGURATION default)
ENDIF(NOT DEFINED CONFIGURATION)

include(./platformConfig.cmake)
SET(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
MESSAGE(STATUS "Starting VolumeControl ")
ADD_DEFINITIONS("-g3")
cmake_minimum_required(VERSION 2.8)
Project("volumeControl" C CXX ASM)

#print_board_list()
set(ARDUINO_DEFAULT_BOARD genericSTM32F103C)        # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT ttyACM0) # Default Port, when not specified
set(ARDUINO_CPU          STM32F103C8)
SET(libPrefix ${ARDUINO_DEFAULT_BOARD}_)
#
SET(SUB_COMPONENTS FreeRTOS RotaryEncoder)
FOREACH(comp ${SUB_COMPONENTS})
    include_directories(${comp})
ENDFOREACH(comp ${SUB_COMPONENTS})

include_directories(${CMAKE_SOURCE_DIR})
include_directories(FreeRTOS/Source/include)
include_directories(FreeRTOS/Source/portable/Stm32duino/)
# Build 
FOREACH(comp ${SUB_COMPONENTS})
    add_subdirectory(${comp})
ENDFOREACH(comp ${SUB_COMPONENTS})
#
# Our code
#

generate_arduino_firmware(volumeControl 
                SKETCH stm32ComponentTester.ino
                SRCS myCode.cpp 
                PORT ${ARDUINO_DEFAULT_PORT}
                BOARD_CPU ${ARDUINO_CPU}
                )
FOREACH(comp ${SUB_COMPONENTS})
    target_link_libraries(volumeControl ${libPrefix}${comp})
ENDFOREACH(comp ${SUB_COMPONENTS})
#dump_all()
# EOF
