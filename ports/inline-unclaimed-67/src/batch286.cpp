// batch286.cpp - unclaimed area 67: lookup table helper 0x439570 (stdcall, ret 4), a cross-check of the batch 42 port.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x439570: walks the 16-byte records at 0x6e48c0 (ptr at +0, size at +4). With c = the sum of earlier sizes, returns the
// dword at ptr_k + 12*(x - c) for the first k with (x - c) < size_k (signed); returns 0 at a zero ptr.
static u32 STDCALL lookupTable39570(u32 x) {
  if (rdw(0x6e48c0, 0) == 0)
    return 0;
  u32 c = 0;
  u32 k = 0;
  for (;;) {
    u32 size = rdw(0x6e48c4 + 16 * k, 0);
    s32 t = (s32)(x - c);
    if (t < (s32)size) {
      u32 base = rdw(0x6e48c0 + 16 * k, 0);
      return rdw(base, 12 * (u32)t);
    }
    c += size;
    k++;
    if (rdw(0x6e48c0 + 16 * k, 0) == 0)
      return 0;
  }
}
PCREG(439570, lookupTable39570);
