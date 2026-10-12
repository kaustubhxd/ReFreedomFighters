#include "ff.h"
// batch938.cpp - unclaimed-80 bottom-up leaf (docs/20-unclaimed-80.md): 0x4e1590, the size of the item at the cursor (thiscall, no
// arguments, returns eax). The cursor is the dword at this+8 (a byte pointer). Tag t = 0xff ? 0xff : tag & 0x3f; idx = t - 1; if idx is
// above 11 (unsigned), the size is 0. Otherwise map[idx] picks: 0 -> 8; 1 -> 4; 2 -> the string length from cur+2 (zero-terminated, counted
// from cur+1) plus one; 3 -> the dword at cur+1; 4 -> 0. The map is the 12-byte table at 0x4e15f4.
// Found free in every docs/20 claim (other areas only stub it as a helper).

static u32 THISCALL dblkItemSize(u8 *self) {
  static const u8 map[12] = {0, 1, 1, 2, 2, 4, 3, 1, 3, 1, 1, 3};
  u8 *cur = *(u8 **)(self + 8);
  u8 tag = cur[0];
  u32 t = (tag == 0xff) ? 0xffu : (u32)(tag & 0x3f);
  u32 idx = t - 1;
  if (idx > 0xb)
    return 0;
  switch (map[idx]) {
    case 0:
      return 8;
    case 1:
      return 4;
    case 2: {
      u8 *ec = cur + 1;
      u8 *ed = cur + 2;
      u8 al;
      do {
        al = *ec;
        ec++;
      } while (al != 0);
      return (u32)(ec - ed) + 1;
    }
    case 3:
      return *(u32 *)(cur + 1);
    default:
      return 0;
  }
}
PCREG(4e1590, dblkItemSize);
