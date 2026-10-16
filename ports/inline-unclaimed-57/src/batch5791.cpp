// batch5791.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 91: 0x5d9810 (GUESS name unnamed_5d9810), thiscall, one stack argument db
// (ret 4), no return value. Order: thirteen dword reads 0x4e5e60(db) (ECX = db), each stored at this+0x48, +0x4c, +0x50, +0x54, +0x58,
// +0x5c, +0x60, +0x68, +0x6c, +0x70, +0x74, +0x78, +0x7c (+0x64 is skipped). The reader runs as a hooked stub in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)

// 0x5d9810, thiscall, one stack argument (GUESS name)
static void THISCALL unnamed5d9810(u8 *self, u8 *db) {
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  *(u32 *)(self + 0x4c) = ext_4e5e60(db);
  *(u32 *)(self + 0x50) = ext_4e5e60(db);
  *(u32 *)(self + 0x54) = ext_4e5e60(db);
  *(u32 *)(self + 0x58) = ext_4e5e60(db);
  *(u32 *)(self + 0x5c) = ext_4e5e60(db);
  *(u32 *)(self + 0x60) = ext_4e5e60(db);
  *(u32 *)(self + 0x68) = ext_4e5e60(db);
  *(u32 *)(self + 0x6c) = ext_4e5e60(db);
  *(u32 *)(self + 0x70) = ext_4e5e60(db);
  *(u32 *)(self + 0x74) = ext_4e5e60(db);
  *(u32 *)(self + 0x78) = ext_4e5e60(db);
  *(u32 *)(self + 0x7c) = ext_4e5e60(db);
}
PCREG(5d9810, unnamed5d9810);
