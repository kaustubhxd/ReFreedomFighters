// batch67503.cpp - cascade s6 batch 67503: 0x6316e0.
#include "ff.h"

// 0x6316e0, stdcall(adler, buf, len) ret 0xc: zlib adler32. A null buffer returns 1; the data is summed in blocks of at most 5552 bytes (reduced modulo 65521 after each block), the
// two halves recombined as (b << 16) | a. With len == 0 the input checksum is returned unreduced.
static u32 STDCALL fn6316e0(u32 adler, const u8 *buf, u32 len) {
  u32 a = adler & 0xffff;
  u32 b = adler >> 16;
  if (!buf) return 1;
  while (len) {
    u32 n = len < 0x15b0 ? len : 0x15b0;
    len -= n;
    while (n--) {
      a += *buf++;
      b += a;
    }
    a %= 65521;
    b %= 65521;
  }
  return (b << 16) | a;
}
PCREG(6316e0, fn6316e0);
