// batch210019.cpp - Sonnet-w3a: small BLOCKED rows (buffer read with clamp, flag lookup chain, grow-copy, state reset, bool-compare loop)
#include "ff.h"

extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);
extern "C" u32 ext_41e290(u32 n);
extern "C" u32 ext_41e2c0(u32 p);
extern "C" u32 THISCALL ext_478ea0(u8 *self, u8 *a, u32 b);
extern "C" u32 THISCALL ext_5b0b70(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5c2c10(u8 *self, u32 a);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

typedef u32 (*HookU)();
static u32 THISCALL fn4d5310(u8 *self, u32 a, u32 b, u8 *c) {
  u8 *edi = self + 4;
  if (c != edi) {  // @4d5310_a
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    return h();
  }
  u32 pos = *(u32 *)(edi + 4);
  u32 n = *(u32 *)(edi + 8) - pos;
  if (b < n) n = b;  // @4d5310_b
  if (n) {
    ext_634d22(a, *(u32 *)edi + pos, n);  // @4d5310_c
    *(u32 *)(edi + 4) += n;  // @4d5310_d
  }
  return n;
}
PCREG(4d5310, fn4d5310);

static u32 STDCALL fn55ff50(u8 *a) {
  u32 *r = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @55ff50_a
  u32 edx = *r;
  u32 flag = 0;
  if (edx) {
    u8 *o = (u8 *)vcall<u32, u32>((u8 *)ld32(G(u8 *, 0x70039c) + 0x9b), 0x58, edx);  // @55ff50_b
    if (o) {
      if (vcall<u32, u32>(o, 0x1e0, 0x2003e8) & 0xff) flag = 1;  // @55ff50_c
    }
  }
  u8 *z = (u8 *)ext_5003d0(*(u8 **)(a + 8), 0);  // @55ff50_d
  return ext_5002f0(z, flag);  // @55ff50_e
}
PCREG(55ff50, fn55ff50);

static u32 THISCALL fn5ff0a0(u8 *self) {
  u16 *old = *(u16 **)self;
  u32 n2 = *(u32 *)(self + 4) * 2;  // @5ff0a0_a
  u64 bytes = (u64)n2 * 2;
  u32 size = (bytes >> 32) ? 0xffffffffu : (u32)bytes;
  u16 *buf = (u16 *)ext_41e290(size);  // @5ff0a0_b
  *(u16 **)self = buf;
  for (u32 i = 0; i < *(u32 *)(self + 4); i++) buf[i] = old[i];  // @5ff0a0_c
  u32 r = ext_41e2c0((u32)old);  // @5ff0a0_d
  *(u32 *)(self + 4) = n2;  // @5ff0a0_e
  return r;
}
PCREG(5ff0a0, fn5ff0a0);

static u32 THISCALL fn47bf10(u8 *self, u8 *a, u32 b) {
  if (ld32(self + 0x695) != 0) vcall<u32, u32, u32, u32>(self, 0x628, 2, 0, 0);  // @47bf10_a
  st32(self + 0x695, (u32)a);  // @47bf10_b
  st32(self + 0x722, 0);  // @47bf10_c
  ext_478ea0(a, self + 0x660, 0);  // @47bf10_d
  st32(self + 0x678, 0x42c80000);  // @47bf10_e
  self[0x726] = 1;  // @47bf10_f
  st32(self + 0x732, 0);
  self[0x72f] = 0;
  self[0x699] = 0;  // @47bf10_g
  if ((u8)b) self[0x6fe] = 0;  // @47bf10_h
  vcall<u32>(self, 0x5f4);  // @47bf10_i
  return vcall<u32>(self, 0x5f8);  // @47bf10_j
}
PCREG(47bf10, fn47bf10);

static void THISCALL fn5c2f90(u8 *self) {
  if (*(u32 *)(self + 4) == 0) return;
  int i = 0;
  if (*(int *)(self + 0x2c0) > i) {
    u8 *p = self + 0x14;
    do {
      u32 x = ext_5b0b70(*(u8 **)(self + 4), *(u32 *)(p - 8)) != 0;  // @5c2f90_a
      if (x == p[0]) {  // @5c2f90_b
        u32 y = ext_5b0b70(*(u8 **)(self + 4), *(u32 *)(p - 4)) != 0;  // @5c2f90_c
        if (y == p[1]) ext_5c2c10(self, i);  // @5c2f90_d
      }
      i++;
      p += 0xe;
    } while (i < *(int *)(self + 0x2c0));  // @5c2f90_e
  }
}
PCREG(5c2f90, fn5c2f90);
