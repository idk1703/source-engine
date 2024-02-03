set(PROJECT replay_common)

set(SOURCES
    replay.cpp
    replaylib.cpp
    basereplayserializeable.cpp
    performance.cpp
    replaytime.cpp
    replayutils.cpp
    screenshot.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})