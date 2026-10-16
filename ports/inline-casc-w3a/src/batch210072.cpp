// batch210072.cpp - Sonnet-w3a: 0x6160e0 (copy a transform into this+0x78 and apply two attach calls)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_64de00(u8 *self, u8 *a);
extern "C" u32 FASTCALL ext_60f040(u8 *ecx, u8 *edx, u8 *stackarg);
extern "C" u32 THISCALL ext_6097d0(u8 *self, u8 *a, u32 b, u8 *c, u32 d);

static u32 THISCALL fn6160e0(u8 *self, u8 *a) {
  ext_64de00(self, a);  // @6160e0_a
  u8 *ebx = (u8 *)ld32(a + 0x10051);
  u32 edi = ld32((u8 *)ld32(self + 0xc) + 0xc);  // @6160e0_b
  ext_60f040(self + 0x78, self + 0x10, self + 0x34);  // @6160e0_c
  u8 *src = a + 0x10061;
  ext_6097d0(ebx, self + 0xb8, edi, src, 0);  // @6160e0_d
  return ext_6097d0(ebx, self + 0xf8, edi, src, 1);  // @6160e0_e
}
PCREG(6160e0, fn6160e0);
