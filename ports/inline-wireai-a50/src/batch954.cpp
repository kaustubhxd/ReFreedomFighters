// batch954.cpp - 0x50a380 (no name in the map), residue-16 slice (2026-10-12). Thiscall (ECX = this), no args, plain ret. SEH-framed in the exe
// (fs:[0] frame and a stack cookie; the frame is NOT reproduced, the body is). If the global at 0x701128 is 0: a local L of three zero dwords is built,
// 0x59a9b0 (thiscall: ECX = &L, one arg 0x32; stood in), then slot +0x1c of this with one arg &L (ECX = this), then 0x4ff9d0 (thiscall: ECX = &L,
// no args; stood in). Nothing else.
#include "ff.h"

#define G32(addr) (*(u32 *)(addr))

extern "C" void THISCALL ext_59a9b0(void *self, u32 a);   // stood in (ctor of L, one arg)
extern "C" void THISCALL ext_4ff9d0(void *self);          // stood in (dtor of L, no args)

// 0x50a380 (no name in the map).
static void THISCALL Init50a380(u8 *self) {
  if (G32(0x701128) != 0) return;
  u32 L[3] = {0, 0, 0};
  ext_59a9b0(L, 0x32);
  vcall<void>(self, 0x1c, L);
  ext_4ff9d0(L);
}
PCREG(50a380, Init50a380);
