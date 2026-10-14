// batch963.cpp - area 56 band, claim A26 (0x533cc0).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 id);               // original exe helper (cdecl, hooked in the spec)
extern "C" u32 THISCALL ext_5328b0(u8 *self);    // original exe code, reached by a tail jump (hooked in the spec)

// A26 0x533cc0: p = ext_41e290(0x548e); if p == 0 return 0; else tail-jump to 0x5328b0 with ecx = p (no arguments).
static u32 tail533cc0(void) {
  u8 *p = ext_41e290(0x548e);
  if (p == 0) return 0;
  return ext_5328b0(p);
}
PCREG(533cc0, tail533cc0);
