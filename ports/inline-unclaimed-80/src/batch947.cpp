#include "ff.h"
// batch947.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x49f670 (high). Thiscall, no stack arguments, returns this.
// Copies the 16-byte constant at 0x67a290 to this+0x804 and this+0x814; sets eight dwords this+0x824..0x840 to 1.0f. Then
// r = (vslot +0x138 of the object at [g+0x9b], g = [0x70039c]); out = 0; r vslot +0x88(0x681320, &out); this[0] = out.
// Both virtual calls are callee-cleaned (nothing is popped after them in the exe), so each is a plain thiscall of the slot.

typedef u32(THISCALL *tc0)(u8 *);
typedef u32(THISCALL *tc2)(u8 *, u32, u32);

static u8 *THISCALL zgroupInitTable(u8 *self) {
  const u32 *cv = (const u32 *)0x67a290;
  for (int i = 0; i < 4; i++) {
    *(u32 *)(self + 0x804 + 4 * i) = cv[i];
    *(u32 *)(self + 0x814 + 4 * i) = cv[i];
  }
  for (int i = 0; i < 8; i++) *(u32 *)(self + 0x824 + 4 * i) = 0x3f800000;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r = (u8 *)((tc0)(*(u32 *)(*(u32 *)obj + 0x138)))(obj);
  u32 out = 0;
  ((tc2)(*(u32 *)(*(u32 *)r + 0x88)))(r, 0x681320, (u32)&out);
  *(u32 *)self = out;
  return self;
}
PCREG(49f670, zgroupInitTable);
