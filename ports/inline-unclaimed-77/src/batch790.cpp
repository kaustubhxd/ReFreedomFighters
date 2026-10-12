// batch790.cpp - unclaimed-77 claim 20 (docs/20-unclaimed-77.md): CGlobalCom::~CGlobalCom() (medium). Thiscall, one argument (flags),
// ret 4, returns this. The CRT delete 0x634273 is stubbed in the harness (GUESS): cdecl, two arguments.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 n);   // CRT delete, cdecl, stubbed (GUESS)

// 0x4d2480, CGlobalCom::~CGlobalCom() (medium): vtable 0x696168; delete (this, 0x10) when bit 0 of the flags is set; returns this.
static u8 *THISCALL globalComDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x696168u;
  if ((u8)flags & 1) {
    ext_634273(self, 0x10u);
  }
  return self;
}
PCREG(4d2480, globalComDtor);
