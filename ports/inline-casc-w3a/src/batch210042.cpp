// batch210042.cpp - Sonnet-w3a: small BLOCKED rows (serialize list of typed records, kind switch with engine lookups)
#include "ff.h"

extern "C" u32 THISCALL ext_5f9db0(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }
typedef u32 (*HookU)();

static void THISCALL fn603990(u8 *self, u8 *a) {
  u8 *vt = *(u8 **)a;
  u32 v = vcall<u32>(self, 0x38);  // @603990_a
  typedef u32 (THISCALL *F1)(u8 *, u32);
  (*(F1 *)vt)(a, v);  // @603990_b
  for (u32 i = 0; i < *(u32 *)(self + 0x14); i++) {  // @603990_c
    u8 *rec = *(u8 **)(self + 0xc) + i * 8;
    if (rec[4] == 4) {  // @603990_d
      u8 *o = *(u8 **)rec;
      u8 *vt2 = *(u8 **)a;
      u32 w = vcall<u32>(o, 0x38);  // @603990_e
      (*(F1 *)vt2)(a, w);  // @603990_f
      vcall<u32, u8 *>(*(u8 **)(*(u8 **)(self + 0xc) + i * 8), 0x3c, a);  // @603990_g
      ext_5f9db0(a, *(u8 **)(*(u8 **)(self + 0xc) + i * 8));  // @603990_h
    }
  }
}
PCREG(603990, fn603990);

static u32 STDCALL fn50dd50(u8 *a) {
  u8 *x = (u8 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @50dd50_a
  u32 kind = x[4];
  u32 edx;
  if (kind == 3) edx = *(u32 *)x;  // @50dd50_b
  else if (kind == 4) edx = vcall<u32>(*(u8 **)x, 0x34);  // @50dd50_c
  else {
    u8 *g = G(u8 *, 0x700390);
    u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69c8e0, 0x111);  // @50dd50_d
    typedef u32 (*F)(u8 *, u32, u32);
    F f = *(F *)(*(u8 **)o + 0x2c);
    f(o, 0x69c6b0, 0x69c9b0);  // @50dd50_e
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    edx = 0;
  }
  u8 *q = *(u8 **)(mgr() + 0xadc);
  u32 v = vcall<u32, u32, u32>(q, 0x25c, edx, 0);  // @50dd50_f
  u32 w = vcall<u32, u32>(mgr(), 0x4c, v);  // @50dd50_g
  u8 *z = (u8 *)ext_5003d0(*(u8 **)(a + 8), 0);  // @50dd50_h
  if (z[4] <= 1) {  // @50dd50_i
    *(u32 *)z = w;  // @50dd50_j
    z[4] = 1;
    return (u32)z;
  }
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69c8e0, 0xc4);  // @50dd50_k
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69c938);  // @50dd50_l
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(50dd50, fn50dd50);
