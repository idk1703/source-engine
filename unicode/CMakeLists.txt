set(PROJECT unicode)

set(SOURCES
	unicode.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE UNICODE_EXPORTS)

target_link_libraries(${PROJECT} PRIVATE
    # tier0 tier1 tier2 tier3
    $<$<BOOL:${LINUX}>:rt>
)
install(TARGETS ${PROJECT} DESTINATION bin)