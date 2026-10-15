// batch762.cpp - residue 17 big entries (docs/20-unclaimed-78b.md), built in the area 75 folder.
#include "ff.h"

typedef u32(THISCALL *VArg)(u8 *, u32);     // one stack word, returns eax
typedef u32(THISCALL *VFloat)(u8 *, float);   // returns eax, which the asm uses as the next object

// 0x563490, thiscall(save) ret 4 (GUESS name, save-style chain; returns bool). Returns (eax & ~0xff) | 1 (the asm's al = 1).
static u32 THISCALL saveChain_563490(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  VArg f3c = (VArg)(*(u32 *)(*(u32 *)save + 0x3c));
  u8 *a = (u8 *)f3c(save, *(u32 *)(self + 0x48));
  VFloat f4c = (VFloat)(*(u32 *)(*(u32 *)a + 0x4c));
  u32 r1 = f4c(a, *(float *)(self + 0x64));           // the next call's object is this return value
  VArg f60a = (VArg)(*(u32 *)(*(u32 *)r1 + 0x60));
  u32 r2 = f60a((u8 *)r1, (u32)self[0x84]);
  VArg f60b = (VArg)(*(u32 *)(*(u32 *)r2 + 0x60));
  f60b((u8 *)r2, (u32)self[0x85]);
  VArg f44 = (VArg)(*(u32 *)(*(u32 *)save + 0x44));
  f44(save, *(u32 *)(self + 0xf0));
  u32 r = f44(save, *(u32 *)(self + 0xdc));
  return (r & ~0xffu) | 1u;
}
PCREG(563490, saveChain_563490);
