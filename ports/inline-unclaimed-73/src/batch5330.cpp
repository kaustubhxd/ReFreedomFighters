// batch5330.cpp - area 73 batch 53 (gap band, GUESS names): FUN_4e6bc0, FUN_4e42a0, FUN_4f2190, FUN_4f21c0.
#include "ff.h"

// 0x4e6bc0 (GUESS FUN_4e6bc0): ret 0, returns a dword. The inverse of FUN_4e6bf0: returns 0 when the cursor (this+0x10)
// equals this+8; otherwise reads the word at that index of the array at this+4, advances the cursor and returns
// this+0xc * word + this[0].
static u32 THISCALL guess4e6bc0(u8 *self) {
  u32 i = *(u32 *)(self + 0x10);
  if (i == *(u32 *)(self + 8))
    return 0;
  u16 *arr = *(u16 **)(self + 4);
  u32 w = arr[i];
  *(u32 *)(self + 0x10) = i + 1;
  return *(u32 *)(self + 0xc) * w + *(u32 *)self;
}
PCREG(4e6bc0, guess4e6bc0);

// 0x4e42a0 (GUESS FUN_4e42a0): ret 4. Links the argument node at the front of the list at this+0xc: node.next = old head,
// the old head's +4 = node, node.prev = 0, head = node, node+0x18 = this.
static void THISCALL guess4e42a0(u8 *self, u32 node) {
  u32 head = *(u32 *)(self + 0xc);
  if (head)
    *(u32 *)(head + 4) = node;
  *(u32 *)node = head;
  *(u32 *)(node + 4) = 0;
  *(u32 *)(self + 0xc) = node;
  *(u32 *)(node + 0x18) = (u32)self;
}
PCREG(4e42a0, guess4e42a0);

// 0x4f2190 (GUESS FUN_4f2190): plain ret. When the byte at this+0x5f9 is set, vtable slot +0x6c is called on the object at
// g_sys+0x1907 and the byte is cleared.
static void THISCALL guess4f2190(u8 *self) {
  if (!self[0x5f9])
    return;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
  vcall<void>(obj, 0x6c);
  self[0x5f9] = 0;
}
PCREG(4f2190, guess4f2190);

// 0x4f21c0 (GUESS FUN_4f21c0): plain ret. When the byte at this+0x5f9 is clear, vtable slot +0x68 is called on the object at
// g_sys+0x1907 and the byte is set.
static void THISCALL guess4f21c0(u8 *self) {
  if (self[0x5f9])
    return;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
  vcall<void>(obj, 0x68);
  self[0x5f9] = 1;
}
PCREG(4f21c0, guess4f21c0);
