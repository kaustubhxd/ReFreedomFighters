// batch90000.cpp - hard trial opus2 batch 90000: 0x5af350 ZFFInventoryBridge::GetNoOf(EFFItemType) (switch through a jump table).
#include "ff.h"

extern "C" u32 THISCALL ext_5af3a0(u8 *self, u32 type);   // ret 4: count for item types 12, 13
extern "C" u32 THISCALL ext_5af430(u8 *self, u32 type);   // ret 4: count for item types 14, 15, 16

// 0x5af350, thiscall(type) ret 4: jump table at 0x5af380 indexed by type - 12 (5 entries, unsigned range check);
// both targets tail-jump with ECX and the argument unchanged, any other type returns 0.
static u32 THISCALL fn5af350(u8 *self, u32 type) {
  switch (type) {
  case 12:
  case 13:
    return ext_5af3a0(self, type);
  case 14:
  case 15:
  case 16:
    return ext_5af430(self, type);
  default:
    return 0;
  }
}
PCREG(5af350, fn5af350);
