// batch37123.cpp - cascade s6 batch 37123: 0x471680.
#include "ff.h"

extern "C" void THISCALL ext_46abf0(u8 *self, u8 *w);   // ret 4

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void *tabObj() { return *(void **)(*(u8 **)0x70039c + 0x9b); }

// 0x471680, thiscall(), plain ret: lazily creates this object's companion (+0x5a) from its owner O (+0x44). Only when +0x52 is unset and O answers slot 0x1e0 (0x1007d1) and its
// slot 0x2e8 object X exists: X builds the companion W (slot 0x2c4 with the table field +0xadc and 'METI'). W is configured by kind (slot 0x1e0 0x1007d2: 0x364 -> 0x360, or
// 0x1007d8: owner's 0x320 -> 0x324), its table handle goes to +0x52, it is given the owner's handle (slot 0x2f0 with 0 and 1) and mode 1 (0x300), takes the owner's two stack records
// (slot 0x80 / 0x7c with a 0x24 and a 0xc byte block), this object's slot 0x68 is poked with (0x10, 0) and 0x46abf0 registers W with the global at 0x7003b8.
static void THISCALL fn471680(u8 *self) {
  if (D32(self, 0x52)) return;
  u8 *O = *(u8 **)(self + 0x44);
  if (!(u8)vcall<u32>(O, 0x1e0, 0x1007d1u)) return;
  u8 *X = (u8 *)vcall<u32>(*(void **)(self + 0x44), 0x2e8);
  if (!X) return;
  u8 *W = (u8 *)vcall<u32>(X, 0x2c4, D32((u8 *)tabObj(), 0xadc), 0x4954454du);
  D32(self, 0x5a) = (u32)W;
  if (!W) return;
  if ((u8)vcall<u32>(W, 0x1e0, 0x1007d2u)) {
    u8 *s = *(u8 **)(self + 0x5a);
    u32 t = vcall<u32>(s, 0x364);
    vcall<void>(s, 0x360, t);
  } else if ((u8)vcall<u32>(*(void **)(self + 0x5a), 0x1e0, 0x1007d8u)) {
    u32 v = vcall<u32>(*(void **)(self + 0x44), 0x320);
    vcall<void>(*(void **)(self + 0x5a), 0x324, v);
  }
  D32(self, 0x52) = vcall<u32>(tabObj(), 0x4c, D32(self, 0x5a));
  u8 *w2 = *(u8 **)(self + 0x5a);
  u32 h = vcall<u32>(tabObj(), 0x4c, D32(self, 0x44));
  vcall<void>(w2, 0x2f0, h, 0u, 1u);
  vcall<void>(*(void **)(self + 0x5a), 0x300, 1u);
  u32 blk[9];
  u32 vec[3];
  vcall<void>(*(void **)(self + 0x44), 0x80, (u32)blk, (u32)vec);
  vcall<void>(*(void **)(self + 0x5a), 0x7c, (u32)blk, (u32)vec);
  vcall<void>(self, 0x68, 0x10u, 0u);
  ext_46abf0(*(u8 **)0x7003b8, *(u8 **)(self + 0x5a));
}
PCREG(471680, fn471680);
