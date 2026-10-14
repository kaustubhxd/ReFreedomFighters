// batch2601.cpp - area 73 batch 1 (residue 12): GUESS FUN_481180 and GUESS FUN_5eaf80 (docs/20-unclaimed-73.md).
#include "ff.h"

// 0x480ff0: thiscall, no arguments (original code, hooked in the spec).
extern "C" void THISCALL ext_480ff0(u8 *self);
// 0x45c510: cdecl, one argument (original code, hooked in the spec).
extern "C" void __attribute__((cdecl)) ext_45c510(u8 *self);
// 0x4690b0: a bare `ret` (no effect); cdecl with two arguments, the caller pops them.
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *self, u32 v);

// 0x481180, GUESS FUN_481180: thiscall, ret 4 (one argument, a flag word). Calls 0x480ff0(this). When bit 0 of the flag is
// set: when bit 2 is clear, 0x45c510(this); otherwise 0x4690b0(this, 0x64b). Returns this.
static u8 *THISCALL guess481180(u8 *self, u32 flags) {
  ext_480ff0(self);
  if ((u8)flags & 1) {
    if (!((u8)flags & 4))
      ext_45c510(self);
    else
      ext_4690b0(self, 0x64bu);
  }
  return self;
}
PCREG(481180, guess481180);

// 0x5eaf80, GUESS FUN_5eaf80: thiscall, no arguments, returns false (al). Calls slot +0x704(0) on this+8 (the object o8).
// Then the render manager ctl (g_sys+0x9b) slot +0x114 with six arguments (0x6a4d58, 0, 0x6b80b4, 0x82, 0, 0), returning a word;
// o8 slot +0x128 with that word (one argument).
static bool THISCALL guess5eaf80(u8 *self) {
  u8 *o8 = *(u8 **)(self + 8);
  vcall<u32>(o8, 0x704, 0u);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  u32 w = vcall<u32>(ctl, 0x114, 0x6a4d58u, 0u, 0x6b80b4u, 0x82u, 0u, 0u);
  vcall<void>(o8, 0x128, (u32)(u16)w);
  return false;
}
PCREG(5eaf80, guess5eaf80);
