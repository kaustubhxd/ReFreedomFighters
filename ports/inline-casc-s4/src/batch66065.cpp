// batch66065.cpp - cascade s4 batch 66065: 0x569ca0 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *ext_41e290(u32 n);   // cdecl

static void dup_string(u8 *dst, u8 *src, u32 off) {
  u8 *s = *(u8 **)(src + off);
  if (!s) return;
  u32 n = 0;
  while (s[n]) n++;
  u8 *p = ext_41e290(n + 1);
  u8 *d = p;
  u8 *q = *(u8 **)(src + off);
  u8 ch;
  do {
    ch = *q++;
    *d++ = ch;
  } while (ch);
  wr(dst + off, (u32)p);
}

// 0x569ca0, thiscall(src) ret 4 (this = t): copies the dwords +0x19c .. +0x1ac (4 step), +0x180 .. +0x190, +0x198; duplicates the strings at +0x1bd and +0x1c1 when set (0x41e290(len + 1), the destination pointer is left alone when the source one is null);
// copies the byte +0x87 and the dwords +0x1b0, +0x194, +0x1b8.
static void THISCALL fn569ca0(u8 *t, u8 *s) {
  static const u16 offs[11] = {0x19c, 0x1a0, 0x1a4, 0x1a8, 0x1ac, 0x180, 0x184, 0x188, 0x18c, 0x190, 0x198};
  for (int i = 0; i < 11; i++) wr(t + offs[i], rd(s + offs[i]));
  dup_string(t, s, 0x1bd);
  dup_string(t, s, 0x1c1);
  t[0x87] = s[0x87];
  wr(t + 0x1b0, rd(s + 0x1b0));
  wr(t + 0x194, rd(s + 0x194));
  wr(t + 0x1b8, rd(s + 0x1b8));
}
PCREG(569ca0, fn569ca0);
