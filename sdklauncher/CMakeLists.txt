set(PROJECT sdklauncher)

set(SOURCES
    ${SRCDIR}/common/ConfigManager.cpp
    ${SRCDIR}/common/SourceAppInfo.cpp
    configs.cpp
    CreateModWizard.cpp
    ${SRCDIR}/public/filesystem_init.cpp
    ${SRCDIR}/public/registry.cpp
    Main.cpp
    min_footprint_files.cpp
    ModConfigsHelper.cpp
    ModWizard_CopyFiles.cpp
    ModWizard_Finished.cpp
    ModWizard_GetModInfo.cpp
    ModWizard_Intro.cpp
    ModWizard_TemplateOptions.cpp
    ${SRCDIR}/public/registry.cpp
    SDKLauncherDialog.cpp
    ${SRCDIR}/public/vgui_controls/vgui_controls.cpp
)

add_executable(${PROJECT} ${SOURCES})
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/utils/common
)
target_compile_definitions(${PROJECT} PRIVATE VERSION_SAFE_STEAM_API_INTERFACES)