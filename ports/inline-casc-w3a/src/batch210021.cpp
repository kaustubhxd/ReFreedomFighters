// batch210021.cpp - Sonnet-w3a: small BLOCKED rows (table clear, dtor with record array, stack-buffer slot loop, out-param init, member loop)
#include "ff.h"

extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 STDCALL ext_610100(u8 *a);
extern "C" u32 THISCALL ext_4e12e0(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_4e14a0(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_5fa590(u8 *self, u8 *a, u32 b);
extern "C" u32 THISCALL ext_605a10(u8 *self, u8 *a, u32 b, u32 c);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 fn630c50(u8 *a) {
  for (u32 i = 0; i < 0x11e; i++) *(u16 *)(a + 0x8c + i * 4) = 0;  // @630c50_a
  for (u32 i = 0; i < 0x1e; i++) *(u16 *)(a + 0x980 + i * 4) = 0;  // @630c50_b
  for (u32 i = 0; i < 0x13; i++) *(u16 *)(a + 0xa74 + i * 4) = 0;  // @630c50_c
  *(u32 *)(a + 0x16a4) = 0;  // @630c50_d
  *(u32 *)(a + 0x16a0) = 0;
  *(u32 *)(a + 0x16a8) = 0;
  *(u32 *)(a + 0x1698) = 0;  // @630c50_e
  *(u16 *)(a + 0x48c) = 1;  // @630c50_f
  return 1;
}
PCREG(630c50, fn630c50);

static u32 THISCALL fn6363a0(u8 *self) {
  *(u32 *)self = 0x6c1f6c;  // @6363a0_v
  if (*(u32 *)(self + 0x10) > 0) {
    u32 i = 0;
    do {
      u8 *rec = *(u8 **)(self + 0x14) + i * 0x14;
      if (rec[0xc]) ext_634273(*(u32 *)(rec + 0x10), 1);  // @6363a0_a
      i++;
    } while (i < *(u32 *)(self + 0x10));
  }
  u32 p = *(u32 *)(self + 0x14);
  u32 r = p;
  if (p) r = ext_634273(p, 0x14);  // @6363a0_b
  if (self[0x28]) r = ext_634273(*(u32 *)(self + 0x18), 1);  // @6363a0_c
  return r;
}
PCREG(6363a0, fn6363a0);

static u32 THISCALL fn439bd0(u8 *self, u8 *a) {
  u32 r = 0;
  if (!a) return 0;
  u32 buf[3];
  vcall<u32, u32 *>(a, 0x4c, buf);  // @439bd0_a
  r = vcall<u32, u32 *>(a, 0x64, buf);  // @439bd0_b
  while (r) {
    vcall<u32, u32>(self, 4, r);  // @439bd0_c
    r = vcall<u32, u32 *>(a, 0x64, buf);  // @439bd0_d
  }
  return 0;
}
PCREG(439bd0, fn439bd0);

static u32 THISCALL fn5d5ae0(u8 *self, u8 *a) {
  u8 *loc = a;
  ext_610100(a);  // @5d5ae0_a
  ext_4e12e0(a, self + 0x1d, 1);  // @5d5ae0_b
  ext_4e12e0(a, self + 0x21, 1);  // @5d5ae0_c
  ext_4e12e0(a, (u8 *)&loc, 1);  // @5d5ae0_d
  ext_4e14a0(a, self + 0x31, 1);  // @5d5ae0_e
  u32 v = vcall<u32, u8 *>(mgr(), 0x58, loc);  // @5d5ae0_f
  st32(self + 0x25, v);  // @5d5ae0_g
  return v;
}
PCREG(5d5ae0, fn5d5ae0);

static u32 THISCALL fn5c4b70(u8 *self) {
  u8 *g = (u8 *)vcall<u32>(mgr(), 0x134);  // @5c4b70_a
  volatile u8 flag = 0;
  u32 r = vcall<u32, u32, volatile u8 *>(g, 0x90, 0x68a9d4, &flag);  // @5c4b70_b
  if (flag != 0) return r;  // @5c4b70_c
  u8 *g2 = (u8 *)vcall<u32>(mgr(), 0x138);  // @5c4b70_d
  u32 loc = 0;
  vcall<u32, u32, u32 *>(g2, 0x88, 0x681320, &loc);  // @5c4b70_e
  u32 v = vcall<u32, u32>(mgr(), 0x58, loc);  // @5c4b70_f
  *(u32 *)(self + 0x60) = v;  // @5c4b70_g
  return v;
}
PCREG(5c4b70, fn5c4b70);

static u32 THISCALL fn604030(u8 *self, u8 *a, u32 b) {
  ext_5fa590(self, a, b);  // @604030_a
  u32 r = vcall<u32, u32>(a, 0x2c, *(u32 *)(self + 0x14));  // @604030_b
  for (u32 i = 0; i < *(u32 *)(self + 0x14); i++)
    r = ext_605a10(*(u8 **)(self + 0xc) + i * 8, a, b, 0);  // @604030_c
  return r;
}
PCREG(604030, fn604030);
