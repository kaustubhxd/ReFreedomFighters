// batch37009.cpp - cascade s6 batch 37009: 0x613690.
#include "ff.h"

static inline u32 lum(u32 p) { return (((p >> 16) & 0xff) + ((p >> 8) & 0xff) + (p & 0xff)) / 3; }

// 0x613690, fastcall(dst, src, w, h, fmt) ret 0xc: writes a luminance-difference image: for every pixel the grey value (mean of the three colour bytes)
// of the pixel above (row 0: itself) minus its own, and of the left neighbour minus its own, plus the alpha byte of the above-left pixel,
// packed by fmt (0x3c: 2 bytes, 0x3d: 5-5-6 word, 0x3e: 4 bytes; other: nothing). Rows of dst are w*2 bytes apart (0x3e: w*4).
static void FASTCALL fn613690(u8 *dst, u32 *src, u32 w, u32 h, u32 fmt) {
  u32 dstride = fmt != 0x3e ? w * 2 : w * 4;
  u32 *row = src;
  u8 *drow = dst;
  for (u32 y = 0; y < h; y++) {
    u32 *prev = y ? row - w : row;
    u8 *d = drow;
    for (u32 x = 0; x < w; x++) {
      u32 lx = x ? x - 1 : 0;
      u32 pp = prev[x];
      u32 cur = row[x];
      u32 lc = lum(cur);
      u32 d1 = lum(pp) - lc;
      u32 d2 = lum(row[lx]) - lc;
      u32 a = (prev[lx] >> 24) & 0xff;
      if (fmt == 0x3c) {
        d[0] = (u8)d1;
        d[1] = (u8)d2;
        d += 2;
      } else if (fmt == 0x3d) {
        u32 t = (((s32)d2 >> 3) & 0x1f) | ((a >> 2) << 5);
        t = (t << 5) | (((s32)d1 >> 3) & 0x1f);
        d[0] = (u8)t;
        d[1] = (u8)(t >> 8);
        d += 2;
      } else if (fmt == 0x3e) {
        d[0] = (u8)d1;
        d[1] = (u8)d2;
        d[2] = (u8)a;
        d[3] = 0;
        d += 4;
      }
    }
    drow += dstride;
    row += w;
  }
}
PCREG(613690, fn613690);
