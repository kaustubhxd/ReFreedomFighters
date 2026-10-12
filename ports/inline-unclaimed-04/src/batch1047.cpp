// batch1047.cpp - unclaimed-04 batch 47 (docs/20-unclaimed-04.md): 0x625c30, cdecl (table, string), returns a pointer.
#include "ff.h"

// 0x625c30: advance over pairs (c, 0) whose class table[c + 0x4c] is 9, 10 or 21; otherwise return the current pair.
static const u8 *__attribute__((cdecl)) unk625c30PairScan(const u8 *tab, const u8 *s) {
  const u8 *p = s;
  for (;;) {
    if (p[1] != 0) return p;
    u8 cls = tab[p[0] + 0x4c];
    if (cls == 9 || cls == 10 || cls == 0x15) {
      p += 2;
      continue;
    }
    return p;
  }
}
PCREG(625c30, unk625c30PairScan);
