// batch33040.cpp - h3 () batch 33040: tier B ctors, field copies, call wrappers
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);
extern "C" u32 THISCALL ext_4e5e60(u8 *self);                          // returns eax, no stack args
extern "C" void THISCALL ext_517030(u8 *self, u32 a, u32 b);           // ret 8
extern "C" void THISCALL ext_45fa00(u8 *self, u32 a);                  // ret 4
extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);               // ret 4, writes *out
extern "C" void THISCALL ext_4702b0(u8 *self, u32 *p);                 // ret 4
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 n);             // operator new
extern "C" void THISCALL ext_4ede80(u8 *self, u32 a);                  // ret 4
extern "C" void THISCALL ext_5ebca0(u8 *self);

// 0x5d6c70: ctor: base, [4]|=0x20, [0x44]=0, vtable 0x6b5bc4, [0x54]=0, [0x58]=0
static u8 *THISCALL fn5d6c70(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5bc4;
  *(u32 *)(self + 0x54) = 0;
  *(u32 *)(self + 0x58) = 0;
  return self;
}
PCREG(5d6c70, fn5d6c70);

// 0x5d8520: ctor: base, [4]|=0x20, [0x44]=0, vtable 0x6b5f30, [0x50]=0, [0x4c]=0, byte [0x54]=1
static u8 *THISCALL fn5d8520(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5f30;
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u8 *)(self + 0x54) = 1;
  return self;
}
PCREG(5d8520, fn5d8520);

// 0x4c58b0: thiscall(a, b) ret 8: [0x48] = 0x4e5e60(b); copy [0x24],[0x28],[0x2c] of [[this+0x44]+8] into [0x4c],[0x50],[0x54]
static void THISCALL fn4c58b0(u8 *self, u32 a, u8 *b) {
  *(u32 *)(self + 0x48) = ext_4e5e60(b);
  u8 *p = *(u8 **)(*(u8 **)(self + 0x44) + 8);
  *(u32 *)(self + 0x4c) = *(u32 *)(p + 0x24);
  *(u32 *)(self + 0x50) = *(u32 *)(p + 0x28);
  *(u32 *)(self + 0x54) = *(u32 *)(p + 0x2c);
}
PCREG(4c58b0, fn4c58b0);

// 0x52a070: thiscall(a) ret 4: two calls to 0x517030 with [a+0x44]/[a+0x48] and string 0x677b5a
static void THISCALL fn52a070(u8 *self, u8 *a) {
  ext_517030(self + 0x3d, *(u32 *)(a + 0x44), 0x677b5a);
  ext_517030(self + 0xb6, *(u32 *)(a + 0x48), 0x677b5a);
}
PCREG(52a070, fn52a070);

// 0x43e110: thiscall(a) ret 4: call 0x45fa00(a); twice: if !([0x14] & 0xe) [0x14] &= ~1
static void THISCALL fn43e110(u8 *self, u32 a) {
  ext_45fa00(self, a);
  u32 f = *(u32 *)(self + 0x14);
  if (!(f & 0xe)) *(u32 *)(self + 0x14) = f & ~1u;
  f = *(u32 *)(self + 0x14);
  if (!(f & 0xe)) *(u32 *)(self + 0x14) = f & ~1u;
}
PCREG(43e110, fn43e110);

// 0x4683f0: thiscall(a) ret 4: [4] &= ~0x40; local=0; 0x6352f0(&local); 0x4702b0(&local); return 1
static u32 THISCALL fn4683f0(u8 *self, u32 a) {
  u32 local = 0;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &local);
  ext_4702b0(self, &local);
  return 1;
}
PCREG(4683f0, fn4683f0);

// 0x4edbd0: thiscall(a) ret 4: if (a) { p = new(0x14); [this+0x1a5] = p (unaligned); 0x4ede80(p, a) }
static void THISCALL fn4edbd0(u8 *self, u32 a) {
  if (a) {
    void *p = ext_41e290(0x14);
    *(u32 *)(self + 0x1a5) = (u32)p;
    ext_4ede80((u8 *)p, a);
  }
}
PCREG(4edbd0, fn4edbd0);

// 0x5ecd40: thiscall: base 0x5ebca0; for i in [0, [0x3e]): rec = [[[0x3a]]+4] + 0x28*i; rec[0x1c] = rec[0x20] = 1.0f
static void THISCALL fn5ecd40(u8 *self) {
  ext_5ebca0(self);
  u32 n = *(u32 *)(self + 0x3e);
  for (u32 i = 0; i < n; i++) {
    u8 *base = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
    *(u32 *)(base + 0x28 * i + 0x1c) = 0x3f800000;
    base = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
    *(u32 *)(base + 0x28 * i + 0x20) = 0x3f800000;
  }
}
PCREG(5ecd40, fn5ecd40);
