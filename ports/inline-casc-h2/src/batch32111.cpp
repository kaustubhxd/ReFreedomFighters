// batch32111.cpp - cascade h2 (): two tier H (float / SSE) functions.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *self);                 // thiscall, plain ret
extern "C" u32 THISCALL ext_4e5e40(u8 *self);                 // thiscall, plain ret, result in AX
extern "C" float THISCALL ext_4e5e80(u8 *self);               // thiscall, plain ret, float in st0
extern "C" void THISCALL ext_59cb60(u8 *self, u8 *p);         // thiscall ret 4
extern "C" u8 THISCALL ext_561be0(u8 *self);                  // thiscall, plain ret, bool in AL
extern "C" void THISCALL ext_5ae710(u8 *self, u32 a);         // thiscall ret 4
extern "C" u32 THISCALL ext_562bc0(u8 *self);                 // thiscall, plain ret (tail jump target)

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }
static inline void wrf(u8 *p, float f) { u32 b; __builtin_memcpy(&b, &f, 4); wr32(p, b); }

// 0x584b40, thiscall(a) ret 4: three floats [this+0x51], [this+0x55], [this+0x59] (unaligned) = three 0x4e5e80(a); one discarded 0x4e5e60(a); byte [this+0x5d] = (0x4e5e60(a) != 0); word [this+0x48] = AX of 0x4e5e40(a);
// [this+0x4a] = 0x4e5e60(a); word [this+0x4e] = AX of 0x4e5e40(a); byte [this+0x50] = (0x4e5e60(a) != 0).
static void THISCALL fn584b40(u8 *self, u8 *a) {
  wrf(self + 0x51, ext_4e5e80(a));
  wrf(self + 0x55, ext_4e5e80(a));
  wrf(self + 0x59, ext_4e5e80(a));
  ext_4e5e60(a);
  self[0x5d] = ext_4e5e60(a) != 0;
  u32 w = ext_4e5e40(a);
  self[0x48] = w;
  self[0x49] = w >> 8;
  wr32(self + 0x4a, ext_4e5e60(a));
  u32 w2 = ext_4e5e40(a);
  self[0x4e] = w2;
  self[0x4f] = w2 >> 8;
  self[0x50] = ext_4e5e60(a) != 0;
}
PCREG(584b40, fn584b40);

// 0x575ee0, thiscall no args, returns the last callee's eax: 0x59cb60([this+0x94], this+0x206); o = engine table slot 0x60 with unaligned [this+0x21d]; o set -> byte [o+0xec] = 1,
// [o+0xed] = (float)[[0x70039c]+0x40] * K(0x6785e4), [o+0xf1] = [o+0x88], [o+0xf5] = [o+0x88] / K2(0x67a284); 0x561be0(this) true -> slot 0xd0 of this with unaligned [this+0x219];
// else 0x5ae710([this+0x94]+0x57, 0) and tail jump to 0x562bc0(this).
static u32 THISCALL fn575ee0(u8 *self) {
  ext_59cb60(*(u8 **)(self + 0x94), self + 0x206);
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x60, rd32(self + 0x21d));
  if (o) {
    o[0xec] = 1;
    wrf(o + 0xed, (float)*(s32 *)(G(u8 *, 0x70039c) + 0x40) * G(float, 0x6785e4));
    float w = *(float *)(o + 0x88);
    wrf(o + 0xf1, w);
    wrf(o + 0xf5, w / G(float, 0x67a284));
  }
  if (ext_561be0(self)) return vcall<u32>(self, 0xd0, rd32(self + 0x219));
  ext_5ae710(*(u8 **)(self + 0x94) + 0x57, 0);
  return ext_562bc0(self);
}
PCREG(575ee0, fn575ee0);
