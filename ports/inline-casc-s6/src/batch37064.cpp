// batch37064.cpp - cascade s6 batch 37064: 0x62f430.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x62f430, cdecl(s, cur_match), returns the match length: zlib's longest_match (unrolled compare). s: +0x24 w_size, +0x2c w_mask, +0x30 window, +0x38 prev, +0x64 strstart,
// +0x68 match_start, +0x6c lookahead, +0x70 prev_length (best so far), +0x74 max_chain, +0x84 good_match, +0x88 nice_match.
static u32 fn62f430(u8 *s, u32 cur) {
  u32 chain = D32(s, 0x74);
  u32 strstart = D32(s, 0x64);
  s32 best = (s32)D32(s, 0x70);
  u32 wsize = D32(s, 0x24);
  u8 *scan0 = (u8 *)(D32(s, 0x30) + strstart);
  u32 limit = strstart > wsize - 0x106 ? strstart - wsize + 0x106 : 0;
  u8 *strend = scan0 + 0x102;
  u8 e1 = scan0[best - 1];
  u8 e0 = scan0[best];
  if ((u32)best >= D32(s, 0x84)) chain = D32(s, 0x74) >> 2;
  u32 look = D32(s, 0x6c);
  u32 nice = D32(s, 0x88);
  if (nice > look) nice = look;
  do {
    u8 *match = (u8 *)(D32(s, 0x30) + cur);
    if (match[best] == e0 && match[best - 1] == e1 && match[0] == scan0[0] && match[1] == scan0[1]) {
      u8 *p = scan0 + 2;
      u8 *m = match + 2;
      for (;;) {
        bool bad = false;
        for (int k = 0; k < 8; k++) {
          p++;
          m++;
          if (*p != *m) { bad = true; break; }
        }
        if (bad) break;
        if (!(p < strend)) break;
      }
      s32 len = (s32)(p - strend) + 0x102;
      if (len > best) {
        D32(s, 0x68) = cur;
        best = len;
        if ((s32)len >= (s32)nice) goto done;
        e1 = scan0[best - 1];
        e0 = scan0[best];
      }
    }
    cur = *(u16 *)(D32(s, 0x38) + (cur & D32(s, 0x2c)) * 2);
    if (cur > limit) {
      chain--;
      if (chain == 0) break;
    } else {
      break;
    }
  } while (true);
done:
  return (u32)best <= look ? (u32)best : look;
}
PCREG(62f430, fn62f430);
