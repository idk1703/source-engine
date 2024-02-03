set(PROJECT vpklib)

set(SOURCES
    packedstore.cpp
    ${SRCDIR}/common/simplebitstring.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})