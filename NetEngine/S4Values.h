#pragma once

namespace S4Values {
	static DWORD GetS4() {
		return reinterpret_cast<DWORD>(GetModuleHandle(nullptr));
	}
};

