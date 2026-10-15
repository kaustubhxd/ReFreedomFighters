// batch32103.cpp - cascade h2 (Sonnet): three tier H (float / SSE) functions.
#include "ff.h"

extern "C" void THISCALL ext_515950(u8 *self);                      // thiscall, plain ret
extern "C" void THISCALL ext_515d00(u8 *self);                      // thiscall, plain ret
extern "C" u32 THISCALL ext_523180(u8 *self);                       // thiscall, plain ret (tail jump target)
extern "C" void THISCALL ext_593f40(u8 *self, u32 a);               // thiscall ret 4
extern "C" u32 THISCALL ext_594040(u8 *self, u32 a, u32 b);         // thiscall ret 8
extern "C" u32 THISCALL ext_596d70(u8 *self, u32 a, u32 b);         // thiscall ret 8

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline float rdf(const u8 *p) { u32 b = rd32(p); float f; __builtin_memcpy(&f, &b, 4); return f; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }
static inline u8 *engTable() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x515c70, thiscall no args: byte [this+0x133] != 0 -> return. o = engine table slot 0x58 with unaligned [this+0x123]; when o set and bit 0x1000 of [[o+8]+0x3c]: 0x515950(this), 0x515d00(this).
// Then f = unaligned float [this+0x233]: f > K(0x679540) -> f -= [[0x70039c]+0x48] and return; else when byte [[this+0x5c]+0x46] is set: [this+0x233] = 0 and tail jump to 0x523180([this+0x5c]).
static u32 THISCALL fn515c70(u8 *self) {
  if (self[0x133]) return 0;
  u8 *o = vcall<u8 *>(engTable(), 0x58, rd32(self + 0x123));
  if (o) {
    if (*(u32 *)(*(u8 **)(o + 8) + 0x3c) & 0x1000) {
      ext_515950(self);
      ext_515d00(self);
    }
  }
  float f = rdf(self + 0x233);
  if (f > G(float, 0x679540)) {
    wrf(self + 0x233, f - *(float *)(G(u8 *, 0x70039c) + 0x48));
    return 0;
  }
  u8 *c = *(u8 **)(self + 0x5c);
  if (!c[0x46]) return 0;
  wr32(self + 0x233, 0);
  return ext_523180(c);
}
PCREG(515c70, fn515c70);

// 0x4703b0, thiscall no args: slot 0x358 of this with 1; o = slot 0x350 of this; f = float (st0) of slot 0x338 of o; [this+0xd1] = (float)([[0x70039c]+0x40] + 0x66 - (int)trunc((float)(f * K(0x678620)))) * K2(0x6785e4) (unaligned).
static void THISCALL fn4703b0(u8 *self) {
  vcall<void>(self, 0x358, 1u);
  void *o = vcall<void *>(self, 0x350);
  s32 base = *(s32 *)(G(u8 *, 0x70039c) + 0x40) + 0x66;
  float f = vcall<float>(o, 0x338);
  float p = (float)((double)f * (double)G(float, 0x678620));
  s32 t;
  __asm__("cvttss2si %1, %0" : "=r"(t) : "m"(p));
  wrf(self + 0xd1, (float)(base - t) * G(float, 0x6785e4));
}
PCREG(4703b0, fn4703b0);

// 0x597e90, thiscall no args, returns the last callee's eax: 0x593f40([this+0x1d0b], 0); f = float (st0) of slot 0x1c0 of the engine object with (0x6ad250, 0x36c); k = f > K(0x67a6ac) ? 0x13 : 0x15;
// [this+0xdd] = 0x594040([this+0x1d0b], k, 1) (unaligned); returns 0x596d70(this, 3, 0).
static u32 THISCALL fn597e90(u8 *self) {
  ext_593f40((u8 *)rd32(self + 0x1d0b), 0);
  float f = vcall<float>(G(void *, 0x70039c), 0x1c0, 0x6ad250u, 0x36cu);
  u8 *o = (u8 *)rd32(self + 0x1d0b);
  u32 k = (f > G(float, 0x67a6ac)) ? 0x13 : 0x15;
  u32 r = ext_594040(o, k, 1);
  wr32(self + 0xdd, r);
  return ext_596d70(self, 3, 0);
}
PCREG(597e90, fn597e90);
