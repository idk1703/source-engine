set(PROJECT appframework)

set(SOURCES
    AppSystemGroup.cpp
    ${SRCDIR}/public/filesystem_init.cpp
    $<$<BOOL:${WINDOWS}>:vguimatsysapp.cpp>
    $<$<BOOL:${WINDOWS}>:winapp.cpp>
    $<$<BOOL:${LINUX}>:posixapp.cpp>
    $<$<BOOL:${ENABLE_SDL}>:sdlmgr.cpp>
)

add_library(${PROJECT} STATIC ${SOURCES})