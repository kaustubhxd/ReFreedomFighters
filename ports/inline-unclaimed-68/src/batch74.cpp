// batch74.cpp - unclaimed-68 batch 74 (slice 7). Names GUESS (FUN_addr).
#include "ff.h"
#include <stdint.h>

typedef u32(THISCALL *VNoArg32)(u8 *self);
typedef u32(THISCALL *VSlot25c)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *VSlot4)(u8 *self, u32 a, u32 b);

// 0x526ef0: vt = 0x6a09ec; byte +0x18 = 0; float +0x14 = 1.0; dword +0x10 = 0; dword +0xc = 0; dword +0x19 = 2; returns this.
static u32 THISCALL g526ef0(u8 *self) {
  *(u32 *)self = 0x6a09ecu;
  self[0x18] = 0;
  *(float *)(self + 0x14) = 1.0f;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x19) = 2;
  return (u32)self;
}
PCREG(526ef0, g526ef0);

// 0x42d2b0: p1 = [this+0x1b61]; dword [p1+4] -= 4; p2 = [this+0x1b6d]; esi = [arg]; if esi != dword [p2+4] then [arg] = esi + 0xc. ret 4
static void THISCALL g42d2b0(u8 *self, u32 argAddr) {
  u8 *p1 = *(u8 **)(self + 0x1b61);
  *(u32 *)(p1 + 4) -= 4u;
  u8 *p2 = *(u8 **)(self + 0x1b6d);
  u32 esi = *(u32 *)argAddr;
  if (esi != *(u32 *)(p2 + 4)) *(u32 *)argAddr = esi + 0xc;
}
PCREG(42d2b0, g42d2b0);

// 0x5db3f0: obj = [[[0x70039c]+0x9b]+0xadc]; [this+0x48] = obj.slot+0x25c(0x685f44, 0); plain ret
static void THISCALL g5db3f0(u8 *self) {
  u8 *mgr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = *(u8 **)(mgr + 0xadc);
  *(u32 *)(self + 0x48) = ((VSlot25c)*(u32 *)(*(u8 **)obj + 0x25c))(obj, 0x685f44u, 0u);
}
PCREG(5db3f0, g5db3f0);

// 0x63e630: this.dec [this+0x18]; o = [this+0x14]; size = ([this+0x1c] << 12) + 0x1010; v = [arg+4];
//   returns o.slot+4(v, size) (ret 4)
static u32 THISCALL g63e630(u8 *self, u32 argAddr) {
  *(u32 *)(self + 0x18) -= 1u;
  u8 *o = *(u8 **)(self + 0x14);
  u32 size = (*(u32 *)(self + 0x1c) << 12) + 0x1010u;
  u32 v = *(u32 *)(argAddr + 4);
  return ((VSlot4)*(u32 *)(*(u8 **)o + 4))(o, v, size);   // size is pushed first, the value last (the value is the first argument)
}
PCREG(63e630, g63e630);

// 0x527030: d = [this+8] - [this+4] (single precision); double, AND with the constant 0x67cd50 (the double abs mask), back to single. Returns ST0.
static float THISCALL g527030(u8 *self) {
  float d = *(float *)(self + 8) - *(float *)(self + 4);
  double dd = (double)d;
  uint64_t bits;
  __builtin_memcpy(&bits, &dd, 8);
  bits &= G(uint64_t, 0x67cd50);
  __builtin_memcpy(&dd, &bits, 8);
  return (float)dd;
}
PCREG(527030, g527030);
