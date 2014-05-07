aux_source_directory(./TestF0 Test1)
add_executable(TestF0 ${Test1})
target_link_libraries(TestF0 CVESVP)
target_link_libraries(TestF0 CVEDSP2)
target_link_libraries(TestF0 RFNL)
target_link_libraries(TestF0 RUtil2)
target_link_libraries(TestF0 m)

aux_source_directory(./TestSTFT Test2)
add_executable(TestSTFT ${Test2})
target_link_libraries(TestSTFT CVESVP)
target_link_libraries(TestSTFT CVEDSP2)
target_link_libraries(TestSTFT RFNL)
target_link_libraries(TestSTFT RUtil2)
target_link_libraries(TestSTFT m)

add_test(TestF0 TestF0)
add_test(TestSTFT TestSTFT)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

