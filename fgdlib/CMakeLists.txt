set(PROJECT fgdlib)

set(SOURCES
    gamedata.cpp
    gdclass.cpp
    gdvar.cpp
    inputoutput.cpp
    wckeyvalues.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})

target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/utils/common
)