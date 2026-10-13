// batch4117.cpp - unclaimed-41 batch 17 (slice 13): 0x523990 (name not in the map; GUESS, serialization write sequence).
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
static void putf(u8 *s, u8 *self, u32 off) {
  call1(s, 0x4c, fbits(*(float *)(self + off)));
}

// 0x523990 (GUESS name): thiscall, one stack argument s (the stream; ret 4), returns al = 1. The sequence (self = this):
// s.[+0x4c](float self+4); s.[+0x68](self+8); s.[+0x4c] floats at +0x20, +0x24, +0x28, +0x2c, +0x30; s.[+0x60](byte +0x34);
// s.[+0x10](self+0x35, 4); s.[+0x10](self+0x39, 4); s.[+0x4c](float +0x3d); s.[+0x60](byte +0x41); s.[+0x4c](float +0x42);
// s.[+0x60](byte +0x46); r = G.+0x9b .[+0x4c](dword +0x4b); s.[+0x3c](r); r = G.+0x9b .[+0x4c](dword +0x4f); s.[+0x3c](r);
// s.[+0x4c] floats at +0x53, +0x57, +0x5b, +0x5f, +0x63.
static u8 THISCALL fn523990(u8 *self, u8 *s) {
  putf(s, self, 4);
  call1(s, 0x68, (u32)(self + 8));
  putf(s, self, 0x20);
  putf(s, self, 0x24);
  putf(s, self, 0x28);
  putf(s, self, 0x2c);
  putf(s, self, 0x30);
  call1(s, 0x60, (u32)self[0x34]);
  call2(s, 0x10, (u32)(self + 0x35), 4u);
  call2(s, 0x10, (u32)(self + 0x39), 4u);
  putf(s, self, 0x3d);
  call1(s, 0x60, (u32)self[0x41]);
  putf(s, self, 0x42);
  call1(s, 0x60, (u32)self[0x46]);
  u8 *b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r = call1r(b, 0x4c, *(u32 *)(self + 0x4b));
  call1(s, 0x3c, r);
  r = call1r(b, 0x4c, *(u32 *)(self + 0x4f));
  call1(s, 0x3c, r);
  putf(s, self, 0x53);
  putf(s, self, 0x57);
  putf(s, self, 0x5b);
  putf(s, self, 0x5f);
  putf(s, self, 0x63);
  return 1;
}
PCREG(523990, fn523990);
