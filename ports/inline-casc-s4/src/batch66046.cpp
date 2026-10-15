// batch66046.cpp - cascade s4 batch 66046: 0x482680 (tier F row).
#include "ff.h"

typedef u32(THISCALL *v2r_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

static u32 opt(u32 name) {
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
  return (u8)(*(v2r_t **)o)[0x38 / 4](o, name, 0);
}

// 0x482680, thiscall() plain ret (this = t): reads the option flags A 0x68b5bc, B 0x68b5c8, C 0x68b5d8, D 0x68b5e8 (slot 0x38(name, 0) of sys[0x1907], low byte) and clears t[0x417] &= 0xfff7fe98.
// A: option 0x68b5b4 -> |= 2 else |= 1; else B: |= 5. C: |= 0x20; else D: |= 0x40. t[0x417] == 0 -> 0x100. Option 0x67a110 -> |= 0x80000.
static void THISCALL fn482680(u8 *t) {
  u32 a = opt(0x68b5bc);
  u32 b = opt(0x68b5c8);
  u32 c = opt(0x68b5d8);
  u32 d = opt(0x68b5e8);
  u8 *f = t + 0x417;
  wr(f, rd(f) & 0xfff7fe98);
  if (a) {
    if (opt(0x68b5b4)) wr(f, rd(f) | 2);
    else wr(f, rd(f) | 1);
  } else if (b) {
    wr(f, rd(f) | 5);
  }
  if (c) wr(f, rd(f) | 0x20);
  else if (d) wr(f, rd(f) | 0x40);
  if (rd(f) == 0) wr(f, 0x100);
  if (opt(0x67a110)) wr(f, rd(f) | 0x80000);
}
PCREG(482680, fn482680);
