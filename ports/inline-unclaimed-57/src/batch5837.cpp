// batch5837.cpp - residue 9, 0x4fc0d0 (CMAINCAMERACONTROL::CopyEventDataBlock(DBREAD&), gc name map), thiscall, one stack argument (DBREAD&), ret 4.
// this+0x78 = A(db); this+0x7c, +0x7e, +0x80, +0x82 (words) = B(db) each; this+0x6e = A(db). A = 0x4e5e60 (dword), B = 0x4e5e40 (word in ax); both thiscall, ecx = db.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);  // reader A (dword), original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e40(u8 *dbread);  // reader B (word in ax), original code (hooked in the spec)

// 0x4fc0d0, thiscall, one stack argument (CMAINCAMERACONTROL::CopyEventDataBlock)
static void THISCALL unnamed4fc0d0(u8 *self, u8 *db) {
  *(u32 *)(self + 0x78) = ext_4e5e60(db);
  *(u16 *)(self + 0x7c) = (u16)ext_4e5e40(db);
  *(u16 *)(self + 0x7e) = (u16)ext_4e5e40(db);
  *(u16 *)(self + 0x80) = (u16)ext_4e5e40(db);
  *(u16 *)(self + 0x82) = (u16)ext_4e5e40(db);
  *(u32 *)(self + 0x6e) = ext_4e5e60(db);
}
PCREG(4fc0d0, unnamed4fc0d0);
