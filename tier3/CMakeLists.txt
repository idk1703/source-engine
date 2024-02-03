set(PROJECT tier3)

set(SOURCES
    tier3.cpp
    mdlutils.cpp
    choreoutils.cpp
    scenetokenprocessor.cpp
    studiohdrstub.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})