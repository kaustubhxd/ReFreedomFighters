// batch837.cpp - gap band small functions with hooked callees (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634d22(void *dst, void *src, u32 n);   // hooked (GUESS): memmove
extern "C" u32 __attribute__((cdecl)) ext_634273(u32 a, u32 b);                    // hooked (GUESS): delete-like
extern "C" u32 __attribute__((cdecl)) ext_41e290(u32 n);                           // hooked (GUESS): new

// 0x62f340: cdecl(obj) - moves min(obj->[0x1c][0x14], obj[0x10]) bytes from the source block [0x1c][0x10] to obj[0xc], advancing
// both sides; when the source has nothing left, its read pointer ([+0x10]) resets to its base ([+8])
static void __attribute__((cdecl)) pumpBytes_62f340(u8 *o) {
  u8 *src = *(u8 **)(o + 0x1c);
  u32 n = *(u32 *)(src + 0x14);
  if (n > *(u32 *)(o + 0x10)) n = *(u32 *)(o + 0x10);
  if (n) {
    ext_634d22(*(void **)(o + 0xc), *(void **)(src + 0x10), n);
    *(u32 *)(o + 0xc) += n;
    *(u32 *)(*(u8 **)(o + 0x1c) + 0x10) += n;
    *(u32 *)(o + 0x14) += n;
    *(u32 *)(o + 0x10) -= n;
    *(u32 *)(*(u8 **)(o + 0x1c) + 0x14) -= n;
    u8 *s2 = *(u8 **)(o + 0x1c);
    if (*(u32 *)(s2 + 0x14) == 0) *(u32 *)(s2 + 0x10) = *(u32 *)(s2 + 8);
  }
}
PCREG(62f340, pumpBytes_62f340);

// 0x623b80: cdecl(unused, u8 **src, u8 *srcEnd, u8 **dst, u8 *dstEnd) - copies 16-bit words with a byte swap from *src to *dst
// until either end; the source end backs up 2 when a surrogate lead (byte & 0xf8 == 0xd8) sits at srcEnd - 2 and the source is
// longer than the room left in dst
static void __attribute__((cdecl)) swapCopy16_623b80(u32 unused, u8 **src, u8 *end, u8 **dst, u8 *dstEnd) {
  (void)unused;
  s32 room = (s32)((u32)dstEnd - (u32)*dst) & ~1;
  u8 *s0 = *src;
  if ((s32)(end - s0) > room) {
    if ((end[-2] & 0xf8) == 0xd8) end -= 2;
  }
  if (s0 == end) return;
  do {
    u8 *d = *dst;
    if (d == dstEnd) return;
    u8 *p = *src;
    *(u16 *)d = (u16)((p[0] << 8) | p[1]);
    *dst += 2;
    *src += 2;
  } while (*src != end);
}
PCREG(623b80, swapCopy16_623b80);

// 0x639d80: thiscall(src, n, own) ret 0xc - frees an owned buffer ([0x2d], flag [0x31]); sets count [0x32] = n; if (u8)own
// it allocates 4n bytes (saturating at 0xffffffff), copies the words and takes ownership, else it just points at src
static void THISCALL setWords_639d80(u8 *self, u32 src, u32 n, u32 own) {
  if (self[0x31]) {
    ext_634273(*(u32 *)(self + 0x2d), 4);
    *(u32 *)(self + 0x2d) = 0;
    self[0x31] = 0;
  }
  *(u32 *)(self + 0x32) = n;
  if ((u8)own) {
    u64 sz = (u64)n * 4;
    u32 p = ext_41e290(sz >> 32 ? 0xffffffffu : (u32)sz);
    *(u32 *)(self + 0x2d) = p;
    ext_634d22((void *)p, (void *)src, *(u32 *)(self + 0x32) << 2);
    self[0x31] = 1;
  } else {
    *(u32 *)(self + 0x2d) = src;
  }
}
PCREG(639d80, setWords_639d80);
