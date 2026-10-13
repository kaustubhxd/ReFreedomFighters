// batch4031.cpp - area 70 (slice 4/5), batch 4031: 0x4a80d0 (name GUESS). SEH frame not reproduced (the exe pushes an
// exception frame around the body). Sets [this+0x44] = 0, [this+0x30] = 0 and the vtable 0x686874, calls slot 0x34 of the
// render manager with this, then for bit 0 of the argument: bit 2 calls 0x4690b0 (cdecl, (this, 0x58)); otherwise the hook
// at 0x7003b0 (cdecl, no arguments). Returns this.
#include "ff.h"

extern "C" void ext_4690b0(void *p, u32 size);   // exe: cdecl free-like helper, stubbed by address in the spec

// 0x4a80d0 (name GUESS): thiscall (ECX = this), one stack argument flags, ret 4.
static u8 *THISCALL initFlags4a80d0(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *sys = G(u8 *, 0x70039c);
  void *rm = *(void **)(sys + 0x9b);
  vcall<void>(rm, 0x34, self);
  u8 f = (u8)flags;
  if (f & 1) {
    if (f & 4) {
      ext_4690b0(self, 0x58);
    } else {
      void (*hook)(void) = (void (*)(void))G(void *, 0x7003b0);
      hook();
    }
  }
  return self;
}
PCREG(4a80d0, initFlags4a80d0);
