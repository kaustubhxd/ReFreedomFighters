// batch67509.cpp - cascade s6 batch 67509: 0x63a1a0.
#include "ff.h"

extern "C" void FASTCALL ext_6383a0(u32 flag, s32 *pal, s32 *x, s32 *y);   // ret 8: fills 16 palette dwords

// 0x63a1a0, fastcall(flag, comp, lo, hi, pixels, out) ret 0x10: block-compression index selection for one colour component. lo and hi are three-component endpoints, expanded to
// full precision (v | v >> 5, the middle component v | v >> 6 for hi and for lo when flag is 0, v | v >> 5 when flag is set); 0x6383a0 builds the four palette entries of 3 components
// from them. For each of the 16 pixels (0x10 bytes: three components then a non-zero "opaque" word at +0xc) the index of the palette entry whose component `comp` is nearest (squared
// distance, strict less keeps the earlier entry) goes to out[i]; transparent pixels get index 3 and an entry no distance is below 0x7fffffff stays -1.
static void FASTCALL fn63a1a0(u32 flag, u32 comp, s32 *lo, s32 *hi, u8 *pix, s32 *out) {
  s32 pal[16];
  s32 X[3], Y[3];
  X[0] = lo[0] | (lo[0] >> 5);
  Y[0] = hi[0] | (hi[0] >> 5);
  X[1] = lo[1] | (lo[1] >> (flag ? 5 : 6));
  Y[1] = hi[1] | (hi[1] >> 6);
  X[2] = lo[2] | (lo[2] >> 5);
  Y[2] = hi[2] | (hi[2] >> 5);
  ext_6383a0(flag, pal, X, Y);
  for (u32 i = 0; i < 16; i++) {
    s32 *p = (s32 *)(pix + i * 0x10);
    if (*(s32 *)(pix + i * 0x10 + 0xc) == 0) {
      out[i] = 3;
      continue;
    }
    out[i] = -1;
    s32 best = 0x7fffffff;
    bool last = false;
    for (u32 k = 0; k < 4; k++) {
      s32 d = (s32)((u32)(p[comp] - pal[k * 4 + comp]) * (u32)(p[comp] - pal[k * 4 + comp]));
      if (d < best) {
        best = d;
        out[i] = (s32)k;
        if (k == 3) last = true;
      } else if (k == 3) {
        break;
      }
    }
    (void)last;
  }
}
PCREG(63a1a0, fn63a1a0);
