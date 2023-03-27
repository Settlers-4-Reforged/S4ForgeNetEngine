#include "pch.h"
#include "INetworkEngineHooks.h"


using namespace NetModAPI;
using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged
#pragma pack(push, 1)
struct alignas(1) CEvn_Event {
	void* __vftable /*VFT*/;
	int event;
	int wparam;
	int lparam;
	DWORD eventEngineAttribute;
	DWORD unknown;
};

 struct alignas(1) CLogic_Event {
	 CEvn_Event cEvent;
	 DWORD field_18;
	 WORD field_1C;
	 BYTE owner;
	 BYTE field_1F;
	 WORD field_20;
	 __int16 field_22;
	 unsigned __int8 owner2;
};
#pragma pack(pop)
#pragma managed


//Seems to be called for every in game net event:
void SendNetGameEvent(void *edx, void *ecx, CLogic_Event* logicEvent,void *eax ) {
	//LOG_CALL();

	Logger::LogInfo(String::Format("Sent NetEvent: Owner:{0}, EventId:{1}, wParam:{2}, lParam:{3}", logicEvent->owner, logicEvent->cEvent.event, logicEvent->cEvent.wparam, logicEvent->cEvent.lparam));
}

//Seldomly called:
void SendNetEvent() {
	LOG_CALL();
}

void ProcessNetGameEvent(void* edx, void* ecx, CLogic_Event* logicEvent, void* eax) {
	LOG_CALL();

	//TODO: differentiate between local call and global call
	//Maybe from "owner" field?

	if (logicEvent->cEvent.event == 5025) {//Build building
		WORD x = logicEvent->cEvent.lparam & 0xFF;
		WORD y = (logicEvent->cEvent.lparam >> 0x10) & 0xFF;

		Logger::LogInfo(String::Format("Received 'NewBuilding' Event at x:{0}, y:{1}", x, y));
	}

	Logger::LogInfo(String::Format("Received NetEvent: Owner:{0}, EventId:{1}, wParam:{2}, lParam:{3}", logicEvent->owner, logicEvent->cEvent.event, logicEvent->cEvent.wparam, logicEvent->cEvent.lparam));
}

#define X HOOK_DEFINE
#define Y HOOK_DEFINE_NAKED
#pragma unmanaged
LIST_OF_NETWORK_ENGINE_HOOKS

void __declspec(naked) SendNetGameEventHook() {
	_asm	push eax
	_asm	mov eax, [esp + 0x8] //first argument
	_asm	push eax
	_asm	push ecx
	_asm	push edx
	_asm	call SendNetGameEvent
	_asm	pop edx
	_asm	pop ecx
	_asm	pop eax //ignored
	_asm	pop eax
	_asm	jmp SendNetGameEventOrig
}

void __declspec(naked) ProcessNetGameEventHook() {
	_asm	push eax
	_asm	mov eax, [esp + 0x8] //first argument
	_asm	push eax
	_asm	push ecx
	_asm	push edx
	_asm	call ProcessNetGameEvent
	_asm	pop edx
	_asm	pop ecx
	_asm	add esp, 4
	//_asm	pop eax //ignored
	_asm	pop eax
	_asm	jmp ProcessNetGameEventOrig
}
#pragma managed
#undef X
#undef Y

void NetEngine::Hooks::INetworkEngineHooks::Init() {

#define X HOOK_INIT
#define Y HOOK_INIT
	LIST_OF_NETWORK_ENGINE_HOOKS
#undef X
#undef Y
}
