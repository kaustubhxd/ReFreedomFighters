// batch210078.cpp - Sonnet-w3a: 0x5d8340 (read a name and two fields from a reader, copy the name through the import at 0x67642c)
#include "ff.h"

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

extern "C" u8 *THISCALL ext_4e5ea0(u8 *s);
extern "C" u32 THISCALL ext_4e5e60(u8 *s);

typedef u32 (*StrN)(u8 *dst, const u8 *src, u32 n);
typedef u32 (*H)();

static void THISCALL fn5d8340(u8 *self, u8 *s) {
  u8 *str = ext_4e5ea0(s);  // @5d8340_a
  u32 len = 0;
  while (str[len]) len++;
  if (len > 0x63) {  // @5d8340_b
    H h = G(H, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  G(StrN, 0x67642c)(self + 0x4e, str, 0x63);  // @5d8340_c
  self[0xb1] = 0;  // @5d8340_d
  self[0xb2] = ext_4e5e60(s) != 0;  // @5d8340_e
  u8 b = **(u8 **)s;
  if (b != 0xff && (b & 0x3f) != 0xff) {  // @5d8340_f
    u32 v = ext_4e5e60(s);  // @5d8340_g
    u8 *mgr = (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b);
    *(u32 *)(self + 0xbc) = vcall<u32, u32>(mgr, 0x58, v);  // @5d8340_h
  }
}
PCREG(5d8340, fn5d8340);
