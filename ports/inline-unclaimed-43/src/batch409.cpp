// batch409.cpp - 0x5f98a0 (residue 2; thiscall, no arguments). Stores the vtable 0x6b9098 at [this]; p = [this+4]; if p != 0:
// call 0x5f97e0 with ECX = p (thiscall, no arguments; exe, hooked by address in the spec, GUESS), then free p with size 0x18
// through 0x634273 (exe delete helper, cdecl, two arguments; hooked in the spec as in batch 381).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_5f97e0(void *self);            // member cleanup by address (hooked in the spec)
extern "C" void ext_634273(void *p, u32 size);               // delete helper (hooked in the spec)

static void THISCALL clearAndFree(u8 *self) {
  U32(self, 0x0) = 0x6b9098u;
  void *p = (void *)(unsigned long)U32(self, 0x4);
  if (p != 0) {
    ext_5f97e0(p);
    ext_634273(p, 0x18u);
  }
}
PCREG(5f98a0, clearAndFree);
