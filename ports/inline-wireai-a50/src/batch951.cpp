// batch951.cpp - five leaf functions from the residue-9 free list (2026-10-12, the coordinator's standing split: floor(addr/16) mod 20 == 9),
// all read in full. None of them is verified in any other folder or docs/20 file.
//  0x615ed0 [no args]: returns 0x55.
//  0x64c750 [no args]: returns 0x7f.
//  0x650c10 [thiscall, no args, returns eax]: tail-jumps to slot +0xc of the object at this+0x8c (ECX = that object, no args).
//  0x65f5d0 [thiscall, no args, returns eax]: c = this+0xc (dword); return [c+0x10069] - [c+0x10061].
//  0x4d1dd0 [thiscall, no args, returns eax]: calls slot +0x10 of this with one arg 0 (thiscall, callee pops 4 assumed); then returns
//           [[this+0xc]+4] & 0x3fffffff.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

// 0x615ed0 (no name in the map).
static u32 Const615ed0(void) { return 0x55; }
PCREG(615ed0, Const615ed0);

// 0x64c750 (no name in the map).
static u32 Const64c750(void) { return 0x7f; }
PCREG(64c750, Const64c750);

// 0x650c10 (no name in the map). Tail call: the callee's return value is this function's.
static u32 THISCALL Forward650c10(u8 *self) { return vcall<u32>(FP(self, 0x8c), 0xc); }
PCREG(650c10, Forward650c10);

// 0x65f5d0 (no name in the map).
static u32 THISCALL Diff65f5d0(u8 *self) {
  u8 *c = (u8 *)FP(self, 0xc);
  return U32(c, 0x10069) - U32(c, 0x10061);
}
PCREG(65f5d0, Diff65f5d0);

// 0x4d1dd0 (no name in the map).
static u32 THISCALL Flags4d1dd0(u8 *self) {
  vcall<void>(self, 0x10, 0u);
  u8 *c = (u8 *)FP(self, 0xc);
  return U32(c, 4) & 0x3fffffff;
}
PCREG(4d1dd0, Flags4d1dd0);
