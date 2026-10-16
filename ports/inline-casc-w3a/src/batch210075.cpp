// batch210075.cpp - Sonnet-w3a: 0x5fa270 (import compare of the name; register this[1] in a cell, or report through the handler objects)
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);

typedef int (*Cmp)(u32 a, u32 b);
typedef u32 (*F3)(u8 *, u32, u32);
typedef u32 (*F4)(u8 *, u8 *, u32, u32);
typedef u32 (*H)();

static void THISCALL fn5fa270(u8 *self, u32 *p) {
  u8 buf[0x68];
  int r = G(Cmp, 0x676414)(p[0], 0x6b9120);  // @5fa270_a
  if (r == 0) {  // @5fa270_b
    u32 edi = *(u32 *)(self + 4);
    u8 *cell = (u8 *)ext_5003d0((u8 *)p[2], 0);  // @5fa270_c
    if (cell[4] <= 1) {  // @5fa270_d
      *(u32 *)cell = edi;  // @5fa270_e
      cell[4] = 1;
      ext_633654(0);
      return;
    }
    u8 *g = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x69c8e0, 0xc4);  // @5fa270_f
    (*(F3 *)(*(u8 **)g + 0x2c))(g, 0x69c6b0, 0x69c938);  // @5fa270_g
    H h = G(H, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    ext_633654(0);
    return;
  }
  u8 *o = G(u8 *, 0x724270);
  (*(F4 *)(*(u8 **)o + 0x14))(o, buf, 0x6b9130, p[0]);  // @5fa270_h
  u8 *g = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x6b9148, 0x13);  // @5fa270_i
  (*(F3 *)(*(u8 **)g + 0x2c))(g, 0x69c6b0, (u32)buf);  // @5fa270_j
  H h = G(H, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  ext_633654(0);
}
PCREG(5fa270, fn5fa270);
