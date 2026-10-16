// batch210038.cpp - Sonnet-w3a: small BLOCKED rows (stored-value lookup, flag-driven engine update)
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5979c0(u8 *self);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }
typedef u32 (*HookU)();

static u32 STDCALL fn555290(u8 *a) {
  u8 *x = (u8 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @555290_a
  u8 kind = x[4];
  if (kind != 0 && kind != 1) {  // @555290_b
    u8 *g = G(u8 *, 0x700390);
    u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69c8e0, 0x104);  // @555290_c
    typedef u32 (*F)(u8 *, u32, u32);
    F f = *(F *)(*(u8 **)o + 0x2c);
    f(o, 0x69c6b0, 0x69c938);  // @555290_d
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  u32 id = *(u32 *)x;
  u8 *y = (u8 *)ext_5003d0(*(u8 **)(a + 4), 1);  // @555290_e
  u32 local = *(u32 *)y;
  u32 edi = 0xffffffffu;
  u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, id);  // @555290_f
  if (o) {
    u8 *m = (u8 *)ld32(o + 0x852);
    if (m) {
      edi = ld32(m + 0x1fae);  // @555290_g
      if (local) edi -= ext_5979c0(m);  // @555290_h
    }
  }
  return ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), edi);  // @555290_i
}
PCREG(555290, fn555290);

static u32 THISCALL fn44c2b0(u8 *self) {
  u32 v = *(u32 *)(*(u8 **)(self + 8) + 0x3c);
  u32 eax = v >> 10;
  eax = (eax & ~0xffu) | (~eax & 0xffu);  // @44c2b0_a
  if (!(eax & 1)) return eax;  // @44c2b0_b
  u8 *e = (u8 *)ld32(G(u8 *, 0x70039c) + 0x1a9f);
  if (!e) return vcall<u32, u32>(self, 0x210, 1);  // @44c2b0_c
  u8 *obj = *(u8 **)(self + 0x18);
  *(u32 *)(obj + 4) = 3;  // @44c2b0_d
  u32 r = vcall<u32, u32>(e, 0x48, *(u32 *)(self + 0x1c));  // @44c2b0_e
  if (!(r & 0xff)) {
    obj = *(u8 **)(self + 0x18);
    u32 t = *(u32 *)(obj + 0x40) & 2;
    *(u32 *)(obj + 0x40) = t;  // @44c2b0_f
    if (!t) return (u32)obj;
    return vcall<u32, u32>(self, 0x210, 1);  // @44c2b0_g
  }
  u8 *src = *(u8 **)(self + 8);
  u8 *dst = *(u8 **)(self + 0x18);
  *(u32 *)(dst + 0x14) = *(u32 *)(src + 0x24);  // @44c2b0_h
  *(u32 *)(dst + 0x18) = *(u32 *)(src + 0x28);
  *(u32 *)(dst + 0x1c) = *(u32 *)(src + 0x2c);  // @44c2b0_i
  src = *(u8 **)(self + 8);
  dst = *(u8 **)(self + 0x18);
  *(u32 *)(dst + 0x20) = *(u32 *)src;  // @44c2b0_j
  *(u32 *)(dst + 0x24) = *(u32 *)(src + 4);
  *(u32 *)(dst + 0x28) = *(u32 *)(src + 8);  // @44c2b0_k
  u8 *mg = mgr();
  u32 ret = (u32)mg;
  if (mg[0xbaf]) ret = vcall<u32, u32>(self, 0xb4, 1);  // @44c2b0_l
  self[0x20] = 1;  // @44c2b0_m
  return ret;
}
PCREG(44c2b0, fn44c2b0);
