#include "pch.h"
#include "INetworkEngineHooks.h"


using namespace NetModAPI;
using namespace System;
using namespace System::Runtime::InteropServices;

//Seems to be called for every in game net event:
void SendNetGameEvent() {
	LOG_CALL();
}

//Seldomly called:
void SendNetEvent() {
	LOG_CALL();
}

#define X HOOK_DEFINE
#pragma unmanaged
LIST_OF_NETWORK_ENGINE_HOOKS
#pragma managed
#undef X

void NetEngine::Hooks::INetworkEngineHooks::Init() {

#define X HOOK_INIT
	LIST_OF_NETWORK_ENGINE_HOOKS
#undef X
}
