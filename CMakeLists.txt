cmake_minimum_required(VERSION 2.8.4)
project(CVESVP)

add_definitions(-std=gnu99 -Wall)

enable_testing()

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)

