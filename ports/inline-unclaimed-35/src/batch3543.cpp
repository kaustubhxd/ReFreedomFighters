#include "ff.h"
// batch3543.cpp - standing assignment, slice 14 (docs/20-gap-band-561000.md batch 43): four leaves (GUESS names).

void THISCALL gap4678e0(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3) {
  *(u32 *)(self + 0x3d) = a0;
  *(u32 *)(self + 0x41) = a1;
  *(u32 *)(self + 0x45) = a2;
  *(u32 *)(self + 0x49) = a3;
}
PCREG(4678e0, gap4678e0);

void THISCALL gap65ca60(u8 *self, u32 a0) {
  *(u32 *)self = a0;
  *(u32 *)(self + 4) = a0 + 4;
}
PCREG(65ca60, gap65ca60);

void STDCALL gap461760(u8 *p, u32 a1, u32 a2) {
  (void)a1;
  (void)a2;
  *(u32 *)(p + 0) = 0x7e967699u;
  *(u32 *)(p + 4) = 0x7e967699u;
  *(u32 *)(p + 8) = 0x7e967699u;
  *(u32 *)(p + 0xc) = 0x7e967699u;
}
PCREG(461760, gap461760);

u8 STDCALL gap6568e0(u32 a0) {
  u8 *m = *(u8 **)0x70039c;
  u8 *o = *(u8 **)(m + 0x1aa3);
  u8 *p = *(u8 **)(o + 0x20);
  return (u8)(a0 > *(u32 *)(p + 4));
}
PCREG(6568e0, gap6568e0);
