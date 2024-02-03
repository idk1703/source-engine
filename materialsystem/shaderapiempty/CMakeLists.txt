set(PROJECT shaderapiempty)

set(SOURCES
    shaderapiempty.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE SHADER_DLL_EXPORT PROTECTED_THINGS_ENABLE)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/materialsystem
)
target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1
)
install(TARGETS ${PROJECT} DESTINATION bin)