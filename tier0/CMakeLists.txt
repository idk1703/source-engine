set(PROJECT tier0)

set(SOURCES
    assert_dialog.cpp
    $<$<BOOL:${WINDOWS}>:assert_dialog.rc> # [$WINDOWS]
    commandline.cpp
    cpu.cpp
    cpumonitoring.cpp
    $<$<BOOL:${LINUX}>:cpu_posix.cpp> # [$POSIX]
    cpu_usage.cpp
    dbg.cpp
    dynfunction.cpp
    $<$<BOOL:${WINDOWS}>:etwprof.cpp> # [$WINDOWS]
    fasttimer.cpp
    # $<$<BOOL:${WINDOWS}>:InterlockedCompareExchange128.masm> # [$WIN64]
	mem.cpp
	mem_helpers.cpp
	memdbg.cpp
	memstd.cpp
	memvalidate.cpp
	minidump.cpp
	pch_tier0.cpp

	$<$<BOOL:${WINDOWS}>:platform.cpp>		# [$WINDOWS||$X360]
	$<$<BOOL:${LINUX}>:platform_posix.cpp>	# [$POSIX]
	# pmc360.cpp		[$X360]
	$<$<BOOL:${WINDOWS}>:pme.cpp>			# [$WINDOWS]
	$<$<BOOL:${LINUX}>:pme_posix.cpp>		# [$POSIX]
	PMELib.cpp		# [$WINDOWS||$POSIX]

	progressbar.cpp
	security.cpp
	systeminformation.cpp
	stacktools.cpp
	thread.cpp # [$WINDOWS||$POSIX]
	threadtools.cpp
	tier0_strtools.cpp
	tslist.cpp
	$<$<BOOL:${WINDOWS}>:vcrmode.cpp> # [$WINDOWS]
	$<$<BOOL:${LINUX}>:vcrmode_posix.cpp> # [$POSIX]
	vprof.cpp
	$<$<BOOL:${WINDOWS}>:win32consoleio.cpp> # [$WINDOWS]
	# $<$<BOOL:${LINUX}>:${SRCDIR}/tier1/pathmatch.cpp> # [$LINUXALL]

    $<$<BOOL:${LINUX}>:${SRCDIR}/public/tier0/memoverride.cpp>
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    TIER0_DLL_EXPORT
    # VERSION_SAFE_STEAM_API_INTERFACES
)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/soundemittersystem
    ${SRCDIR}/game/shared
)

target_link_libraries(${PROJECT} PRIVATE
    $<$<BOOL:${LINUX}>:rt>
    $<$<BOOL:${LINUX}>:dl>
    $<$<BOOL:${LINUX}>:Threads::Threads>
	$<$<BOOL:${WINDOWS}>:ws2_32.lib>
)
install(TARGETS ${PROJECT} DESTINATION bin)