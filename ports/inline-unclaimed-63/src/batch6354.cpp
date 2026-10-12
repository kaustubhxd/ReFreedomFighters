// batch6354.cpp - unclaimed-63 gap-band batch 54 (core residue 2): 0x5a8360 ZOnScreenDisplay::GetSpriteInfo(const char *), thiscall,
//   one stack argument s, ret 4, returns a pointer into this's table.
//   found = strstr(G[0x6ed270], s) (cdecl, the import at 0x67625c; caller cleans). n = the number of ';' bytes in the prefix of
//   G[0x6ed270] that ends at found (zero if found is NULL or lies before the string). Returns this + 12 * (n + 2).
#include "ff.h"

typedef char *(*strstr_fn)(u32, u32);

// 0x5a8360 (ZOnScreenDisplay::GetSpriteInfo; the name is from the core list).
static u8 *THISCALL unnamed5a8360(u8 *self, u32 s) {
  u32 p = G(u32, 0x6ed270);
  u32 found = (u32)((strstr_fn)G(u32, 0x67625c))(p, s);
  u32 len = found - p;
  if (p > found)
    len = 0;
  u32 n = 0;
  for (u32 i = 0; i < len; i++) {
    if (*(u8 *)(p + i) == ';')
      n++;
  }
  return self + 12u * (n + 2u);
}
PCREG(5a8360, unnamed5a8360);
