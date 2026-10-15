// batch90001.cpp - hard-function trial (fable), batch 90001: 0x5af350 ZFFInventoryBridge::GetNoOf(EFFItemType) (jump table).
#include "ff.h"

extern "C" u32 THISCALL ext_5af3a0(void *, u32);   // ret 4 (verified s1): count of one item type
extern "C" u32 THISCALL ext_5af430(void *, u32);   // ret 4 (verified unclaimed-22): count by iterating the inventory (SEH frame inside)

// 0x5af350, thiscall(t) ret 4. Jump table at 0x5af380 indexed by t - 0xc (unsigned, 5 entries):
// 0xc, 0xd -> tail jump 0x5af3a0(t); 0xe, 0xf, 0x10 -> tail jump 0x5af430(t); anything else -> 0.
static u32 THISCALL fn5af350(u8 *E, u32 t) {
  switch (t) {
    case 0xc:
    case 0xd:
      return ext_5af3a0(E, t);
    case 0xe:
    case 0xf:
    case 0x10:
      return ext_5af430(E, t);
    default:
      return 0;
  }
}
PCREG(5af350, fn5af350);
