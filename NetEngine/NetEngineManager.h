#pragma once
#include "IHook.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace NetModAPI;
using namespace NetEngine::Hooks;

namespace NetEngine {
	public ref class NetEngineManager : IPlugin
	{
	private:
		List<Hooks::IHook^>^ m_hooks;

	public:
		virtual void Initialize();
		void InitializeHooks();
	};
}
