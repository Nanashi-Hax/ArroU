add_executable(ArroU main.cpp)

target_include_directories(ArroU PRIVATE
    "${WUT}/include"
    "${WUPS}/include"
    "${WUMS}/include"
)

set(LINKER_SCRIPTS
    "-T${WUMS}/share/libmappedmemory.ld"
    "-T${WUMS}/share/libkernel.ld"
    "-T${WUPS}/share/wups.ld"
)

set(SPECS_FILES
    "-specs=${WUT}/share/wut.specs"
    "-specs=${WUPS}/share/wups.specs"
)

set(LINKER_FLAGS
    "-g"
)

target_link_options(ArroU PRIVATE
    ${SPECS_FILES}
    ${LINKER_SCRIPTS}
    ${LINKER_FLAGS}
)

target_link_directories(ArroU PRIVATE
    "${WUT}/lib"
    "${WUPS}/lib"
    "${WUMS}/lib"
)

target_link_libraries(ArroU PRIVATE
    wut
    wups
    wums
    notifications
)

set_target_properties(ArroU PROPERTIES SUFFIX ".elf")

add_custom_command(
    OUTPUT "${DIST_DIR}/ArroU.wps"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${DIST_DIR}"
    COMMAND "${CMAKE_SOURCE_DIR}/Tool/elf2wps"
            "$<TARGET_FILE:ArroU>"
            "${DIST_DIR}/ArroU.wps"
    DEPENDS ArroU
)

add_custom_target(wps ALL
    DEPENDS "${DIST_DIR}/ArroU.wps"
)