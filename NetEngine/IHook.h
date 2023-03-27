#pragma once

#include "Helper.h"
#include "minhook.h"
#include "S4Values.h"

namespace NetEngine::Hooks {
	ref  struct IHook abstract {
		virtual void Init() = 0;
	};
}

#pragma warning( push )
#pragma warning( disable : 4003 )

#define HOOK_INIT(name, _) { \
		Logger::LogInfo(System::String::Format("Hooking function: "#name)); \
		void* target = Get##name##Address(); \
		if FAILED(MH_CreateHook(target, &name##Hook, &name##Orig)) { \
			Logger::LogInfo("Failed to hook SearchSession"); \
		} \
		if FAILED(MH_EnableHook(target)) { \
			Logger::LogInfo("Failed to enable hook "#name); \
		} \
	}

#define HOOK_DEFINE(name, address) \
void* name##Orig; \
void __declspec(naked) name##Hook() { \
	_asm	push eax \
	_asm	push ecx \
	_asm	push edx \
	_asm	call name \
	_asm	pop edx \
	_asm	pop ecx \
	_asm	pop eax \
	_asm	jmp name##Orig \
}	 \
LPVOID* Get##name##Address() { \
	return reinterpret_cast<LPVOID*>(S4Values::GetS4() + address); \
}

#define HOOK_DEFINE_NAKED(name, address) \
void* name##Orig; \
void name##Hook();	 \
LPVOID* Get##name##Address() { \
	return reinterpret_cast<LPVOID*>(S4Values::GetS4() + address); \
}
