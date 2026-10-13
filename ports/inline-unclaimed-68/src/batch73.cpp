// batch73.cpp - unclaimed-68 batch 73 (slice 7). Names GUESS (FUN_addr).
#include "ff.h"
#include <stdint.h>

typedef void(THISCALL *VNoArgVoid)(u8 *self);
typedef u32(THISCALL *VNoArgRet)(u8 *self, u32 a);
typedef u32(THISCALL *VSlot9c)(u8 *self, u32 a, u32 b);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);   // CRT sized delete, cdecl

// 0x445c70: if (byte this+0x48 & 0x20): o = [G+0x190f]; if o, o.slot+0x2c(); clear bit 0x20 of this+0x48. Thiscall, plain ret.
static void THISCALL g445c70(u8 *self) {
  if (self[0x48] & 0x20) {
    u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x190f);
    if (o) ((VNoArgVoid)*(u32 *)(*(u8 **)o + 0x2c))(o);
    *(u32 *)(self + 0x48) &= 0xffffffdfu;
  }
}
PCREG(445c70, g445c70);

// 0x656c30: r = this.slot+0xc(a); return this.slot+0x9c(r, b); ret 8
static u32 THISCALL g656c30(u8 *self, u32 a, u32 b) {
  u32 r = ((VNoArgRet)*(u32 *)(*(u8 **)self + 0xc))(self, a);
  return ((VSlot9c)*(u32 *)(*(u8 **)self + 0x9c))(self, r, b);
}
PCREG(656c30, g656c30);

// 0x6042f0: this.vt = 0x6b9b6c; ext_634273(p = [this+8], 0x320) (cdecl). Plain ret.
static void THISCALL g6042f0(u8 *self) {
  void *p = *(void **)(self + 8);
  *(u32 *)self = 0x6b9b6cu;
  ext_634273(p, 0x320u);
}
PCREG(6042f0, g6042f0);
