// batch210029.cpp - Sonnet-w3a: small BLOCKED rows (field reads, tree search, serializer chain, stack-buffer iterators)
#include "ff.h"

extern "C" u32 THISCALL ext_43f900(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_4e11e0(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_4e12e0(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_4e1600(u8 *self);
extern "C" u32 THISCALL ext_4e1b30(u8 *self);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn46cee0(u8 *self, u8 *a) {
  ext_43f900(self, a);  // @46cee0_a
  ext_4e11e0(a, self + 0x5c, 1);  // @46cee0_b
  ext_4e11e0(a, self + 0x60, 1);
  ext_4e12e0(a, self + 0x64, 1);  // @46cee0_c
  ext_4e12e0(a, self + 0x68, 1);
  ext_4e12e0(a, self + 0x6c, 1);  // @46cee0_d
  if ((u8)ext_4e1600(a) == 0xb) ext_4e12e0(a, self + 0x78, 1);  // @46cee0_e
  return ext_4e1b30(a);  // @46cee0_f
}
PCREG(46cee0, fn46cee0);

static u32 THISCALL fn4daff0(u8 *self) {
  u8 *s = *(u8 **)(self + 0x54);
  u32 key = s ? ld32(*(u8 **)(s + 0xc) + 0x23) : 0x200002;  // @4daff0_a
  if (!(key & 0x100000)) {  // @4daff0_b
    s = *(u8 **)(self + 0x50);
    if (!s) return 0;
    s = *(u8 **)(s + 0x54);
  }
  while (s) {
    if (vcall<u32, u32>(s, 0x1e0, 0x100020) & 0xff) {  // @4daff0_c
      if (vcall<u32>(s, 0x30c) & 0xff) return (u32)s;  // @4daff0_d
      if (vcall<u32>(s, 0x310) & 0xff) return 0;  // @4daff0_e
    }
    s = (u8 *)vcall<u32>(s, 0x20);  // @4daff0_f
  }
  return 0;
}
PCREG(4daff0, fn4daff0);

static u32 THISCALL fn5626d0(u8 *self, u8 *a) {
  u32 loc1 = (u32)a;
  u32 loc2;
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5626d0_a
  u8 *r = (u8 *)vcall<u32, u8 *>(a, 0x40, self + 0x48);  // @5626d0_b
  r = (u8 *)vcall<u32, u8 *>(r, 0x50, self + 0x64);  // @5626d0_c
  r = (u8 *)vcall<u32, u8 *>(r, 0x68, self + 0x84);  // @5626d0_d
  r = (u8 *)vcall<u32, u8 *>(r, 0x68, self + 0x85);  // @5626d0_e
  vcall<u32, u32 *>(a, 0x48, &loc1);  // @5626d0_f
  *(u32 *)(self + 0xf0) = loc1;  // @5626d0_g
  vcall<u32, u32 *>(a, 0x48, &loc2);  // @5626d0_h
  *(u32 *)(self + 0xdc) = loc2;  // @5626d0_i
  return (loc2 & ~0xffu) | 1;
}
PCREG(5626d0, fn5626d0);

static void walk_list(u8 *self, u8 *a, u32 wordAddr, bool setTo) {
  u32 buf[3];
  u8 *m = *(u8 **)(a + 0x10);
  if (m) {
    vcall<u32, u32 *>(m, 0x4c, buf);  // @5c7980_a
    u8 *b = (u8 *)vcall<u32, u32 *>(*(u8 **)(a + 0x10), 0x5c, buf);  // @5c7980_b
    while (buf[0] != 0) {  // @5c7980_c
      u8 *ent = *(u8 **)(self + 0x44);
      u32 w = *(u16 *)wordAddr;
      vcall<u32, u8 *, u32, u32>(ent, 0x12c, b, w, 0);  // @5c7980_d
      b = (u8 *)vcall<u32, u32 *>(*(u8 **)(a + 0x10), 0x5c, buf);
    }
  }
  a[0x2c] = setTo;  // @5c7980_e
}

static void THISCALL fn5c7980(u8 *self, u8 *a) {
  if (a[0x2c] == 0) walk_list(self, a, 0x71434c, true);  // @5c7980_f
}
PCREG(5c7980, fn5c7980);

static void THISCALL fn5c7a40(u8 *self, u8 *a) {
  if (a[0x2c] != 0) walk_list(self, a, 0x714348, false);  // @5c7a40_f
}
PCREG(5c7a40, fn5c7a40);
