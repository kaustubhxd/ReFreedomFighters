// batch33056.cpp - h3 (Sonnet) batch 33056: tier C wrappers with flags, loops and imports
#include "ff.h"

extern "C" u32 THISCALL ext_4614d0(u8 *self, u32 a, u32 b, u32 c);   // ret 0xc
extern "C" void THISCALL ext_43e0f0(u8 *self);
typedef u32 (STDCALL *imp3_t)(u32, u32, u32);
typedef u32 (__attribute__((cdecl)) *log2_t)(u8 *, u32);

#define SYS_TABLE (*(u8 **)(*(u8 **)0x70039c + 0x9b))

// 0x4869a0: thiscall(): d=[this+0x14]; d ? (r=[this+8]->slot 0x230(d,1); 0x4614d0(r, 12.0f, 0x465710, 0); eax low byte 1) : tail slot 0xc()
static u32 THISCALL fn4869a0(u8 *self) {
  u32 d = *(u32 *)(self + 0x14);
  if (!d) return vcall<u32>(self, 0xc);
  u32 r = vcall<u32>(*(u8 **)(self + 8), 0x230, d, 1u);
  u32 x = ext_4614d0((u8 *)r, 0x41480000, 0x465710, 0);
  return (x & 0xffffff00u) | 1;
}
PCREG(4869a0, fn4869a0);

// 0x52abc0: thiscall: 0x43e0f0; slot 0x110(0x10, 0); [this+0x91] = (u16)table->slot 0x114(str, 0, str, 0x2292)
static void THISCALL fn52abc0(u8 *self) {
  ext_43e0f0(self);
  vcall<u32>(self, 0x110, 0x10u, 0u);
  u32 r = vcall<u32>(SYS_TABLE, 0x114, 0x6a0f84u, 0u, 0x6a0f54u, 0x2292u);
  *(u16 *)(self + 0x91) = (u16)r;
}
PCREG(52abc0, fn52abc0);

// 0x54df10: thiscall bool: claim slot flag byte at [this+0x40a7+i]
static u32 THISCALL fn54df10(u8 *self) {
  u32 i = *(u32 *)(self + 0x40ad);
  if (self[0x40a7 + i]) {
    u32 r = vcall<u32>(self, 0x4c);
    if (self[0x40a7 + r]) return 0;
    i = vcall<u32>(self, 0x4c);
  }
  self[0x40a7 + i] = 1;
  return 1;
}
PCREG(54df10, fn54df10);

// 0x584cc0: thiscall(a) ret 4: five entries at this+0x179: clear those the table lookup 0x58 resolves
static void THISCALL fn584cc0(u8 *self, u32 a) {
  u32 *p = (u32 *)(self + 0x179);
  for (int i = 0; i != 5; i++, p++) {
    if (vcall<u32>(SYS_TABLE, 0x58, *p)) *p = 0;
  }
}
PCREG(584cc0, fn584cc0);

// 0x5de3e0: thiscall: [0x7003b8][+0x2c4d]=this; r=table->slot 0x58([[this+0x114]+0x676]); [this+0x134]=r; [this+0x130]=r->slot 0x100(0x67d9e8)
static u32 THISCALL fn5de3e0(u8 *self) {
  *(u8 **)(G(u8 *, 0x7003b8) + 0x2c4d) = self;
  u32 id = *(u32 *)(*(u8 **)(self + 0x114) + 0x676);
  u8 *r = vcall<u8 *>(SYS_TABLE, 0x58, id);
  *(u8 **)(self + 0x134) = r;
  u32 r2 = vcall<u32>(r, 0x100, 0x67d9e8u);
  *(u32 *)(self + 0x130) = r2;
  return r2;
}
PCREG(5de3e0, fn5de3e0);

// 0x426790: stdcall(a,b) ret 8: r = import[0x67612c](a,b,1); on 0: g->slot 0x20(str,0x189) then cdecl s->vtable[0x2c](s, str) and return its eax
static u32 STDCALL fn426790(u32 a, u32 b) {
  u32 r = (*(imp3_t *)0x67612c)(a, b, 1);
  if (r) return r;
  u8 *g = G(u8 *, 0x700390);
  u8 *s = vcall<u8 *>(g, 0x20, 0x6789acu, 0x189u);
  return (*(log2_t *)(*(u8 **)s + 0x2c))(s, 0x678cb0);
}
PCREG(426790, fn426790);

// 0x4690c0: thiscall(a) ret 4: this null -> nothing; if [this+4]&4 slot 0x4c(); [this+4]|=0x100; table->slot 0x148(a, this)
static void THISCALL fn4690c0(u8 *self, u32 a) {
  if (!self) return;
  if (*(u32 *)(self + 4) & 4) vcall<u32>(self, 0x4c);
  *(u32 *)(self + 4) |= 0x100;
  vcall<u32>(SYS_TABLE, 0x148, a, (u32)self);
}
PCREG(4690c0, fn4690c0);

// 0x475280: thiscall(a) ret 4: o=[this+0x3b7]; o && o->slot 0x28(a) ? tail [this+0x3b7]->slot 0x3c(a) : 0
static u32 THISCALL fn475280(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 0x3b7);
  if (!o) return 0;
  if (!vcall<u32>(o, 0x28, a)) return 0;
  o = *(u8 **)(self + 0x3b7);
  return vcall<u32>(o, 0x3c, a);
}
PCREG(475280, fn475280);
