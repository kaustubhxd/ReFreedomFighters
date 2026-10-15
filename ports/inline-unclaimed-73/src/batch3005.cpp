// batch3005.cpp - area 73 batch 5 (residue 12): ZKillBox::~ZKillBox() (0x5b1a00, docs/20-unclaimed-73.md).
// The SEH frame of the original (fs:[0]) is not reproduced; it is restored on every return, so only the effects are compared.
#include "ff.h"

// 0x4690b0: a bare `ret` (cdecl, two arguments; the caller pops them).
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *self, u32 v);

// 0x5b1a00, ZKillBox::~ZKillBox() (high), thiscall, ret 4: this+0x44 = 0; this+0x30 = 0; vtable 0x686874. ctl = (g_sys+0x9b):
// ctl slot +0x34(this). When bit 0 of the flag is set: bit 2 set: ext_4690b0(this, 0x8d); otherwise the assert pointer at
// 0x7003b0 is called (no arguments). Returns this.
static u8 *THISCALL killBoxDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874u;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  vcall<void>(ctl, 0x34, (u32)self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4) {
      ext_4690b0(self, 0x8du);
    } else {
      void *assertp = G(void *, 0x7003b0);
      if (assertp)
        ((void(__attribute__((cdecl)) *)(void))assertp)();
    }
  }
  return self;
}
PCREG(5b1a00, killBoxDtor);
