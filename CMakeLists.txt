cmake_minimum_required(VERSION 3.25)

project(hl2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_GL "Enable OpenGL" 1)
option(ENABLE_SDL "Enable SDL" 1)
option(DEDICATED "Build dedicated" 0)
option(SUPPRESS_WARNINGS "Disable all warnings" 0)

set(SRCDIR ${CMAKE_CURRENT_LIST_DIR})

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_definitions(-D_DEBUG -DDEBUG)
else()
	add_definitions(-DNDEBUG)
endif()

add_definitions(-D_LIB_PREFIX=${CMAKE_SHARED_LIBRARY_PREFIX})

if(UNIX AND NOT APPLE)
	set(LINUX 1)
	set(WINDOWS 0)
	add_definitions(
		-DNO_X360_XDK
		-D_GLIBCXX_USE_CXX11_ABI=0
		-DLINUX
		-D_LINUX
		-DPOSIX
		-D_POSIX
		-DPLATFORM_POSIX
		-DGNUC
		-DNO_HOOK_MALLOC
		-D_LIB_EXT=.so
		-DPLATFORM_64BITS
		-DFRAME_POINTER_OMISSION_DISABLED
		-DRAD_TELEMETRY_DISABLED
	)
	set(CMAKE_POSITION_INDEPENDENT_CODE ON)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic")

	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")
	if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "(AMD64|x86_64)")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2 -march=core2")
	endif()
	set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")
	if(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	   add_compile_options(-fdiagnostics-color=always)
	elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	   add_compile_options(-fcolor-diagnostics)
	endif()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-offsetof -Wno-null-dereference")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-inconsistent-missing-override -Wno-unknown-pragmas -Wno-overloaded-virtual")
	set(THREADS_PREFER_PTHREAD_FLAG ON)
	find_package(Threads REQUIRED)
	if(SUPPRESS_WARNINGS)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
	endif()
elseif(WIN32)
	set(WINDOWS 1)
	set(LINUX 0)
	add_definitions(
		-DNO_X360_XDK
		-D_WINDOWS
		-D_WIN32
		-DWIN64
		-D_WIN64
		-DCOMPILER_MSVC
		-DCOMPILER_MSVC64
		-D_LIB_EXT=.dll
		-D_CRT_SECURE_NO_DEPRECATE
		-D_CRT_NONSTDC_NO_DEPRECATE
		-D_ALLOW_RUNTIME_LIBRARY_MISMATCH
		-D_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
		-D_ALLOW_MSC_VER_MISMATCH
		-DFRAME_POINTER_OMISSION_DISABLED
		-DRAD_TELEMETRY_DISABLED
	)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /GF /fp:fast /Zc:forScope /Zc:wchar_t /GR /FC /EHsc")
	if($<CONFIG:Debug>)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Od /MTd")
	elseif($<CONFIG:Release>)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O2 /Ob2 /Oi /Ot /MT /Gy")
	endif()

	add_link_options(
		$<$<CONFIG:Debug>:/INCREMENTAL>
		$<$<CONFIG:Debug>:/FORCE:MULTIPLE>
		$<$<CONFIG:Release>:/INCREMENTAL:NO>
		$<$<CONFIG:Release>:/OPT:REF>
		/NODEFAULTLIB:libc
		/NODEFAULTLIB:libcd
		/NODEFAULTLIB:libcmt
		/NODEFAULTLIB:libcmtd
	)
	if(SUPPRESS_WARNINGS)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /w")
	endif()
endif()

if(DEDICATED)
	add_definitions(-DDEDICATED)
	add_definitions(-DSWDS)
	set(ENABLE_SDL 0)
	set(ENABLE_GL 0)
endif()

if(ENABLE_GL)
	add_definitions(
		-DDX_TO_GL_ABSTRACTION
		-DGL_GLEXT_PROTOTYPES
		-DBINK_VIDEO
	)
endif()

if(ENABLE_SDL)
	add_definitions(-DUSE_SDL)
	find_package(SDL2 REQUIRED)
endif()

include_directories(
	common
	public
	public/tier0
	public/tier1
	public/tier2
	public/tier3
	thirdparty
	thirdparty/steamworks-sdk/public
)

add_subdirectory(appframework)
add_subdirectory(bitmap)
add_subdirectory(choreoobjects)
add_subdirectory(datacache)
add_subdirectory(datamodel)
add_subdirectory(dedicated)
add_subdirectory(dedicated_main)
add_subdirectory(dmserializers)
add_subdirectory(dmxloader)
add_subdirectory(engine)
add_subdirectory(fgdlib)
add_subdirectory(filesystem)
add_subdirectory(game)
add_subdirectory(gameui)
# add_subdirectory(hammer) # win only
# add_subdirectory(hammer_launcher) # win only
add_subdirectory(inputsystem)
add_subdirectory(launcher)
add_subdirectory(launcher_main)
add_subdirectory(materialsystem)
add_subdirectory(mathlib)
add_subdirectory(mdllib)
add_subdirectory(mdlobjects)
# add_subdirectory(movieobjects)
# add_subdirectory(networksystem) # win only
add_subdirectory(particles)
add_subdirectory(raytrace)
add_subdirectory(replay)
add_subdirectory(scenefilecache)
# add_subdirectory(sdklauncher) # win only
add_subdirectory(serverbrowser)
# add_subdirectory(sfmobjects) # win only
add_subdirectory(soundemittersystem)
# add_subdirectory(soundsystem) # win only
add_subdirectory(studiorender)
add_subdirectory(tier0)
add_subdirectory(tier1)
add_subdirectory(tier2)
add_subdirectory(tier3)
add_subdirectory(togl)
# add_subdirectory(tools) # sometime
add_subdirectory(tracker)
# add_subdirectory(unicode) # win only
add_subdirectory(unitlib)
# add_subdirectory(unittests) # sometime
# add_subdirectory(utils) # sometime
add_subdirectory(vgui2)
add_subdirectory(vguimatsurface)
add_subdirectory(video)
# add_subdirectory(vphysics)
# add_subdirectory(vphysics_jolt)
add_subdirectory(vpklib)
add_subdirectory(vstdlib)
add_subdirectory(vtf)

add_subdirectory(steam_api_null)