cmake_minimum_required(VERSION 2.8.4)
project(CVESVP)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

add_definitions(-std=gnu99 -Wall)

set(CMAKE_C_FLAGS_DEBUG "-O1 -ffast-math -g")
set(CMAKE_C_FLAGS_RELEASE "-Ofast")

set(CMAKE_LD_FLAGS_DEBUG "-Wl,-O0,-rdynamic")
set(CMAKE_LD_FLAGS_RELEASE "-Wl,-O1,--as-needed,--sort-common")

enable_testing()

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)

