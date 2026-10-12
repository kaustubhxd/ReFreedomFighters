// batch6204.cpp - unclaimed-62 claim 2 (residue 03): CExplodeMolotov::~CExplodeMolotov(flags) [map 0x581630; thiscall, ret 4, returns this].
// The SEH frame of the exe is not reproduced (nothing in the body can throw here). Sets +0x44 and +0x30 to zero and the vtable to 0x686874;
// the message table's slot 0x34 is called with this; then if flag bit 0 is set: with bit 2 set, exe 0x4690b0 (cdecl, line 0x372) runs; without
// it the assert hook at 0x7003b0 is called (a trap when there is none).
#include "ff.h"

extern "C" void ext_4690b0(u8 *self, u32 line);   // exe: cdecl, two arguments (the caller pops)

static u8 *THISCALL explodeMolotovDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874u;
  vcall<void>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x34, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x372);
    } else {
      typedef void (*hookfn)();
      hookfn h = G(hookfn, 0x7003b0);
      if (h) h();
      else __builtin_debugtrap();
    }
  }
  return self;
}
PCREG(581630, explodeMolotovDtor);
