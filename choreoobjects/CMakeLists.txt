set(PROJECT choreoobjects)

set(SOURCES
    ${SRCDIR}/game/shared/choreoactor.cpp
    ${SRCDIR}/game/shared/choreochannel.cpp
    ${SRCDIR}/game/shared/choreoevent.cpp
    ${SRCDIR}/game/shared/choreoscene.cpp
    ${SRCDIR}/game/shared/sceneimage.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/game/shared
    ${SRCDIR}/utils/common
)