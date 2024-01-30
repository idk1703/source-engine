set(PROJECT vgui2)

set(SOURCES
    Bitmap.cpp
    Border.cpp
    ScalableImageBorder.cpp
    ImageBorder.cpp
    fileimage.cpp
    ${SRCDIR}/public/filesystem_helpers.cpp
    ${SRCDIR}/public/filesystem_init.cpp
    InputWin32.cpp
    LocalizedStringTable.cpp
    MemoryBitmap.cpp
    MessageListener.cpp
    Scheme.cpp
    $<$<BOOL:${WINDOWS}>:Surface.cpp> #	[$WIN32]
    $<$<BOOL:${WINDOWS}>:System.cpp> #  [$WINDOWS||$X360]
    $<$<BOOL:${LINUX}>:system_posix.cpp> # [$POSIX]
    ${SRCDIR}/public/UnicodeFileHelpers.cpp
    vgui.cpp
    vgui_internal.cpp
    vgui_key_translation.cpp
    VPanel.cpp
    VPanelWrapper.cpp
    keyrepeat.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    DONT_PROTECT_FILEIO_FUNCTIONS
)
target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2 tier3
    vstdlib
    $<$<BOOL:${ENABLE_SDL}>:SDL2::SDL2>
)
install(TARGETS ${PROJECT} DESTINATION bin)