// batch38047.cpp - cascade s8 batch 38047: 0x52d580 (visit the 8x8 cells of an octree leaf region with two callbacks).
#include "ff.h"

typedef u32(THISCALL *cb1_t)(void *obj, void *self, u32 id, s32 *lo, s32 *hi);                                   // returns AL
typedef u32(THISCALL *cb2_t)(void *obj, void *self, u32 *bits, u32 cell, s32 *lo, s32 *hi, u32 n1, u32 id);      // returns a count

// 0x52d580, thiscall(x, idp, n, p0, p1, p2, q0, q1, q2) ret 0x24, returns the sum of the second callback's results. x: +0 first callback object (slot 0), +0xc second callback object (slot 0), byte +0x10 = stop
// after the first cell that produced a result. For the 8 x 8 grid (i, k) = 0..7 the box lo = (p0 + k, p1 + i, p2) / hi = lo + 1 is offered to the first callback (when present; AL == 0 skips the cell), the
// cell's bit pattern is gathered from this[0x72] (this[0x48] levels, 2 dwords apart, selected by the record this[0x5a] + id * 12) and everything goes to the second callback (cell id + record base,
// n - 1, id), whose return values are added up. (The last three arguments are only overwritten by the box.)
static u32 THISCALL fn52d580(u8 *self, u8 *x, u16 *idp, u32 n, s32 p0, s32 p1, s32 p2, u32 q0, u32 q1, u32 q2) {
  u8 *rec = *(u8 **)(self + 0x5a) + (u32)*idp * 12;
  u32 mulv = *(u16 *)(rec + 6);
  u8 *base = *(u8 **)(self + 0x72) + (u32) * (u16 *)(self + 0x2a) * mulv * 4;
  u32 total = 0;
  s32 j0 = 0;
  s32 py = p1;
  s32 lo[3], hi[3];
  u32 bits;
  do {
    for (s32 k = 0; k < 8; k++) {
      lo[0] = p0 + k;
      hi[0] = lo[0] + 1;
      lo[1] = py;
      hi[1] = py + 1;
      lo[2] = p2;
      hi[2] = p2 + 1;
      void *c1 = *(void **)x;
      if (c1) {
        u8 al = (u8)(*(cb1_t *)(*(u8 **)c1))(c1, self, *idp, lo, hi);
        if (al == 0) continue;   // goes straight to the loop increment (the stop flag is not tested)
      }
      s32 cell = j0 + k;
      if (*(u16 *)(rec + 6) == 0) {
        bits = 0;
      } else {
        s32 cnt = *(s32 *)(self + 0x48);
        s32 bi = (cnt << 6) - 0x40 + cell;
        u32 *ptr = (u32 *)(base + (bi >> 5) * 4);
        u32 sh = (u32)bi & 0x1f;
        u32 v = 0;
        for (s32 e = cnt - 1; e >= 0; e--) {
          s32 d = (s32)*ptr;
          ptr -= 2;
          v = v * 2 | (((u32)(d >> sh)) & 1);
        }
        bits = v;
      }
      u32 cellid = *(u16 *)(rec + 0xa) + (u32)cell;
      void *c2 = *(void **)(x + 0xc);
      if (c2) total += (*(cb2_t *)(*(u8 **)c2))(c2, self, &bits, cellid, lo, hi, n - 1, *idp);
      if (x[0x10] != 0) return total;
    }
    py++;
    j0 += 8;
  } while (j0 < 0x40);
  return total;
}
PCREG(52d580, fn52d580);
