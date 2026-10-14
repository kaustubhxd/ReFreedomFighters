// batch925.cpp - unclaimed-09 batch 17: 0x647380 (no GC name; docs/20-unclaimed-09.md, claim 17). thiscall, one stack
// argument (the save object), ret 4, returns true in al. Save calls are rec stubs; 0x644e30 is unverified (hooked).
#include "ff.h"

typedef void(THISCALL *SaveU32)(u8 *self, u32 v);

// 0x644e30 (thiscall, one argument; the spec hooks it). Its result is passed to the save object.
extern "C" u32 THISCALL ext_644e30(u8 *self, u32 a);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x647380 (GUESS name: none in the GC map): writes three header fields, then, for each of count elements (stride 0x38
// from this+0x99), four fields; then writes ext 0x644e30(this+0x28d, this+0x291) to sv; returns true.
static u8 THISCALL dump647380(u8 *self, u8 *sv) {
  ((SaveU32)slot(sv, 0x60))(sv, (u32)self[0x295]);
  ((SaveU32)slot(sv, 0x3c))(sv, *(u32 *)(self + 0x11));
  ((SaveU32)slot(sv, 0x3c))(sv, *(u32 *)(self + 0x69));
  ((SaveU32)slot(sv, 0x60))(sv, (u32)self[4]);
  if (*(u32 *)(self + 0x69)) {
    u32 i = 0;
    u8 *e = self + 0x99;
    do {
      ((SaveU32)slot(sv, 0x3c))(sv, *(u32 *)(e - 0x2c));
      ((SaveU32)slot(sv, 0x3c))(sv, *(u32 *)(e - 0x28));
      ((SaveU32)slot(sv, 0x68))(sv, (u32)e);
      ((SaveU32)slot(sv, 0x70))(sv, (u32)(e - 0x24));
      e += 0x38;
      i++;
    } while (i != *(u32 *)(self + 0x69));
  }
  u32 r = ext_644e30(*(u8 **)(self + 0x28d), *(u32 *)(self + 0x291));
  ((SaveU32)slot(sv, 0x44))(sv, r);
  return 1;
}
PCREG(647380, dump647380);
