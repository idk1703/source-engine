set(PROJECT vguimatsurface)

set(SOURCES
    Clip2D.cpp
    Cursor.cpp
    ${SRCDIR}/public/filesystem_helpers.cpp
    FontTextureCache.cpp
    Input.cpp
    MatSystemSurface.cpp
    $<$<BOOL:${WINDOWS}>:memorybitmap.cpp> #[$WIN32]
    TextureDictionary.cpp
    ${SRCDIR}/vgui2/src/vgui_key_translation.cpp
    ${SRCDIR}/public/vgui_controls/vgui_controls.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE BENCHMARK VGUIMATSURFACE_DLL_EXPORT GAMEUI_EXPORTS DONT_PROTECT_FILEIO_FUNCTIONS PROTECTED_THINGS_ENABLE)

if(LINUX)
	find_package(Freetype REQUIRED)
	find_package(Fontconfig REQUIRED)
endif()

target_link_libraries(${PROJECT} PRIVATE
    bitmap
    vgui_controls
    vgui_surfacelib
    tier0 tier1 tier2 tier3
    mathlib
    vstdlib
    $<$<BOOL:${LINUX}>:Freetype::Freetype>
    $<$<BOOL:${LINUX}>:Fontconfig::Fontconfig>
    $<$<BOOL:${ENABLE_SDL}>:SDL2::SDL2>
)
install(TARGETS ${PROJECT} DESTINATION bin)