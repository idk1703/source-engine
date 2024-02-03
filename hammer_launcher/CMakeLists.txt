set(PROJECT hammer_launcher)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} PRIVATE
    appframework
    tier0 tier1
    vstdlib
    $<$<BOOL:${LINUX}>:dl>
)