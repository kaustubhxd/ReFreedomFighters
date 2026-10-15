// batch3106.cpp - area 73 batch 6 (residue 12): ZParamAnim::~ZParamAnim() (0x49e3c0, docs/20-unclaimed-73.md).
#include "ff.h"

// 0x4e6ce0: member destructor, thiscall, no arguments (original code, hooked in the spec).
extern "C" void THISCALL ext_4e6ce0(u8 *self);
// 0x4690b0: a bare `ret` (cdecl, two arguments; the caller pops them).
extern "C" void __attribute__((cdecl)) ext_4690b0(u8 *self, u32 v);

// 0x49e3c0, ZParamAnim::~ZParamAnim() (high), thiscall, ret 4: ext_4e6ce0(this+0x59); this+0x44 = 0; this+0x30 = 0; vtable
// 0x686874. ctl = (g_sys+0x9b): ctl slot +0x34(this). When bit 0 of the flag is set: bit 2 set: ext_4690b0(this, 0x122);
// otherwise the assert pointer at 0x7003b0 is called (no arguments). Returns this.
static u8 *THISCALL paramAnimDtor(u8 *self, u32 flags) {
  ext_4e6ce0(self + 0x59);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874u;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  vcall<void>(ctl, 0x34, (u32)self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4) {
      ext_4690b0(self, 0x122u);
    } else {
      void *assertp = G(void *, 0x7003b0);
      if (assertp)
        ((void(__attribute__((cdecl)) *)(void))assertp)();
    }
  }
  return self;
}
PCREG(49e3c0, paramAnimDtor);
