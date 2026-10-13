// batch4115.cpp - unclaimed-41 batch 15 (slice 13): 0x523710 (name not in the map; GUESS, serialization sequence).
#include "ff.h"

static void call1(u8 *o, u32 slot, u32 a) {
  typedef void(THISCALL * f_t)(u8 *, u32);
  (*(f_t *)(*(u32 *)o + slot))(o, a);
}
static void call2(u8 *o, u32 slot, u32 a, u32 b) {
  typedef void(THISCALL * f_t)(u8 *, u32, u32);
  (*(f_t *)(*(u32 *)o + slot))(o, a, b);
}
static u32 call1r(u8 *o, u32 slot, u32 a) {
  typedef u32(THISCALL * f_t)(u8 *, u32);
  return (*(f_t *)(*(u32 *)o + slot))(o, a);
}

// 0x523710 (GUESS name): thiscall, one stack argument (the stream s, ret 4), returns al = 1. The sequence (this = self):
// s.[+0x50](self+4); s.[+0x6c](self+8); s.[+0x50] at self+0x20, +0x24, +0x28, +0x2c, +0x30; s.[+0x68](self+0x34);
// s.[+0x18](self+0x35, 4); s.[+0x18](self+0x39, 4); s.[+0x50](self+0x3d); s.[+0x68](self+0x41); s.[+0x50](self+0x42);
// s.[+0x68](self+0x46); s.[+0x40](&l1) with l1 = s (the stack slot); self+0x4b = G.+0x9b .[+0x58](l1);
// s.[+0x40](&l2); self+0x4f = G.+0x9b .[+0x58](l2);  s.[+0x50] at self+0x53, +0x57, +0x5b, +0x5f, +0x63.
static u8 THISCALL fn523710(u8 *self, u8 *s) {
  call1(s, 0x50, (u32)(self + 4));
  call1(s, 0x6c, (u32)(self + 8));
  call1(s, 0x50, (u32)(self + 0x20));
  call1(s, 0x50, (u32)(self + 0x24));
  call1(s, 0x50, (u32)(self + 0x28));
  call1(s, 0x50, (u32)(self + 0x2c));
  call1(s, 0x50, (u32)(self + 0x30));
  call1(s, 0x68, (u32)(self + 0x34));
  call2(s, 0x18, (u32)(self + 0x35), 4u);
  call2(s, 0x18, (u32)(self + 0x39), 4u);
  call1(s, 0x50, (u32)(self + 0x3d));
  call1(s, 0x68, (u32)(self + 0x41));
  call1(s, 0x50, (u32)(self + 0x42));
  call1(s, 0x68, (u32)(self + 0x46));
  u32 l1 = (u32)s;
  call1(s, 0x40, (u32)&l1);
  u8 *b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x4b) = call1r(b, 0x58, l1);
  u32 l2 = 0;
  call1(s, 0x40, (u32)&l2);
  *(u32 *)(self + 0x4f) = call1r(b, 0x58, l2);
  call1(s, 0x50, (u32)(self + 0x53));
  call1(s, 0x50, (u32)(self + 0x57));
  call1(s, 0x50, (u32)(self + 0x5b));
  call1(s, 0x50, (u32)(self + 0x5f));
  call1(s, 0x50, (u32)(self + 0x63));
  return 1;
}
PCREG(523710, fn523710);
