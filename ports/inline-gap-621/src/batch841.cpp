// batch841.cpp - gap band zlib trees.c helpers (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_6301a0(u8 *s);   // real callee: bi_windup (verified in batch 803)

// deflate state field offsets: pending_buf +8, pending +0x14, last_eob_len +0x16ac, bi_buf (u16) +0x16b0, bi_valid +0x16b4
#define S_PBUF(s) (*(u8 **)((s) + 8))
#define S_PEND(s) (*(u32 *)((s) + 0x14))
#define S_BIBUF(s) (*(u16 *)((s) + 0x16b0))
#define S_BIVALID(s) (*(s32 *)((s) + 0x16b4))

// 0x630120: cdecl(s) - zlib bi_flush: with 16 bits buffered, writes both bytes and clears; with 8 or more, writes the low byte
// and shifts the buffer down by 8
static void __attribute__((cdecl)) biFlush_630120(u8 *s) {
  s32 n = S_BIVALID(s);
  if (n == 16) {
    S_PBUF(s)[S_PEND(s)] = (u8)S_BIBUF(s);
    S_PEND(s)++;
    S_PBUF(s)[S_PEND(s)] = ((u8 *)s)[0x16b1];
    S_PEND(s)++;
    S_BIVALID(s) = 0;
    S_BIBUF(s) = 0;
    return;
  }
  if (n >= 8) {
    S_PBUF(s)[S_PEND(s)] = (u8)S_BIBUF(s);
    u16 hi = s[0x16b1];
    S_PEND(s)++;
    S_BIVALID(s) += -8;
    S_BIBUF(s) = hi;
  }
}
PCREG(630120, biFlush_630120);

// 0x630910: cdecl(s, buf, len, header) - zlib copy_block: bi_windup, last_eob_len = 8, optionally writes len and ~len as two
// little-endian words, then copies len bytes into the pending buffer
static void __attribute__((cdecl)) copyBlock_630910(u8 *s, const u8 *buf, u32 len, u32 header) {
  ext_6301a0(s);
  *(u32 *)(s + 0x16ac) = 8;
  if (header) {
    S_PBUF(s)[S_PEND(s)] = (u8)len;
    S_PEND(s)++;
    S_PBUF(s)[S_PEND(s)] = (u8)(len >> 8);
    S_PEND(s)++;
    S_PBUF(s)[S_PEND(s)] = (u8)~len;
    S_PEND(s)++;
    S_PBUF(s)[S_PEND(s)] = (u8)(~len >> 8);
    S_PEND(s)++;
  }
  while (len) {
    S_PBUF(s)[S_PEND(s)] = *buf++;
    S_PEND(s)++;
    len--;
  }
}
PCREG(630910, copyBlock_630910);
