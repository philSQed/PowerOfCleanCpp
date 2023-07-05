cmake_minimum_required(VERSION 3.23)
project(PowerOfCleanCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(PowerOfCleanCpp main.cpp Wrapper.cpp Token.cpp)
if ("$ENV{IS_32}" STREQUAL "1" )
MESSAGE(STATUS "Building for 32-bit ($ENV{IS_32})")
set_target_properties(PowerOfCleanCpp PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
else()
MESSAGE(STATUS "Building for 64-bit ($ENV{IS_32})")
endif()
