// batch381.cpp - 0x420b50 (gap band). cdecl(void): call 0x41cf80 (exe, cdecl, no arguments); then for the global object at
// 0x7003a8: if set, slot 0x10() and slot 0(1); clear 0x7003a8. Same for the global at 0x7003a4.
#include "ff.h"

extern "C" void ext_41cf80(void);   // global cleanup (batch 379's function, exe code)

static void cleanupTwoGlobals(void) {
  ext_41cf80();
  u32 *g8 = (u32 *)0x7003a8u;
  if (*g8 != 0)
    vcall<void>((void *)(unsigned long)*g8, 0x10);
  if (*g8 != 0)
    vcall<void>((void *)(unsigned long)*g8, 0x0, 1u);
  *g8 = 0;
  u32 *g4 = (u32 *)0x7003a4u;
  if (*g4 != 0)
    vcall<void>((void *)(unsigned long)*g4, 0x10);
  if (*g4 != 0)
    vcall<void>((void *)(unsigned long)*g4, 0x0, 1u);
  *g4 = 0;
}
PCREG(420b50, cleanupTwoGlobals);
