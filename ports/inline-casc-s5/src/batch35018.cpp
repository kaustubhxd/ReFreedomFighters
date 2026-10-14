// batch35018.cpp - cascade s5 batch 35018: 0x56c6a0 (GUESS reset two sub-objects according to a mode word and update the camera-like object at +0xcae).
#include "ff.h"

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x56c6a0, thiscall, no arguments; every field below is read unaligned. this slot 0xfc(0). With mode = (s32)[+0xce6]: X = [+0xcb2], Y = [+0xcae], v = {0, 0, 0}, flag = 1.
// mode > 1: v[0] = 0x41b00000, flag = 0, X slot 0x31c(Y, 3), o = this slot 0x84(), o slot 0x2ec(Y). Otherwise X slot 0x31c(0, 3), o = this slot 0x84(), o slot 0x2ec(X).
// Then [+0xcd2] slot 0xbc(flag), [+0xcd6] slot 0xbc(flag) (only the low byte of the pushed dword is defined) and [+0xcae] slot 0x70(&v) (three dwords).
static void THISCALL fn56c6a0(u8 *self) {
  u32 v[3];
  vcall<void>(self, 0xfc, 0u);
  s32 mode = (s32)rd32u(self + 0xce6);
  u8 *X = (u8 *)rd32u(self + 0xcb2);
  v[0] = 0;
  v[1] = 0;
  v[2] = 0;
  u32 flag = 1;
  u8 *o;
  u32 arg;
  if (mode > 1) {
    u8 *Y = (u8 *)rd32u(self + 0xcae);
    v[0] = 0x41b00000;
    flag = 0;
    vcall<void>(X, 0x31c, (u32)Y, 3u);
    o = vcall<u8 *>(self, 0x84);
    arg = rd32u(self + 0xcae);
  } else {
    vcall<void>(X, 0x31c, 0u, 3u);
    o = vcall<u8 *>(self, 0x84);
    arg = rd32u(self + 0xcb2);
  }
  vcall<void>(o, 0x2ec, arg);
  vcall<void>((void *)rd32u(self + 0xcd2), 0xbc, flag);
  vcall<void>((void *)rd32u(self + 0xcd6), 0xbc, flag);
  vcall<void>((void *)rd32u(self + 0xcae), 0x70, (u32)v);
}
PCREG(56c6a0, fn56c6a0);
