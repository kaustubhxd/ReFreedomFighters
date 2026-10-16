// batch210040.cpp - Sonnet-w3a: small BLOCKED rows (string-keyed table add, read-and-report chain, selector with callbacks)
#include "ff.h"

extern "C" u32 THISCALL ext_4e12e0(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_4e1600(u8 *self);
extern "C" u32 THISCALL ext_4e1b30(u8 *self);
extern "C" u32 STDCALL ext_512850(u8 *a);

static bool same_str(const u8 *s, const u8 *t) {
  for (u32 i = 0;; i++) {
    if (s[i] != t[i]) return false;
    if (s[i] == 0) return true;
  }
}

static u32 THISCALL fn5c2e10(u8 *self, const u8 *s) {
  if (!s) return 0;  // @5c2e10_a
  int n = *(int *)(self + 0x2c4);
  for (int i = 0; i < n; i++) {  // @5c2e10_b
    u8 *entry = self + 0xf8 + i * 0x4c;
    if (same_str(s, *(const u8 **)entry)) return (u32)entry;  // @5c2e10_c
  }
  if (n >= 6) return 0;  // @5c2e10_d
  *(const u8 **)(self + 0xf8 + n * 0x4c) = s;  // @5c2e10_e
  (*(u32 *)(self + 0x2c4))++;  // @5c2e10_f
  return (u32)self + *(u32 *)(self + 0x2c4) * 0x4c + 0xac;  // @5c2e10_g
}
PCREG(5c2e10, fn5c2e10);

static void report(u32 line, u32 msg, u8 *self) {
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69f8b8, line);
  u32 name = *(u32 *)(self + 4);
  if (!name) name = 0x67c8e8;
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, msg, name);
}

static u32 THISCALL fn51c210(u8 *self, u8 *a) {
  ext_512850(a);  // @51c210_a
  ext_4e12e0(a, self + 0x44d, 1);  // @51c210_b
  if (*(u32 *)(self + 0x44d) == 0) report(0x102, 0x69f8f4, self);  // @51c210_c
  if ((u8)ext_4e1600(a) == 8) {  // @51c210_d
    ext_4e12e0(a, self + 0x451, 1);  // @51c210_e
    if (*(u32 *)(self + 0x451) == 0) report(0x105, 0x69f90c, self);  // @51c210_f
  } else {
    *(u32 *)(self + 0x451) = 0;  // @51c210_g
  }
  return ext_4e1b30(a);  // @51c210_h
}
PCREG(51c210, fn51c210);

static u32 fn62d840(u8 *A, u32 sel, u32 p10, u32 p14, u8 *obj) {
  if (sel == 0xf) return 0;  // @62d840_a
  typedef u32 (*CB)(u8 *, u32, u32, u32);
  if (sel == 0x12) {  // @62d840_b
    if ((*(CB *)(obj + 0x1c))(obj, p10, p14, 0x6c0208)) {  // @62d840_c
      *(u32 *)A = 0x62d940;  // @62d840_d
      return 0;
    }
    if ((*(CB *)(obj + 0x1c))(obj, p10, p14, 0x6c01f4)) {  // @62d840_e
      *(u32 *)A = 0x62d8f0;  // @62d840_f
      return 0;
    }
  } else if (sel == 0x1b) {  // @62d840_g
    *(u32 *)A = 0x62cf90;  // @62d840_h
    return sel - 0x11;  // @62d840_i
  }
  if (*(u32 *)(A + 0xc) == 0 && sel == 0x1c) return sel + 0x18;  // @62d840_j
  *(u32 *)A = 0x51f230;  // @62d840_k
  return 0xffffffffu;
}
PCREG(62d840, fn62d840);
