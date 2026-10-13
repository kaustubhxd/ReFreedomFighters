// batch813.cpp - core gameplay batch 813 (docs/20-unclaimed-65.md, batch 813): 0x5c56c0, a thiscall with one stack argument it never reads
// (ret 4). It clears bit 6 of this+4, calls 0x6352f0 (thiscall, one pointer argument: the local) and then 0x5c56f0 (thiscall, the same
// pointer argument), and returns true in al. Both callees are hooked by address in the spec (GUESS, labelled in the doc): their bodies
// are other claims.
#include "ff.h"

extern "C" void THISCALL ext_6352f0(u8 *self, u32 *out);   // thiscall, one argument, ret 4 (hooked in the spec)
extern "C" void THISCALL ext_5c56f0(u8 *self, u32 *out);   // thiscall, one argument, ret 4 (hooked in the spec)

static u8 THISCALL fn5c56c0(u8 *self, u32 unused) {
  (void)unused;
  u32 local = 0;
  *(u32 *)(self + 4) &= 0xffffffbf;
  ext_6352f0(self, &local);
  ext_5c56f0(self, &local);
  return 1;
}

PCREG(5c56c0, fn5c56c0);
