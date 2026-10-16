// batch 103: residue 6 helper caller 0x52aae0
#include "ff.h"

extern "C" void ext_52a84c(u32 a, u32 b);

// 0x52aae0: stdcall, two arguments (ret 8), returns 0
static u32 STDCALL guess52aae0(u32 a, u32 b) {
  ext_52a84c(a, b);
  return 0;
}
PCREG(52aae0, guess52aae0);
