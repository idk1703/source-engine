set(PROJECT datacache)

set(SOURCES
    datacache.cpp
    mdlcache.cpp
    ${SRCDIR}/public/studio.cpp
    ${SRCDIR}/public/studio_virtualmodel.cpp
    ${SRCDIR}/common/studiobyteswap.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE MDLCACHE_DLL_EXPORT)
target_link_libraries(${PROJECT} PRIVATE tier0 tier1 tier2 tier3)
install(TARGETS ${PROJECT} DESTINATION bin)