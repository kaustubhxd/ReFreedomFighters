// batch37061.cpp - cascade s6 batch 37061: 0x62f1e0.
#include "ff.h"

extern "C" void ext_634d22(u8 *dst, u8 *src, u32 n);                    // memcpy thunk, cdecl
extern "C" u32 STDCALL ext_6316e0(u32 adler, u8 *buf, u32 n);          // checksum update, stdcall (ret 0xc)
#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static void slide16(u16 *base, u32 n, u32 wsize) {
  u16 *p = base + n;
  do {
    u32 m = *--p;
    *p = (u16)(m >= wsize ? m - wsize : 0);
  } while (--n);
}

// 0x62f1e0, cdecl(s): zlib's fill_window (old layout). s: +0 stream {next_in +0, avail_in +4, total_in +8, state +0x1c (+0x18 flag), checksum +0x30}, +0x24 w_size, +0x30 window,
// +0x34 window_size, +0x38 prev, +0x3c head, +0x40 ins_h, +0x44 hash_size, +0x4c hash_mask, +0x50 hash_shift, +0x54 match_start, +0x64 strstart, +0x68 block_start, +0x6c lookahead.
// Loops while lookahead < 0x106 and input remains: slides the window by w_size when strstart is near the end (adjusting positions, head and prev), reads up to the free space
// from the stream (checksum updated when the state flag is clear), then recomputes ins_h from the first two bytes once lookahead >= 3.
static void fn62f1e0(u8 *s) {
  u32 wsize = D32(s, 0x24);
  for (;;) {
    u32 strstart = D32(s, 0x64), look = D32(s, 0x6c);
    u32 more = D32(s, 0x34) - strstart - look;
    u32 edx;
    if (more == 0 && strstart == 0 && look == 0) {
      edx = wsize;
    } else if (more == 0xffffffffu) {
      edx = 0xfffffffeu;
    } else {
      edx = more;
      if (strstart >= D32(s, 0x24) + 0xfffffefau + wsize) {
        u8 *window = *(u8 **)(s + 0x30);
        ext_634d22(window, window + wsize, wsize);
        D32(s, 0x68) -= wsize;
        D32(s, 0x64) -= wsize;
        D32(s, 0x54) -= wsize;
        slide16(*(u16 **)(s + 0x3c), D32(s, 0x44), wsize);
        slide16(*(u16 **)(s + 0x38), wsize, wsize);
        edx = more + wsize;
      }
    }
    u8 *strm = *(u8 **)s;
    if (D32(strm, 4) == 0) return;
    u8 *dest = (u8 *)(D32(s, 0x6c) + D32(s, 0x64) + D32(s, 0x30));
    u32 avail = D32(strm, 4);
    u32 n = avail > edx ? edx : avail;
    u32 added;
    if (n == 0) {
      added = 0;
    } else {
      D32(strm, 4) = avail - n;
      u8 *state = *(u8 **)(strm + 0x1c);
      if (D32(state, 0x18) == 0) D32(strm, 0x30) = ext_6316e0(D32(strm, 0x30), *(u8 **)strm, n);
      ext_634d22(dest, *(u8 **)strm, n);
      D32(strm, 0) += n;
      D32(strm, 8) += n;
      added = n;
    }
    D32(s, 0x6c) += added;
    u32 lookahead = D32(s, 0x6c);
    if (lookahead >= 3) {
      u8 *p = (u8 *)(D32(s, 0x30) + D32(s, 0x64));
      u32 h = p[0];
      D32(s, 0x40) = h;
      h = ((h << (D32(s, 0x50) & 31)) ^ p[1]) & D32(s, 0x4c);
      D32(s, 0x40) = h;
    }
    if (lookahead >= 0x106) return;
    if (D32(*(u8 **)s, 4) == 0) return;
  }
}
PCREG(62f1e0, fn62f1e0);
