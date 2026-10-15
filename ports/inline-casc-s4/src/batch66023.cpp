// batch66023.cpp - cascade s4 batch 66023: 0x42aee0, 0x42afb0 (tier F rows).
#include "ff.h"

typedef void *(*memmove_t)(void *, const void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void *ext_634d22(void *d, const void *s, u32 n);   // cdecl memcpy thunk
extern "C" void THISCALL ext_5f2c60(void *self, u32 a, u32 b); // ret 8

// Assign byte vector s (begin +0, end +4) to d: memcpy when it fits in d's current size, else memcpy the d-sized prefix and append the rest through 0x5f2c60(d, srcbeg + dcap, srcend).
// n is the element count remaining in the caller's loop.
static void assign_vec(u8 *s, u8 *d) {
  u32 sb = rd(s), se = rd(s + 4), db = rd(d);
  u32 len = se - sb;
  u32 dcap = rd(d + 4) - db;
  if (len > dcap) {
    ext_634d22((void *)db, (void *)sb, dcap);
    ext_5f2c60(d, rd(d + 4) - rd(d) + sb, se);
    return;
  }
  ext_634d22((void *)rd(d), (void *)sb, len);
  u32 nb = rd(d) + len;
  u32 oe = rd(d + 4);
  if (nb != oe) {
    G(memmove_t, 0x676278)((void *)nb, (void *)oe, 1);
    wr(d + 4, rd(d + 4) + (nb - oe));
  }
}

// 0x42aee0, fastcall(first = ecx, last = edx, dest, x, y) ret 0xc: n = (last - first) / 12 (signed); n <= 0 -> return dest. For each of the n 12-byte elements s in [first, last) with d = dest + 12 * i:
// s != d -> assign_vec(s, d). Returns the end of the destination.
static u8 *FASTCALL fn42aee0(u8 *first, u8 *last, u8 *dest, u32 x, u32 y) {
  s32 n = (s32)(last - first) / 12;
  if (n <= 0) return dest;
  u8 *s = first;
  u8 *d = dest;
  do {
    if (s != d) assign_vec(s, d);
    n--;
    d += 12;
    s += 12;
  } while (n > 0);
  return d;
}
PCREG(42aee0, fn42aee0);

// 0x42afb0, fastcall(first = ecx, last = edx, destEnd, x, y) ret 0xc: backward version: n = (last - first) / 12; each step moves both pointers back by 12 and assigns last[i] to dest[i]. Returns the final destination start.
static u8 *FASTCALL fn42afb0(u8 *first, u8 *last, u8 *dend, u32 x, u32 y) {
  s32 n = (s32)(last - first) / 12;
  if (n <= 0) return dend;
  u8 *s = last;
  u8 *d = dend;
  do {
    d -= 12;
    s -= 12;
    if (s != d) assign_vec(s, d);
    n--;
  } while (n > 0);
  return d;
}
PCREG(42afb0, fn42afb0);
