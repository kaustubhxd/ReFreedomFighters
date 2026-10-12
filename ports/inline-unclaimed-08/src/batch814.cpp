// batch814.cpp - unclaimed-08 batch 14: CBoxAutoFire::Init(ZGEOM*, DBREAD&) (high). Slice: floor(addr/16) mod 20 = 7.
// Thiscall, two stack arguments (ret 8). The first argument (the geometry) is not read. The DBREAD readers are called as
// the original calls them: 0x4e5e80 (float) -> this+0x48; 0x4e5e60 (dword) -> this+0x50, this+0x54, then the call through
// 0x7003b0 (no argument), then 0x4e5e60 -> this+0x58. Then this+0x4c = (float)(sys+0x40 as a signed int) * 1/1024;
// finally the word returned by the engine db's vtable +0x114 (0x682e18, 0, 0x6b53ac, 0x18) goes to this+0x60.
// The readers and the 0x7003b0 function are unverified: the spec stubs them (see docs/20-unclaimed-08.md).
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(void *);
extern "C" u32 THISCALL ext_4e5e60(void *);

static const float kTickToSec = 0.0009765625f;  // 0x6785e4

// 0x5d4af0, CBoxAutoFire::Init(ZGEOM*, DBREAD&) (high).
static void THISCALL boxAutoFireInit(u8 *self, void *geom, void *dbread) {
  (void)geom;
  *(float *)(self + 0x48) = ext_4e5e80(dbread);
  *(u32 *)(self + 0x50) = ext_4e5e60(dbread);
  *(u32 *)(self + 0x54) = ext_4e5e60(dbread);
  void (*hook)() = *(void (**)())0x7003b0;
  hook();
  *(u32 *)(self + 0x58) = ext_4e5e60(dbread);
  u8 *sys = *(u8 **)0x70039c;
  *(float *)(self + 0x4c) = (float)*(s32 *)(sys + 0x40) * kTickToSec;
  u8 *db = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  *(u16 *)(self + 0x60) = (u16)vcall<u32>(db, 0x114, (u32)0x682e18, (u32)0, (u32)0x6b53ac, (u32)0x18);
}
PCREG(5d4af0, boxAutoFireInit);
