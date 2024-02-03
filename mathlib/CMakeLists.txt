set(PROJECT mathlib)

set(SOURCES
    color_conversion.cpp
    halton.cpp
    lightdesc.cpp
    mathlib_base.cpp
    powsse.cpp
    sparse_convolution_noise.cpp
    sseconst.cpp
    sse.cpp  # [$WINDOWS||$POSIX]
    ssenoise.cpp
    3dnow.cpp    #[$WINDOWS||$LINUX],
    anorms.cpp
    bumpvects.cpp
    IceKey.cpp
    imagequant.cpp
    polyhedron.cpp
    quantize.cpp
    randsse.cpp
    spherical.cpp
    simdvectormatrix.cpp
    vector.cpp
    vmatrix.cpp
    almostequal.cpp
)

add_library(${PROJECT} STATIC ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE MATHLIB_LIB)

target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/public/mathlib
)