#ifdef LINUX
#define S_API extern "C" __attribute__((visibility("default")))
#else
#define S_API extern "C" __declspec(dllexport)
#endif

S_API void *g_pSteamClientGameServer;
void *g_pSteamClientGameServer = nullptr;

S_API bool SteamAPI_Init()
{
	return true;
}

S_API bool SteamAPI_InitSafe()
{
	return true;
}

S_API void SteamAPI_Shutdown()
{
}

S_API bool SteamAPI_RestartAppIfNecessary()
{
	return false;
}

S_API void SteamAPI_ReleaseCurrentThreadMemory()
{
}

S_API void SteamAPI_WriteMiniDump()
{
}

S_API void SteamAPI_SetMiniDumpComment()
{
}

S_API void SteamAPI_RunCallbacks()
{
}

S_API void SteamAPI_RegisterCallback()
{
}

S_API void SteamAPI_UnregisterCallback()
{
}

S_API void SteamAPI_RegisterCallResult()
{
}

S_API void SteamAPI_UnregisterCallResult()
{
}

S_API bool SteamAPI_IsSteamRunning()
{
	return false;
}

S_API void Steam_RunCallbacks()
{
}

S_API void Steam_RegisterInterfaceFuncs()
{
}

S_API int Steam_GetHSteamUserCurrent()
{
	return 0;
}

S_API const char *SteamAPI_GetSteamInstallPath()
{
	return nullptr;
}

S_API int SteamAPI_GetHSteamPipe()
{
	return 0;
}

S_API void SteamAPI_SetTryCatchCallbacks()
{
}

S_API void SteamAPI_SetBreakpadAppID()
{
}

S_API void SteamAPI_UseBreakpadCrashHandler()
{
}

S_API int GetHSteamPipe()
{
	return 0;
}

S_API int GetHSteamUser()
{
	return 0;
}

S_API int SteamAPI_GetHSteamUser()
{
	return 0;
}

S_API void *SteamInternal_ContextInit()
{
	return nullptr;
}

S_API void *SteamInternal_CreateInterface()
{
	return nullptr;
}

S_API void *SteamApps()
{
	return nullptr;
}

S_API void *SteamClient()
{
	return nullptr;
}

S_API void *SteamFriends()
{
	return nullptr;
}

S_API void *SteamHTTP()
{
	return nullptr;
}

S_API void *SteamMatchmaking()
{
	return nullptr;
}

S_API void *SteamMatchmakingServers()
{
	return nullptr;
}

S_API void *SteamNetworking()
{
	return nullptr;
}

S_API void *SteamRemoteStorage()
{
	return nullptr;
}

S_API void *SteamScreenshots()
{
	return nullptr;
}

S_API void *SteamUser()
{
	return nullptr;
}

S_API void *SteamUserStats()
{
	return nullptr;
}

S_API void *SteamUtils()
{
	return nullptr;
}

S_API int SteamGameServer_GetHSteamPipe()
{
	return 0;
}

S_API int SteamGameServer_GetHSteamUser()
{
	return 0;
}

S_API int SteamGameServer_GetIPCCallCount()
{
	return 0;
}

S_API int SteamGameServer_InitSafe()
{
	return 0;
}

S_API void SteamGameServer_RunCallbacks()
{
}

S_API void SteamGameServer_Shutdown()
{
}