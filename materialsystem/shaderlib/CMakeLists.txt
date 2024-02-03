set(PROJECT shaderlib)

set(SOURCES
    BaseShader.cpp
    ShaderDLL.cpp
    shaderlib_cvar.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE FAST_MATERIALVAR_ACCESS)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/materialsystem
)