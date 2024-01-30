set(PROJECT tier1)

set(SOURCES
    bitbuf.cpp
    newbitbuf.cpp
    byteswap.cpp
    characterset.cpp
    checksum_crc.cpp
    checksum_md5.cpp
    checksum_sha1.cpp
    commandbuffer.cpp
    convar.cpp
    datamanager.cpp
    diff.cpp
    generichash.cpp
    ilocalize.cpp
    interface.cpp
    KeyValues.cpp
    keyvaluesjson.cpp
    kvpacker.cpp
    lzmaDecoder.cpp
    lzss.cpp #[!$SOURCESDK]
    mempool.cpp
    memstack.cpp
    NetAdr.cpp
    splitstring.cpp
    $<$<BOOL:${WINDOWS}>:processor_detect.cpp> # [$WINDOWS||$X360]
    $<$<BOOL:${LINUX}>:processor_detect_linux.cpp>	# [$POSIX]
    $<$<BOOL:${LINUX}>:qsort_s.cpp>	# [$LINUXALL||$PS3]
    rangecheckedvar.cpp
    reliabletimer.cpp
    stringpool.cpp
    strtools.cpp
    strtools_unicode.cpp
    tier1.cpp
    tokenreader.cpp
    sparsematrix.cpp
    uniqueid.cpp
    utlbuffer.cpp
    utlbufferutil.cpp
    utlstring.cpp
    utlsymbol.cpp
    utlbinaryblock.cpp
    $<$<BOOL:${LINUX}>:pathmatch.cpp> # [$LINUXALL]
    snappy.cpp
    snappy-sinksource.cpp
    snappy-stubs-internal.cpp

    ${SRCDIR}/utils/lzma/C/LzmaDec.c
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE TIER1_STATIC_LIB)
target_link_libraries(${PROJECT} PRIVATE
    $<$<BOOL:${LINUX}>:dl>
    $<$<BOOL:${LINUX}>:Threads::Threads>
)