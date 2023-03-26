#pragma once
#include "IHook.h"

namespace NetEngine::Hooks {
	ref class CGameHostCallbackHooks : public IHook {
	private:


	public:
		void Init() override;
	};
}



#define LIST_OF_C_GAME_HOST_HOOKS \
  X(SearchSessions, 0x1A05E0) \
  X(AddNewClient, 0x1A3FC0) \
  X(LeaveGameSession, 0x1A1070) \
  X(NewGameSession, 0x19E1E0) \
  X(sub_1A2940, 0x1A2940) \
  X(sub_19EDB0, 0x19EDB0) \
  X(sub_1A05A0, 0x1A05A0) \
  X(sub_19EDA0, 0x19EDA0) \
  X(sub_1A3B90, 0x1A3B90) \
  X(sub_1A3D40, 0x1A3D40) \
  X(sub_1A3F20, 0x1A3F20) \
  X(sub_1A42B0, 0x1A42B0) \
  X(sub_1A42C0, 0x1A42C0) \
  X(sub_1A4450, 0x1A4450) \
  X(sub_1A44C0, 0x1A44C0) \
  X(sub_1A4560, 0x1A4560) \
  X(sub_1A45E0, 0x1A45E0) \
  X(sub_1A46F0, 0x1A46F0) \
  X(sub_1A4A30, 0x1A4A30) \
  X(sub_19C2C0, 0x19C2C0) \
  X(sub_1A0740, 0x1A0740) \
  X(sub_1A0920, 0x1A0920) \
  X(sub_1A0C20, 0x1A0C20) \
  X(sub_1A1200, 0x1A1200) \
  X(sub_1A17F0, 0x1A17F0) \
  X(sub_1A1FE0, 0x1A1FE0) \
  X(sub_1A1470, 0x1A1470) \
  X(sub_1A1520, 0x1A1520) \
  X(sub_1A1530, 0x1A1530) \
  X(sub_1A27E0, 0x1A27E0) \
  X(sub_1A26B0, 0x1A26B0) \
  X(sub_1A2750, 0x1A2750) \
  X(sub_1A22B0, 0x1A22B0) \
  X(sub_1A0FB0, 0x1A0FB0) \
  X(sub_1A4940, 0x1A4940) \
  X(sub_1A3570, 0x1A3570) \
  X(sub_1A35F0, 0x1A35F0) \
  X(sub_1A0580, 0x1A0580) \
  X(sub_1A05C0, 0x1A05C0) \
  X(sub_1A19A0, 0x1A19A0) \
  X(sub_1A1D50, 0x1A1D50) \
  X(sub_1A1390, 0x1A1390) \
  X(sub_1A1080, 0x1A1080) \
  X(sub_1A1140, 0x1A1140) \
  X(sub_1A2070, 0x1A2070) \
  X(sub_19E350, 0x19E350) \
  X(sub_19E360, 0x19E360) \
  X(sub_1A5270, 0x1A5270) \
  X(sub_1A4D20, 0x1A4D20) \
  X(sub_1A4DE0, 0x1A4DE0) \
  X(sub_1A47C0, 0x1A47C0) \
  X(sub_1A4660, 0x1A4660) 
