// u69_52.cpp - area 69, group 52 (slice 8). MMX packing of four-byte fields into two fixed tables (0x812840 and 0x812940). No callees. The MMX lanes are modelled with 64-bit integers (no MMX instructions in the port).
#include "ff.h"

// Four byte lanes of a dword, zero-extended to 16-bit words (punpcklbw with a zero register).
static u64 unpackBytes4(u32 v) {
  return (u64)(v & 0xff) | ((u64)((v >> 8) & 0xff) << 16) | ((u64)((v >> 16) & 0xff) << 32) | ((u64)(v >> 24) << 48);
}

// psllw by n on each 16-bit lane.
static u64 shiftLanes(u64 a, unsigned n) {
  u64 r = 0;
  for (unsigned i = 0; i < 4; ++i) {
    u32 lane = (u32)(a >> (16 * i)) & 0xffff;
    r |= (u64)((lane << n) & 0xffff) << (16 * i);
  }
  return r;
}

// psubw on each 16-bit lane (no borrow between lanes).
static u64 subLanes(u64 a, u64 b) {
  u64 r = 0;
  for (unsigned i = 0; i < 4; ++i) {
    u32 la = (u32)(a >> (16 * i)) & 0xffff;
    u32 lb = (u32)(b >> (16 * i)) & 0xffff;
    r |= (u64)((la - lb) & 0xffff) << (16 * i);
  }
  return r;
}

// 0x61ad80, stdcall three args (src, count, flags; ret 0xc), void. count must be at least 1 (the original loops until ecx wraps when count is 0).
// nIter = (count + 3) / 4. If flags has bit 0x2000: table 0x812840 gets the four fields (+0x18, +0x3c, +0x60, +0x84) of each 0x90-byte record shifted left 5 per 16-bit lane,
// and table 0x812940 gets (0x6efd14 - (byte 3 of the dword at +0x18) * 0x10101 << 5) per lane, one qword per count (not nIter), with the records 0x24 bytes apart.
// Otherwise the same first table is written with shift 4, and table 0x812940 is zeroed (32 bytes per iteration).
static void STDCALL pack61ad80(u8 *src, u32 count, u32 flags) {
  const u32 nIter = (count + 3) >> 2;
  u8 *dst = (u8 *)0x812840;
  u8 *s = src;
  if (flags & 0x2000) {
    for (u32 i = 0; i < nIter; ++i, s += 0x90, dst += 0x20) {
      *(u64 *)(dst + 0x00) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x18)), 5);
      *(u64 *)(dst + 0x08) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x3c)), 5);
      *(u64 *)(dst + 0x10) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x60)), 5);
      *(u64 *)(dst + 0x18) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x84)), 5);
    }
    u64 c = *(u64 *)0x6efd14;
    u8 *d2 = (u8 *)0x812940;
    s = src;
    for (u32 i = 0; i < count; ++i, s += 0x24, d2 += 8) {   // this loop counts N, not nIter
      u32 b3 = *(u32 *)(s + 0x18) >> 24;
      u32 v = b3 * 0x010101u;
      *(u64 *)d2 = subLanes(c, shiftLanes(unpackBytes4(v), 5));
    }
  } else {
    for (u32 i = 0; i < nIter; ++i, s += 0x90, dst += 0x20) {
      *(u64 *)(dst + 0x00) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x18)), 4);
      *(u64 *)(dst + 0x08) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x3c)), 4);
      *(u64 *)(dst + 0x10) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x60)), 4);
      *(u64 *)(dst + 0x18) = shiftLanes(unpackBytes4(*(u32 *)(s + 0x84)), 4);
    }
    u8 *z = (u8 *)0x812940;
    for (u32 i = 0; i < nIter; ++i, z += 0x20) {
      *(u64 *)(z + 0x00) = 0;
      *(u64 *)(z + 0x08) = 0;
      *(u64 *)(z + 0x10) = 0;
      *(u64 *)(z + 0x18) = 0;
    }
  }
}
PCREG(61ad80, pack61ad80);
