set(PROJECT vgui_surfacelib)

set(SOURCES
    BitmapFont.cpp
    FontAmalgam.cpp
    FontManager.cpp
    FontEffects.cpp
    $<$<BOOL:${WINDOWS}>:Win32Font.cpp> # [$WIN32 && !$X360]
    # Win32Font_x360.cpp	[$X360]
    # osxfont.cpp			[$OSXALL]
    $<$<BOOL:${LINUX}>:linuxfont.cpp> # [$LINUXALL]
)

add_library(${PROJECT} STATIC ${SOURCES})