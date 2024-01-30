set(PROJECT launcher_main)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT} ${SOURCES})
target_link_options(${PROJECT} PRIVATE
	$<$<BOOL:${WINDOWS}>:/SUBSYSTEM:WINDOWS>
	$<$<BOOL:${WINDOWS}>:/FIXED:NO>
)
target_compile_definitions(${PROJECT} PRIVATE
    $<$<BOOL:${WINDOWS}>:fopen=dont_use_fopen>
)
target_link_libraries(${PROJECT} PRIVATE $<$<BOOL:${LINUX}>:dl>)
install(TARGETS ${PROJECT} DESTINATION bin)