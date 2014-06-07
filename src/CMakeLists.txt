aux_source_directory(./Misc SRC_LIST)
aux_source_directory(./EpR SRC_LIST)
aux_source_directory(./Structure SRC_LIST)
aux_source_directory(./ SRC_LIST)

set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

add_library(CVESVP SHARED ${SRC_LIST})
include_directories(CVESVP PUBLIC "${CMAKE_SOURCE_DIR}/src")

file(GLOB Header_Misc "Misc/*.h")
file(GLOB Header_EpR "EpR/*.h")
file(GLOB Header_Misc "Structure/*.h")
file(GLOB Header_ROOT "./*.h")
install(FILES ${Header_Misc}
              DESTINATION /usr/include/CVESVP/Misc)
install(FILES ${Header_EpR}
              DESTINATION /usr/include/CVESVP/EpR)
install(FILES ${Header_Structure}
              DESTINATION /usr/include/CVESVP/Structure)
install(FILES ${Header_ROOT}
              DESTINATION /usr/include/CVESVP)
install(FILES Include/CVESVP.h
              DESTINATION /usr/include/)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    install(TARGETS CVESVP LIBRARY DESTINATION /usr/lib64)
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    install(TARGETS CVESVP LIBRARY DESTINATION /usr/lib)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
