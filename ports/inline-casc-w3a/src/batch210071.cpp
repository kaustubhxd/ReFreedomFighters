// batch210071.cpp - Sonnet-w3a: 0x591b20 (refresh the cached lookup value, forced to 9 while flag 0x2000000 is set)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u32 THISCALL ext_5aeff0(u8 *self, u32 a);

static u32 THISCALL fn591b20(u8 *self) {
  u8 al = 0;
  if (ld32(self + 0x417) & 0x2000000) {  // @591b20_a
    al = 1;
    *(u32 *)(self + 0x654) = 9;  // @591b20_b
  }
  u8 bl = self[0x65c];
  self[0x65c] = al;
  if (!al) {  // @591b20_c
    u32 v = vcall<u32>(self, 0x504);  // @591b20_d
    if (v != *(u32 *)(self + 0x658) || bl) {  // @591b20_e
      *(u32 *)(self + 0x658) = v;
      *(u32 *)(self + 0x654) = 0;  // @591b20_f
      if (v) *(u32 *)(self + 0x654) = ext_5aeff0(self + 0x95b, v);  // @591b20_g
    }
    if (vcall<u32>(self, 0x438) & 0xff) *(u32 *)(self + 0x654) = 0;  // @591b20_h
  }
  return *(u32 *)(self + 0x654);
}
PCREG(591b20, fn591b20);
