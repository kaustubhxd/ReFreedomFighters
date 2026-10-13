// batch4136.cpp - unclaimed-41 batch 36 (core-todo residue-19): 0x4c5cb0 ZFollowShape::Save(ZSaveGame*) (thiscall, one stack argument s,
// ret 4, returns al = 1). this+4 &= ~0x40; s.vt[0x44](dword this+0x5a); s.vt[0x60](byte this+0x66); s.vt[0x44](dword this+0x67);
// s.vt[0x54](dword this+0x4c).
#include "ff.h"

typedef u32(THISCALL * f1_t)(u8 *, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static u8 THISCALL fn4c5cb0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((f1_t)vslot(s, 0x44))(s, *(u32 *)(self + 0x5a));
  ((f1_t)vslot(s, 0x60))(s, (u32)self[0x66]);
  ((f1_t)vslot(s, 0x44))(s, *(u32 *)(self + 0x67));
  ((f1_t)vslot(s, 0x54))(s, *(u32 *)(self + 0x4c));
  return 1;
}
PCREG(4c5cb0, fn4c5cb0);
