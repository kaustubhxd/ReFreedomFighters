// batch49000.cpp - cascade u2 batch 49000: 0x5f0af0 (vector of 12-byte elements: insert one element at a position).
#include "ff.h"

extern "C" u8 *THISCALL ext_6014a0(u8 *self, u32 bytes);       // ret 4: allocate
extern "C" void THISCALL ext_54f870(u8 *self, u8 *p, u32 n);   // ret 8: free

static inline void cp12(u8 *d, const u8 *s) {
  *(u64 *)d = *(const u64 *)s;
  *(u32 *)(d + 8) = *(const u32 *)(s + 8);
}
// the compiler's divide-by-12 for a byte difference (signed, magic 0x2aaaaaab)
static inline s32 div12(s32 d) {
  s32 hi = (s32)(((long long)d * 0x2aaaaaab) >> 32);
  hi >>= 1;
  return hi + (s32)((u32)hi >> 31);
}

// 0x5f0af0, thiscall(pos, val) ret 8: vector {first, last, cap end} of 12-byte elements; inserts *val before pos.
static void THISCALL fn5f0af0(u32 *v, u8 *pos, u8 *val) {
  u8 *last = (u8 *)v[1];
  if (last != (u8 *)v[2]) {
    if (last) cp12(last, last - 12);
    u8 *esi = (u8 *)v[1];
    u8 *ecx = esi + 12;
    v[1] = (u32)ecx;
    u8 *edi = ecx - 24;
    u64 x1 = *(u64 *)val;
    u32 tail = *(u32 *)(val + 8);
    s32 n = div12((s32)(edi - pos));
    while (n > 0) {
      edi -= 12;
      esi -= 12;
      cp12(esi, edi);
      n--;
    }
    *(u64 *)pos = x1;
    *(u32 *)(pos + 8) = tail;
    return;
  }
  u8 *first = (u8 *)v[0];
  s32 n = div12((s32)(last - first));
  u32 cap;
  u8 *nb;
  if (n == 0) {
    cap = 1;
    nb = ext_6014a0((u8 *)v, 12);
  } else {
    cap = (u32)n * 2;
    nb = cap == 0 ? 0 : ext_6014a0((u8 *)v, cap * 12);
  }
  u8 *src = first;
  u8 *dst = nb;
  while (src != pos) {
    if (dst) cp12(dst, src);
    src += 12;
    dst += 12;
  }
  if (dst) cp12(dst, val);
  u8 *esi = dst + 12;
  u8 *l2 = (u8 *)v[1];
  if (pos != l2) {
    u8 *s = pos;
    while (s != l2) {
      if (esi) cp12(esi, s);
      s += 12;
      esi += 12;
    }
  }
  u8 *f2 = (u8 *)v[0];
  s32 m = div12((s32)((u8 *)v[2] - f2));
  if (m != 0) ext_54f870((u8 *)v, f2, (u32)m * 12);
  v[1] = (u32)esi;
  v[0] = (u32)nb;
  v[2] = (u32)nb + cap * 12;
}
PCREG(5f0af0, fn5f0af0);
