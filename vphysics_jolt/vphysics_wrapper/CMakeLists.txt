set(PROJECT vphysics)

set(SOURCES
	vphysics_wrapper.cpp

	${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1
)
install(TARGETS ${PROJECT} DESTINATION bin)