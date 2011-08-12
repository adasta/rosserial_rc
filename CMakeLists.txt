cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)


rosbuild_find_ros_package(rosserial_arduino)
include(${rosserial_arduino_PACKAGE_PATH}/cmake_scripts/rosserial.cmake)
#====================================================================#
#  rc_car                                                            #
#====================================================================#


set(FIRMWARE_NAME rc)

set(${FIRMWARE_NAME}_BOARD atmega328)               # Arduino Target board
set(${FIRMWARE_NAME}_SRCS # 							Firmware sources
							src/rc.cpp
							src/motorcontrol.cpp
							)  
set(${FIRMWARE_NAME}_LIBS )

set(${FIRMWARE_NAME}_PORT /dev/ttyUSB0)            # Serial upload port
generate_ros_firmware(${FIRMWARE_NAME})
