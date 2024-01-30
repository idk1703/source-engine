set(PROJECT AdminServer)

set(SOURCES
    AdminServer/AdminServer.cpp
    AdminServer/BanContextMenu.cpp
    AdminServer/ConfigPanel.cpp
    AdminServer/GamePanelInfo.cpp
    AdminServer/MapCycleEditDialog.cpp
    common/msgbuffer.cpp
    AdminServer/PlayerContextMenu.cpp
    AdminServer/PlayerListCompare.cpp
    AdminServer/RemoteServer.cpp
    AdminServer/VarEditDialog.cpp
    AdminServer/VarListPropertyPage.cpp
    ${SRCDIR}/common/vgui/vgui_basebudgetpanel.cpp
    ${SRCDIR}/common/vgui/vgui_budgetbargraphpanel.cpp
    ${SRCDIR}/common/vgui/vgui_budgethistorypanel.cpp
    ${SRCDIR}/common/vgui/vgui_budgetpanelshared.cpp
    ${SRCDIR}/public/vgui_controls/vgui_controls.cpp
    #Utils
    AdminServer/TokenLine.cpp
    #Generic Dialogs
    AdminServer/DialogAddBan.cpp
    AdminServer/DialogCvarChange.cpp
    #Pages
    AdminServer/BanPanel.cpp
    AdminServer/BudgetPanelContainer.cpp
    AdminServer/ChatPanel.cpp
    AdminServer/GraphPanel.cpp
    AdminServer/PlayerPanel.cpp
    AdminServer/RawLogPanel.cpp
    AdminServer/ServerConfigPanel.cpp
    AdminServer/serverinfopanel.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    ADMINSERVER_EXPORTS BUDGET_ADMIN_SERVER
)
target_include_directories(${PROJECT} PRIVATE
    common
)

target_link_libraries(${PROJECT} PRIVATE
    vgui_controls
    tier0 tier1 tier2 tier3
    mathlib
    vstdlib
)
install(TARGETS ${PROJECT} DESTINATION bin)