#include "ff.h"
// batch3513.cpp - area 35 claim 13 (docs/20-unclaimed-35.md): three leaves in slice 14. 0x4d4da0 calls the global hook at 0x7003b0
// with no arguments (ret 0x10); 0x41f9a0 tail-jumps to 0x4d0c00 with this = [this+0x31] (stubbed, no arguments).

extern "C" void THISCALL ext_4d0c00(u8 *self);

// 0x4d4da0, ZBigFile::Add(...) (high): calls the hook at 0x7003b0 when it is non-null; four stack arguments (ret 0x10), unused.
static void THISCALL bigFileAdd(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3) {
  (void)self;
  (void)a0;
  (void)a1;
  (void)a2;
  (void)a3;
  void (*hook)() = (void (*)())*(u32 *)0x7003b0;
  if (hook)
    hook();
}
PCREG(4d4da0, bigFileAdd);

// 0x613360, ZTextureManagerGC::ReserveTexture() (medium): true when the dword at this + 0x22030 is 0x3d or 0x3e.
static u8 THISCALL textureManagerReserve(u8 *self) {
  u32 v = *(u32 *)(self + 0x22030);
  return (v == 0x3d || v == 0x3e) ? 1 : 0;
}
PCREG(613360, textureManagerReserve);

// 0x41f9a0, GUESS FUN_41f9a0: tail-jumps to 0x4d0c00 with this = the dword at this + 0x31 (no arguments).
static void THISCALL guessTailJump(u8 *self) {
  ext_4d0c00(*(u8 **)(self + 0x31));
}
PCREG(41f9a0, guessTailJump);
