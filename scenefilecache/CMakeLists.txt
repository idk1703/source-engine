set(PROJECT scenefilecache)

set(SOURCES
    SceneFileCache.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE PROTECTED_THINGS_ENABLE)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/game/shared
)
target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1
)
install(TARGETS ${PROJECT} DESTINATION bin)