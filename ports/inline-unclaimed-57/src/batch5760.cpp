// batch5760.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 60: 0x5da280 (GUESS name unnamed_5da280), thiscall, one stack
// argument (the DBREAD pointer, ret 4), returns nothing. Order: four dwords from 0x4e5e60(db) stored at this+0x56, +0x5a, +0x5e,
// +0x62; then 0x4e6180(db, this+0x66) (a float array reader; its result is not stored). Both readers run through the hooks in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *db);  // dword reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e6180(u8 *db, u8 *out);  // float array reader, original code (hooked in the spec)

// 0x5da280, thiscall, one stack argument (the DBREAD pointer), ret 4 (GUESS name)
static void THISCALL unnamed5da280(u8 *self, u8 *db) {
  *(u32 *)(self + 0x56) = ext_4e5e60(db);
  *(u32 *)(self + 0x5a) = ext_4e5e60(db);
  *(u32 *)(self + 0x5e) = ext_4e5e60(db);
  *(u32 *)(self + 0x62) = ext_4e5e60(db);
  ext_4e6180(db, self + 0x66);
}
PCREG(5da280, unnamed5da280);
