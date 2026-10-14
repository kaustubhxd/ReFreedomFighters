// batch5747.cpp - unclaimed-57, band batch 47 (name GUESS): 0x5d5510, thiscall, no args, ret. eng = dword 0x70039c; sub = dword this+0x44.
// pair[0] = (float)(((v + ((v >> 31) & 15)) >> 4) + 1) with v = dword eng+0x6f (signed, as cdq/and/sar/inc in the original);
// pair[1] = the same from dword eng+0x73. Then sub->vt[+0x258](&pair, 0) (thiscall, two arguments; unverified: a fake slot in the spec
// logs the pair's values, not its address, which differs between runs).
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef void(THISCALL *Slot2)(u8 *self, float *p, u32 b);

static void THISCALL unnamed5d5510(u8 *self) {
  u8 *engine = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(self + 0x44);
  float pair[2];
  s32 v = *(s32 *)(engine + 0x6f);
  pair[0] = (float)(((v + ((v >> 31) & 0xf)) >> 4) + 1);
  s32 w = *(s32 *)(engine + 0x73);
  pair[1] = (float)(((w + ((w >> 31) & 0xf)) >> 4) + 1);
  ((Slot2)VT(sub)[0x258 / 4])(sub, pair, 0);
}
PCREG(5d5510, unnamed5d5510);
