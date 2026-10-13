#include "ff.h"
// batch3538.cpp - claim 38 (docs/20-gap-band-561000.md): 0x5b2ac0 ZActionControlMap::~ZActionControlMap(). Thiscall, one arg (flags),
// ret 4, returns this. SEH frame not reproduced; the null-hook int3 is not reproduced (the spec installs the hook).
// Stubbed in the harness: 0x5b2a00 (base dtor, thiscall, no args), 0x4690b0 (cdecl, two args), the hook at 0x7003b0 (cdecl).

extern "C" void THISCALL ext_5b2a00(u8 *self);
extern "C" void ext_4690b0(u32 a0, u32 a1);

u8 *THISCALL zactionControlMapDtor(u8 *self, u32 flags) {
  ext_5b2a00(self);
  if (!(flags & 1))
    return self;
  if (flags & 4) {
    ext_4690b0((u32)self, 0x261);
    return self;
  }
  {
    u32 hook = *(u32 *)0x7003b0;
    if (hook != 0)
      ((void (*)(void))hook)();
  }
  return self;
}
PCREG(5b2ac0, zactionControlMapDtor);
