set(PROJECT vlocalize)

set(SOURCES
    CreateTokenDialog.cpp
    LocalizationDialog.cpp
    main.cpp
    ${SRCDIR}/public/vgui_controls/vgui_controls.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_executable(${PROJECT} ${SOURCES})

target_link_libraries(${PROJECT} PRIVATE
    appframework
    vgui_controls
    tier0 tier1 tier2 tier3
    mathlib
    vstdlib
)