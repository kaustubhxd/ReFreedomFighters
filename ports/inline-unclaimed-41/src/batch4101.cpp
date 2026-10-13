// batch4101.cpp - unclaimed-41 batch 1 (residue 13, small end): CAction::Load2().
#include "ff.h"

// 0x4a1270, the second half of the load (original code, not lifted here): a checksum stub in the spec (GUESS: its effects are
// not modelled). No stack arguments; the PC calls it with ecx = this and does not adjust esp.
extern "C" void THISCALL ext_4a1270(u8 *self);

// 0x4a1350, CAction::Load2() (high): thiscall, no arguments, plain ret. this+0x64 = (u8)P.vt[+0x1e0](0x1007d1), where P = this+0x44;
// this+0x65 = (Q.dword[+0x3c] >> 1) & 1, where Q = P+8; then ext_4a1270(this); this+0x63 = 1.
static void THISCALL actionLoad2(u8 *self) {
  typedef u32(THISCALL * f1e0_t)(u8 *, u32);
  u8 *p = *(u8 **)(self + 0x44);
  u32 v = (*(f1e0_t *)(*(u32 *)p + 0x1e0))(p, 0x1007d1u);
  self[0x64] = (u8)v;
  u8 *q = *(u8 **)(p + 8);
  self[0x65] = (u8)((*(u32 *)(q + 0x3c) >> 1) & 1);
  ext_4a1270(self);
  self[0x63] = 1;
}
PCREG(4a1350, actionLoad2);
