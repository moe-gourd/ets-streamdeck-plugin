#pragma once

//-------------------------------------------------------------------
// C++ headers
//-------------------------------------------------------------------

#include <winsock2.h>
#include <Windows.h>
#include <string>
#include <set>
#include <thread>
#include <strsafe.h>

//-------------------------------------------------------------------
// Debug logging
//-------------------------------------------------------------------

#ifdef _DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif

void __cdecl dbgprintf(const char* format, ...);

#if DEBUG
#define DebugPrint			dbgprintf
#else
#define DebugPrint(...)		while(0)
#endif

//-------------------------------------------------------------------
// websocketpp
//-------------------------------------------------------------------

#define ASIO_STANDALONE