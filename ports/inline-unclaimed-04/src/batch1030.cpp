// batch1030.cpp - unclaimed-04 batch 30 (docs/20-unclaimed-04.md): 0x4022f0, cdecl, two arguments (object, n).
// When n != 0 and the signed sum obj[+0x18] + n exceeds the signed obj[+0x30], return -131 and change nothing. Otherwise
// obj[+0x18] += n and return 0.
#include "ff.h"

static u32 __attribute__((cdecl)) unk4022f0CheckedAdvance(s32 *obj, s32 n) {
  if (n != 0) {
    s32 next = (s32)((u32)obj[6] + (u32)n);  // obj+0x18
    if (next > obj[12]) return 0xffffff7d;   // obj+0x30
  }
  obj[6] = (s32)((u32)obj[6] + (u32)n);
  return 0;
}
PCREG(4022f0, unk4022f0CheckedAdvance);
