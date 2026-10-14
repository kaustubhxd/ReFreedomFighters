// batch5725.cpp - unclaimed-57, band batch 25 (names GUESS): two thiscall functions with one stack argument (a DBREAD), ret 4.
// 0x5d3ac0: this+0x4c = reader A(dbread) (0x4e5e60); this+0x50 = float reader B(dbread) (0x4e5e80).
// 0x5d6e60: this+0x48 = float reader B(dbread); this+0x4c = float reader B(dbread) again.
// The readers (ECX = dbread, no stack args) are unverified callees, hooked in the spec with per-call counters in the DBREAD object.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *dbread);    // reader A, original code (hooked in the spec)
extern "C" float THISCALL ext_4e5e80(u8 *dbread);  // reader B (float in st0), original code (hooked in the spec)

static void THISCALL unnamed5d3ac0(u8 *self, u8 *dbread) {
  *(u32 *)(self + 0x4c) = ext_4e5e60(dbread);
  *(float *)(self + 0x50) = ext_4e5e80(dbread);
}
PCREG(5d3ac0, unnamed5d3ac0);

static void THISCALL unnamed5d6e60(u8 *self, u8 *dbread) {
  *(float *)(self + 0x48) = ext_4e5e80(dbread);
  *(float *)(self + 0x4c) = ext_4e5e80(dbread);
}
PCREG(5d6e60, unnamed5d6e60);
