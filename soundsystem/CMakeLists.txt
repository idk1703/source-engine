set(PROJECT soundsystem)

set(SOURCES
    ${SRCDIR}/public/sentence.cpp
    snd_audio_source.cpp
    snd_dev_wave.cpp
    snd_io.cpp
    snd_wave_mixer.cpp
    snd_wave_mixer_adpcm.cpp
    snd_wave_source.cpp
    soundsystem.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    SOUNDSYSTEM_EXPORTS
)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/soundemittersystem
    ${SRCDIR}/game/shared
)

target_link_libraries(${PROJECT} PRIVATE
	mathlib
    tier0 tier1 tier2
)