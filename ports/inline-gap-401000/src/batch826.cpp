// batch826.cpp - core gameplay batch 826 (docs/20-unclaimed-65.md, batch 826): 0x438290 (ZInputActions::ConvertScanCode), a stdcall with one
// argument (ret 4). When the byte at [[0x70039c]+0x6e] is nonzero it returns the argument. Otherwise it walks a table of (key, value) pairs
// at 0x6e492c (key_i = dword at 0x6e492c+8i, value_i = dword at 0x6e4928+8i): if the first key is above the argument (signed), or zero, it
// returns the argument; else it returns the value of the first key equal to the argument, and the argument when none matches before a zero key.
#include "ff.h"

static u32 STDCALL fn438290(u32 key) {
  if (*(const u8 *)(G(u8 *, 0x70039c) + 0x6e) != 0) return key;
  const int k0 = (int)G(u32, 0x6e492c);
  if (k0 > (int)key || k0 == 0) return key;
  u32 cur = (u32)k0;
  u32 i = 0;
  for (;;) {
    if (cur == key) return G(u32, 0x6e4928 + 8 * i);
    cur = G(u32, 0x6e492c + 8 * (i + 1));
    i++;
    if (cur == 0) break;
  }
  return key;
}

PCREG(438290, fn438290);
