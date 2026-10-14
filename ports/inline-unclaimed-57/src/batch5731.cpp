// batch5731.cpp - unclaimed-57, band batch 31 (names GUESS).
// 0x5c7ce0 (thiscall, no args, returns this): 0x469870(this) (hooked, logged); dword this+4 |= 0x20; dword this+0x44 = 0; vtable 0x6b4858;
//   dword this+0x4c = 0.
// 0x5ddad0 (thiscall, one stack arg dbread, ret 4): float this+0x54 = reader B(dbread) (0x4e5e80, float in st0); float this+0x58 =
//   reader B(dbread) again. Reader B is unverified, hooked in the spec with a per-call counter.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);            // unverified, original code (logged in the spec)
extern "C" float THISCALL ext_4e5e80(u8 *dbread);         // reader B (float in st0), original code (hooked in the spec)

static u8 *THISCALL unnamed5c7ce0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b4858;
  *(u32 *)(self + 0x4c) = 0;
  return self;
}
PCREG(5c7ce0, unnamed5c7ce0);

static void THISCALL unnamed5ddad0(u8 *self, u8 *dbread) {
  *(float *)(self + 0x54) = ext_4e5e80(dbread);
  *(float *)(self + 0x58) = ext_4e5e80(dbread);
}
PCREG(5ddad0, unnamed5ddad0);
