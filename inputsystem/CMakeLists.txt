set(PROJECT inputsystem)

set(SOURCES
    inputsystem.cpp
    $<$<BOOL:${ENABLE_SDL}>:joystick_sdl.cpp>
    $<$<BOOL:${WINDOWS}>:novint.cpp> # [$WIN32]
    key_translation.cpp
    steamcontroller.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE VERSION_SAFE_STEAM_API_INTERFACES)

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2
    vstdlib
    steam_api
    $<$<BOOL:${ENABLE_SDL}>:SDL2::SDL2>
)
install(TARGETS ${PROJECT} DESTINATION bin)