//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
// $NoKeywords: $
//=============================================================================

#ifndef STEAMTYPES_H
#define STEAMTYPES_H

#include <cstdint>

#ifdef _WIN32
#pragma once
#endif

// Steam-specific types. Defined here so this header file can be included in other code bases.
#ifndef WCHARTYPES_H
typedef unsigned char uint8;
#endif
#ifndef uint16
typedef unsigned short uint16;
#endif
#ifndef int32
typedef int32_t int32;
#endif
#ifndef uint32
typedef uint32_t uint32;
#endif
#ifndef int64
typedef int64_t int64;
#endif
#ifndef uint64
typedef uint64_t uint64;
#endif

#ifndef NETADR_H
class netadr_t;
#endif

#endif // STEAMTYPES_H