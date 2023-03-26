#include "pch.h"
#include "CGameHostCallbackHooks.h"

using namespace NetModAPI;
using namespace System;
using namespace System::Runtime::InteropServices;

void __stdcall SearchSessions() {
	LOG_CALL();
}
void __stdcall AddNewClient(){
	LOG_CALL();
}
void __stdcall LeaveGameSession(){
	LOG_CALL();
}
void __stdcall NewGameSession(){
	LOG_CALL();
}
void __stdcall sub_1A2940(){
	LOG_CALL();
}
void __stdcall sub_19EDB0(){
	LOG_CALL();
}
void __stdcall sub_1A05A0(){
	LOG_CALL();
}
void __stdcall sub_19EDA0(){
	LOG_CALL();
}
void __stdcall sub_1A3B90(){
	LOG_CALL();
}
void __stdcall sub_1A3D40(){
	LOG_CALL();
}
void __stdcall sub_1A3F20(){
	LOG_CALL();
}
void __stdcall sub_1A42B0(){
	LOG_CALL();
}
void __stdcall sub_1A42C0(){
	LOG_CALL();
}
void __stdcall sub_1A4450(){
	LOG_CALL();
}
void __stdcall sub_1A44C0(){
	LOG_CALL();
}
void __stdcall sub_1A4560(){
	LOG_CALL();
}
void __stdcall sub_1A45E0(){
	LOG_CALL();
}
void __stdcall sub_1A46F0(){
	LOG_CALL();
}
//This gets called very often during Lobby host it seems...
void __stdcall sub_1A4A30(){
	//LOG_CALL();
	//Returns 1 in HE game code...
	//Maybe a connection/socket check that is handled elsewhere in Storm?
}
void __stdcall sub_19C2C0(){
	LOG_CALL();
}
void __stdcall sub_1A0740(){
	LOG_CALL();
}
void __stdcall sub_1A0920(){
	LOG_CALL();
}
void __stdcall sub_1A0C20(){
	LOG_CALL();
}
void __stdcall sub_1A1200(){
	LOG_CALL();
}
void __stdcall sub_1A17F0(){
	LOG_CALL();
}
void __stdcall sub_1A1FE0(){
	LOG_CALL();
}
void __stdcall sub_1A1470(){
	LOG_CALL();
}
void __stdcall sub_1A1520(){
	LOG_CALL();
}
void __stdcall sub_1A1530(){
	LOG_CALL();
}
void __stdcall sub_1A27E0(){
	LOG_CALL();
}
void __stdcall sub_1A26B0(){
	LOG_CALL();
}
void __stdcall sub_1A2750(){
	LOG_CALL();
}
void __stdcall sub_1A22B0(){
	LOG_CALL();
}
void __stdcall sub_1A0FB0(){
	LOG_CALL();
}
void __stdcall sub_1A4940(){
	LOG_CALL();
}
void __stdcall sub_1A3570(){
	LOG_CALL();
}
void __stdcall sub_1A35F0(){
	LOG_CALL();
}
void __stdcall sub_1A0580(){
	LOG_CALL();
}
void __stdcall sub_1A05C0(){
	LOG_CALL();
}
void __stdcall sub_1A19A0(){
	LOG_CALL();
}
void __stdcall sub_1A1D50(){
	LOG_CALL();
}
void __stdcall sub_1A1390(){
	LOG_CALL();
}
void __stdcall sub_1A1080(){
	LOG_CALL();
}
void __stdcall sub_1A1140(){
	LOG_CALL();
}
void __stdcall sub_1A2070(){
	LOG_CALL();
}
void __stdcall sub_19E350(){
	LOG_CALL();
}
void __stdcall sub_19E360(){
	LOG_CALL();
}
void __stdcall sub_1A5270(){
	LOG_CALL();
}
void __stdcall sub_1A4D20(){
	LOG_CALL();
}
void __stdcall sub_1A4DE0(){
	LOG_CALL();
}
void __stdcall sub_1A47C0(){
	LOG_CALL();
}
void __stdcall sub_1A4660(){
	LOG_CALL();
}




#define X HOOK_DEFINE
#pragma unmanaged
LIST_OF_C_GAME_HOST_HOOKS
#pragma managed
#undef X



void NetEngine::Hooks::CGameHostCallbackHooks::Init() {
	Logger::LogInfo("Init CGameHostCallbackHooks");
	
#define X HOOK_INIT
	LIST_OF_C_GAME_HOST_HOOKS
#undef X


}
