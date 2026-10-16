// batch6507.cpp - unclaimed-65: batch 7 (docs/20-unclaimed-65.md, claim 7). Thiscall, no stack arguments. The name is a GUESS.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);
typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);

static u32 vcall1(u8 *o, u32 slot, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + slot)))(o, a); }
static u32 vcall2(u8 *o, u32 slot, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + slot)))(o, a, b); }
static u32 vcall3(u8 *o, u32 slot, u32 a, u32 b, u32 c) { return ((F3)(*(const u32 *)(*(const u32 *)o + slot)))(o, a, b, c); }

// 0x4c35e0, GUESS FUN_4c35e0: the list at +0x48 gives its first item (slot +0x5c, out flag after slot +0x4c). While the flag is set,
// the render object's slot +0x58 takes the item; a zero result sends the list's slot +0x44 with the flag. A nonzero result r goes
// through r's slot +0x10c (0x693e10, 0x64) to s; s's slot +0x5c (1, r, 0) and s's slot +0x84 ([this+0x44], this). Then the next
// item from the list's slot +0x5c.
static void THISCALL unknown4c35e0(u8 *self) {
  u8 *list = *(u8 **)(self + 0x48);
  if (!list) return;
  u32 out = 0;
  vcall1(list, 0x4c, (u32)&out);
  u32 item = vcall1(list, 0x5c, (u32)&out);
  if (!out) return;
  do {
    u8 *render = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    const u32 r = vcall1(render, 0x58, item);
    if (!r) {
      vcall1(*(u8 **)(self + 0x48), 0x44, (u32)&out);
    } else {
      u8 *s = (u8 *)vcall2((u8 *)r, 0x10c, 0x693e10, 0x64);
      vcall3(s, 0x5c, 1, r, 0);
      vcall2(s, 0x84, *(const u32 *)(self + 0x44), (u32)self);
    }
    item = vcall1(*(u8 **)(self + 0x48), 0x5c, (u32)&out);
  } while (out);
}
PCREG(4c35e0, unknown4c35e0);
