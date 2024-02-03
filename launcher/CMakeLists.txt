set(PROJECT launcher)

set(SOURCES
    ${SRCDIR}/public/filesystem_init.cpp
    launcher.cpp
    reslistgenerator.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE LAUNCHERONLY)

target_link_libraries(${PROJECT} PRIVATE
    appframework
    tier0 tier1 tier2 tier3
    vstdlib
    togl
    $<$<BOOL:${ENABLE_SDL}>:SDL2::SDL2>
)
install(TARGETS ${PROJECT} DESTINATION bin)