// batch32133.cpp - cascade h2 (): three tier H (float / SSE) functions.
#include "ff.h"
#include <xmmintrin.h>

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }

extern "C" void FASTCALL ext_633654(u32 cookie);          // /GS check
extern "C" void THISCALL ext_441790(u8 *self, void *o);   // thiscall ret 4
extern "C" void THISCALL ext_4db500(u8 *self, float *out);// thiscall ret 4: out[0..2] = this[0x24..0x2c]
extern "C" void THISCALL ext_52c000(u8 *self, u32 a);     // thiscall ret 4

// 0x470720, thiscall(o) ret 4, returns true (al): 0x441790(this, o); then on o: slot 0x6c([this+0x70]), slot 0x70(this+0xdb), slot 0x68(this+0xff), slot 0x4c(float [this+0x10b]), slot 0x4c(float [this+0x10f]),
// slot 0x64([this+0x11b]), slot 0x64([this+0x11f]), slot 0x64([this+0x123]), slot 0x64([this+0x127]).
static u8 THISCALL fn470720(u8 *self, void *o) {
  ext_441790(self, o);
  vcall<void>(o, 0x6c, rd32(self + 0x70));
  vcall<void>(o, 0x70, (u32)(self + 0xdb));
  vcall<void>(o, 0x68, (u32)(self + 0xff));
  vcall<void>(o, 0x4c, rdf(self + 0x10b));
  vcall<void>(o, 0x4c, rdf(self + 0x10f));
  vcall<void>(o, 0x64, rd32(self + 0x11b));
  vcall<void>(o, 0x64, rd32(self + 0x11f));
  vcall<void>(o, 0x64, rd32(self + 0x123));
  vcall<void>(o, 0x64, rd32(self + 0x127));
  return 1;
}
PCREG(470720, fn470720);

// 0x4f8510, thiscall(flag byte) ret 4 (/GS frame): o = slot 0x58 of [[0x70039c]+0x9b] with [this+0xab]; o == 0 -> only the /GS check.
// y = (float)(int)trunc(f[this+0xa3] * f[this+0x9f] - (float)(int)[this+0xa7]); tmp = 0x4db500([o+8]) (3 dwords [obj+0x24..0x2c]);
// tmp[0] is not ordered-equal to (float)y -> tmp[0] = (float)y; slot 0x70 of o with &tmp; if flag != 0: slot 0x358 of this.
static void THISCALL fn4f8510(u8 *self, u32 flag) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *o = vcall<u8 *>(*(void **)(eng + 0x9b), 0x58, rd32(self + 0xab));
  if (o) {
    float tmp[3];
    float t = rdf(self + 0xa3) * rdf(self + 0x9f) - (float)(s32)rd32(self + 0xa7);
    s32 yi = _mm_cvttss_si32(_mm_set_ss(t));
    ext_4db500(*(u8 **)(o + 8), tmp);
    float y = (float)yi;
    if (!(tmp[0] == y)) {
      tmp[0] = y;
      vcall<void>(o, 0x70, (u32)tmp);
      if ((u8)flag) vcall<void>(self, 0x358);
    }
  }
  ext_633654(0);
}
PCREG(4f8510, fn4f8510);

// 0x52ab00, thiscall no args: a profiler scope pair around 0x52c000(this, 0): when both floats [eng+0x9c7] and [eng+0x9c3] are not ordered-equal to 0:
// r = slot 0x1c8 of eng with (0x67a7f8, 0x259) (edx:eax), then slot 0x178 of the engine with (eax, edx, 0x6a0f48); after the call the same with line 0x260 and slot 0x17c.
static void THISCALL fn52ab00(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  if (!(rdf(eng + 0x9c7) == 0.0f) && !(rdf(eng + 0x9c3) == 0.0f)) {
    u64 t = vcall<u64>(eng, 0x1c8, 0x67a7f8u, 0x259u);
    u8 *eng2 = G(u8 *, 0x70039c);
    vcall<void>(eng2, 0x178, (u32)t, (u32)(t >> 32), 0x6a0f48u);
  }
  ext_52c000(self, 0);
  eng = G(u8 *, 0x70039c);
  if (!(rdf(eng + 0x9c7) == 0.0f) && !(rdf(eng + 0x9c3) == 0.0f)) {
    u64 t = vcall<u64>(eng, 0x1c8, 0x67a7f8u, 0x260u);
    u8 *eng2 = G(u8 *, 0x70039c);
    vcall<void>(eng2, 0x17c, (u32)t, (u32)(t >> 32), 0x6a0f48u);
  }
}
PCREG(52ab00, fn52ab00);
