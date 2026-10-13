// batch 104: residue 6 helper caller 0x6014a0
#include "ff.h"

extern "C" void ext_5ff8f0(u32 a);

// 0x6014a0: stdcall, one argument (ret 4), returns 0
// push [ebp+8]; call 0x5ff8f0; add esp, 4; ret 4
static u32 STDCALL guess6014a0(u32 a) {
  ext_5ff8f0(a);
  return 0;
}
PCREG(6014a0, guess6014a0);
