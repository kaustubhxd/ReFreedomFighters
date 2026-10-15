// batch52011.cpp - cascade tier H, batch 52011: 0x4bf6b0 (timed fade of an object's level between engine ticks).
#include "ff.h"
#include <xmmintrin.h>

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static float rdf(const u8 *p) { return bitsf(rd32(p)); }
static void wrf(u8 *p, float f) { wr32(p, fbits(f)); }
static s32 tr(float f) { return _mm_cvttss_si32(_mm_set_ss(f)); }

static u8 *lookup(u32 key) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return vcall<u8 *>(tab, 0x58, key);
}
static void set_level(u8 *self) {
  u8 *o = lookup(rd32(self + 0x52));
  if (o) wr32(*(u8 **)(o + 0x18) + 0x84, rd32(self + 0x62));
}

// 0x4bf6b0, thiscall plain. Fields (unaligned): byte +0x6e, handle +0x4a, handle +0x52, floats +0x56 (start), +0x5a, +0x5e, +0x62 (level), +0x66, +0x6a. tick = engine int [0x70039c+0x40], dt = engine float +0x48, 1024.0 (0x678620).
// +0x6e clear: this->slot0x68(0x10, 0). +0x4a == 0: return. +0x56 == 0: +0x56 = tick * 0x6785e4. tick < cvtt((+0x5a + +0x56) * 1024): return.
// o = table slot 0x58(+0x4a); none: final call. +0x52 == 0: o->slot0x1e0(0x2007d0). +0x66 != 0 and tick <= cvtt(((+0x5a + +0x56) + +0x66) * 1024): level += dt / +0x66, push to the object of +0x52 (field [+0x18] + 0x84).
// +0x5e == 0: final call. +0x6a != 0 and tick >= cvtt((+0x5e + +0x56) * 1024): level -= dt / +0x6a, push likewise. tick < cvtt(((+0x5e + +0x56) + +0x6a) * 1024): return.
// +0x52 == 0: final call; else its object's slot 0x210(1), +0x52 = 0, final call (this->slot0x68(0x10, 0)).
static void THISCALL fn4bf6b0(u8 *self) {
  u8 *sys;
  if (self[0x6e]) {
    u32 A = rd32(self + 0x4a);
    if (!A) return;
    sys = G(u8 *, 0x70039c);
    if (rdf(self + 0x56) == 0.0f) wrf(self + 0x56, (float)*(s32 *)(sys + 0x40) * G(float, 0x6785e4));
    float c = G(float, 0x678620);
    sys = G(u8 *, 0x70039c);
    if (*(s32 *)(sys + 0x40) < tr((rdf(self + 0x5a) + rdf(self + 0x56)) * c)) return;
    u8 *o = lookup(A);
    if (!o) goto fin;
    if (rd32(self + 0x52) == 0) vcall<void>(o, 0x1e0, 0x2007d0u);
    {
      float f66 = rdf(self + 0x66);
      sys = G(u8 *, 0x70039c);
      if (f66 != 0.0f) {
        float s = rdf(self + 0x5a) + rdf(self + 0x56);
        s = s + f66;
        if (!(*(s32 *)(sys + 0x40) > tr(s * c))) {
          float l = *(float *)(sys + 0x48) / f66 + rdf(self + 0x62);
          wrf(self + 0x62, l);
          set_level(self);
          sys = G(u8 *, 0x70039c);
        }
      }
      float f5e = rdf(self + 0x5e);
      if (f5e == 0.0f) goto fin;
      float f6a = rdf(self + 0x6a);
      if (f6a != 0.0f) {
        if (!(*(s32 *)(sys + 0x40) < tr((f5e + rdf(self + 0x56)) * c))) {
          float l = rdf(self + 0x62) - *(float *)(sys + 0x48) / f6a;
          wrf(self + 0x62, l);
          set_level(self);
          sys = G(u8 *, 0x70039c);
        }
      }
      float s4 = f5e + rdf(self + 0x56);
      s4 = s4 + rdf(self + 0x6a);
      if (*(s32 *)(sys + 0x40) < tr(s4 * G(float, 0x678620))) return;
      u32 B = rd32(self + 0x52);
      if (!B) goto fin;
      u8 *o4 = lookup(B);
      if (o4) vcall<void>(o4, 0x210, 1u);
      wr32(self + 0x52, 0);
    }
  }
fin:
  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(4bf6b0, fn4bf6b0);
