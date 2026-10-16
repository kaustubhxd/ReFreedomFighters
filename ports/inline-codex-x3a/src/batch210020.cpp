// batch210020.cpp - Sonnet-w3a: small BLOCKED rows (array membership, bit-buffer flush, chain iterator init, release loop, engine flag check)
#include "ff.h"

extern "C" u32 THISCALL ext_4db580(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4dc1e0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_56ad00(u8 *self, u32 a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u8 THISCALL fn5fb550(u8 *self, u32 a) {
  u32 i = 0;
  if (*(u32 *)(self + 0x20) > i) {
    do {
      if (a == (*(u32 **)(self + 0x18))[i]) return 1;  // @5fb550_a
      i++;
    } while (i < *(u32 *)(self + 0x20));  // @5fb550_b
  }
  return 0;
}
PCREG(5fb550, fn5fb550);

static u32 fn630120(u8 *a) {
  u32 n = *(u32 *)(a + 0x16b4);
  if (n == 0x10) {  // @630120_a
    u8 *buf = *(u8 **)(a + 8);
    buf[*(u32 *)(a + 0x14)] = a[0x16b0];  // @630120_b
    (*(u32 *)(a + 0x14))++;
    (*(u8 **)(a + 8))[*(u32 *)(a + 0x14)] = a[0x16b1];  // @630120_c
    (*(u32 *)(a + 0x14))++;
    *(u32 *)(a + 0x16b4) = 0;
    *(u16 *)(a + 0x16b0) = 0;
    return 0;
  }
  if ((int)n >= 8) {  // @630120_d
    u8 *buf = *(u8 **)(a + 8);
    buf[*(u32 *)(a + 0x14)] = a[0x16b0];
    u32 b1 = a[0x16b1];
    (*(u32 *)(a + 0x14))++;
    *(u32 *)(a + 0x16b4) -= 8;  // @630120_e
    *(u16 *)(a + 0x16b0) = (u16)b1;  // @630120_f
    return b1;
  }
  return n;
}
PCREG(630120, fn630120);

static u32 THISCALL fn440ce0(u8 *self, u8 *a) {
  *(u8 **)self = a;
  if (a) {
    for (;;) {
      u8 *cur = *(u8 **)self;
      u8 al = cur[8];
      if (al >= 2) break;  // @440ce0_a
      if (al & 1) {
        u8 *nx = *(u8 **)(cur + 0xc);
        *(u8 **)self = nx;  // @440ce0_b
        if (nx) continue;
        break;
      }
      *(u8 **)self = 0;  // @440ce0_c
      break;
    }
  }
  u8 *n = *(u8 **)self;
  *(u32 *)(self + 4) = 0;
  if (!n) return 0;
  u8 *p = n + 0xc;
  *(u8 **)(self + 4) = p;
  if (n[8] & 1) *(u8 **)(self + 4) = p + 4;  // @440ce0_d
  u8 *e = *(u8 **)self;
  u32 r = (u32)(e + ((u32)e[8] + 3) * 4);  // @440ce0_e
  *(u32 *)(self + 8) = r;
  return r;
}
PCREG(440ce0, fn440ce0);

static u32 THISCALL fn4dae60(u8 *self) {
  u32 id = *(u16 *)(self + 0x5c);
  if (id == 0) return 0;  // @4dae60_a
  u8 *h = *(u8 **)(mgr() + 8);
  u8 *o = (u8 *)vcall<u32, u32>(h, 0x5c, id);  // @4dae60_b
  if (o) {
    if (o[0x1c]) {
      do {
        u32 r = ext_4db580(o, 0);  // @4dae60_c
        ext_4dc1e0(self, r);  // @4dae60_d
      } while (o[0x1c]);  // @4dae60_e
    }
    u8 *h2 = *(u8 **)(mgr() + 8);
    vcall<u32, u8 *>(h2, 0x54, o);  // @4dae60_f
    *(u16 *)(self + 0x5c) = 0;  // @4dae60_g
  }
  return 0;
}
PCREG(4dae60, fn4dae60);

static u8 THISCALL fn56a7e0(u8 *self, u32 a, u32 b) {
  (void)a;
  if (ld32(self + 0x1c5) == 4) {  // @56a7e0_a
    u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, b);  // @56a7e0_b
    if (o && (vcall<u32, u32>(o, 0x1e0, 0x100033) & 0xff)) {  // @56a7e0_c
      u32 r = vcall<u32>(o, 0x310);  // @56a7e0_d
      ext_56ad00(self, r);  // @56a7e0_e
    }
  }
  return 0;
}
PCREG(56a7e0, fn56a7e0);
