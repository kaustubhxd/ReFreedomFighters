// batch41004.cpp - cascade t2 (Sonnet): tier H float function 0x51f930.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }
static inline void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

extern "C" void FASTCALL ext_633654(u32 cookie);                              // /GS check
extern "C" void FASTCALL ext_43e920(void *out, const void *a, const void *b); // x87 vector subtract: out = a - b (ecx = out, edx = a, stack b, ret 4)

// 0x51f930, thiscall, no args (/GS frame): edi = this + 0x1678. When e = [this+0x1654] != 0: v = {0,0,0}; o = sys[0x9b] slot 0x58(e); o slot 0x84(&v); w = dwords [this+0x1660..0x1668];
// this slot 0x84(&w); 0x43e920(edi, &v, &w) (exe code, v - w); else edi[0..2] = dwords [this+0x6c..0x74]. Then this slot 0x90(edi); [this+0x167c] = 0; /GS check.
static void THISCALL fn51f930(u8 *self) {
  u8 *edi = self + 0x1678;
  u32 e = rd32(self + 0x1654);
  if (e) {
    u32 v[3] = {0, 0, 0};
    void *o = vcall<void *>((void *)rd32(G(u8 *, 0x70039c) + 0x9b), 0x58, e);
    vcall<void>(o, 0x84, (u32)v);
    u32 w[3];
    w[0] = rd32(self + 0x1660);
    w[1] = rd32(self + 0x1664);
    w[2] = rd32(self + 0x1668);
    vcall<void>(self, 0x84, (u32)w);
    ext_43e920(edi, v, w);
  } else {
    wr32(edi, rd32(self + 0x6c));
    wr32(edi + 4, rd32(self + 0x70));
    wr32(edi + 8, rd32(self + 0x74));
  }
  vcall<void>(self, 0x90, (u32)edi);
  wr32(self + 0x167c, 0);
  ext_633654(0);
}
PCREG(51f930, fn51f930);
