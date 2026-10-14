// batch1517.cpp - recruits thread, batch 1517: two small bit-table helpers used by the save-mission code under
// ZFFLevelController (GUESS names: the callers only give their use, not their class).
#include "ff.h"

// Table layout (GUESS from the two functions): this + 0xb2 + 4*k is the number of bits n_k of group k (k = first
// argument, 0..4 at the callers); this + 0x76 + 4*(m + 5*k) is the 32-bit word for group k at slot m (second
// argument). Bits are read from bit 0 upward; the mask rotates, so a group of more than 32 bits reads its word again.

// 0x5ad6c0 (GUESS: CountBitsInGroup(k, m)), thiscall, ret 8. Number of set bits among the first n_k bits of the word.
static u32 THISCALL countBitsInGroup(u8 *self, u32 k, u32 m) {
  u32 n = *(u32 *)(self + 0xb2 + 4 * k);
  u32 cnt = 0;
  if (n != 0) {
    u32 w = *(u32 *)(self + 0x76 + 4 * (m + 5 * k));
    u32 mask = 1;
    for (u32 i = 0; i < n; ++i) {
      if (w & mask)
        ++cnt;
      mask = (mask << 1) | (mask >> 31);   // rol ecx, 1
    }
  }
  return cnt;
}
PCREG(5ad6c0, countBitsInGroup);

// 0x5ad640 (GUESS: AllBitsInGroup(k, m)), thiscall, ret 8. True when every one of the first n_k bits of the word is
// set (true for an empty group). The shift count is the bit index modulo 32, as the x86 shl does.
static u8 THISCALL allBitsInGroup(u8 *self, u32 k, u32 m) {
  u32 n = *(u32 *)(self + 0xb2 + 4 * k);
  if (n == 0)
    return 1;
  u32 w = *(u32 *)(self + 0x76 + 4 * (m + 5 * k));
  for (u32 i = 0; i < n; ++i)
    if ((w & (1u << (i & 31))) == 0)
      return 0;
  return 1;
}
PCREG(5ad640, allBitsInGroup);
