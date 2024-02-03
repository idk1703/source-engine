add_subdirectory(shaderapidx9)
add_subdirectory(shaderapiempty)
add_subdirectory(shaderlib)
add_subdirectory(stdshaders)

set(PROJECT materialsystem)

set(SOURCES
    CColorCorrection.cpp
    cmaterial.cpp
    cmaterial_queuefriendly.cpp
    CMaterialSubRect.cpp
    cmaterialvar.cpp
    cmatnullrendercontext.cpp
    colorspace.cpp
    ctexture.cpp
    ${SRCDIR}/public/filesystem_helpers.cpp
    imagepacker.cpp
    mat_stub.cpp
    materialsystem_global.cpp
    morph.cpp
    occlusionquerymgr.cpp
    shadersystem.cpp
    texturemanager.cpp

    pch_materialsystem.cpp

    cmaterialdict.cpp
    cmaterialsystem.cpp
    cmatlightmaps.cpp
    cmatrendercontext.cpp
    cmatqueuedrendercontext.cpp
    ctexturecompositor.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE DEFINE_MATERIALSYSTEM_INTERFACE MATERIALSYSTEM_EXPORTS PROTECTED_THINGS_ENABLE strncpy=use_Q_strncpy_instead _snprintf=use_Q_snprintf_instead)

target_link_libraries(${PROJECT} PRIVATE
    bitmap
    tier0 tier1 tier2 tier3
    vstdlib
    mathlib
    shaderlib
    vtf
    $<$<BOOL:${ENABLE_SDL}>:SDL2::SDL2>
)
install(TARGETS ${PROJECT} DESTINATION bin)