// batch210069.cpp - Sonnet-w3a: 0x6206e0 (make room in a growable block-list buffer: reuse a free block, grow in place, or chain a new block)
#include "ff.h"

extern "C" u32 ext_634d22(u32 dst, u32 src, u32 n);

typedef u32 (*Malloc)(u32 n);
typedef u32 (*Realloc)(u32 p, u32 n);

static u32 fn6206e0(u32 *s) {
  u32 *edx = (u32 *)s[1];
  if (edx) {  // @6206e0_a
    u32 ecx = s[4];
    if (!ecx) {  // @6206e0_b
      s[0] = (u32)edx;
      s[1] = edx[0];
      edx[0] = 0;  // @6206e0_c
      u32 d = s[0] + 8;
      s[4] = d;
      u32 sz = ((u32 *)s[0])[1];
      s[3] = d;
      s[2] = sz + d;  // @6206e0_d
      return 1;
    }
    if ((int)(s[2] - ecx) < (int)edx[1]) {  // @6206e0_e
      u32 nxt = edx[0];
      edx[0] = s[0];
      s[0] = s[1];
      s[1] = nxt;  // @6206e0_f
      u32 n = s[2] - s[4];
      ext_634d22(s[0] + 8, s[4], n);  // @6206e0_g
      u32 b = s[0];
      s[3] += b - s[4] + 8;  // @6206e0_h
      s[4] = b + 8;
      s[2] = ((u32 *)b)[1] + b + 8;
      return 1;
    }
  }
  u32 *cur = (u32 *)s[0];
  if (cur && s[4] == (u32)cur + 8) {  // @6206e0_i
    u32 want = (s[2] - s[4]) * 2;  // @6206e0_j
    u32 *alloc = (u32 *)s[5];
    u32 *nb = (u32 *)(*(Realloc *)(alloc + 1))((u32)cur, want + 8);  // @6206e0_k
    s[0] = (u32)nb;
    if (!nb) return 0;
    nb[1] = want;
    u32 b = s[0];
    s[3] += b - s[4] + 8;
    s[4] = b + 8;
    s[2] = s[4] + want;  // @6206e0_l
    return 1;
  }
  u32 sz = 0x400;
  int avail = (int)(s[2] - s[4]);
  if (avail >= 0x400) sz = (u32)avail * 2;  // @6206e0_m
  u32 *alloc = (u32 *)s[5];
  u32 *nb = (u32 *)(*(Malloc *)alloc)(sz + 8);  // @6206e0_n
  if (!nb) return 0;
  nb[1] = sz;
  nb[0] = s[0];
  u32 eax = s[3], ecx = s[4];
  s[0] = (u32)nb;
  if (eax != ecx) ext_634d22((u32)nb + 8, ecx, eax - ecx);  // @6206e0_o
  s[3] += (u32)nb - s[4] + 8;  // @6206e0_p
  s[4] = (u32)nb + 8;
  s[2] = sz + 8 + (u32)nb;
  return 1;
}
PCREG(6206e0, fn6206e0);
