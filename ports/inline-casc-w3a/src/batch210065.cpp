// batch210065.cpp - Sonnet-w3a: 0x5c56f0 (read two bounded strings and five fields from a stream reader)
#include "ff.h"

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

extern "C" u8 *THISCALL ext_4e5ea0(u8 *s);
extern "C" u32 THISCALL ext_4e5e40(u8 *s);
extern "C" u32 THISCALL ext_4e5e60(u8 *s);

static u32 slen(const u8 *p) { u32 n = 0; while (p[n]) n++; return n; }

static void THISCALL fn5c56f0(u8 *self, u8 *s) {
  u8 *a = ext_4e5ea0(s);  // @5c56f0_a
  u8 *b = ext_4e5ea0(s);  // @5c56f0_b
  typedef u32 (*F)(u8 *, u32, u32);
  if (slen(a) < 0x80) {  // @5c56f0_c
    u32 i = 0;
    do { self[0x48 + i] = a[i]; } while (a[i++]);  // @5c56f0_d
  } else {
    u8 *r = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x6b4204, 0x40);  // @5c56f0_e
    (*(F *)(*(u8 **)r + 0x2c))(r, 0x6b4240, (u32)a);  // @5c56f0_f
  }
  if (slen(b) < 0x80) {  // @5c56f0_g
    u32 i = 0;
    do { self[0xc8 + i] = b[i]; } while (b[i++]);  // @5c56f0_h
  } else {
    u8 *r = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x6b4204, 0x43);  // @5c56f0_i
    (*(F *)(*(u8 **)r + 0x2c))(r, 0x6b4240, (u32)b);  // @5c56f0_j
  }
  *(u16 *)(self + 0x148) = (u16)ext_4e5e40(s);  // @5c56f0_k
  *(u16 *)(self + 0x14a) = (u16)ext_4e5e40(s);  // @5c56f0_l
  st32(self + 0x14e, ext_4e5e60(s));  // @5c56f0_m
  *(u16 *)(self + 0x14c) = (u16)ext_4e5e40(s);  // @5c56f0_n
  self[0x152] = ext_4e5e60(s) != 0;  // @5c56f0_o
}
PCREG(5c56f0, fn5c56f0);
