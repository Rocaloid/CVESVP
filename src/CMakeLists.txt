aux_source_directory(./Misc SRC_LIST)
aux_source_directory(./EpR SRC_LIST)
aux_source_directory(./Structure SRC_LIST)
aux_source_directory(./ SRC_LIST)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${TopDir}/src -DWITH_ASSERT_ABORT")

add_library(CVESVP SHARED ${SRC_LIST})
include_directories(CVESVP PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(CVESVP CVEDSP2)
target_link_libraries(CVESVP RFNL)
target_link_libraries(CVESVP m)

file(GLOB Header_Misc "./Misc/*.h")
file(GLOB Header_EpR "./EpR/*.h")
file(GLOB Header_Structure "./Structure/*.h")
file(GLOB Header_Iterator "./Iterator/*.h")
file(GLOB Header_ROOT "./*.h")
install(FILES ${Header_Misc}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/Misc)
install(FILES ${Header_EpR}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/EpR)
install(FILES ${Header_Structure}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/Structure)
install(FILES ${Header_Iterator}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/Iterator)
install(FILES ${Header_ROOT}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP)
install(FILES Include/CVESVP.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)

if(CYGWIN OR WIN32)
    message(STATUS "You are compiling this project as COFF.")
    install(TARGETS CVESVP LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
                           ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
                           RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "You are compiling this project as 64bit.")
    install(TARGETS CVESVP LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib64
                           ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib64
                           RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(STATUS "You are compiling this project as 32bit.")
    install(TARGETS CVESVP LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
                           ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
                           RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
else()
    message(FATAL_ERROR "Your system is unsupported!")
endif()

