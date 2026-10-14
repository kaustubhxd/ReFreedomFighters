// batch37098.cpp - cascade s6 batch 37098: 0x62fc30.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_630120(u8 *s);   // bi_flush

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define BUF(s) (*(u16 *)((u8 *)(s) + 0x16b0))
#define VALID(s) (*(s32 *)((u8 *)(s) + 0x16b4))

static void putShort(u8 *s) {
  u8 *pb = *(u8 **)(s + 8);
  pb[D32(s, 0x14)] = (u8)BUF(s);
  D32(s, 0x14)++;
  pb[D32(s, 0x14)] = (u8)(BUF(s) >> 8);
  D32(s, 0x14)++;
}

// zlib send_bits(value, length) with Buf_size 16.
static void sendBits(u8 *s, u32 value, s32 length) {
  s32 valid = VALID(s);
  BUF(s) |= (u16)(value << (valid & 31));
  if (valid > 16 - length) {
    putShort(s);
    BUF(s) = (u16)(value >> (16 - valid));
    VALID(s) += length - 16;
  } else {
    VALID(s) = valid + length;
  }
}

// 0x62fc30, cdecl(s), plain ret: zlib _tr_align. Sends an empty static block (3 bits value 2 and the 7-bit end-of-block code 0), flushes, and when the previous end-of-block
// code plus this one leave fewer than 9 bits of lookahead sends a second empty static block; last_eob_len (+0x16ac) becomes 7.
static void fn62fc30(u8 *s) {
  sendBits(s, 2, 3);
  sendBits(s, 0, 7);
  ext_630120(s);
  if (1 + (s32)D32(s, 0x16ac) + 10 - VALID(s) < 9) {
    sendBits(s, 2, 3);
    sendBits(s, 0, 7);
    ext_630120(s);
  }
  D32(s, 0x16ac) = 7;
}
PCREG(62fc30, fn62fc30);
