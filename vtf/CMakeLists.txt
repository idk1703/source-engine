set(PROJECT vtf)

set(SOURCES
    convert_x360.cpp
    $<$<BOOL:${WINDOWS}>:s3tc_decode.cpp> 	# [$WINDOWS]
    vtf.cpp
    # vtf_x360.cpp		# [$X360]
)

add_library(${PROJECT} STATIC ${SOURCES})