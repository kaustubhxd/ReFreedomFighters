// batch5776.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 76: 0x5c2f90 (GUESS name unnamed_5c2f90), thiscall, no stack args,
// plain ret. Order: if this+4 == 0 return; for i = 0; i < this+0x2c0 (re-read each step); i++: ent = this+0x14+14*i;
// t1 = (0x5b0b70(ECX = this+4, ent[-8]) != 0); if t1 == ent[0]: t2 = (0x5b0b70(ECX = this+4, ent[-4]) != 0); if t2 == ent[1]:
// 0x5c2c10(ECX = this, i). Both callees are other areas' code and run as hooked stubs in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_5b0b70(u8 *self, u32 a);  // one-argument test, original code (hooked in the spec)
extern "C" void THISCALL ext_5c2c10(u8 *self, u32 i);  // per-entry action, original code (hooked in the spec)

// 0x5c2f90, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5c2f90(u8 *self) {
  if (*(u32 *)(self + 4) == 0) return;
  for (s32 i = 0; i < (s32)*(u32 *)(self + 0x2c0); i++) {
    u8 *ent = self + 0x14 + 0xe * i;
    u8 t1 = ext_5b0b70((u8 *)(unsigned long)*(u32 *)(self + 4), *(u32 *)(ent - 8)) != 0;
    if (t1 == *ent) {
      u8 t2 = ext_5b0b70((u8 *)(unsigned long)*(u32 *)(self + 4), *(u32 *)(ent - 4)) != 0;
      if (t2 == *(ent + 1)) ext_5c2c10(self, (u32)i);
    }
  }
}
PCREG(5c2f90, unnamed5c2f90);
