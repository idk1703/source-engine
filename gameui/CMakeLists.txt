set(PROJECT gameui)

set(SOURCES
	BackgroundMenuButton.cpp
	BasePanel.cpp
	GameConsole.cpp
	GameUI_Interface.cpp
	$<$<BOOL:${WINDOWS}>:LogoFile.cpp> # [!$POSIX]
	ModInfo.cpp
	MouseMessageForwardingPanel.cpp
	$<$<BOOL:${WINDOWS}>:${SRCDIR}/tracker/common/msgbuffer.cpp> # [!$POSIX]
	$<$<BOOL:${WINDOWS}>:${SRCDIR}/tracker/common/netapi.cpp> # [!$POSIX]
	${SRCDIR}/common/GameUI/ObjectList.cpp
	PanelListPanel.cpp
	RunGameEngine.cpp
	${SRCDIR}/common/GameUI/scriptobject.cpp
	$<$<BOOL:${WINDOWS}>:${SRCDIR}/tracker/common/Socket.cpp> # [!$POSIX]
	Sys_Utils.cpp
	TextEntryBox.cpp
	TGAImagePanel.cpp
	${SRCDIR}/public/vgui_controls/vgui_controls.cpp
	VGuiSystemModuleLoader.cpp
	BonusMapsDatabase.cpp
	${SRCDIR}/common/language.cpp
	${SRCDIR}/common/imageutils.cpp
	SaveGameBrowserDialog.cpp
	gameui_util.cpp
	#Controls
	BitmapImagePanel.cpp
	CommandCheckButton.cpp
	CvarNegateCheckButton.cpp
	${SRCDIR}/common/GameUI/cvarslider.cpp
	CvarTextEntry.cpp
	CvarToggleCheckButton.cpp
	HapticControlBox.cpp
	KeyToggleCheckButton.cpp
	LabeledCommandComboBox.cpp
	URLButton.cpp
	vcontrolslistpanel.cpp
	# Dialogs
	BenchmarkDialog.cpp
	BonusMapsDialog.cpp
	CommentaryDialog.cpp
	CommentaryExplanationDialog.cpp
	ContentControlDialog.cpp
	CustomTabExplanationDialog.cpp
	GameConsoleDialog.cpp
	LoadGameDialog_Xbox.cpp
	LoadGameDialog.cpp
	MultiplayerAdvancedDialog.cpp
	NewGameDialog.cpp
	PlayerListDialog.cpp
	SaveGameDialog_Xbox.cpp
	SaveGameDialog.cpp
	LoadCommentaryDialog.cpp
	LoadingDialog.cpp
	BaseSaveGameDialog.cpp
	$<$<BOOL:${WINDOWS}>:ChangeGameDialog.cpp> # [!$POSIX]
	CreateMultiplayerGameBotPage.cpp
	CreateMultiplayerGameDialog.cpp
	CreateMultiplayerGameGameplayPage.cpp
	CreateMultiplayerGameServerPage.cpp
	OptionsDialog_Xbox.cpp
	ControllerDialog.cpp
	#Matchmaking
	matchmaking/achievementsdialog.cpp
	matchmaking/basedialog.cpp
	matchmaking/dialogmenu.cpp
	matchmaking/leaderboarddialog.cpp
	matchmaking/matchmakingbasepanel.cpp
	matchmaking/pausedialog.cpp
	matchmaking/sessionlobbydialog.cpp
	matchmaking/sessionoptionsdialog.cpp
	matchmaking/sessionbrowserdialog.cpp
	matchmaking/welcomedialog.cpp
	#Options Dialog
	OptionsDialog.cpp
	OptionsSubAudio.cpp
	OptionsSubDifficulty.cpp
	OptionsSubGame.cpp
	$<$<BOOL:${WINDOWS}>:OptionsSubHaptics.cpp> #	[$WIN32]
	OptionsSubKeyboard.cpp
	OptionsSubMouse.cpp
	OptionsSubMultiplayer.cpp
	OptionsSubPortal.cpp
	OptionsSubVideo.cpp
	OptionsSubVoice.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE GAMEUI_EXPORTS VERSION_SAFE_STEAM_API_INTERFACES)
target_include_directories(${PROJECT} PRIVATE
	${SRCDIR}/vgui2/include
	${SRCDIR}/vgui2/controls
	${SRCDIR}/common/GameUI
	${SRCDIR}/gameui
)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
target_link_libraries(${PROJECT} PRIVATE
	bitmap
	vgui_controls
	matsys_controls
    tier0 tier1 tier2 tier3
	mathlib
	vstdlib
    vtf
	steam_api
	JPEG::JPEG
	PNG::PNG
    $<$<BOOL:${LINUX}>:rt>
	$<$<BOOL:${ENABLE_SDL}>:SDL2::SDL2>
)
install(TARGETS ${PROJECT} DESTINATION bin)