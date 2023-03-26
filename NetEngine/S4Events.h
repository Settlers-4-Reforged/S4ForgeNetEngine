#pragma once

using namespace System::Collections::Generic;

ref class S4Events {
public:
	ref struct DebugEventQueue {
		char* fmtString;
		void* a;
		void* b;
		void* c;
		void* d;
		void* e;
	};

	static int GetDebugEventIndex();

	static List<DebugEventQueue^>^ GetAllDebugEventQueueEntries();
};

