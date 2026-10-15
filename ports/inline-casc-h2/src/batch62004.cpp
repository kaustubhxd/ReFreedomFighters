#include "ff.h"

// 0x46ca60, thiscall(src) ret 4: ask src's slot 0x1e0 about 0x2007db;
// on a true AL, copy its three adjacent fields into this and return EAX as
// left by the byte stores.
static u32 THISCALL fn46ca60(u8 *dst, u8 *src) {
  u32 accepted = vcall<u32>(src, 0x1e0, 0x2007dbu);
  if (!(u8)accepted) return accepted;
  u32 word = *(u32 *)(src + 0x4c);
  *(u32 *)(dst + 0x4c) = word;
  dst[0x50] = src[0x50];
  dst[0x51] = src[0x51];
  return (word & 0xffffff00u) | src[0x51];
}

PCREG(46ca60, fn46ca60);
