set(PROJECT steam_api)

set(SOURCES
    steam_api_null.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
install(TARGETS ${PROJECT} DESTINATION bin)