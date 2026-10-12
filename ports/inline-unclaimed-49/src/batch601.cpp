// batch601.cpp - area 49, batch 601: ZFFSimpleTrain2::~ZFFSimpleTrain2() (0x5b8400, 54 insns, vtable 0x686874).
// thiscall, ret 4 (flags), returns this. Clears +0x44 and +0x30, sets the vtable, calls the render manager's slot 0x34
// with this, then for flags bit 0: if bit 2 is clear the debug assert hook [0x7003b0] runs (int3 without one), else
// ZRenderGC::SetState(this, 0xf6) (cdecl, two pushes). The exe's SEH frame is not reproduced.
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
extern "C" void ext_4690b0(void *gc, u32 state);   // ZRenderGC::SetState (cdecl in the caller: two pushes)
typedef u32 (*hookFn)();

static u32 THISCALL trainDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *rm = *(u8 **)(sys + 0x9b);
  ((vOne)VT(rm, 0x34))(rm, (u32)self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0xf6);
    } else {
      hookFn h = G(hookFn, 0x7003b0);
      if (!h)
        __builtin_debugtrap();
      h();
    }
  }
  return (u32)self;
}
PCREG(5b8400, trainDtor);
