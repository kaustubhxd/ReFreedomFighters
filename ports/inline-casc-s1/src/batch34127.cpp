// batch34127.cpp - cascade tier E, batch 34127: 0x45be60 (find a slot by kind), 0x54dff0 (copy a record into a widget), 0x5f0380 (query two engine values and apply them).
#include "ff.h"

extern "C" u32 THISCALL ext_5f0e10(void *self, u32 a);   // thiscall ret 4

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x45be60, thiscall(want) ret 4: the first index i < [this+0x20] (unsigned, re-read) whose entry e = [[this+0x254]+4i] is set and resolves, through the engine object o = unaligned [[0x70039c]+0x1aa3]
// (o->[+0x18]->slot0xe4(e, 0x678d04), then o->slot0x80), to a record whose byte +2 equals want; 0 when none (also for index 0).
static u32 THISCALL fn45be60(u8 *self, u32 want) {
  u32 n = *(u32 *)(self + 0x20);
  if (n == 0) return 0;
  u32 i = 0;
  do {
    u32 e = (*(u32 **)(self + 0x254))[i];
    if (e) {
      u8 *o = (u8 *)rd32(G(u8 *, 0x70039c) + 0x1aa3);
      u8 *sub = *(u8 **)(o + 0x18);
      u32 x = vcall<u32>(sub, 0xe4, e, 0x678d04u);
      if (x) {
        o = (u8 *)rd32(G(u8 *, 0x70039c) + 0x1aa3);
        u8 *y = vcall<u8 *>(o, 0x80, x);
        if (y && y[2] == want) return i;
      }
    }
    i++;
  } while (i < *(u32 *)(self + 0x20));
  return 0;
}
PCREG(45be60, fn45be60);

// 0x54dff0, thiscall(p) ret 4: copies [p+0x10] -> unaligned +0x2d, [p+0x14] -> +0x35, flag (p[0x18] != 0) -> byte +0x7b and into byte +0x57 of the object at unaligned [this+0x29] (twice, the second after copying [p+0x1c] -> +0x61);
// kinds other than 3 and 4 also copy [p+0x2c, 0x30, 0x34, 0x3c, 0x40, 0x38, 0x28] -> +0x41, +0x45, +0x49, +0x55, +0x59, +0x4d, +0x51; then when byte +0x79 is set it is cleared and this->slot0x58() runs.
static void THISCALL fn54dff0(u8 *self, u8 *p) {
  u8 *o = (u8 *)rd32(self + 0x29);
  wr32(self + 0x2d, *(u32 *)(p + 0x10));
  wr32(self + 0x35, *(u32 *)(p + 0x14));
  u8 flag = *(u32 *)(p + 0x18) != 0;
  self[0x7b] = flag;
  if (o) o[0x57] = flag;
  o = (u8 *)rd32(self + 0x29);
  wr32(self + 0x61, *(u32 *)(p + 0x1c));
  if (o) o[0x57] = self[0x7b];
  u32 kind = *(u32 *)(self + 0x18);
  if (kind != 4 && kind != 3) {
    wr32(self + 0x41, *(u32 *)(p + 0x2c));
    wr32(self + 0x45, *(u32 *)(p + 0x30));
    wr32(self + 0x49, *(u32 *)(p + 0x34));
    wr32(self + 0x55, *(u32 *)(p + 0x3c));
    wr32(self + 0x59, *(u32 *)(p + 0x40));
    wr32(self + 0x4d, *(u32 *)(p + 0x38));
    wr32(self + 0x51, *(u32 *)(p + 0x28));
  }
  if (self[0x79]) {
    self[0x79] = 0;
    vcall<void>(self, 0x58);
  }
}
PCREG(54dff0, fn54dff0);

// 0x5f0380, thiscall plain: t = [[0x70039c]+0x9b]; x = t->slot0x138(); x->slot0x88(0x6a5c48, &l4) (l4 pre-set to 0); w = t->slot0x114(0x6add1c, 0, 0x6b8240, 0x1b, &l8) (l8 pre-set to 0);
// [this+4]->slot0x12c(l4, (u16) w) using the vtable read before the second call; when l8 is non-zero ext_5f0e10(l8, [[this+4]+0x684]).
static void THISCALL fn5f0380(u8 *self) {
  u32 l4 = 0, l8 = 0;
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = vcall<u8 *>(t, 0x138);
  l4 = 0;
  vcall<void>(x, 0x88, 0x6a5c48u, (u32)&l4);
  u8 *vt = **(u8 ***)(self + 4);
  u32 v4 = *(volatile u32 *)&l4;
  t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 w = (u16)vcall<u32>(t, 0x114, 0x6add1c, 0u, 0x6b8240u, 0x1bu, (u32)&l8);
  typedef void (THISCALL *f2)(void *, u32, u32);
  (*(f2 *)(vt + 0x12c))(*(u8 **)(self + 4), v4, w);
  u32 h = *(volatile u32 *)&l8;
  if (h) ext_5f0e10((void *)h, *(u32 *)(*(u8 **)(self + 4) + 0x684));
}
PCREG(5f0380, fn5f0380);
