// batch794.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

typedef u32(THISCALL *VOneArg)(u8 *, u32);   // vt[0x50]: one stack word, callee cleans (ret 4)

// 0x63cc40, thiscall(a, b) ret 8. Returns vt[0x50](this, a). The second argument is not read.
static u32 THISCALL forwardVt50_63cc40(u8 *self, u32 a, u32 b) {
  (void)b;
  VOneArg f = (VOneArg)(*(u32 *)(*(u32 *)self + 0x50));
  return f(self, a);
}
PCREG(63cc40, forwardVt50_63cc40);
