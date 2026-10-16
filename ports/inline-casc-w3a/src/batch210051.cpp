// batch210051.cpp - Sonnet-w3a: 0x50bf60 (stdcall 1 arg: look up an object through two cursor cells, check capability, toggle)
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);

static void STDCALL fn50bf60(u8 *p) {
  ext_5002f0((u8 *)ext_5003d0(*(u8 **)(p + 8), 0), 0);  // @50bf60_a
  u8 *cell = (u8 *)ext_5003d0(*(u8 **)(p + 4), 0);  // @50bf60_b
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = (u8 *)vcall<u32, u32>(mgr, 0x58, *(u32 *)cell);  // @50bf60_c
  if (!obj) {
    u8 *r = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x69d420, 0x107);  // @50bf60_d
    typedef u32 (*F)(u8 *, u32);
    (*(F *)(*(u8 **)r + 0x2c))(r, 0x69d5dc);  // @50bf60_e
    return;
  }
  if (!(vcall<u32, u32>(obj, 0x1e0, 0x1007d1) & 0xff)) {  // @50bf60_f
    u8 *r = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x69d420, 0x10d);  // @50bf60_g
    typedef u32 (*F3)(u8 *, u32, u32);
    (*(F3 *)(*(u8 **)r + 0x2c))(r, 0x69d5fc, *(u32 *)(obj + 4));  // @50bf60_h
    return;
  }
  vcall<u32, u32>(obj, 0x210, 1);  // @50bf60_i
  ext_5002f0((u8 *)ext_5003d0(*(u8 **)(p + 8), 0), 1);  // @50bf60_j
}
PCREG(50bf60, fn50bf60);
