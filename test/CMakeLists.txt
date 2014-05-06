aux_source_directory(./TestF0 Test1)
add_executable(TestF0 ${Test1})
target_link_libraries(TestF0 CVESVP)
target_link_libraries(TestF0 CVEDSP2)
target_link_libraries(TestF0 RFNL)
target_link_libraries(TestF0 RUtil2)
target_link_libraries(TestF0 m)

add_test(TestF0 TestF0)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

