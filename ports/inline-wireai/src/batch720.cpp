// batch720.cpp - soldier AI, batch 720 (2026-10-11): element copy routines of the CFFCoverList spot vector.
// Records are CCoverSpot-sized (0x48 bytes). Both routines work on [first, last) in ecx/edx; the destination (and two
// unused stack words) come from the stack, as the originals take them.
#include "ff.h"

// 0x5853a0 (ret 8): copy [first, last) forward to dest. Returns the advanced destination (one past the last copy) in EAX.
static u8 *FASTCALL cover_CopyForward(u8 *first, u8 *last, u8 *dest, u32) {
  for (u8 *p = first; p != last; p += 0x48, dest += 0x48) {
    if (dest)
      for (int k = 0; k < 0x48; k++)
        dest[k] = p[k];
  }
  return dest;
}
PCREG(5853a0, cover_CopyForward);

// 0x5852f0 (ret 0xc): copy backward. The count is (last - first) / 0x48 (signed); the destination is the stack word
// [ebp+8], moved down by one record before each copy. Returns nothing.
static void FASTCALL cover_CopyBackward(u8 *first, u8 *last, u8 *dest, u32, u32) {
  s32 n = (s32)(last - first) / 0x48;
  u8 *src = last;
  while (n > 0) {
    dest -= 0x48;
    src -= 0x48;
    for (int k = 0; k < 0x48; k++)
      dest[k] = src[k];
    n--;
  }
}
PCREG(5852f0, cover_CopyBackward);
