// batch5772.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 72: 0x5ddea0 (GUESS name unnamed_5ddea0), thiscall, one stack
// argument (the DBREAD pointer db, ret 4), no return value. Order: floats from 0x4e5e80(db) stored at this+0x48, +0x4c, +0x50;
// 0x4e6180(db, this+0x54) (float array reader; its result is not stored); then this+0x54, +0x58 and +0x5c are each divided by 255.0f.
// The readers run as hooked stubs in the spec.
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(u8 *db);  // float reader, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e6180(u8 *db, u8 *out);  // float array reader, original code (hooked in the spec)

// 0x5ddea0, thiscall, one stack argument (the DBREAD pointer), ret 4 (GUESS name)
static void THISCALL unnamed5ddea0(u8 *self, u8 *db) {
  *(float *)(self + 0x48) = ext_4e5e80(db);
  *(float *)(self + 0x4c) = ext_4e5e80(db);
  *(float *)(self + 0x50) = ext_4e5e80(db);
  ext_4e6180(db, self + 0x54);
  *(float *)(self + 0x54) = *(float *)(self + 0x54) / 255.0f;
  *(float *)(self + 0x58) = *(float *)(self + 0x58) / 255.0f;
  *(float *)(self + 0x5c) = *(float *)(self + 0x5c) / 255.0f;
}
PCREG(5ddea0, unnamed5ddea0);
