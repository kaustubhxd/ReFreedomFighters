// batch38035.cpp - cascade s8 batch 38035: 0x6383a0 (build the four sample points of a segment).
#include "ff.h"

static inline s32 third(s32 v) { return v / 3; }   // the original uses the 0x55555556 multiply, i.e. truncating division

// 0x6383a0, fastcall(flag = ECX, out = EDX; a, b) ret 8. a and b are int[3] points, out is four int[4] records (the 4th int of each is 0xff). With flag == 0 the records are the 1/3 points of the
// segment: a rounded toward a ((3a+1)/3), (2a+1+b)/3, (2b+1+a)/3 and b ((3b+1)/3). With flag != 0 they are a, the midpoint (a+b)/2 (truncated toward zero), b and a zero record.
static void FASTCALL fn6383a0(u32 flag, s32 *out, s32 *a, s32 *b) {
  if (flag == 0) {
    for (int i = 0; i < 3; i++) out[i] = third((s32)(a[i] * 3u + 1));
    out[3] = 0xff;
    for (int i = 0; i < 3; i++) out[4 + i] = third((s32)(a[i] * 2u + 1 + b[i]));
    out[7] = 0xff;
    for (int i = 0; i < 3; i++) out[8 + i] = third((s32)(b[i] * 2u + 1 + a[i]));
    out[11] = 0xff;
    for (int i = 0; i < 3; i++) out[12 + i] = third((s32)(b[i] * 3u + 1));
    out[15] = 0xff;
  } else {
    out[0] = a[0];
    out[1] = a[1];
    out[2] = a[2];
    out[3] = 0xff;
    for (int i = 0; i < 3; i++) {
      s32 s = (s32)((u32)a[i] + (u32)b[i]);
      out[4 + i] = (s - (s >> 31)) >> 1;
    }
    out[7] = 0xff;
    out[8] = b[0];
    out[9] = b[1];
    out[10] = b[2];
    out[11] = 0xff;
    out[12] = 0;
    out[13] = 0;
    out[14] = 0;
    out[15] = 0;
  }
}
PCREG(6383a0, fn6383a0);
