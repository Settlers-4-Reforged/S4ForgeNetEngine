#include "pch.h"
#include "S4Values.h"
#include "S4Events.h"


#include "NetEngineManager.h"

#include <functional>

#include "CGameHostCallbackHooks.h"
#include "INetworkEngineHooks.h"
#include "MinHook.h"

using namespace System::Diagnostics;
using namespace NetEngine::Hooks;


void NetEngine::NetEngineManager::Initialize() {
	Logger::LogInfo("Loading NetEngine...");

	NetS4ModApi^ api = gcnew NetS4ModApi();

	this->m_hooks = gcnew List<Hooks::IHook^>();

	this->InitializeHooks();

	Logger::LogInfo("Loaded NetEngine");
}

void NetEngine::NetEngineManager::InitializeHooks() {
	Logger::LogInfo("Loading NetEngine Hooks...");

	if FAILED(MH_Initialize()) {
		throw gcnew System::ApplicationException("Failed to load MinHook");
	}

	this->m_hooks->Add(gcnew CGameHostCallbackHooks());
	this->m_hooks->Add(gcnew INetworkEngineHooks());

	for(int i = 0; i < m_hooks->Count; i++) {
		m_hooks[i]->Init();
	}

	Logger::LogInfo("Loaded NetEngine Hooks");
}

