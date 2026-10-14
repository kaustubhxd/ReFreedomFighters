// batch35119.cpp - cascade s5 batch 35119: 0x4f0040 (GUESS measure the first n characters of a string: sum of glyph advances minus kerning).
#include "ff.h"

extern "C" u32 THISCALL ext_4cc500(u32 *it);   // next UTF-8 code point of the cursor (plain ret; real exe code runs in the spec)
typedef u8 *(THISCALL *g1_t)(void *, u32);
typedef s32(THISCALL *g2_t)(void *, u32, u32);

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x4f0040, thiscall(n) ret 4, returns a signed sum. Cursor {string pointer = unaligned dword [this+0x97], previous code point = 0, this} on the stack (0x4cc500 advances it). For up to n (signed) code points c (0 ends):
// glyph = [this+0x9f] slot 0x280(c); sum += (s8) glyph[0x10]; when there is a previous code point p: sum -= [this+0x9f] slot 0x28c(p, c). Returns the sum.
static s32 THISCALL fn4f0040(u8 *self, s32 n) {
  u32 loc[3];
  loc[0] = rd32u(self + 0x97);
  loc[1] = 0;
  loc[2] = (u32)self;
  s32 sum = 0;
  s32 i = 0;
  if (n > 0) {
    do {
      u32 c = ext_4cc500(loc);
      if (!c) break;
      u8 *o = *(u8 **)(self + 0x9f);
      u8 *g = (*(g1_t **)o)[0x280 / 4](o, c);
      sum += (s8)g[0x10];
      if (loc[1]) {
        o = *(u8 **)(self + 0x9f);
        sum -= (*(g2_t **)o)[0x28c / 4](o, loc[1], c);
      }
      i++;
      loc[1] = c;
    } while (i < n);
  }
  return sum;
}
PCREG(4f0040, fn4f0040);
