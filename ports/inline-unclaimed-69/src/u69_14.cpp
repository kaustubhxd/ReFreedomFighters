// u69_14.cpp - area 69, group 14 (unclaimed-69 thread).
#include "ff.h"

// 0x54db90, thiscall with one stack arg (ret 4), no callees. A null arg gives 0; otherwise the dword at self+0x8031 plus the dword at arg+4.
static u32 THISCALL sumAt8031(u8 *self, u8 *p) {
  if (!p)
    return 0;
  return *(u32 *)(self + 0x8031) + *(u32 *)(p + 4);
}
PCREG(54db90, sumAt8031);
