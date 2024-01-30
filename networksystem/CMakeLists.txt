set(PROJECT networksystem)

set(SOURCES
    netchannel.cpp
    networkclient.cpp
    networkserver.cpp
    networksystem.cpp
    udp_process.cpp
    udp_socket.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE NETWORKSYSTEM_EXPORTS)
target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2
	$<$<BOOL:${WINDOWS}>:winmm.lib ws2_32.lib>
)