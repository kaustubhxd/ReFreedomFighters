// batch210047.cpp - Sonnet-w3a: three more /GS-protected rows (code table builder, object recreate, string format call)
#include "ff.h"

extern "C" void FASTCALL ext_633654(u32 cookie);  // /GS check
extern "C" u32 THISCALL ext_513d10(u8 *self);
extern "C" u32 THISCALL ext_4de7a0(u8 *self);
extern "C" u32 THISCALL ext_5ac940(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_5acac0(u8 *self, u32 a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static void fn630bb0(u16 *tree, int maxcode, const u16 *blcount) {
  u16 next[16];
  u32 code = 0;
  for (int i = 1; i <= 15; i++) {
    u16 ax = (u16)(blcount[i - 1] + (u16)code);  // @630bb0_a
    ax = (u16)(ax + ax);
    code = ax;
    next[i] = (u16)code;  // @630bb0_b
  }
  for (int n = 0; n <= maxcode; n++) {  // @630bb0_c
    u32 len = tree[n * 2 + 1];
    if (!len) continue;
    u32 c = next[len];
    next[len] = (u16)(c + 1);  // @630bb0_d
    u32 res = 0;
    do {
      res |= c & 1;  // @630bb0_e
      c >>= 1;
      res += res;
      len--;
    } while ((int)len > 0);
    res >>= 1;
    tree[n * 2] = (u16)res;  // @630bb0_f
  }
  ext_633654(0);
}
PCREG(630bb0, fn630bb0);

static void THISCALL fn5124d0(u8 *self) {
  u8 loc34[0x24];
  u32 loc10[3];
  vcall<u32, u32, u32>(self, 0x110, 0x10, 0);  // @5124d0_a
  vcall<u32, u32, u32>(self, 0x2c8, ld32(self + 0xce), 0);  // @5124d0_b
  ext_513d10(self);  // @5124d0_c
  u8 *m = *(u8 **)(self + 0x134);
  if (m) {  // @5124d0_d
    vcall<u32>(m, 0x28);  // @5124d0_e
    ext_4de7a0(loc34);  // @5124d0_f
    m = *(u8 **)(self + 0x134);
    loc10[0] = 0; loc10[1] = 0; loc10[2] = 0;
    u32 adcp = *(u32 *)(ld32(G(u8 *, 0x70039c) + 0x9b) + 0xadc);
    typedef u32 (THISCALL *F)(u8 *, u32, void *, void *, u32, u32, u32, u32);
    u32 r = (*(F *)(*(u8 **)m + 0x1bc))(m, adcp, loc34, loc10, 0, 0, 0, 1);  // @5124d0_g
    *(u32 *)(self + 0x134) = r;  // @5124d0_h
    vcall<u32>((u8 *)r, 0x28);  // @5124d0_i
  }
  vcall<u32>(self, 0x2e4);  // @5124d0_j
  ext_633654(0);
}
PCREG(5124d0, fn5124d0);

static void THISCALL fn5ab230(u8 *self, u32 a) {
  u8 loc[0x24];
  u8 *o = (u8 *)vcall<u32>(G(u8 *, 0x70039c), 0x190);  // @5ab230_a
  typedef u32 (*F)(u8 *, void *, u32, u32);
  (*(F *)(*(u8 **)o + 0x198))(o, loc, 0x6784f4, a);  // @5ab230_b
  ext_5ac940(*(u8 **)(self + 0x648), loc);  // @5ab230_c
  ext_5acac0(*(u8 **)(self + 0x648), 1);  // @5ab230_d
  ext_633654(0);
}
PCREG(5ab230, fn5ab230);
