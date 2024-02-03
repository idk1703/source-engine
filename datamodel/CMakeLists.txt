set(PROJECT datamodel)

set(SOURCES
    clipboardmanager.cpp
    datamodel.cpp
    dependencygraph.cpp
    dmattribute.cpp
    dmelement.cpp
    dmelementdictionary.cpp
    dmelementfactoryhelper.cpp
    DmElementFramework.cpp
    dmserializerbinary.cpp
    dmserializerkeyvalues.cpp
    dmserializerkeyvalues2.cpp
    undomanager.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE DATAMODEL_LIB)