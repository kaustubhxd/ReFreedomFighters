// batch379.cpp - 0x41cf80 (gap band). cdecl(void): p = G(0x6fcd44); if p: __builtin_delete(p, 0xd) (exe 0x634273, cdecl);
// G(0x6fcd44) = 0. o = G(0x6fcd48); if o: o slot 0x10() (thiscall, no arguments). o = G(0x6fcd48); if o: o slot 0 (1) (thiscall,
// one argument = 1). Then G(0x6fcd48) = 0.
#include "ff.h"

extern "C" void ext_634273(void *p, unsigned long size);   // __builtin_delete (cdecl, two arguments)

static void globalCleanup(void) {
  u32 *g44 = (u32 *)0x6fcd44u;
  u32 *g48 = (u32 *)0x6fcd48u;
  if (*g44 != 0)
    ext_634273((void *)(unsigned long)*g44, 0xd);
  *g44 = 0;
  if (*g48 != 0)
    vcall<void>((void *)(unsigned long)*g48, 0x10);
  if (*g48 != 0)
    vcall<void>((void *)(unsigned long)*g48, 0x0, 1u);
  *g48 = 0;
}
PCREG(41cf80, globalCleanup);
