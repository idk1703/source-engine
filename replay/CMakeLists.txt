add_subdirectory(common)

set(PROJECT replay)

set(SOURCES
    baserecordingsession.cpp
    baserecordingsessionblock.cpp
    baserecordingsessionblockmanager.cpp
    baserecordingsessionmanager.cpp
    basethinker.cpp
    compression.cpp
    
    errorsystem.cpp
    
    ${SRCDIR}/common/netmessages.cpp
    replay_dbg.cpp
    replaysystem.cpp
    sessioninfoheader.cpp
    shared_cvars.cpp
    shared_replaycontext.cpp
    spew.cpp
    sv_basejob.cpp
    sv_commands.cpp
    sv_filepublish.cpp
    sv_fileservercleanup.cpp
    sv_cvars.cpp
    sv_publishtest.cpp
    sv_recordingsession.cpp
    sv_recordingsessionblock.cpp
    sv_recordingsessionmanager.cpp
    sv_recordingsessionblockmanager.cpp
    sv_replaycontext.cpp
    sv_sessionblockpublisher.cpp
    sv_sessioninfopublisher.cpp
    sv_sessionpublishmanager.cpp
    sv_sessionrecorder.cpp
    thinkmanager.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)
if(NOT DEDICATED)
    list(APPEND SOURCES
        cl_commands.cpp # [!$DEDICATED ]
        cl_cvars.cpp # [!$DEDICATED]
        cl_downloader.cpp # [!$DEDICATED]
        cl_recordingsession.cpp #[!$DEDICATED]
        cl_recordingsessionblock.cpp # [!$DEDICATED]
        cl_recordingsessionblockmanager.cpp # [!$DEDICATED]
        cl_recordingsessionmanager.cpp # [!$DEDICATED]
        cl_renderqueue.cpp #	[!$DEDICATED]
        cl_replaycontext.cpp # [!$DEDICATED]
        cl_replaymanager.cpp #[!$DEDICATED]
        cl_replaymovie.cpp #	[!$DEDICATED]
        cl_replaymoviemanager.cpp #	[!$DEDICATED]
        cl_performancecontroller.cpp #	[!$DEDICATED]
        cl_performancemanager.cpp #	[!$DEDICATED]
        cl_screenshotmanager.cpp #[!$DEDICATED]
        cl_sessionblockdownloader.cpp # [!$DEDICATED]
        cl_sessioninfodownloader.cpp # [!$DEDICATED]
        ${SRCDIR}/common/imageutils.cpp # [!$DEDICATED]
        managertest.cpp # [!$DEDICATED]
        replay_reconstructor.cpp # [!$DEDICATED]
    )
endif()

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE REPLAY_DLL REPLAY_ENABLED)

if(LINUX)
    find_package(CURL REQUIRED)
endif()

find_package(ZLIB REQUIRED)
# find_package(OpenSSL REQUIRED)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(BZip2 REQUIRED)

target_link_libraries(${PROJECT} PRIVATE
    bitmap
    tier0 tier1 tier2 tier3
    mathlib
    replay_common
    vstdlib
    vtf
    $<$<BOOL:${LINUX}>:CURL::libcurl>
    $<$<BOOL:${LINUX}>:rt>
    ${LIBLZMA_LIBRARIES}
    BZip2::BZip2
    ZLIB::ZLIB
    # OpenSSL::Crypto
    $<$<NOT:$<BOOL:${DEDICATED}>>:JPEG::JPEG>
    ${PNG_LIBRARIES}
)
install(TARGETS ${PROJECT} DESTINATION bin)