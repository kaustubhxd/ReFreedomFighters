// batch4135.cpp - unclaimed-41 batch 35 (core-todo residue-19): 0x5c5cf0 ZFFSearchLightAddActors::Save(ZSaveGame*) (thiscall, one stack
// argument s, ret 4, returns al = 1). this+4 &= ~0x40; s.vt[0x3c](this+0x48); s.vt[0x44](this+0x4c).
#include "ff.h"

typedef u32(THISCALL * f1_t)(u8 *, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static u8 THISCALL fn5c5cf0(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((f1_t)vslot(s, 0x3c))(s, *(u32 *)(self + 0x48));
  ((f1_t)vslot(s, 0x44))(s, *(u32 *)(self + 0x4c));
  return 1;
}
PCREG(5c5cf0, fn5c5cf0);
