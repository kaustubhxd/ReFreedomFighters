// batch38038.cpp - cascade s8 batch 38038: 0x62ef10 (zlib deflateInit2_).
#include "ff.h"

extern "C" s32 STDCALL ext_62ee40(u8 *strm);   // deflateEnd, ret 4
extern "C" s32 STDCALL ext_62f140(u8 *strm);   // deflateReset, ret 4
typedef u8 *(*zalloc_t)(u32 opaque, u32 items, u32 size);   // cdecl

// 0x62ef10, stdcall(strm, level, method, windowBits, memLevel, strategy, version, stream_size) ret 0x20 -> zlib status. Rejects a wrong version / stream size (-6), a null stream or bad
// parameter (-2), allocates the 0x16b8-byte deflate state and its window / prev / head / pending buffers through the stream's zalloc (defaults 0x631810 / 0x631840 when unset) and fills the
// state: wrap flag (negative windowBits), window and hash sizes / masks / shift, lit_bufsize = 1 << (memLevel + 6), the pending / d_buf / l_buf layout, level and strategy; any failed allocation
// stores the message from 0x6f44d0 and ends the stream (-4); success returns deflateReset (0x62f140).
static s32 STDCALL fn62ef10(u8 *strm, s32 level, s32 method, s32 windowBits, s32 memLevel, u32 strategy, const char *version, u32 streamSize) {
  s32 wrap = 0;
  if (!version) return -6;
  if (version[0] != **(char **)0x6f4478) return -6;
  if (streamSize != 0x38) return -6;
  if (!strm) return -2;
  *(u32 *)(strm + 0x18) = 0;
  if (*(u32 *)(strm + 0x20) == 0) {
    *(u32 *)(strm + 0x20) = 0x631810;
    *(u32 *)(strm + 0x28) = 0;
  }
  if (*(u32 *)(strm + 0x24) == 0) *(u32 *)(strm + 0x24) = 0x631840;
  if (level == -1) level = 6;
  s32 wbits = windowBits;
  if (wbits < 0) {
    wbits = -wbits;
    wrap = 1;
  }
  if ((u32)(memLevel - 1) > 8 || method != 8 || (u32)(wbits - 8) > 7 || (u32)level > 9 || strategy > 2) return -2;
  u8 *s = (*(zalloc_t *)(strm + 0x20))(*(u32 *)(strm + 0x28), 1, 0x16b8);
  if (!s) return -4;
  *(u8 **)(strm + 0x1c) = s;
  *(s32 *)(s + 0x28) = wbits;
  u32 wsize = 1u << wbits;
  *(s32 *)(s + 0x18) = wrap;
  u32 hbits = (u32)memLevel + 7;
  *(u32 *)(s + 0x48) = hbits;
  *(u8 **)s = strm;
  *(u32 *)(s + 0x2c) = wsize - 1;
  u32 hsize = 1u << hbits;
  *(u32 *)(s + 0x44) = hsize;
  *(u32 *)(s + 0x4c) = hsize - 1;
  *(u32 *)(s + 0x24) = wsize;
  *(u32 *)(s + 0x50) = (hbits + 2) / 3;
  zalloc_t za = *(zalloc_t *)(strm + 0x20);
  *(u8 **)(s + 0x30) = za(*(u32 *)(strm + 0x28), wsize, 2);
  za = *(zalloc_t *)(strm + 0x20);
  *(u8 **)(s + 0x38) = za(*(u32 *)(strm + 0x28), *(u32 *)(s + 0x24), 2);
  za = *(zalloc_t *)(strm + 0x20);
  *(u8 **)(s + 0x3c) = za(*(u32 *)(strm + 0x28), *(u32 *)(s + 0x44), 2);
  u32 lit = 1u << ((u32)memLevel + 6);
  *(u32 *)(s + 0x1694) = lit;
  za = *(zalloc_t *)(strm + 0x20);
  u8 *over = za(*(u32 *)(strm + 0x28), lit, 4);
  u32 l2 = *(u32 *)(s + 0x1694);
  *(u8 **)(s + 8) = over;
  *(u32 *)(s + 0xc) = l2 * 4;
  if (*(u32 *)(s + 0x30) == 0 || *(u32 *)(s + 0x38) == 0 || *(u32 *)(s + 0x3c) == 0 || over == 0) {
    *(u32 *)(strm + 0x18) = G(u32, 0x6f44d0);
    ext_62ee40(strm);
    return -4;
  }
  s[0x1d] = 8;
  *(u8 **)(s + 0x169c) = over + (l2 >> 1) * 2;
  *(u8 **)(s + 0x1690) = over + l2 * 3;
  *(s32 *)(s + 0x7c) = level;
  *(u32 *)(s + 0x80) = strategy;
  return ext_62f140(strm);
}
PCREG(62ef10, fn62ef10);
