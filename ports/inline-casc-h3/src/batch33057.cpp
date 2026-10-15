// batch33057.cpp - h3 (Sonnet) batch 33057: tier C wrappers
#include "ff.h"

extern "C" u32 THISCALL ext_4cc1d0(u8 *self);                      // 3 bytes
extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);           // ret 4, writes *out
extern "C" u32 THISCALL ext_597640(u8 *self);
extern "C" u32 THISCALL ext_597f70(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);

#define G7 (*(u8 **)0x70039c)
typedef u32 (*hook_t)();

// 0x48f840: thiscall(a) ret 4: vt of [this+0x104] read first; r=slot 4(a); x=0x4cc1d0(r); [this+0x104] re-read: vt->[0x12c](0, x)
static u32 THISCALL fn48f840(u8 *self, u32 a) {
  u8 *vto = *(u8 **)(*(u8 **)(self + 0x104));
  u32 r = vcall<u32>(self, 4, a);
  u32 x = ext_4cc1d0((u8 *)r);
  u8 *o2 = *(u8 **)(self + 0x104);
  return ((u32(THISCALL *)(u8 *, u32, u32)) * (u32 *)(vto + 0x12c))(o2, 0, x);
}
PCREG(48f840, fn48f840);

// 0x4afd90: thiscall(a) ret 4 bool: local=0; [this+4]&=~0x40; 0x6352f0(&local); slot 0x84(&local); return 1
static u32 THISCALL fn4afd90(u8 *self, u32 a) {
  u32 local = 0;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &local);
  vcall<u32>(self, 0x84, (u32)&local);
  return 1;
}
PCREG(4afd90, fn4afd90);

// 0x4b8e00: thiscall(a,b) ret 8: if (u16)a == word [this+0x48] slot 0x84(); if (u16)a == word [this+0x4a] slot 0x88(); return 0
static u32 THISCALL fn4b8e00(u8 *self, u32 a, u32 b) {
  u16 di = (u16)a;
  if (di == *(u16 *)(self + 0x48)) vcall<u32>(self, 0x84);
  if (di == *(u16 *)(self + 0x4a)) vcall<u32>(self, 0x88);
  return 0;
}
PCREG(4b8e00, fn4b8e00);

// 0x5396d0: thiscall: reset state; sub-object slot 0xc() at +0x53b2 and +0x5306; slot 0xf4(0)
static void THISCALL fn5396d0(u8 *self) {
  u8 *p1 = self + 0x53b2;
  *(u32 *)(self + 0x51ad) = 0;
  vcall<u32>(p1, 0xc);
  vcall<u32>(self + 0x5306, 0xc);
  *(u16 *)(self + 0x5147) = 0;
  vcall<u32>(self, 0xf4, 0u);
  self[0x15] = 0;
  self[0x22] = 0;
  self[0x2f] = 0;
  self[0x3c] = 0;
}
PCREG(5396d0, fn5396d0);

// 0x59a7a0: thiscall(a) ret 4: (u8)a ? 0x597640(this) : 0x597f70(this) (both flag values take the same branches)
static u32 THISCALL fn59a7a0(u8 *self, u32 a) {
  if ((u8)a) return ext_597640(self);
  return ext_597f70(self);
}
PCREG(59a7a0, fn59a7a0);

// 0x5eb7a0: thiscall(a) ret 4: a==0 -> [this+0x18]=0; a==1 -> =1; else assert hook (int3 when null)
static u32 THISCALL fn5eb7a0(u8 *self, u32 a) {
  if (a == 0) {
    *(u32 *)(self + 0x18) = 0;
    return 0;
  }
  if (a == 1) {
    *(u32 *)(self + 0x18) = 1;
    return 0;
  }
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(5eb7a0, fn5eb7a0);

// 0x656360: stdcall(a,b) ret 8: n=b*24; if n: o=[sysobj+0x190f]->slot 0x20(); o->vtable[0x18](a, n)
static void STDCALL fn656360(u32 a, u32 b) {
  u32 n = b * 24;
  if (n) {
    u8 *g = *(u8 **)(G7 + 0x190f);
    u8 *o = vcall<u8 *>(g, 0x20);
    vcall<u32>(o, 0x18, a, n);
  }
}
PCREG(656360, fn656360);

// 0x47fb30: thiscall(a) ret 4: o=[this+4]; vtable 0x68b164; o && o->slot 0(1); a&1 -> delete(this, 0xc); return this
static u8 *THISCALL fn47fb30(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 4);
  *(u32 *)self = 0x68b164;
  if (o) vcall<u32>(o, 0, 1u);
  if (a & 1) ext_634273(self, 0xc);
  return self;
}
PCREG(47fb30, fn47fb30);
