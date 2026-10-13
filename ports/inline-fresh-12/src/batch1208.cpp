// batch1208.cpp - fresh slice 12, batch 8. Names are FUN_ in the exe list (no map entry). Exe callees run as
// ext_<hex>; the harness hooks and logs them.
#include "ff.h"

extern "C" u32 *THISCALL ext_5003d0(u8 *self, u32 i);   // ret 4

// 0x4f0f80: when the low 24 bits of v differ from +0x18: +0x18 = (byte +0x8e << 24) | v, and every one of the +0x2e
// records (stride 0x28, from (+0x2a)+0x24) is re-sent with engine(+0x1aa3)->+0x18 slot 0x12c(record, this+0x18). ret 4.
static void THISCALL setColor(u8 *self, u32 v) {
  if (!((*(u32 *)(self + 0x18) ^ v) & 0xffffff)) return;
  *(u32 *)(self + 0x18) = ((u32)self[0x8e] << 24) | v;
  if (!*(u32 *)(self + 0x2a)) return;
  for (u32 i = 0; i < *(u32 *)(self + 0x2e); i++) {
    u8 *mgr = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
    vcall<u32>(mgr, 0x12c, *(u8 **)(self + 0x2a) + 0x24 + i * 0x28, self + 0x18);
  }
}
PCREG(4f0f80, setColor);

// 0x50cb40: a, b = engine(+0x9b)->slot 0x58(*0x5003d0(s->+4, 0 / 1)); when both exist and a->slot 0x1e0(0x200073) is
// true: a->slot 0x4e4(b). ret 4.
static void THISCALL linkPair(u8 *, u8 *s) {
  u32 *i0 = ext_5003d0(*(u8 **)(s + 4), 0);
  u8 *a = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, *i0);
  u32 *i1 = ext_5003d0(*(u8 **)(s + 4), 1);
  u8 *b = vcall<u8 *>(*(u8 **)(G(u8 *, 0x70039c) + 0x9b), 0x58, *i1);
  if (!a || !b) return;
  if (!vcall<u8>(a, 0x1e0, 0x200073)) return;
  vcall<u32>(a, 0x4e4, b);
}
PCREG(50cb40, linkPair);

// 0x54ddc0: for each object in the array +0x803d (count +0x805d, signed) with byte +0x7d: slot 0x3c(); then if not
// +0x7a, not +0x79 and +0x7c: slot 0x10(), and when +0x75 == 3 its +0x61 is appended to the list at +0x14 (count
// +0x8014).
static void THISCALL collect(u8 *self) {
  if (!*(u32 *)(self + 0x803d)) return;
  for (s32 i = 0; i < *(s32 *)(self + 0x805d); i++) {
    u8 *o = (*(u8 ***)(self + 0x803d))[i];
    if (!o[0x7d]) continue;
    vcall<u32>(o, 0x3c);
    if (o[0x7a] || o[0x79] || !o[0x7c]) continue;
    vcall<u32>(o, 0x10);
    if (*(u32 *)(o + 0x75) != 3) continue;
    u32 n = *(u32 *)(self + 0x8014);
    *(u32 *)(self + 0x14 + n * 4) = *(u32 *)(o + 0x61);
    (*(u32 *)(self + 0x8014))++;
  }
}
PCREG(54ddc0, collect);

// 0x63b340: allocates a block (slot 0x30), tags it with byte +0x10, builds its free list of slot 0x28() entries
// (stride 0x40 from +0x10, 0xffff at the end), and links it into the ring at +8 (next +8, prev +0xc). Returns false when
// the allocation fails.
static bool THISCALL addBlock(u8 *self) {
  u8 *p = vcall<u8 *>(self, 0x30);
  if (!p) return false;
  p[1] = self[0x10];
  u32 n = vcall<u32>(self, 0x28);
  *(u8 **)(p + 8) = p;
  *(u8 **)(p + 0xc) = p;
  p[0] = 0;
  *(u16 *)(p + 2) = 0;
  u8 *e = p + 0x10;
  u32 last = n - 1;
  for (u32 i = 0; i != last; i++, e += 0x40) *(u16 *)e = (u16)(i + 1);
  *(u16 *)e = 0xffff;
  u8 *h = *(u8 **)(self + 8);
  if (h) {
    *(u8 **)(p + 8) = h;
    u8 *pv = *(u8 **)(h + 0xc);
    *(u8 **)(p + 0xc) = pv;
    *(u8 **)(pv + 8) = p;
    *(u8 **)(h + 0xc) = p;
  }
  *(u8 **)(self + 8) = p;
  return true;
}
PCREG(63b340, addBlock);
