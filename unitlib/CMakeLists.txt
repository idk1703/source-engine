set(PROJECT unitlib)

set(SOURCES
    unitlib.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE UNITLIB_DLL_EXPORT)

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2 tier3
    $<$<BOOL:${LINUX}>:rt>
)