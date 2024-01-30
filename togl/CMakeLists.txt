set(PROJECT togl)

set(SOURCES
    linuxwin/dx9asmtogl2.cpp
    linuxwin/dxabstract.cpp
    linuxwin/glentrypoints.cpp
    linuxwin/glmgr.cpp
    linuxwin/glmgrbasics.cpp
    # linuxwin/glmgrcocoa.mm	# [$OSXALL]
    # linuxwin/intelglmallocworkaround.cpp	# [$OSXALL]
    # linuxwin/mach_override.c	# [$OSXALL]
    linuxwin/cglmtex.cpp
    linuxwin/cglmfbo.cpp
    linuxwin/cglmprogram.cpp
    linuxwin/cglmbuffer.cpp
    linuxwin/cglmquery.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    TOGL_DLL_EXPORT PROTECTED_THINGS_ENABLE strncpy=use_Q_strncpy_instead _snprintf=use_Q_snprintf_instead
)

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2
    mathlib
    vstdlib
)
install(TARGETS ${PROJECT} DESTINATION bin)