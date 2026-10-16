// batch210046.cpp - Sonnet-w3a: two /GS-protected rows with small stack buffers (cookie check hooked as 0x633654)
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4daf90(u8 *self, u32 *out);
extern "C" void FASTCALL ext_633654(u32 cookie);  // /GS check

static void THISCALL fn508560(u8 *self, u8 *a) {
  u8 buf34[0x24], buf10[0x10];
  u32 *x = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @508560_a
  u32 v = *x;
  (*(u8 **)(self + 0x18))[0x6fe] = (v != 0);  // @508560_b
  if (v) {  // @508560_c
    u8 *m = *(u8 **)(self + 0x18);
    vcall<u32, void *, void *>(m, 0x57c, buf34, buf10);  // @508560_d
    m = *(u8 **)(self + 0x18);
    vcall<u32, void *, u32, u32>(m, 0x620, buf10, 1, 1);  // @508560_e
    m = *(u8 **)(self + 0x18);
    vcall<u32, void *, void *>(m, 0x578, buf34, buf10);  // @508560_f
  }
  ext_633654(0);
}
PCREG(508560, fn508560);

static void THISCALL fn4af500(u8 *self, u8 *a) {
  u32 loc[4];
  ext_4daf90(*(u8 **)(a + 8), loc);  // @4af500_a
  vcall<u32, u32 *>(a, 0x84, loc);  // @4af500_b
  u8 *m = *(u8 **)(self + 0x44);
  vcall<u32, u32 *>(m, 0x8c, loc);  // @4af500_c
  m = *(u8 **)(self + 0x44);
  u32 al = vcall<u32, u32 *, u32>(m, 0x180, loc, 0xc1200000u) & 0xff;  // @4af500_d
  u32 cx;
  bool call = false;
  if (al) {
    if (self[0x5f] != 0 || self[0x5e] == 0) {  // @4af500_e
      cx = *(u16 *)(self + 0x50);  // @4af500_f
      self[0x5e] = 1;  // @4af500_g
      call = true;
    }
  } else if (self[0x5e] != 0) {  // @4af500_h
    cx = *(u16 *)(self + 0x52);  // @4af500_i
    self[0x5e] = 0;  // @4af500_j
    call = true;
  }
  if (call && (u16)cx != 0) vcall<u32, u32>(self, 0x84, cx);  // @4af500_k
  ext_633654(0);
}
PCREG(4af500, fn4af500);
