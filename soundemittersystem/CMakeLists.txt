set(PROJECT soundemittersystem)

set(SOURCES
    ${SRCDIR}/game/shared/interval.cpp
    soundemittersystembase.cpp
    ${SRCDIR}/public/SoundParametersInternal.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    SOUNDEMITTERSYSTEM_EXPORTS
    PROTECTED_THINGS_ENABLE
)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/soundemittersystem
    ${SRCDIR}/game/shared
)

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1
    vstdlib
)
install(TARGETS ${PROJECT} DESTINATION bin)