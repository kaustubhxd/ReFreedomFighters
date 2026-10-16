// batch210032.cpp - Sonnet-w3a: small BLOCKED rows (suffix matcher, stored-block writer, list unlink with lazy pool, indexed cache)
#include "ff.h"

extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 ext_41e290(u32 n);
extern "C" u32 ext_6301a0(u8 *a);

static u32 fn626ed0(u32 unused, const u8 *p, const u8 *end, u32 *out) {
  (void)unused;
  *out = 0xb;
  u32 edx = 0;
  if (end - p == 6 && p[0] == 0) {  // @626ed0_a
    int c1 = (signed char)p[1];
    if (c1 == 0x58) edx = 1;  // @626ed0_b
    else if (c1 != 0x78) return 1;
    if (p[2] != 0) return 1;  // @626ed0_c
    int c3 = (signed char)p[3];
    if (c3 == 0x4d) edx = 1;  // @626ed0_d
    else if (c3 != 0x6d) return 1;
    if (p[4] != 0) return 1;  // @626ed0_e
    int c5 = (signed char)p[5];
    if (c5 == 0x4c) return 0;  // @626ed0_f
    if (c5 != 0x6c) return 1;
    if (edx) return 0;  // @626ed0_g
    *out = 0xc;  // @626ed0_h
    return 1;
  }
  return 1;
}
PCREG(626ed0, fn626ed0);

static u32 fn630910(u8 *a, const u8 *src, u32 n, u32 d) {
  u32 r = ext_6301a0(a);  // @630910_a
  *(u32 *)(a + 0x16ac) = 8;  // @630910_b
  if (d) {
    u8 *buf;
    buf = *(u8 **)(a + 8); buf[*(u32 *)(a + 0x14)] = (u8)n; (*(u32 *)(a + 0x14))++;  // @630910_c
    buf = *(u8 **)(a + 8); buf[*(u32 *)(a + 0x14)] = (u8)(n >> 8); (*(u32 *)(a + 0x14))++;  // @630910_d
    buf = *(u8 **)(a + 8); buf[*(u32 *)(a + 0x14)] = (u8)~n; (*(u32 *)(a + 0x14))++;  // @630910_e
    buf = *(u8 **)(a + 8); buf[*(u32 *)(a + 0x14)] = (u8)(~n >> 8); (*(u32 *)(a + 0x14))++;  // @630910_f
    r = (u32)buf;
  }
  if (n) {
    u8 last = 0;
    do {
      u8 *buf = *(u8 **)(a + 8);
      last = *src++;
      buf[*(u32 *)(a + 0x14)] = last;  // @630910_g
      (*(u32 *)(a + 0x14))++;
    } while (--n);
    r = (r & ~0xffu) | last;
  }
  return r;
}
PCREG(630910, fn630910);

static u32 THISCALL fn4cdd50(u8 *self, u32 a) {
  u8 *esi = (u8 *)(a - 8 + *(u32 *)(self + 0x18) * 4);  // @4cdd50_a
  if (*(u32 *)(self + 0x24) == 0) {  // @4cdd50_b
    u8 *n = (u8 *)ext_41e290(0x1c);  // @4cdd50_c
    if (n) {
      *(u32 *)n = 0x695734;  // @4cdd50_d
      *(u32 *)(n + 0x10) = 8;
      *(u32 *)(n + 0x14) = 0;
      *(u32 *)(n + 0x18) = 1;
      *(u32 *)(n + 0xc) = 8;
      *(u32 *)(n + 4) = 0;
      *(u32 *)(n + 8) = 0;
    }
    *(u32 *)(self + 0x24) = (u32)n;
  }
  vcall<u32, u8 *>(*(u8 **)(self + 0x24), 4, esi);  // @4cdd50_e
  u32 prev = *(u32 *)esi;
  u32 next = *(u32 *)(esi + 4);
  if (prev) *(u32 *)(prev + 4) = next;  // @4cdd50_f
  else *(u32 *)(self + 0x1c) = next;  // @4cdd50_g
  u32 e = *(u32 *)esi;
  if (next) *(u32 *)next = e;  // @4cdd50_h
  else *(u32 *)(self + 0x20) = e;  // @4cdd50_i
  *(u32 *)(esi + 4) = 0;
  *(u32 *)esi = 0;
  *(u32 *)(self + 0xc) |= 0x80000000u;  // @4cdd50_j
  return e;
}
PCREG(4cdd50, fn4cdd50);

static u32 THISCALL fn4d1cf0(u8 *self, int i) {
  if (i < *(int *)(self + 0x10)) return (*(u32 **)(self + 0x14))[i];  // @4d1cf0_a
  u32 arr = *(u32 *)(self + 0x14);
  if (arr) ext_634273(arr, 4);  // @4d1cf0_b
  u32 n = vcall<u32>(self, 0x2c);  // @4d1cf0_c
  *(u32 *)(self + 0x10) = n;
  u64 bytes = (u64)n * 4;
  u32 size = (bytes >> 32) ? 0xffffffffu : (u32)bytes;
  u32 buf = ext_41e290(size);  // @4d1cf0_d
  *(u32 *)(self + 0x14) = buf;
  u32 p = *(u32 *)(self + 0x18);
  u32 off = 0;
  while (p) {
    *(u32 *)(*(u32 *)(self + 0x14) + off) = p;  // @4d1cf0_e
    off += 4;
    p = *(u32 *)(p + 8);  // @4d1cf0_f
  }
  if (i >= *(int *)(self + 0x10)) return 0;  // @4d1cf0_g
  return (*(u32 **)(self + 0x14))[i];
}
PCREG(4d1cf0, fn4d1cf0);
