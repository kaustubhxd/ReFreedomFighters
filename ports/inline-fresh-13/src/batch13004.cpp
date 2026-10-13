// batch13004.cpp - fresh slice 13, batch 4 (docs/20-fresh-13.md), 2026-10-12.
// 0x62fe10 zlib 1.2.3 trees.c _tr_flush_block(deflate_state *s, charf *buf, ulg stored_len, int eof) (cdecl). Name from the
// zlib source this matches (set_data_type on s->data_type == Z_UNKNOWN (byte +0x1c == 2), no Z_FIXED test); the name map
// has no entry. Fields: level +0x7c, pending_buf +8, pending +0x14, l_desc +0xb10 (max_code +0xb14), d_desc +0xb1c
// (max_code +0xb20), bl tree build, opt_len +0x16a0, static_len +0x16a4, bi_buf (word) +0x16b0, bi_valid +0x16b4.
// send_bits(s, value, 3) is inlined with Buf_size 16 (16-bit shifts; the hardware masks counts to 5 bits, kept here).
// Callees (all cdecl, original code, hooked by the spec): set_data_type 0x631620, build_tree 0x6302f0, build_bl_tree
// 0x630200, _tr_stored_block 0x630070, compress_block 0x6304f0 (static trees 0x6c0b78 / 0x6c0ff8, dynamic s+0x8c /
// s+0x980), send_all_trees 0x630ec0, init_block 0x630c50, bi_windup 0x6301a0.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_631620[], ext_6302f0[], ext_630200[], ext_630070[], ext_6304f0[], ext_630ec0[], ext_630c50[],
    ext_6301a0[];
typedef void (*F1)(u8 *s);
typedef u32 (*F1r)(u8 *s);
typedef void (*F2)(u8 *s, u32 a);
typedef void (*F3)(u8 *s, u32 a, u32 b);
typedef void (*F4)(u8 *s, u32 a, u32 b, u32 c);

static void sendBits3(u8 *s, u32 value) {
  u32 bv = AT(u32, s, 0x16b4);
  if ((s32)bv > 13) {
    AT(u16, s, 0x16b0) |= (u16)(((u32)(u16)value) << (bv & 31));
    u8 *pb = AT(u8 *, s, 8);
    pb[AT(u32, s, 0x14)] = AT(u8, s, 0x16b0);
    AT(u32, s, 0x14)++;
    pb = AT(u8 *, s, 8);
    pb[AT(u32, s, 0x14)] = AT(u8, s, 0x16b1);
    u8 cl = (u8)(0x10 - AT(u8, s, 0x16b4));
    AT(u32, s, 0x14)++;
    u16 hi = (u16)((u32)(u16)value >> (cl & 31));
    AT(u32, s, 0x16b4) += (u32)-13;
    AT(u16, s, 0x16b0) = hi;
  } else {
    AT(u16, s, 0x16b0) |= (u16)(((u32)(u16)value) << (bv & 31));
    AT(u32, s, 0x16b4) = bv + 3;
  }
}

static void trFlushBlock(u8 *s, u32 buf, u32 stored_len, u32 eof) {
  u32 max_blindex = 0, opt_lenb, static_lenb;
  if ((s32)AT(u32, s, 0x7c) > 0) {
    if (AT(u8, s, 0x1c) == 2)
      ((F1)(void *)ext_631620)(s);
    ((F2)(void *)ext_6302f0)(s, (u32)(s + 0xb10));
    ((F2)(void *)ext_6302f0)(s, (u32)(s + 0xb1c));
    max_blindex = ((F1r)(void *)ext_630200)(s);
    opt_lenb = (AT(u32, s, 0x16a0) + 10) >> 3;
    static_lenb = (AT(u32, s, 0x16a4) + 10) >> 3;
    if (static_lenb <= opt_lenb)
      opt_lenb = static_lenb;
  } else {
    opt_lenb = static_lenb = stored_len + 5;
  }
  if (stored_len + 4 <= opt_lenb && buf) {
    ((F4)(void *)ext_630070)(s, buf, stored_len, eof);
  } else if (static_lenb == opt_lenb) {
    sendBits3(s, eof + 2);
    ((F3)(void *)ext_6304f0)(s, 0x6c0b78, 0x6c0ff8);
  } else {
    sendBits3(s, eof + 4);
    ((F4)(void *)ext_630ec0)(s, AT(u32, s, 0xb14) + 1, AT(u32, s, 0xb20) + 1, max_blindex + 1);
    ((F3)(void *)ext_6304f0)(s, (u32)(s + 0x8c), (u32)(s + 0x980));
  }
  ((F1)(void *)ext_630c50)(s);
  if (eof)
    ((F1)(void *)ext_6301a0)(s);
}
PCREG(62fe10, trFlushBlock);
