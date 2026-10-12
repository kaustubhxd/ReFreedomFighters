#include "ff.h"
// batch958.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x429a50 (field +0x71) and 0x429a80 (field +0xd). Thiscall, no
// arguments, returns al = 1. If the field is nonzero, call its vslot +0x20 with ecx = the object and one stack argument (the object,
// callee-cleaned). Re-read the field; if nonzero, call its vslot +8 the same way, then clear the field (4 bytes).

typedef u32(THISCALL *tc1)(u8 *, u32);

static u8 THISCALL zg429a50(u8 *self) {
  u8 *o = *(u8 **)(self + 0x71);
  if (o != 0) ((tc1)(*(u32 *)(*(u32 *)o + 0x20)))(o, (u32)o);
  o = *(u8 **)(self + 0x71);
  if (o != 0) {
    ((tc1)(*(u32 *)(*(u32 *)o + 8)))(o, (u32)o);
    *(u32 *)(self + 0x71) = 0;
  }
  return 1;
}
PCREG(429a50, zg429a50);

static u8 THISCALL zg429a80(u8 *self) {
  u8 *o = *(u8 **)(self + 0xd);
  if (o != 0) ((tc1)(*(u32 *)(*(u32 *)o + 0x20)))(o, (u32)o);
  o = *(u8 **)(self + 0xd);
  if (o != 0) {
    ((tc1)(*(u32 *)(*(u32 *)o + 8)))(o, (u32)o);
    *(u32 *)(self + 0xd) = 0;
  }
  return 1;
}
PCREG(429a80, zg429a80);
