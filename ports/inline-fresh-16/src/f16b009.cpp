// f16b009.cpp - fresh slice 16, batch 9 (2026-10-12).
// 0x4f6600 ZTTFONT::Load(lg): ZWINOBJ::Load 0x4f05d0 false -> return it; lg slot 0x40(&slot) (ZLoadGame vtable 0x68e9cc, ret 4;
//           slot = the argument's stack word); +0x93 = v; r = [[0x70039c]+0x1aa3]+0x18 slot 0xc(v); +0x97 = 0, then
//           +0x97 = h = r + [r+4]; +0x9b = h+0x18; +0x9f = h+0x18 + [h+8]*20. Returns true. Ret 4.
// 0x639d00 (str): +0x28 -> __builtin_delete([+0x18], 1), +0x18 = 0, +0x28 = 0; str -> +0x18 = __builtin_new 0x41e290(len+1)
//           with str copied, +0x28 = 1; null str -> +0x18 = 0x677b5a (a constant empty string). Ret 4.
// 0x63b240: e = this slot 0x30(); none -> false. e+1 = byte +0x10; n = this slot 0x28(); e is an empty ring (e+8 = e+0xc = e),
//           e[0] = 0, u16 e+2 = 0; free list of n 16-byte entries from e+0x10 (u16 next index, last 0xffff); e is linked
//           before the ring head +8 (if any) and becomes the head. Returns true. (n == 0 would run 2^32 times; not generated.)
// 0x603c00 (pn): 0x5f55e0(this); 0x41e2c0([this]) (cdecl); +8 = 0; n = *pn; +4 = n; p = __builtin_new(n*8, or -1 on
//           overflow); p -> n entries {dword 0, byte 0} and [this] = p; else [this] = 0. Ret 4.
// 0x485a40: o = [[0x70039c]+0x9b]+8 slot 0x44(ECX as passed); o -> ctor 0x469870(o), o+4 |= 0x20, o+0x44 = 0, vtable 0x68c774.
//           Returns o. SEH not reproduced (same shape as 0x5bf780).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_4f05d0[], ext_634273[], ext_41e290[], ext_5f55e0[], ext_41e2c0[], ext_469870[];

extern "C" u32 THISCALL f16_4f6600(u8 *self, void *lg) {
  u32 ok = ((u32(THISCALL *)(void *, void *))(void *)ext_4f05d0)(self, lg);
  if (!(u8)ok) return ok;
  u32 slot = (u32)lg;
  vcall<void>(lg, 0x40, &slot);
  AT(u32, self, 0x93) = slot;
  u8 *r = vcall<u8 *>(AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x1aa3), 0x18), 0xc, slot);
  AT(u32, self, 0x97) = 0;
  u8 *h = r + AT(u32, r, 4);
  AT(u8 *, self, 0x97) = h;
  AT(u8 *, self, 0x9b) = h + 0x18;
  AT(u8 *, self, 0x9f) = h + 0x18 + AT(u32, h, 8) * 20;
  return (ok & 0xffffff00u) | 1;
}

extern "C" void THISCALL f16_639d00(u8 *self, const char *s) {
  if (AT(u8, self, 0x28)) {
    ((void (*)(void *, u32))(void *)ext_634273)(AT(void *, self, 0x18), 1);
    AT(u32, self, 0x18) = 0;
    AT(u8, self, 0x28) = 0;
  }
  if (!s) {
    AT(u32, self, 0x18) = 0x677b5au;
    return;
  }
  u32 n = 0;
  while (s[n]) n++;
  char *d = ((char *(*)(u32))(void *)ext_41e290)(n + 1);
  AT(char *, self, 0x18) = d;
  char c;
  do {
    c = *s++;
    *d++ = c;
  } while (c);
  AT(u8, self, 0x28) = 1;
}

extern "C" bool THISCALL f16_63b240(u8 *self) {
  u8 *e = vcall<u8 *>(self, 0x30);
  if (!e) return false;
  AT(u8, e, 1) = AT(u8, self, 0x10);
  u32 n = vcall<u32>(self, 0x28);
  AT(u8 *, e, 8) = e;
  AT(u8 *, e, 0xc) = e;
  AT(u8, e, 0) = 0;
  AT(u16, e, 2) = 0;
  u8 *d = e + 0x10;
  for (u32 i = 0; i != n - 1; ++i, d += 0x10) AT(u16, d, 0) = (u16)(i + 1);
  AT(u16, d, 0) = 0xffff;
  u8 *l = AT(u8 *, self, 8);
  if (l) {
    AT(u8 *, e, 8) = l;
    u8 *t = AT(u8 *, l, 0xc);
    AT(u8 *, e, 0xc) = t;
    AT(u8 *, t, 8) = e;
    AT(u8 *, l, 0xc) = e;
  }
  AT(u8 *, self, 8) = e;
  return true;
}

extern "C" void THISCALL f16_603c00(u32 *self, u32 *pn) {
  ((void(THISCALL *)(void *))(void *)ext_5f55e0)(self);
  ((void (*)(u32))(void *)ext_41e2c0)(self[0]);
  self[2] = 0;
  u32 n = *pn;
  self[1] = n;
  u64 sz = (u64)n * 8;
  u8 *p = ((u8 * (*)(u32))(void *)ext_41e290)((sz >> 32) ? 0xffffffffu : (u32)sz);
  if (!p) {
    self[0] = 0;
    return;
  }
  for (u8 *q = p; n; --n, q += 8) {
    AT(u32, q, 0) = 0;
    AT(u8, q, 4) = 0;
  }
  self[0] = (u32)p;
}

extern "C" void *THISCALL f16_485a40(void *self) {
  void *a = AT(void *, AT(u8 *, G(u8 *, 0x70039c), 0x9b), 8);
  u8 *o = vcall<u8 *>(a, 0x44, self);
  if (o) {
    ((void(THISCALL *)(void *))(void *)ext_469870)(o);
    AT(u32, o, 4) |= 0x20;
    AT(u32, o, 0x44) = 0;
    AT(u32, o, 0) = 0x68c774u;
  }
  return o;
}

PCREG(4f6600, f16_4f6600);
PCREG(639d00, f16_639d00);
PCREG(63b240, f16_63b240);
PCREG(603c00, f16_603c00);
PCREG(485a40, f16_485a40);
