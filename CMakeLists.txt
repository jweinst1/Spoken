# Spoken #

cmake_minimum_required(VERSION 3.3)

project(Spoken)

if(DEFINED ENV{SPOKEN_HOME})
     message("-- Will install Spoken binaries and libraries to location: " $ENV{SPOKEN_HOME})
	 set(CMAKE_INSTALL_PREFIX, $ENV{SPOKEN_HOME})
else(DEFINED ENV{SPOKEN_HOME})
     message("-- Will install Spoken binaries and libraries to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX, ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{SPOKEN_HOME})

# Disable some windows specific warnings for using more modern c functions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Check for availability of headers c95 or later
include(build/header_check.cmake)

# Options
option(WITH_testing "Allows tests to be run and built" ON)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)


add_subdirectory(util)