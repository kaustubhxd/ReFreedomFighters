// batch5754.cpp - unclaimed-57, band batch 54 (names GUESS): two thiscall functions with one stack argument (a DBREAD), ret 4.
// 0x5c65e0: this+0x48 = reader A(db); this+0x4c = reader A(db); this+0x50 = reader S(db) (pointer).
// 0x5d6240: this+0x50 = reader A(db); this+0x5a = reader A(db); byte this+0x7a = (reader A(db) != 0).
// Readers: A = 0x4e5e60 (dword), S = 0x4e5ea0 (pointer); unverified, hooked in the spec. DBREAD is the argument (ECX for the readers).
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);  // reader A, original code (hooked in the spec)
extern "C" u32 THISCALL ext_4e5ea0(u8 *dbread);  // reader S, original code (hooked in the spec)

static void THISCALL unnamed5c65e0(u8 *self, u8 *db) {
  *(u32 *)(self + 0x48) = ext_4e5e60(db);
  *(u32 *)(self + 0x4c) = ext_4e5e60(db);
  *(u32 *)(self + 0x50) = ext_4e5ea0(db);
}
PCREG(5c65e0, unnamed5c65e0);

static void THISCALL unnamed5d6240(u8 *self, u8 *db) {
  *(u32 *)(self + 0x50) = ext_4e5e60(db);
  *(u32 *)(self + 0x5a) = ext_4e5e60(db);
  self[0x7a] = (u8)(ext_4e5e60(db) != 0);
}
PCREG(5d6240, unnamed5d6240);
