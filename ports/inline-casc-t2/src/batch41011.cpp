// batch41011.cpp - cascade t2 (Sonnet): tier H function 0x4fbd50.
#include "ff.h"

static inline u32 rd32(const u8 *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((u32)p[3] << 24); }

extern "C" void FASTCALL ext_633654(u32 cookie); // /GS check

// 0x4fbd50, thiscall, no args, returns bool in al (/GS frame): a = sys[0x9b] slot 0x58([this+0x59]), null -> 0; b = sys[0x9b] slot 0x58([this+0x51]), null -> 0;
// v = {0,0,0}; a slot 0x84(&v); v[1] += K(0x67cd40); b slot 0x8c(&v); r = b slot 0x180(&v, -10.0f (0xc1200000)); return r != 0 (low byte).
static u8 THISCALL fn4fbd50(u8 *self) {
  u8 r = 0;
  void *a = vcall<void *>((void *)rd32(G(u8 *, 0x70039c) + 0x9b), 0x58, rd32(self + 0x59));
  if (a) {
    void *b = vcall<void *>((void *)rd32(G(u8 *, 0x70039c) + 0x9b), 0x58, rd32(self + 0x51));
    if (b) {
      float v[3] = {0.0f, 0.0f, 0.0f};
      vcall<void>(a, 0x84, (u32)v);
      v[1] = v[1] + G(float, 0x67cd40);
      vcall<void>(b, 0x8c, (u32)v);
      u8 t = (u8)vcall<u32>(b, 0x180, (u32)v, 0xc1200000u);
      r = (t != 0);
    }
  }
  ext_633654(0);
  return r;
}
PCREG(4fbd50, fn4fbd50);
