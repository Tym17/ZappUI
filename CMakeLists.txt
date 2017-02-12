cmake_minimum_required(VERSION 3.0)
project(PSU_2015_zappy)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O3 -lm")

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(
	"${INCLUDE_DIR}/"
	"${INCLUDE_DIR}/ui")

include(${CMAKE_SOURCE_DIR}/source/ui/CMakeLists.txt)
