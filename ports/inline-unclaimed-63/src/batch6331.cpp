// batch6331.cpp - unclaimed-63 gap-band batch 31: two functions.
//   0x4cf620 (C-set; no GC name): thiscall, arguments P (a pointer value) and f (a float), ret 8. v = this->vtbl[+0x98]([P], f, 0)
//     (thiscall, three stack arguments, callee pops 12); 0x634d22(v - 4, P, [this+0x18]*4 - 0x10) (cdecl, caller cleans); then
//     this->vtbl[+0x20](P) (thiscall, one stack argument). The PC's pushed ECX slot is overwritten by the float, as written here.
//   0x4da3c0 (A+D set; no GC name): thiscall, one argument src (a pointer), ret 4. Copies the dwords at src+0x30, +0x34, +0x38, +0x40,
//     +0x44, +0x48, +0x4c into this; sets bit 0x100000 in [this+0x3c] (twice); for each of +0x40, +0x44, +0x48: if the constant
//     [0x679540] (a float, 2^-13) is greater than the stored float, store 0x39000000 (the same float) there.
#include "ff.h"

extern "C" void ext_634d22(u32 a, u32 b, u32 c);   // cdecl import thunk, stubbed by the spec

typedef u32(THISCALL * call3_fn)(void *, u32, float, u32);
typedef void(THISCALL * call1_fn)(void *, u32);

// 0x4cf620 (C-set).
static void THISCALL unnamed4cf620(u8 *self, u32 p, float f) {
  u32 v = ((call3_fn)(*(u32 *)(*(u32 *)self + 0x98)))((void *)self, *(u32 *)p, f, 0u);
  u32 c = *(u32 *)(self + 0x18) * 4u - 0x10u;
  ext_634d22(v - 4u, p, c);
  ((call1_fn)(*(u32 *)(*(u32 *)self + 0x20)))((void *)self, p);
}
PCREG(4cf620, unnamed4cf620);

// 0x4da3c0 (A+D set).
static void THISCALL unnamed4da3c0(u8 *self, u8 *src) {
  float k = G(float, 0x679540);
  *(u32 *)(self + 0x30) = *(u32 *)(src + 0x30);
  *(u32 *)(self + 0x34) = *(u32 *)(src + 0x34);
  *(u32 *)(self + 0x38) = *(u32 *)(src + 0x38);
  *(u32 *)(self + 0x3c) |= 0x100000u;
  *(u32 *)(self + 0x40) = *(u32 *)(src + 0x40);
  *(u32 *)(self + 0x44) = *(u32 *)(src + 0x44);
  *(u32 *)(self + 0x48) = *(u32 *)(src + 0x48);
  if (k > *(float *)(self + 0x40))
    *(u32 *)(self + 0x40) = 0x39000000u;
  if (k > *(float *)(self + 0x44))
    *(u32 *)(self + 0x44) = 0x39000000u;
  if (k > *(float *)(self + 0x48))
    *(u32 *)(self + 0x48) = 0x39000000u;
  *(u32 *)(self + 0x3c) |= 0x100000u;
  *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
  *(u32 *)(self + 0x3c) |= 0x100000u;
}
PCREG(4da3c0, unnamed4da3c0);
