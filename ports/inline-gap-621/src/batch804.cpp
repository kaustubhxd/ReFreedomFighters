// batch804.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x623010, cdecl(unused, src_ref, end, dst_ref, dst_end): copies bytes into 16-bit words, two bytes of output per byte of input.
static void __attribute__((cdecl)) widenBytes_623010(u32 unused, u32 *src, u32 end, u32 *dst, u32 dstEnd) {
  (void)unused;
  if (*src == end) return;
  do {
    if (*dst == dstEnd) break;
    *(u16 *)*dst = (u16)*(u8 *)*src;
    *dst += 2;
    *src += 1;
  } while (*src != end);
}
PCREG(623010, widenBytes_623010);

// 0x623050, cdecl(unused, src_ref, end, dst_ref, dst_end): copies bytes one for one.
static void __attribute__((cdecl)) copyBytes_623050(u32 unused, u32 *src, u32 end, u32 *dst, u32 dstEnd) {
  (void)unused;
  if (*src == end) return;
  do {
    if (*dst == dstEnd) break;
    *(u8 *)*dst = *(u8 *)*src;
    *dst += 1;
    *src += 1;
  } while (*src != end);
}
PCREG(623050, copyBytes_623050);
