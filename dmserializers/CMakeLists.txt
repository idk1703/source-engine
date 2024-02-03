set(PROJECT dmserializers)

set(SOURCES
    dmebaseimporter.cpp
    dmserializers.cpp
    importactbusy.cpp
    importkeyvaluebase.cpp
    importsfmv1.cpp
    importsfmv2.cpp
    importsfmv3.cpp
    importsfmv4.cpp
    importsfmv5.cpp
    importsfmv6.cpp
    importsfmv7.cpp
    importsfmv8.cpp
    importsfmv9.cpp
    importvmf.cpp
    importvmt.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE DMSERIALIZERS_LIB)