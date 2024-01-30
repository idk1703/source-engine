set(PROJECT studiorender)

set(SOURCES
    studiorender.cpp
    studiorendercontext.cpp
    flexrenderdata.cpp
    r_studio.cpp
    r_studiodecal.cpp
    r_studiodraw.cpp
    r_studiodraw_computeflexedvertex.cpp
    r_studioflex.cpp
    r_studiogettriangles.cpp
    r_studiolight.cpp
    r_studiostats.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    STUDIORENDER_EXPORTS
    PROTECTED_THINGS_ENABLE
)
target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2 tier3
    mathlib
    vstdlib
)
install(TARGETS ${PROJECT} DESTINATION bin)