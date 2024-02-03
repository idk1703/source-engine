
set(PROJECT srcds)

set(SOURCES
    main.cpp
    ${SRCDIR}/common/SteamAppStartup.cpp
)

add_executable(${PROJECT} ${SOURCES})
target_link_options(${PROJECT} PRIVATE
	$<$<BOOL:${WINDOWS}>:/SUBSYSTEM:WINDOWS>
	$<$<BOOL:${WINDOWS}>:/FIXED:NO>
)
target_link_libraries(${PROJECT} PRIVATE $<$<BOOL:${LINUX}>:dl>)
install(TARGETS ${PROJECT} DESTINATION .)
install(FILES ${SRCDIR}/linux/srcds_run DESTINATION . PERMISSIONS WORLD_EXECUTE)