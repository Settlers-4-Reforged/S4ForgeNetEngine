#include "pch.h"
#include "S4Values.h"
#include "S4Events.h"


int S4Events::GetDebugEventIndex() {
	DWORD* debugEventIndex = reinterpret_cast<DWORD*>(S4Values::GetS4() + 0xDB5A60);

	return *debugEventIndex;
}

List<S4Events::DebugEventQueue^>^ S4Events::GetAllDebugEventQueueEntries() {
	int index = GetDebugEventIndex();

	return nullptr;
}
