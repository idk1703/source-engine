set(PROJECT filesystem_stdio)

set(SOURCES
    basefilesystem.cpp
    packfile.cpp
    filetracker.cpp
    filesystem_async.cpp
    $<$<BOOL:${LINUX}>:linux_support.cpp> # [$POSIX]
    QueuedLoader.cpp
    ${SRCDIR}/public/kevvaluescompiler.cpp
    ${SRCDIR}/public/zip_utils.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE FILESYSTEM_STDIO_EXPORTS DONT_PROTECT_FILEIO_FUNCTIONS PROTECTED_THINGS_ENABLE)

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1 tier2
    vstdlib
    $<$<BOOL:${LINUX}>:Threads::Threads>
)
install(TARGETS ${PROJECT} DESTINATION bin)