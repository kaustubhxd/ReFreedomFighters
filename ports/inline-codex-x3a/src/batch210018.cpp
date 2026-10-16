// batch210018.cpp - Sonnet-w3a: small BLOCKED rows (engine-table out-param slots, fastcall edx pointer, dtor with buffers, callback classifier, loop)
#include "ff.h"

extern "C" u32 ext_41e2c0(u32 p);
extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_4dbe30(u8 *self, u32 a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn5c2ec0(u8 *self) {
  u8 *g = (u8 *)vcall<u32>(mgr(), 0x134);  // @5c2ec0_a
  u32 local = 0;
  u32 r = vcall<u32, u32, u32 *>(g, 0x88, 0x6b3d60, &local);  // @5c2ec0_b
  if (local != 0) {  // @5c2ec0_c
    u8 *g2 = (u8 *)vcall<u32>(mgr(), 0x134);
    r = vcall<u32, u8 *, u32, u32>(g2, 0x6c, self + 0xe8, 0x6b3d74, 5);  // @5c2ec0_d
  }
  return r;
}
PCREG(5c2ec0, fn5c2ec0);

static u32 FASTCALL fn5f0cd0(u8 *entry_ecx, u32 edx) {
  u32 local = edx;
  u8 *s = (u8 *)vcall<u32, u8 *>(mgr(), 0x58, entry_ecx);  // @5f0cd0_a
  u8 *vt = *(u8 **)s;
  u32 ax = vcall<u32, u32, u32, u32, u32, u32 *>(mgr(), 0x114, 0x6a6684, 0, 0x6b82f4, 0x1a, &local) & 0xffff;  // @5f0cd0_b
  typedef u32 (THISCALL *F)(u8 *, u8 *, u32);
  return (*(F *)(vt + 0x130))(s, s, ax);  // @5f0cd0_c
}
PCREG(5f0cd0, fn5f0cd0);

static u8 *THISCALL fn477580(u8 *self, u32 flags) {
  u32 p = *(u32 *)(self + 0xc);
  if (p) ext_41e2c0(p);  // @477580_a
  u32 q = *(u32 *)(self + 0x10);
  if (q) ext_634273(q, 4);  // @477580_b
  u32 r = *(u32 *)(self + 0x14);
  if (r) ext_634273(r, 4);  // @477580_c
  if (flags & 1) ext_634273((u32)self, 0x18);  // @477580_d
  return self;
}
PCREG(477580, fn477580);

static u32 fn62c6c0(u8 *a, u32 b) {
  typedef u32 (*CB)(u32, u32);
  u32 r = (*(CB *)(a + 0x170))(*(u32 *)(a + 0x174), b);  // @62c6c0_a
  if (r & 0xffff0000u) return 1;  // @62c6c0_b
  int ecx = (int)r >> 8;
  if (ecx > 0xdf) {
    if (ecx == 0xff) {  // @62c6c0_c
      if (r == 0xfffe) return 1;
      if (r == 0xffff) return 1;
    }
  } else {
    if (ecx >= 0xd8) return 1;  // @62c6c0_d
    if (ecx == 0) {
      if (*(u8 *)(0x6bf2f4 + r) == 0) return 1;  // @62c6c0_e
    }
  }
  // original also tests r < 0 (js) here: unreachable, r < 0x10000 after the high-word test
  return 0;
}
PCREG(62c6c0, fn62c6c0);

static u32 STDCALL fn493090(u32 *a) {
  u32 r = vcall<u32>(mgr(), 0x2c);  // @493090_a
  if (r & 0xff) return r;  // @493090_b
  if (a[0] != 0) {
    u32 i = 0;
    u32 *p = a + 1;
    do {
      u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x54, *p);  // @493090_c
      r = ext_4dbe30(o, 1);  // @493090_d
      i++;
      p += 2;
    } while (i != a[0]);  // @493090_e
  }
  return r;
}
PCREG(493090, fn493090);
