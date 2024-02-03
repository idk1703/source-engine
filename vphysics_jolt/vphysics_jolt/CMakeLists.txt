set(PROJECT vphysics_jolt_sse2)

set(SOURCES
	cbase.cpp
	${SRCDIR}/public/collisionutils.cpp
	${SRCDIR}/public/filesystem_helpers.cpp

	vjolt_collide.cpp
	vjolt_collide_trace.cpp
	vjolt_constraints.cpp
	vjolt_controller_fluid.cpp
	vjolt_controller_motion.cpp
	vjolt_controller_player.cpp
	vjolt_controller_vehicle.cpp
	vjolt_controller_shadow.cpp
	vjolt_debugrender.cpp
	vjolt_environment.cpp
	vjolt_friction.cpp
	vjolt_interface.cpp
	vjolt_keyvalues_schema.cpp
	vjolt_object.cpp
	vjolt_objectpairhash.cpp
	vjolt_parse.cpp
	vjolt_querymodel.cpp
	vjolt_surfaceprops.cpp

	${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE GAME_SDK2013 JPH_DISABLE_CUSTOM_ALLOCATOR JPH_PROFILE_ENABLED JPH_DEBUG_RENDERER)
target_include_directories(${PROJECT} PRIVATE
	${SRCDIR}/vphysics_jolt/joltphysics/src
)

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2
	mathlib
	vstdlib
	joltphysics_sse2
	$<$<BOOL:${LINUX}>:Threads::Threads>
)
install(TARGETS ${PROJECT} DESTINATION bin)