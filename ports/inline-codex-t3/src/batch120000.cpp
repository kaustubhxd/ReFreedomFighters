#include "ff.h"
extern "C" int THISCALL ext_530e80(void *, u16 *, const u16 *, u32, u32, float);
#define CELLS(o,k) (*(int *)((o)+0x3c+4*(k)))
static bool THISCALL octCheckPosition(u8 *oct, float *p) {
  float px = p[0], py = p[1] + 30.0f, pz = p[2];   // 30.0 at 0x67da24
  float *mn = (float *)(oct + 6), *mx = (float *)(oct + 0x12);
  float ex = mx[0] - mn[0], ey = mx[1] - mn[1], ez = mx[2] - mn[2];
  float lx = (px - mn[0]) / ex * (float)CELLS(oct, 0);
  float ly = (py - mn[1]) / ey * (float)CELLS(oct, 2);
  float lz = (pz - mn[2]) / ez * (float)CELLS(oct, 1);
  u16 c[3], out[4];
  c[0] = (u16)_mm_cvtt_ss2si(_mm_set_ss(lx));
  c[1] = (u16)_mm_cvtt_ss2si(_mm_set_ss(lz));
  c[2] = (u16)_mm_cvtt_ss2si(_mm_set_ss(ly));
  return ext_530e80(oct, out, c, 10, 1, 1.0f) != 0;
}
PCREG(52e240, octCheckPosition);
