// batch33054.cpp - h3 () batch 33054: tiny tier C wrappers
#include "ff.h"

extern "C" u32 THISCALL ext_642050(u8 *self);                      // returns eax
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 a);               // ret 4
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);               // ret 4
extern "C" void THISCALL ext_610100(u8 *self, u32 a);              // ret 4 (no-op)
extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" void THISCALL ext_488bc0(u8 *self);

#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x536840: thiscall(a) ret 4: p=[this+0x5302] (unaligned); !p ? 0 : q=p+[p]; slot 0x1ac([q+0x2c], [q+0x14], a)
static u32 THISCALL fn536840(u8 *self, u32 a) {
  u8 *p = *(u8 **)(self + 0x5302);
  if (!p) return 0;
  u8 *q = p + *(u32 *)p;
  return vcall<u32>(self, 0x1ac, *(u32 *)(q + 0x2c), *(u32 *)(q + 0x14), a);
}
PCREG(536840, fn536840);

// 0x536950: same with slot 0x1b0([q+0x18], [q], a)
static u32 THISCALL fn536950(u8 *self, u32 a) {
  u8 *p = *(u8 **)(self + 0x5302);
  if (!p) return 0;
  u8 *q = p + *(u32 *)p;
  return vcall<u32>(self, 0x1b0, *(u32 *)(q + 0x18), *(u32 *)q, a);
}
PCREG(536950, fn536950);

// 0x554cc0: thiscall(a) ret 4: r=[sysobj+0x1aa3]->slot 0x94(); x=0x642050(r); return 0x5002f0(0x5003d0([a+8],0), x)
static u32 THISCALL fn554cc0(u8 *self, u8 *a) {
  u8 *o = *(u8 **)(*(u8 **)0x70039c + 0x1aa3);
  u8 *r = vcall<u8 *>(o, 0x94);
  u32 x = ext_642050(r);
  u8 *t = ext_5003d0(*(u8 **)(a + 8), 0);
  return ext_5002f0(t, x);
}
PCREG(554cc0, fn554cc0);

// 0x574df0: thiscall(a) ret 4: 0x610100(this,a); r=0x4e5e60(a); [this+0x1dc] = table->slot 0x58(r)
static void THISCALL fn574df0(u8 *self, u8 *a) {
  ext_610100(self, (u32)a);
  u32 r = ext_4e5e60(a);
  *(u32 *)(self + 0x1dc) = vcall<u32>(SYS_TABLE, 0x58, r);
}
PCREG(574df0, fn574df0);

// 0x5e4600: thiscall: 0x488bc0; vt read once for slot 0x58(0x68d410) -> [this+0x5e5]; then vt re-read for slot 0x54(this+0x5e5)
static u32 THISCALL fn5e4600(u8 *self) {
  ext_488bc0(self);
  u8 *vt = *(u8 **)self;
  u32 r = ((u32(THISCALL *)(u8 *, u32)) * (u32 *)(vt + 0x58))(self, 0x68d410);
  *(u32 *)(self + 0x5e5) = r;
  return vcall<u32>(self, 0x54, (u32)(self + 0x5e5));
}
PCREG(5e4600, fn5e4600);

// 0x5f94b0: stdcall(a,b) ret 8: r = g->slot 0x20(str, 0x2a7); log-style cdecl slot 0x2c of r(r, s1, s2); assert hook; return its eax
typedef u32 (*hook_t)();
typedef u32 (__attribute__((cdecl)) *log3_t)(u8 *, u32, u32);
static u32 STDCALL fn5f94b0(u32 a, u32 b) {
  u8 *g = G(u8 *, 0x700390);
  u8 *r = vcall<u8 *>(g, 0x20, 0x6b8a64u, 0x2a7u);
  (*(log3_t *)(*(u8 **)r + 0x2c))(r, 0x69c6b0, 0x69c7f0);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(5f94b0, fn5f94b0);

// 0x656460: thiscall(a) ret 4: r = slot 0xc(0); r2 = slot 0xc([r]); return r2[a]
static u32 THISCALL fn656460(u8 *self, u32 a) {
  u8 *r = vcall<u8 *>(self, 0xc, 0u);
  u8 *r2 = vcall<u8 *>(self, 0xc, *(u32 *)r);
  return *(u32 *)(r2 + a * 4);
}
PCREG(656460, fn656460);

// 0x46e3e0: thiscall(a) ret 4: c = slot 0x100(0x67a110); c ? c->slot 0x8c(0, 0, a, 0) : 0
static u32 THISCALL fn46e3e0(u8 *self, u32 a) {
  u8 *c = vcall<u8 *>(self, 0x100, 0x67a110u);
  if (!c) return 0;
  return vcall<u32>(c, 0x8c, 0u, 0u, a, 0u);
}
PCREG(46e3e0, fn46e3e0);
