// batch66032.cpp - cascade s4 batch 66032: 0x5ee110 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_5ee920(void *self);                  // plain ret
extern "C" void THISCALL ext_5aca30(void *self, u32 a, u32 b);    // ret 8
extern "C" void THISCALL ext_5ac5d0(void *self, u32 a);           // ret 4
extern "C" u32 THISCALL ext_5ab9d0(void *self);                   // plain ret

// 0x5ee110, thiscall(a, b, c) ret 0xc (this = t): b == 0 -> return. v = t[5] (begin), t[9] (end), count n = (end - begin) >> 2 (signed), cursor t[0x19].
// t[0x11] == 1: cursor == n -> 0x5ee920(t), t[0x19]--, t[0x77] = 1; o = v[t[0x19]]; o[4] = c; t[0x19]++; x = *o.
// Otherwise: 0x5ee920(t); o = v[0]; x = *o; cursor != n -> t[0x19]++, t[0x77] = 1; o = v[0] again, o[4] = c.
// Then 0x5aca30(x, a, b); 0x5ac5d0(x, c); t[0x41] = 0; t[4] = 1; t[0x6a] set -> walk the first t[0x19] entries (at most to the end): m = max 0x5ab9d0(**e), t[0x45] = m + 10 (t[0x77] = 1 when it changed). Finally t[0x77] = 1.
static void THISCALL fn5ee110(u8 *t, u32 a, u32 b, u32 c) {
  if (!b) return;
  u8 *v;
  u8 *o;
  u8 *x;
  if (rd(t + 0x11) == 1) {
    s32 n = (s32)(rd(t + 9) - rd(t + 5)) >> 2;
    if ((s32)rd(t + 0x19) == n) {
      ext_5ee920(t);
      wr(t + 0x19, rd(t + 0x19) - 1);
      t[0x77] = 1;
    }
    v = *(u8 **)(t + 5);
    o = ((u8 **)v)[rd(t + 0x19)];
    x = *(u8 **)o;
    wr(o + 4, c);
    wr(t + 0x19, rd(t + 0x19) + 1);
  } else {
    ext_5ee920(t);
    v = *(u8 **)(t + 5);
    u32 k = rd(t + 0x19);
    o = *(u8 **)v;
    x = *(u8 **)o;
    s32 n = (s32)(rd(t + 9) - (u32)v) >> 2;
    if ((s32)k != n) {
      wr(t + 0x19, k + 1);
      t[0x77] = 1;
    }
    o = *(u8 **)v;
    wr(o + 4, c);
  }
  ext_5aca30(x, a, b);
  ext_5ac5d0(x, c);
  u8 flag = t[0x6a];
  wr(t + 0x41, 0);
  t[4] = 1;
  if (flag) {
    u8 **e = *(u8 ***)(t + 5);
    u32 m = 0;
    u32 k = 0;
    if ((u32)e != rd(t + 9)) {
      for (;;) {
        u32 r = ext_5ab9d0(*(u8 **)*e);
        if (r > m) m = r;
        k++;
        if (k == rd(t + 0x19)) break;
        e++;
        if ((u32)e == rd(t + 9)) break;
      }
    }
    m += 10;
    if (rd(t + 0x45) != m) {
      wr(t + 0x45, m);
      t[0x77] = 1;
    }
  }
  t[0x77] = 1;
}
PCREG(5ee110, fn5ee110);
