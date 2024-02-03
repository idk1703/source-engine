set(PROJECT raytrace)

set(SOURCES
    raytrace.cpp
    trace2.cpp
    trace3.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/utils/common
)