// batch210053.cpp - Sonnet-w3a: 0x450ef0 (load one record from a stream object)
#include "ff.h"

extern "C" u32 THISCALL ext_45f3c0(u8 *self, u8 *s);
extern "C" u32 ext_41e290(u32 n);

static u32 THISCALL fn450ef0(u8 *self, u8 *s) {
  if (!(ext_45f3c0(self, s) & 0xff)) return 0;  // @450ef0_a
  u32 id;
  vcall<u32, u32 *>(s, 0x40, (u32 *)(self + 0x94));  // @450ef0_b
  vcall<u32, u32 *>(s, 0x40, &id);  // @450ef0_c
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x98) = vcall<u32, u32>(mgr, 0x58, id);  // @450ef0_d
  vcall<u32, u32 *>(s, 0x40, &id);  // @450ef0_e
  mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0xc8) = vcall<u32, u32>(mgr, 0x58, id);  // @450ef0_f
  u32 *np = (u32 *)(self + 0x88);
  vcall<u32, u32 *>(s, 0x40, np);  // @450ef0_g
  vcall<u32, u32 *>(s, 0x40, (u32 *)(self + 0xa8));  // @450ef0_h
  u32 n = *np;
  u32 bytes = (n > 0x7fffffffu) ? 0xffffffffu : n * 2;  // @450ef0_i
  u32 buf = ext_41e290(bytes);
  *(u32 *)(self + 0x8c) = buf;
  vcall<u32, u32, u32>(s, 0x18, buf, n + n);  // @450ef0_j
  return 1;
}
PCREG(450ef0, fn450ef0);
