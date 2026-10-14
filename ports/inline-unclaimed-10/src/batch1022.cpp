// batch1022.cpp - unclaimed-10, batch 18 (docs/20-unclaimed-10.md): CMAINCAMERACONTROL::CopyEventDataBlock(DBREAD&) (0x4fc0d0),
// thiscall, one argument (the DBREAD), ret 4. Stores: dword +0x78 = reader A(DBREAD); word +0x7c, +0x7e, +0x80, +0x82 = reader B
// (DBREAD), each in turn; dword +0x6e = reader A(DBREAD) again. Readers A (0x4e5e60) and B (0x4e5e40) are unverified, run as
// original code through ext_ (hooked with fixed results in the spec).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);  // reader A, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);  // reader B, original code (hooked in the spec)

// 0x4fc0d0, CMAINCAMERACONTROL::CopyEventDataBlock(DBREAD&) (high)
static void THISCALL cameraControlCopyEventDataBlock(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x78) = ext_4e5e60(dbread);
  *(u16 *)(self + 0x7c) = (u16)ext_4e5e40(dbread);
  *(u16 *)(self + 0x7e) = (u16)ext_4e5e40(dbread);
  *(u16 *)(self + 0x80) = (u16)ext_4e5e40(dbread);
  *(u16 *)(self + 0x82) = (u16)ext_4e5e40(dbread);
  *(u32 *)(self + 0x6e) = ext_4e5e60(dbread);
}
PCREG(4fc0d0, cameraControlCopyEventDataBlock);
