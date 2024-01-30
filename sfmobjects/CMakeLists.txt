set(PROJECT sfmobjects)

set(SOURCES
    exportfacialanimation.cpp
    flexcontrolbuilder.cpp
    sfmsession.cpp
    sfmanimationsetutils.cpp
    sfmphonemeextractor.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE SFMOBJECTS_LIB)