set(PROJECT mdllib)

set(SOURCES
    mdllib.cpp
    mdllib_stripinfo.cpp
    mdllib_stripmodel.cpp
    mdllib_utils.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1
)
install(TARGETS ${PROJECT} DESTINATION bin)