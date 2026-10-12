// batch504.cpp - unclaimed-05 batch 4 (claim 4, slice floor(addr/16) mod 20 = 4). Names from the GC name map (naming
// only, never committed); GUESS where marked. Float rounding follows the original's x87 code: products and sums are done
// in double precision (PC control word 0x27f, 53-bit) and rounded to float once at each store.
#include "ff.h"

// ext_451890: Vec3 scaled add, original code. ecx = destination (float[3]), edx = source (float[3]), stack = scale.
// Body: dst[i] = dst[i] + src[i] * scale, all three read before any store (ret 4).
extern "C" void FASTCALL ext_451890(float *dst, const float *src, float scale);

// Engine virtual slot +0x1c0: takes (file, line) and returns a float in ST0 (thiscall, callee pops 8).
typedef float(THISCALL *VEngineGetF)(u8 *self, const char *file, u32 line);

// 0x55f900, ZFFHeroIf::calcPositionInBox(ZGEOM*, float*, float*) (high): stdcall, ret 0xc.
//   q = geom->+8; t1 = q->+0x40; t2 = q->+0x48; the engine object is the global at 0x70039c.
//   local copies: l24 = a[0..2], l18 = a[6..8] (a+0x18 .. a+0x20).
//   r1 = engine->vcall(0x1c0)("file 0x6a6148", 0x17d);  v1 = (float)((r1 - c0) * t1)   with c0 = float at 0x67a6ac
//   r2 = engine->vcall(0x1c0)("file 0x6a6148", 0x17e); f2 = (float)((r2 - c0) * t2)
//   b->Add(l18, v1 + v1); b->Add(l24, f2 + f2)   where Add is ext_451890 with ecx = b.
static void STDCALL heroCalcPositionInBox(u8 *geom, float *a, float *b) {
  u8 *q = *(u8 **)(geom + 8);
  float t1 = *(float *)(q + 0x40);
  float t2 = *(float *)(q + 0x48);
  float l18[3] = {a[6], a[7], a[8]};
  float l24[3] = {a[0], a[1], a[2]};
  const float c0 = G(float, 0x67a6ac);
  const char *file = (const char *)0x6a6148;

  u8 *eng = G(u8 *, 0x70039c);
  u8 *vt = *(u8 **)eng;
  float r1 = ((VEngineGetF)*(u32 *)(vt + 0x1c0))(eng, file, 0x17d);
  float v1 = (float)(((double)r1 - (double)c0) * (double)t1);

  eng = G(u8 *, 0x70039c);
  vt = *(u8 **)eng;
  float r2 = ((VEngineGetF)*(u32 *)(vt + 0x1c0))(eng, file, 0x17e);
  float f2 = (float)(((double)r2 - (double)c0) * (double)t2);

  ext_451890((float *)b, l18, v1 + v1);
  ext_451890((float *)b, l24, f2 + f2);
}
PCREG(55f900, heroCalcPositionInBox);
