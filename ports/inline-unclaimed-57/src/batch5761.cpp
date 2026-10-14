// batch5761.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 61: 0x5d5ea0 (GUESS name unnamed_5d5ea0), thiscall, one stack
// argument (the DBREAD pointer db, ret 4), no return value. Order: floats from 0x4e5e80(db) stored at this+0x48, +0x54, +0x58;
// dwords from 0x4e5e60(db) stored at this+0x5e, +0x62, +0x66. The readers run as hooked stubs in the spec.
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(u8 *db);  // float reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)

// 0x5d5ea0, thiscall, one stack argument (the DBREAD pointer), ret 4 (GUESS name)
static void THISCALL unnamed5d5ea0(u8 *self, u8 *db) {
  *(float *)(self + 0x48) = ext_4e5e80(db);
  *(float *)(self + 0x54) = ext_4e5e80(db);
  *(float *)(self + 0x58) = ext_4e5e80(db);
  *(u32 *)(self + 0x5e) = ext_4e5e60(db);
  *(u32 *)(self + 0x62) = ext_4e5e60(db);
  *(u32 *)(self + 0x66) = ext_4e5e60(db);
}
PCREG(5d5ea0, unnamed5d5ea0);
