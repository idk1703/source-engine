set(PROJECT vstdlib)

set(SOURCES
    coroutine.cpp
    cvar.cpp
	jobthread.cpp
	KeyValuesSystem.cpp
	osversion.cpp
	$<$<BOOL:${WINDOWS}>:processutils.cpp>	# [$WINDOWS]
	random.cpp
	vcover.cpp

    ${SRCDIR}/public/tier0/memoverride.cpp
)

if(WINDOWS)
	enable_language(ASM_MASM)

	set(masm_srcs
		getstackptr64 # [$WIN64]
		coroutine_win64 # [$WIN64]
	)

	foreach(src ${masm_srcs})
		set(MASM_SRC ${CMAKE_CURRENT_SOURCE_DIR}/${src}.masm)
		set(MASM_OBJ ${CMAKE_CURRENT_BINARY_DIR}/${src}.obj)
		add_custom_command(
				OUTPUT ${MASM_OBJ}
				COMMAND ml64 /nologo /Fo ${MASM_OBJ} /c /Cx ${MASM_SRC}
				DEPENDS ${MASM_SRC}
				COMMENT "Assembling ${MASM_SRC}"
		)
		set(MASM_OBJECTS ${MASM_OBJECTS} ${MASM_OBJ})
	endforeach()
endif()

add_library(${PROJECT} SHARED ${SOURCES} $<$<BOOL:${WINDOWS}>:${MASM_OBJECTS}>)
target_compile_definitions(${PROJECT} PRIVATE
    VSTDLIB_DLL_EXPORT
)
target_include_directories(${PROJECT} PRIVATE
    ${SRCDIR}/soundemittersystem
    ${SRCDIR}/game/shared
)

target_link_libraries(${PROJECT} PRIVATE
    tier0 tier1
)
install(TARGETS ${PROJECT} DESTINATION bin)