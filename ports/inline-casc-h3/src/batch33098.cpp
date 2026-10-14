// batch33098.cpp - h3 () batch 33098: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

static inline void W32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 R32(u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" void THISCALL ext_4804e0(u8 *self);                       // plain ret
extern "C" u8 *ext_41e290(u32 size);                                 // cdecl

// 0x5c3310: thiscall(s) ret 4, returns true: [this+4] &= ~0x40; s->slot 0x60(byte [+0x114]); s->slot 0x4c(float [+0x115], [+0x119], [+0x11d], [+0x121]); s->slot 0x60(byte [+0x125])
static u8 THISCALL fn5c3310(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<u32>(s, 0x60, (u32)self[0x114]);
  vcall<u32>(s, 0x4c, R32(self + 0x115));
  vcall<u32>(s, 0x4c, R32(self + 0x119));
  vcall<u32>(s, 0x4c, R32(self + 0x11d));
  vcall<u32>(s, 0x4c, R32(self + 0x121));
  vcall<u32>(s, 0x60, (u32)self[0x125]);
  return 1;
}
PCREG(5c3310, fn5c3310);

// 0x4805a0: thiscall no args: 0x4804e0(this); for i in 0..5: [this+0x34+12i] == 0.0 (ordered) -> [this+0x74+4i] = 0; else p=alloc(8): p[0]=1; q=alloc(0x18): p[4]=q; q[0..0x14)=0; q[0x14]=-1; [this+0x74+4i]=p
static void THISCALL fn4805a0(u8 *self) {
  ext_4804e0(self);
  u8 *dst = self + 0x74;
  u8 *src = self + 0x34;
  for (int i = 6; i != 0; i--, src += 12, dst += 4) {
    u8 *p;
    if (bitsf(R32(src)) == 0.0f) {
      p = 0;
    } else {
      p = ext_41e290(8);
      *(u32 *)p = 1;
      u8 *q = ext_41e290(0x18);
      *(u32 *)(p + 4) = (u32)q;
      for (int j = 0; j < 6; j++) *(u32 *)(q + 4 * j) = 0;
      *(u32 *)(q + 0x14) = 0xffffffffu;
    }
    *(u32 *)dst = (u32)p;
  }
}
PCREG(4805a0, fn4805a0);

// 0x471ad0: thiscall no args, bool: o=this->slot 0x350(); !o->slot 0x328() -> true; byte [this+0xbf]==0 -> false; r = this->slot 0x350()->slot 0x338() (x87); k=(int)(float)((r + [this+0xd1])*1024); return k <= [sys+0x40]
static u8 THISCALL fn471ad0(u8 *self) {
  u8 *o = vcall<u8 *>(self, 0x350);
  if (!vcall<u8>(o, 0x328)) return 1;
  if (self[0xbf] == 0) return 0;
  u8 *o2 = vcall<u8 *>(self, 0x350);
  double r = vcall<float>(o2, 0x338);
  double v = r + (double)bitsf(R32(self + 0xd1));
  v = v * 1024.0;
  float fv = (float)v;
  s32 k = _mm_cvttss_si32(_mm_set_ss(fv));
  return k <= *(s32 *)(SYS + 0x40);
}
PCREG(471ad0, fn471ad0);
