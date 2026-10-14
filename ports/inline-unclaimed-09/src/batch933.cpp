// batch933.cpp - unclaimed-09 batch 25: 0x438840 (core list name ZInputActions::ForceSetAction; docs/20-unclaimed-09.md,
// claim 27). stdcall, two stack arguments (pointer, unused), ret 8. No calls out.
#include "ff.h"

// 0x438840 (list name ZInputActions::ForceSetAction; GUESS on the name): for a non-null p whose dword at +0 is zero and
// whose byte at +0x2e lacks bit 2: copies the dword at global+0x40 to p+0x21 (unless p+0x21 is that address), then sets
// bits 0x90 of the byte at +0x2e and 0x3e of the byte at +0x2f.
static void STDCALL forceSetAction(u8 *p, u32 b) {
  (void)b;
  if (p && *(u32 *)p == 0 && !(p[0x2e] & 4)) {
    u8 *g = G(u8 *, 0x70039c);
    u8 *dst = p + 0x21;
    if (dst != g + 0x40) *(u32 *)dst = *(u32 *)(g + 0x40);
    p[0x2e] |= 0x90;
    p[0x2f] |= 0x3e;
  }
}
PCREG(438840, forceSetAction);
