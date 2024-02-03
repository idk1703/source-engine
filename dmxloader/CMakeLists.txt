set(PROJECT dmxloader)

set(SOURCES
    dmxattribute.cpp
    dmxelement.cpp
    dmxloader.cpp
    dmxloadertext.cpp
    dmxserializationdictionary.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE DMXLOADER_LIB)