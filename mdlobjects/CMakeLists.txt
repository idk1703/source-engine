set(PROJECT mdlobjects)

set(SOURCES
    dmebodygroup.cpp
    dmebodygrouplist.cpp
    dmecollisionmodel.cpp
    dmehitbox.cpp
    dmehitboxset.cpp
    dmebodypart.cpp
    dmeblankbodypart.cpp
    dmelod.cpp
    dmelodlist.cpp
    dmemdllist.cpp
    dmeboneweight.cpp
    dmebonemask.cpp
    dmebonemasklist.cpp
    dmesequence.cpp
    dmesequencelist.cpp
    dmeboneflexdriver.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE MDLOBJECTS_LIB)