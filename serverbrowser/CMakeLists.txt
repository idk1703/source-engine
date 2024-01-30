set(PROJECT serverbrowser)

set(SOURCES
    BaseGamesPage.cpp
    BlacklistedServers.cpp
    CustomGames.cpp
    DialogAddServer.cpp
    DialogGameInfo.cpp
    DialogServerPassword.cpp
    FavoriteGames.cpp
    FriendsGames.cpp
    HistoryGames.cpp
    InternetGames.cpp
    LanGames.cpp
    ModList.cpp
    ServerBrowser.cpp
    ServerBrowserDialog.cpp
    ServerContextMenu.cpp
    ServerListCompare.cpp
    SpectateGames.cpp
    VACBannedConnRefusedDialog.cpp
    VACBannedConnRefusedDialog.h

    QuickListPanel.cpp

    ${SRCDIR}/public/vgui_controls/vgui_controls.cpp

    ${SRCDIR}/common/ServerBrowser/blacklisted_server_manager.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    VERSION_SAFE_STEAM_API_INTERFACES
    SERVERBROWSER_EXPORTS
    GAME_SRC
    # _USE_32BIT_TIME_T
)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/game/shared
)

target_link_libraries(${PROJECT} PRIVATE
    vgui_controls
    tier0 tier1 tier2 tier3
    mathlib
    vstdlib
    steam_api
)
install(TARGETS ${PROJECT} DESTINATION bin)