// batch2908.cpp - unclaimed-29: batch 8 (docs/20-unclaimed-29.md, claim 8, slice 8). Thiscall with two stack arguments (ret 8).
// No GC name for this address: the name is a GUESS and is only a label.
#include "ff.h"

typedef u32(THISCALL *VirtArg1)(u8 *self, u32 a);

static u32 vcall1(u8 *obj, u32 slot, u32 arg) {
  return ((VirtArg1)(*(const u32 *)(*(const u32 *)obj + slot)))(obj, arg);
}

// 0x439840 (GUESS name): p = this's slot +0x58 with the first argument. A mode of 0 at p calls slot +0x10 of the object at p-4
// with the second argument. A mode of 1 calls the function pointer at 0x7003b0 (no arguments), then walks the list at p+0xd: its
// slot +0x4c, then its slot +0x5c for the item and out flag; for each item, this's slot +0x58 with the item, then the list's
// slot +0x5c again while the flag is set. Any other mode does nothing.
static void THISCALL unknown439840(u8 *self, u32 a1, u32 a2) {
  u8 *p = (u8 *)vcall1(self, 0x58, a1);
  const u32 mode = *(const u32 *)p;
  if (mode == 0) {
    u8 *q = p - 4;
    vcall1(q, 0x10, a2);
    return;
  }
  if (mode != 1) return;
  typedef void(*PlainFn)(void);
  ((PlainFn)G(u32, 0x7003b0))();
  u8 *list = *(u8 **)(p + 0xd);
  if (!list) return;
  u32 out = 0;
  vcall1(list, 0x4c, (u32)&out);
  u32 item = vcall1(list, 0x5c, (u32)&out);
  if (!out) return;
  do {
    vcall1(self, 0x58, item);
    list = *(u8 **)(p + 0xd);
    item = vcall1(list, 0x5c, (u32)&out);
  } while (out);
}
PCREG(439840, unknown439840);
