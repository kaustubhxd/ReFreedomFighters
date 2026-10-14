// batch38003.cpp - cascade s8 batch 38003: 0x630ec0 (zlib send_all_trees).
#include "ff.h"

extern "C" void ext_631100(u8 *s, u8 *tree, int max_code);   // cdecl (send_tree)

// send_bits into the deflate state: bi_buf u16 at +0x16b0, bi_valid at +0x16b4, pending_buf at +8, pending at +0x14.
// Shift counts are masked to 5 bits like the x86 instructions the original uses.
static inline void send_bits(u8 *s, u32 value, int length) {
  int bv = *(int *)(s + 0x16b4);
  u16 v = (u16)value;
  if (bv > 16 - length) {
    u16 buf = *(u16 *)(s + 0x16b0);
    u32 p = *(u32 *)(s + 0x14);
    buf = (u16)(buf | (u16)(v << (bv & 31)));
    *(u16 *)(s + 0x16b0) = buf;
    ((u8 *)*(u32 *)(s + 8))[p] = (u8)buf;
    *(u32 *)(s + 0x14) = p + 1;
    p = *(u32 *)(s + 0x14);
    ((u8 *)*(u32 *)(s + 8))[p] = s[0x16b1];
    u8 cl = (u8)(16 - *(int *)(s + 0x16b4));
    *(u32 *)(s + 0x14) += 1;
    u16 r = (u16)(v >> (cl & 31));
    *(int *)(s + 0x16b4) += length - 16;
    *(u16 *)(s + 0x16b0) = r;
  } else {
    *(u16 *)(s + 0x16b0) |= (u16)(v << (bv & 31));
    *(int *)(s + 0x16b4) = bv + length;
  }
}

// 0x630ec0, cdecl(s, lcodes, dcodes, blcodes): the dynamic tree header (5, 5, 4 bit counts, then 3-bit bit-length code lengths in bl_order
// order) followed by send_tree for the literal and distance trees.
static void fn630ec0(u8 *s, int lcodes, int dcodes, int blcodes) {
  send_bits(s, (u32)(lcodes - 257), 5);
  send_bits(s, (u32)(dcodes - 1), 5);
  send_bits(s, (u32)(blcodes - 4), 4);
  for (int rank = 0; rank < blcodes; rank++)
    send_bits(s, *(u16 *)(s + *(u8 *)(0x6c1070 + rank) * 4 + 0xa76), 3);
  ext_631100(s, s + 0x8c, lcodes - 1);
  ext_631100(s, s + 0x980, dcodes - 1);
}
PCREG(630ec0, fn630ec0);
