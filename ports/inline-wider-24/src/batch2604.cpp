// batch2604.cpp - wider batch 2604 (from ladder batch 234): three folded assert stubs. Each loads the hook at 0x7003b0; if set it is called
// (0x4d50c0: tail-jumped to, no arguments; 0x510bd0: called, then ret 8; 0x6368b0: called, then ret 4), else int3.
#include "ff.h"

typedef void (*hook_t)();
static inline void assert_hook() {
  hook_t h = G(hook_t, 0x7003b0);
  if (h)
    h();
  else
    __asm__ volatile("int3");
}
static void hands_4d50c0() { assert_hook(); }
PCREG(4d50c0, hands_4d50c0);
static void THISCALL hands_510bd0(u8 *, u32, u32) { assert_hook(); }
PCREG(510bd0, hands_510bd0);
static void THISCALL hands_6368b0(u8 *, u32) { assert_hook(); }
PCREG(6368b0, hands_6368b0);
