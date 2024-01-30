set(PROJECT bitmap)

set(SOURCES
    ImageByteSwap.cpp
    colorconversion.cpp
    float_bm.cpp
    float_bm2.cpp
    float_bm3.cpp
    $<$<BOOL:${WINDOWS}>:float_bm4.cpp> # [$WINDOWS]
    float_bm_bilateral_filter.cpp
    float_cube.cpp
    imageformat.cpp
    psd.cpp
    resample.cpp
    tgaloader.cpp
    tgawriter.cpp
    bitmap.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_include_directories(${PROJECT} PRIVATE
    $<$<BOOL:${WINDOWS}>:${SRCDIR}/dx9sdk/include> # [$WINDOWS]
)