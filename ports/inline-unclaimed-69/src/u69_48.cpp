// u69_48.cpp - area 69, group 48 (slice 8). No callees, no SEH, no x87 (SSE floats only). Byte flag updates on self, one float path, and reads of the globals 0x70039c and 0x7003b8.
#include "ff.h"

// 0x5b3540, thiscall no args (ret), void. Copies the four flag bytes at +0x177..0x17a to +0x19b..0x19e; with +0x1bc set, clears +0x19f; otherwise masks the bytes +0x171..0x174 into +0x19f..0x1a2 (mask 0x7f, or 0x1f when +0x1a4 is set).
// Swaps pairs under +0x55 and +0x56 (the +0x56 pair depends on the dword at +0x63 -> +0xa4c). Sets +0x16d from +0x1b4 (or 0 when the dword at +0x63 -> +0xe1c is 2),
// stores a few bytes, runs a float path on +0x1e5 and +0x1e9, sets +0x1aa from +0x169 and +0x16c, and ORs +0x17c into +0x1aa when +0xe1c is 2.
static void THISCALL flagUpdate5b3540(u8 *d) {
  d[0x19b] = d[0x177];
  d[0x19c] = d[0x178];
  d[0x19d] = d[0x179];
  d[0x19e] = d[0x17a];
  if (d[0x1bc] != 0) {
    *(u32 *)(d + 0x19f) = 0;
  } else {
    u8 mask = d[0x1a4] == 0 ? 0x7f : 0x1f;
    d[0x19f] = d[0x171] & mask;
    d[0x1a0] = d[0x172] & mask;
    d[0x1a1] = d[0x173] & mask;
    d[0x1a2] = d[0x174] & mask;
  }
  if (d[0x55] != 0) {
    u8 t = d[0x19c];
    d[0x19c] = d[0x19b];
    d[0x19b] = t;
  }
  if (d[0x56] != 0) {
    u8 *p = *(u8 **)(d + 0x63);
    if (*(u32 *)(p + 0xa4c) == 0) {
      u8 t = d[0x1a2];
      d[0x1a2] = d[0x1a1];
      d[0x1a1] = t;
    } else {
      u8 t = d[0x19e];
      d[0x19e] = d[0x19d];
      d[0x19d] = t;
    }
  }
  u8 *e = *(u8 **)(d + 0x63);
  if (*(u32 *)(e + 0xe1c) == 2)
    d[0x16d] = 0;
  else
    d[0x16d] = d[0x1b4];
  u8 al = d[0x175];
  u8 cl = d[0x176];
  u8 ch = d[0x16c];
  d[0x1b1] = al;
  u32 sete = *(u32 *)(d + 0x4d) == 3 ? 1u : 0u;
  d[0x1a3] = ch;
  u32 ebx = 0;
  d[0x1b3] = cl;
  u8 *g = *(u8 **)0x70039c;
  if (g[0x6c] != 0)
    ebx = sete;
  if (cl != 0) {
    if (d[0x1e9] == 0) {
      if (d[0x1b2] != 0) {
        if (ebx == 0)
          d[0x1b2] = 0;
        d[0x1e9] = 1;
      } else {
        if (ebx == 0)
          d[0x1b2] = 0x7f;
        *(float *)(d + 0x1e5) = (float)*(s32 *)(g + 0x40) * *(float *)0x6785e4;
        d[0x1e9] = 1;
      }
    }
  } else if (d[0x1e9] != 0) {
    float t = *(float *)(d + 0x1e5);
    t = t + *(float *)0x67a288;
    t = t * *(float *)0x678620;
    s32 r = (s32)t;
    if (!(r >= *(s32 *)(g + 0x40)) && ebx == 0)
      d[0x1b2] = 0;
    d[0x1e9] = 0;
  }
  u8 *h = *(u8 **)0x7003b8;
  if (h[0x2c89] == 0)
    d[0x1aa] = ch;
  else
    d[0x1aa] = d[0x169] | ch;
  if (*(u32 *)(e + 0xe1c) == 2)
    d[0x1aa] |= d[0x17c];
}
PCREG(5b3540, flagUpdate5b3540);
