// batch13018.cpp - fresh slice 13, batch 18 (docs/20-fresh-13.md), 2026-10-12.
// 0x45a810 ZPICOBJ::GetSysMemPixInterpolated(const float* uv, int level, int* out) (name map high): thiscall, ret 0xc.
//  - img = (this+0x33)->vtbl[+0x30](level + 1): s16 width at +0, s16 height at +2, pixels (u32) from +4.
//  - x = width * uv[0], y = height * uv[1]; ix / iy = truncations; outside [0, width) x [0, height) -> return 0.
//    fx = x - ix, fy = y - iy; the last column / row is clamped to width - 2 / height - 2 (the fractions are kept).
//  - Bit depth this+0x2f > 0xff (true colour): with an `out` pointer the assert hook at 0x7003b0 is called (int3 when it
//    is not set); the four neighbours are blended with this->vtbl[+0x220](a, b, t) (x twice, then y) and the result is
//    returned (out is not written).
//  - Otherwise (palettized): pal = (this+0x33)->vtbl[+0x30](0); this->vtbl[+0x228](pixels, ix, iy, width, &i00, &i10,
//    &i01, &i11) fetches four palette indices (bytes); the colours pal[i] are blended the same way; with `out` the
//    result goes to out[0] and a second blend of (pal + 0x30)[i >> 2] to out[1]. Returns the first blend.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

typedef u8 *(THISCALL *R1)(void *self, u32 a);
typedef u32(THISCALL *Blend)(void *self, u32 a, u32 b, float t);
typedef void(THISCALL *Idx)(void *self, u8 *pix, s32 x, s32 y, s32 w, u8 *a, u8 *b, u8 *c, u8 *d);
typedef void (*Hook)();

static inline u32 blend4(u8 *self, u32 p00, u32 p10, u32 p01, u32 p11, float fx, float fy) {
  u32 a = ((Blend)VT(self, 0x220))(self, p00, p10, fx);
  u32 b = ((Blend)VT(self, 0x220))(self, p01, p11, fx);
  return ((Blend)VT(self, 0x220))(self, a, b, fy);
}

static u32 THISCALL fn45a810(u8 *self, const float *uv, s32 level, u32 *out) {
  u8 *mip = AT(u8 *, self, 0x33);
  u8 *img = ((R1)VT(mip, 0x30))(mip, (u32)(level + 1));
  s32 w = AT(s16, img, 0);
  s32 h = AT(s16, img, 2);
  float x = (float)w * uv[0];
  float y = (float)h * uv[1];
  s32 ix = _mm_cvttss_si32(_mm_set_ss(x));
  s32 iy = _mm_cvttss_si32(_mm_set_ss(y));
  if (ix >= w || iy >= h || ix < 0 || iy < 0)
    return 0;
  float fx = x - (float)ix;
  float fy = y - (float)iy;
  if (ix + 1 >= w)
    ix = w - 2;
  if (iy + 1 >= h)
    iy = h - 2;
  if (AT(s32, self, 0x2f) > 0xff) {
    if (out) {
      Hook f = G(Hook, 0x7003b0);
      if (!f)
        __builtin_debugtrap();
      else
        f();
    }
    s32 w2 = AT(s16, img, 0);
    u32 *p = (u32 *)(img + 4) + (w2 * iy + ix);
    return blend4(self, p[0], p[1], p[w2], p[w2 + 1], fx, fy);
  }
  u32 *pal = (u32 *)((R1)VT(mip, 0x30))(mip, 0);
  u8 i00, i10, i01, i11;
  ((Idx)VT(self, 0x228))(self, img + 4, ix, iy, AT(s16, img, 0), &i00, &i10, &i01, &i11);
  u32 r = blend4(self, pal[i00], pal[i10], pal[i01], pal[i11], fx, fy);
  if (out) {
    out[0] = r;
    u32 *p2 = pal + 0xc;
    out[1] = blend4(self, p2[i00 >> 2], p2[i10 >> 2], p2[i01 >> 2], p2[i11 >> 2], fx, fy);
  }
  return r;
}
PCREG(45a810, fn45a810);
