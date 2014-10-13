if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    if(NOT DEFINED WITH_IN_SOURCE_BUILD)
        message(FATAL_ERROR
            "CMake generation for this project is not allowed within the source directory!"
            "\n Remove the CMakeCache.txt file and try again from another folder, e.g.:"
            "\n "
            "\n rm -r CMakeFiles CMakeCache.txt"
            "\n cd .."
            "\n mkdir CVESVP-make"
            "\n cd CVESVP-make"
            "\n cmake ../CVESVP"
            "\n "
            "\n Alternately define WITH_IN_SOURCE_BUILD to force this option (not recommended!)"
        )
    endif()
endif()
cmake_minimum_required(VERSION 2.8.4)
project(CVESVP)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

add_definitions(-std=gnu99 -Wall)

# RUtil2 should work on any platform.
if    (${CMAKE_SYSTEM_PROCESSOR} MATCHES armv7l)
    add_definitions(-march=armv7 -mfloat-abi=hard -mfpu=neon)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES x86_64*
    OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES amd64*
    OR ${CMAKE_SYSTEM_NAME}      MATCHES Darwin*)
    add_definitions(-march=x86-64 -mtune=generic -mtune=core2 -mtune=core-avx-i)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES i686*
    OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES i386*
    OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES x86*)
    add_definitions(-march=i686 -mtune=generic -mtune=core2 -mtune=core-avx-i)
endif()
message("-- Detected Supported Platform: " ${CMAKE_SYSTEM_PROCESSOR})

# Because of inline functions, we cannot use -O0 for debug.
set(CMAKE_C_FLAGS_DEBUG "-O2 -ffast-math -g")
set(CMAKE_C_FLAGS_RELEASE "-Ofast -DNDEBUG")

set(CMAKE_LD_FLAGS_DEBUG "-Wl,-O0")
set(CMAKE_LD_FLAGS_RELEASE "-Wl,-O1,--as-needed,--sort-common")

enable_testing()

include(GNUInstallDirs)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)

