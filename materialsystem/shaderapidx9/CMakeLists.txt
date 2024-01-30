set(PROJECT shaderapidx9)

set(SOURCES
    colorformatdx8.cpp
    ${SRCDIR}/public/filesystem_helpers.cpp
    hardwareconfig.cpp
    meshbase.cpp
    meshdx8.cpp
    $<$<BOOL:${WINDOWS}>:recording.cpp>								#[$WIN32 && !$GL]
    shaderapidx8.cpp
    shaderdevicebase.cpp
    shaderapibase.cpp
    shaderdevicedx8.cpp
    shadershadowdx8.cpp
    texturedx8.cpp
    TransitionTable.cpp
    cvballoctracker.cpp
    vertexdecl.cpp
    vertexshaderdx8.cpp
    $<$<BOOL:${WINDOWS}>:wmi.cpp>									#[$WIN32 && !$GL]
    # textureheap.cpp							#[$X360]
    $<$<BOOL:${LINUX}>:winutils.cpp>							#[!$WIN32]

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
    SHADERAPIDX9
    SHADER_DLL_EXPORT
    PROTECTED_THINGS_ENABLE
    strncpy=use_Q_strncpy_instead
    _snprintf=use_Q_snprintf_instead
)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/materialsystem
)
target_link_libraries(${PROJECT} PRIVATE
    bitmap
    tier0 tier1 tier2
    mathlib
    vstdlib
    $<$<BOOL:ENABLE_GL>:togl>
)
install(TARGETS ${PROJECT} DESTINATION bin)