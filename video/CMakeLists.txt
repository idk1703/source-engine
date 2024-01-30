set(PROJECT video_services)

set(SOURCES
    videoservices.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2 tier3
)
install(TARGETS ${PROJECT} DESTINATION bin)