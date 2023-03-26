#pragma once
#include "IHook.h"


namespace NetEngine::Hooks {
	ref class INetworkEngineHooks : public IHook{
	public:
		void Init() override;
	};
}

#define LIST_OF_NETWORK_ENGINE_HOOKS \
	X(SendNetGameEvent, 0x001A7A90) \
	X(SendNetEvent, 0x001A7990)