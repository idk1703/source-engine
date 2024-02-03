set(PROJECT tier2)

set(SOURCES
    beamsegdraw.cpp
    defaultfilesystem.cpp
    dmconnect.cpp
    fileutils.cpp
    keybindings.cpp
    ${SRCDIR}/public/map_utils.cpp
    ${SRCDIR}/public/materialsystem/MaterialSystemUtil.cpp
    camerautils.cpp
    meshutils.cpp
    # p4helpers.cpp
    renderutils.cpp
    riff.cpp
    soundutils.cpp
    tier2.cpp
    util_init.cpp
    utlstreambuffer.cpp
    vconfig.cpp
    keyvaluesmacros.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})