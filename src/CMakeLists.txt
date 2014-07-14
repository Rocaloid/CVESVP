aux_source_directory(./Misc SRC_LIST)
aux_source_directory(./Spectral SRC_LIST)
aux_source_directory(./Structure SRC_LIST)
aux_source_directory(./ SRC_LIST)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${TopDir}/src -DWITH_ASSERT_ABORT")

add_library(CVESVP SHARED ${SRC_LIST})
include_directories(CVESVP PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(CVESVP CVEDSP2)
target_link_libraries(CVESVP RFNL)
target_link_libraries(CVESVP m)

file(GLOB Header_Misc "./Misc/*.h")
file(GLOB Header_Spectral "./Spectral/*.h")
file(GLOB Header_Structure "./Structure/*.h")
file(GLOB Header_Iterator "./Iterator/*.h")
file(GLOB Header_ROOT "./*.h")
install(FILES ${Header_Misc}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/Misc)
install(FILES ${Header_Spectral}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/Spectral)
install(FILES ${Header_Structure}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/Structure)
install(FILES ${Header_Iterator}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP/Iterator)
install(FILES ${Header_ROOT}
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/CVESVP)
install(FILES Include/CVESVP.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)

install(TARGETS CVESVP LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
                       ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
                       RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

