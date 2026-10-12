// batch206.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Two wrappers around
// vtable calls: one on an argument object, one that goes through the render-manager object and then a vtable of this.
#include "ff.h"

typedef u32(THISCALL *SlotU32)(u8 *, u32);
typedef void(THISCALL *SlotVoid2)(u8 *, u32, u32);

// 0x5c5cf0, thiscall(a): [this+4] &= ~0x40; a->vtable[0x3c](a, [this+0x48]); r = a->vtable[0x44](a, [this+0x4c]);
// return (r & ~0xff) | 1 (the asm sets al = 1). Name GUESS.
static u32 THISCALL clearFlagCallTwo_5c5cf0(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  SlotU32 f3c = (SlotU32)(*(u32 *)(*(u32 *)a + 0x3c));
  f3c(a, *(u32 *)(self + 0x48));
  SlotU32 f44 = (SlotU32)(*(u32 *)(*(u32 *)a + 0x44));
  u32 r = f44(a, *(u32 *)(self + 0x4c));
  return (r & ~0xffu) | 1u;
}
PCREG(5c5cf0, clearFlagCallTwo_5c5cf0);

// 0x512e70, thiscall(a1, a2): obj = [[0x70039c] + 0x9b]; r = obj->vtable[0x58](obj, a2); this->vtable[0x30c](this, a1, r).
// Name GUESS.
static void THISCALL callViaRmThenSelf_512e70(u8 *self, u32 a1, u32 a2) {
  u8 *rm = *(u8 **)0x70039cu;
  u8 *obj = *(u8 **)(rm + 0x9b);
  SlotU32 f58 = (SlotU32)(*(u32 *)(*(u32 *)obj + 0x58));
  u32 r = f58(obj, a2);
  SlotVoid2 f30c = (SlotVoid2)(*(u32 *)(*(u32 *)self + 0x30c));
  f30c(self, a1, r);
}
PCREG(512e70, callViaRmThenSelf_512e70);
