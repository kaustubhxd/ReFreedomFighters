// batch5726.cpp - unclaimed-57, band batch 26 (names GUESS).
// 0x5dd690 (thiscall, one stack arg dbread, ret 4): r = reader A(dbread) (0x4e5e60); sub = dword this+0x44; 0x47bde0(sub, r) (thiscall,
// one argument; unverified, hooked and logged in the spec).
// 0x5c7c80 (thiscall, two stack args (unused, dbread), ret 8): this+0x48 = reader S(dbread) (0x4e5ea0, returns a pointer); this+0x4c =
// word reader B(dbread) (0x4e5e40).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);   // reader A, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);   // reader B, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5ea0(u8 *dbread);   // reader S (pointer result), original code (hooked in the spec)
extern "C" void THISCALL ext_47bde0(u8 *self, u32 a);  // helper, original code (hooked and logged in the spec)

static void THISCALL unnamed5dd690(u8 *self, u8 *dbread) {
  u32 r = ext_4e5e60(dbread);
  u8 *sub = *(u8 **)(self + 0x44);
  ext_47bde0(sub, r);
}
PCREG(5dd690, unnamed5dd690);

static void THISCALL unnamed5c7c80(u8 *self, u32 unused, u8 *dbread) {
  (void)unused;
  *(u32 *)(self + 0x48) = ext_4e5ea0(dbread);
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(dbread);
}
PCREG(5c7c80, unnamed5c7c80);
