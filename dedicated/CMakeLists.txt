set(PROJECT dedicated)

set(SOURCES
	filesystem.cpp
	${SRCDIR}/public/filesystem_init.cpp
	${SRCDIR}/common/netapi.cpp
	${SRCDIR}/common/SteamAppStartup.cpp
	sys_common.cpp
	sys_ded.cpp
	$<$<BOOL:${WINDOWS}>:sys_windows.cpp> # [$WINDOWS]
	$<$<BOOL:${LINUX}>:sys_linux.cpp> # [$POSIX]

	console/conproc.cpp
	console/textconsole.cpp
	$<$<BOOL:${LINUX}>:console/TextConsoleUnix.cpp> # [$POSIX]
	$<$<BOOL:${WINDOWS}>:console/TextConsoleWin32.cpp> # [$WINDOWS]
	# vgui
	$<$<BOOL:${WINDOWS}>:${SRCDIR}/public/vgui_controls/vgui_controls.cpp>
	$<$<BOOL:${WINDOWS}>:vgui/CreateMultiplayerGameServerPage.cpp>
	$<$<BOOL:${WINDOWS}>:vgui/MainPanel.cpp>
	$<$<BOOL:${WINDOWS}>:vgui/vguihelpers.cpp>

	${SRCDIR}/filesystem/filetracker.cpp
	${SRCDIR}/filesystem/basefilesystem.cpp
	${SRCDIR}/filesystem/packfile.cpp
	${SRCDIR}/filesystem/filesystem_async.cpp
	${SRCDIR}/filesystem/filesystem_stdio.cpp
	${SRCDIR}/filesystem/QueuedLoader.cpp
	${SRCDIR}/public/zip_utils.cpp
	$<$<BOOL:${LINUX}>:${SRCDIR}/filesystem/linux_support.cpp>

	${SRCDIR}/public/tier0/memoverride.cpp

	${SRCDIR}/common/crypto_null.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE DEDICATED LAUNCHERONLY SUPPORT_PACKED_STORE)

target_link_libraries(${PROJECT} PRIVATE
	appframework
	vpklib
	tier0 tier1 tier2 tier3
	vstdlib
	mathlib
	$<$<BOOL:${WINDOWS}>:vgui_controls>
	$<$<BOOL:${LINUX}>:edit>
	$<$<BOOL:${WINDOWS}>:wsock32.lib odbc32.lib odbccp32.lib winmm.lib>
)
install(TARGETS ${PROJECT} DESTINATION bin)