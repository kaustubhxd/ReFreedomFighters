// batch1042.cpp - area 81, batch 1042: 0x54a740, thiscall (this), no stack arguments, plain ret. Sets the byte at this+4 to 0, the words at this+0x11
// and this+0x15 to 0, then calls 0x4109e0 (real exe code, cdecl, one argument: this+0x2045; it zeroes five words from its argument and returns 0).
// No SEH frame, no cookie check. No stand-ins.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_4109e0(void *p);   // real exe code

// 0x54a740 (thiscall: this).
static void THISCALL initFields(u8 *self) {
  *(u8 *)(self + 4) = 0;
  *(u32 *)(self + 0x11) = 0;
  *(u32 *)(self + 0x15) = 0;
  ext_4109e0(self + 0x2045);
}
PCREG(54a740, initFields);
