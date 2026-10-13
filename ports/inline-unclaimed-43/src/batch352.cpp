// batch352.cpp - 0x4079c0 (gap band). cdecl, one argument p; if p != 0: call 0x40fa40(p) (cdecl, one argument). Returns nothing.
#include "ff.h"

extern "C" void ext_40fa40(void *p);   // exe callee (cdecl, one argument)

static void optionalRelease(void *p) {
  if (p != 0)
    ext_40fa40(p);
}
PCREG(4079c0, optionalRelease);
