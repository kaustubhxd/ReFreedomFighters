// batch13013.cpp - fresh slice 13, batch 13 (docs/20-fresh-13.md), 2026-10-12.
// 0x44f550 GUESS (no name map entry): thiscall, no arguments. Rebuilds 0x3c-byte clip records at this+0xb0 and pushes
// vertices out of them (GUESS meaning: a soft-body / cloth collision pass).
//  1. For each of the +0xa4 geoms in this+0xac[]: 0x4db6c0(geom; rec, rec+0x24) (thiscall, ret 8), this->vtbl[+0x94](rec,
//     rec+0x24) (ret 8), rec+0x30..0x38 = geom+0x40..0x48.
//  2. When this+0xc8 has a list at +0x50 (next at +0x60, object at +0x54): every object other than this whose
//     vtbl[+0x1e0](0x200002) is true fills the next record through its vtbl[+0x80](rec, rec+0x24) (ret 8), then
//     this->vtbl[+0x94], and copies its +8 object's +0x40..0x48.
//  3. For each of the +0x44 vertices (array *this+0x7c, 12 bytes each; a second array of the same count follows it)
//     with a non-zero weight in this+0x64[]: d = v - rec.pos (0x43e920, fastcall out, a, b: out = a - b); the record is
//     a candidate when |axis1 . d| < rec+0x30 and |axis0 . d| < rec+0x38 (float bits compared as signed ints) and
//     n . d is negative and not above the best so far (bits compared as signed ints, start -500.0f); the winner pushes
//     the vertex out along n (0x451890, fastcall dst, src, s: dst += src * s) and the second vertex moves halfway
//     toward it (0x443ef0, fastcall out, a, b, s: out = a + b * s). Zero-weight vertices do not advance the two
//     array pointers (as in the exe). The helpers are x87 code and run as exe code.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))
#define VT(o, off) (*(u32 *)(*(u32 *)(o) + (off)))

extern "C" char ext_4db6c0[], ext_43e920[], ext_451890[], ext_443ef0[];
typedef void(THISCALL *P2)(void *self, u32 a, u32 b);
typedef u8(THISCALL *B1)(void *self, u32 a);
typedef void(FASTCALL *Sub)(float *out, const float *a, const float *b);
typedef void(FASTCALL *AddScaled)(float *dst, const float *src, float s);
typedef void(FASTCALL *Lerp)(float *out, const float *a, const float *b, float s);

static inline s32 bits(float f) {
  union {
    float f;
    s32 i;
  } u;
  u.f = f;
  return u.i;
}

static void THISCALL fn44f550(u8 *self) {
  u32 i = 0;
  if (AT(u32, self, 0xa4) > 0) {
    u32 off = 0;
    do {
      u32 rec = AT(u32, self, 0xb0) + off;
      ((P2)(void *)ext_4db6c0)(AT(u8 **, self, 0xac)[i], rec, rec + 0x24);
      rec = AT(u32, self, 0xb0) + off;
      ((P2)VT(self, 0x94))(self, rec, rec + 0x24);
      u8 *g = AT(u8 **, self, 0xac)[i];
      u8 *r = AT(u8 *, self, 0xb0) + off;
      AT(u32, r, 0x30) = AT(u32, g, 0x40);
      AT(u32, r, 0x34) = AT(u32, g, 0x44);
      AT(u32, r, 0x38) = AT(u32, g, 0x48);
      i++;
      off += 0x3c;
    } while (i < AT(u32, self, 0xa4));
  }
  u8 *p = AT(u8 *, self, 0xc8);
  if (p) {
    u8 *q = AT(u8 *, p, 0x50);
    if (q) {
      u32 off = i * 0x3c;
      do {
        u8 *s = AT(u8 *, q, 0x54);
        if (s != self && ((B1)VT(s, 0x1e0))(s, 0x200002)) {
          u32 rec = off + AT(u32, self, 0xb0);
          ((P2)VT(s, 0x80))(s, rec, rec + 0x24);
          rec = off + AT(u32, self, 0xb0);
          ((P2)VT(self, 0x94))(self, rec, rec + 0x24);
          u8 *g = AT(u8 *, s, 8);
          u8 *r = AT(u8 *, self, 0xb0) + off;
          AT(u32, r, 0x30) = AT(u32, g, 0x40);
          AT(u32, r, 0x34) = AT(u32, g, 0x44);
          AT(u32, r, 0x38) = AT(u32, g, 0x48);
          off += 0x3c;
        }
        q = AT(u8 *, q, 0x60);
      } while (q);
    }
  }
  float *v = *AT(float **, self, 0x7c);
  u32 n = AT(u32, self, 0x44);
  float *v2 = v + 3 * n;
  if (!n)
    return;
  for (u32 j = 0; j < AT(u32, self, 0x44); j++) {
    s32 best = -1;
    s32 bestv = (s32)0xc3fa0000;
    if (AT(float *, self, 0x64)[j] == 0.0f)
      continue;
    if (AT(u32, self, 0xa8) != 0) {
      u32 off = 0;
      for (u32 k = 0; k < AT(u32, self, 0xa8); k++, off += 0x3c) {
        u8 *r = AT(u8 *, self, 0xb0);
        float d[3];
        ((Sub)(void *)ext_43e920)(d, v, (float *)(r + 0x24 + off));
        u8 *e = r + off;
        float x = d[0], y = d[1], z = d[2];
        float a = AT(float, e, 0x1c) * y;
        a = a + AT(float, e, 0x18) * x;
        a = a + AT(float, e, 0x20) * z;
        if (bits(__builtin_fabsf(a)) >= AT(s32, e, 0x30))
          continue;
        float b = AT(float, e, 4) * y;
        b = b + x * AT(float, e, 0);
        b = b + AT(float, e, 8) * z;
        if (bits(__builtin_fabsf(b)) >= AT(s32, e, 0x38))
          continue;
        float c = AT(float, e, 0x10) * y;
        c = c + AT(float, e, 0xc) * x;
        c = c + AT(float, e, 0x14) * z;
        if (bits(c) < 0 && !(bits(c) > bestv)) {
          bestv = bits(c);
          best = (s32)k;
        }
      }
      if (best != -1) {
        u8 *e = AT(u8 *, self, 0xb0) + (u32)best * 0x3c;
        float d[3];
        ((Sub)(void *)ext_43e920)(d, v, (float *)(e + 0x24));
        float t = AT(float, e, 0x10) * d[1];
        t = t + AT(float, e, 0xc) * d[0];
        t = t + AT(float, e, 0x14) * d[2];
        ((AddScaled)(void *)ext_451890)(v, (float *)(e + 0xc), -t);
        ((Sub)(void *)ext_43e920)(d, v2, v);
        ((Lerp)(void *)ext_443ef0)(v2, v, d, 0.5f);
      }
    }
    v += 3;
    v2 += 3;
  }
}
PCREG(44f550, fn44f550);
