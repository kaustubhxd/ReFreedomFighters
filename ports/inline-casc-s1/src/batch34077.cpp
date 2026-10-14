// batch34077.cpp - cascade tier E, batch 34077: 0x5b7090 (find, commit and release an entry), 0x5be690 (find or add a key in a 5-byte-entry table), 0x60cea0 (reset a device state through COM-style calls).
#include "ff.h"

extern "C" void THISCALL ext_609a70(void *m);   // thiscall, plain ret (fills a 16-dword matrix)
extern "C" void FASTCALL ext_633654(u32 cookie);   // /GS check

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x5b7090, thiscall(a, b) ret 8: e = [this+0x48]->slot0x2c(a); null: return 0. m = [e+4]; when m->slot0x2c(b) is zero return 0; m->slot0x3c(b); r = m->slot0x14(); when r is non-zero return r. Else delete (slot 0 with 1) [e+4]
// and [e+8] when they are non-null, and return [this+0x48]->slot0x3c(a).
static u32 THISCALL fn5b7090(u8 *self, u32 a, u32 b) {
  u8 *e = vcall<u8 *>(*(u8 **)(self + 0x48), 0x2c, a);
  if (!e) return 0;
  if (vcall<u32>(*(u8 **)(e + 4), 0x2c, b) == 0) return 0;
  vcall<void>(*(u8 **)(e + 4), 0x3c, b);
  u32 r = vcall<u32>(*(u8 **)(e + 4), 0x14);
  if (r != 0) return r;
  if (*(u8 **)(e + 4)) vcall<void>(*(u8 **)(e + 4), 0, 1u);
  if (*(u8 **)(e + 8)) vcall<void>(*(u8 **)(e + 8), 0, 1u);
  return vcall<u32>(*(u8 **)(self + 0x48), 0x3c, a);
}
PCREG(5b7090, fn5b7090);

// 0x5be690, thiscall(a) ret 4: table of 5-byte entries (dword key, byte tag) at this+0x718, count [this+0x910] (signed), limit unaligned dword [this+0x992]. Returns the index of key a when present. Otherwise
// when count < limit: appends {a, tag 0xff}, count++, unaligned dword [this+0x91e]++, returns the old count. Else sets the tag byte of the slot at the count to 0xff, calls
// engine table object (slot 0x58 of [[0x70039c]+0x9b]) (a)->slot0x20()->slot0x28() and returns the count.
static u32 THISCALL fn5be690(u8 *self, u32 a) {
  s32 n = (s32)*(u32 *)(self + 0x910);
  s32 i;
  for (i = 0; i < n; i++)
    if (rd32(self + 0x718 + 5 * i) == a) return i;
  if (n < (s32)rd32(self + 0x992)) {
    *(u32 *)(self + 0x910) = n + 1;
    wr32(self + 0x718 + 5 * n, a);
    self[0x71c + 5 * n] = 0xff;
    wr32(self + 0x91e, rd32(self + 0x91e) + 1);
    return n;
  }
  self[0x71c + 5 * n] = 0xff;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = vcall<u8 *>(tbl, 0x58, a);
  u8 *o2 = vcall<u8 *>(o, 0x20);
  vcall<void>(o2, 0x28);
  return n;
}
PCREG(5be690, fn5be690);

typedef u32(STDCALL *com3)(u8 *, u32, u32);
typedef u32(STDCALL *com1)(u8 *);
#define COM(o, off) (*(u8 **)(*(u8 **)(o) + (off)))

// 0x60cea0, thiscall, plain ret: when byte [0x724b34] is zero: o = unaligned pointer [this+0x1377]; byte [this+0x1e] = 0; stdcall slot 0x7c(o, [this+0x1416], [this+0x141a]); a 16-dword matrix M from 0x609a70;
// stdcall slot 0x94(o, 2, &M); slot 0xc8(o, 7, 1); then Release-style slot 8 of the objects [this+0x1416] and [this+0x141a]. The /GS check.
static void THISCALL fn60cea0(u8 *self) {
  u32 M[16];
  if (G(u8, 0x724b34) == 0) {
    u8 *o = (u8 *)rd32(self + 0x1377);
    u32 p1 = rd32(self + 0x1416), p2 = rd32(self + 0x141a);
    self[0x1e] = 0;
    ((com3)COM(o, 0x7c))(o, p1, p2);
    ext_609a70(M);
    o = (u8 *)rd32(self + 0x1377);
    ((com3)COM(o, 0x94))(o, 2, (u32)M);
    o = (u8 *)rd32(self + 0x1377);
    ((com3)COM(o, 0xc8))(o, 7, 1);
    u8 *q = (u8 *)rd32(self + 0x1416);
    ((com1)COM(q, 8))(q);
    q = (u8 *)rd32(self + 0x141a);
    ((com1)COM(q, 8))(q);
  }
  ext_633654(0);
}
PCREG(60cea0, fn60cea0);
