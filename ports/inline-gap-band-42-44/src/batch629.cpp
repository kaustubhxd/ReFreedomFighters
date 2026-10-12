// batch629.cpp - band 0x421000-0x441000, batch 629: four functions (all callees are virtual slots on fake objects in the spec).
//   0x431fb0 CConfiguration::ApplySound() (thiscall): o = [[0x70039c]+0x1a9f]; if o: slot 0x104 of o with (0, [this+0xe8], 2),
//     (1, [this+0xec], 2), (2, [this+0xf0], 2), (3, [this+0xf4], 2): kind, value, flags.
//   0x4265e0 (thiscall, three args a, b, c; ret 0xc): e = slot 0xc of this with a; if e is 0 return 0; else slot 0x38 of this
//     with (e, b, c), then slot 0x1c of this with e (its result is returned).
//   0x423fb0 (thiscall, three args a, b, c; ret 0xc): for each node of the list at [this+0x190f] (next at +8): o = slot 0x108 of
//     node (ecx = node); slot 0 of o with (a, b, c).
//   0x424460 (same, slot 4 of o instead of slot 0).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])
typedef u32(THISCALL *vOne)(void *self, u32 a);
typedef u32(THISCALL *vTwo)(void *self, u32 a, u32 b);
typedef u32(THISCALL *vThree)(void *self, u32 a, u32 b, u32 c);
typedef u32(THISCALL *vNone)(void *self);

static void THISCALL applySound(u8 *self) {
  u8 *o = *(u8 **)(G(u8 *, 0x70039c) + 0x1a9f);
  if (!o)
    return;
  ((vThree)VT(o, 0x104))(o, 0u, *(u32 *)(self + 0xe8), 2u);
  ((vThree)VT(o, 0x104))(o, 1u, *(u32 *)(self + 0xec), 2u);
  ((vThree)VT(o, 0x104))(o, 2u, *(u32 *)(self + 0xf0), 2u);
  ((vThree)VT(o, 0x104))(o, 3u, *(u32 *)(self + 0xf4), 2u);
}
PCREG(431fb0, applySound);

static u32 THISCALL slot0cThen38Then1c(u8 *self, u32 a, u32 b, u32 c) {
  u32 e = ((vOne)VT(self, 0xc))(self, a);
  if (!e)
    return 0;                                   // the exe jumps to the epilogue here: no slot 0x1c call
  ((vThree)VT(self, 0x38))(self, e, b, c);
  return ((vOne)VT(self, 0x1c))(self, e);
}
PCREG(4265e0, slot0cThen38Then1c);

static void THISCALL walkListSlot0(u8 *self, u32 a, u32 b, u32 c) {
  u8 *node = *(u8 **)(self + 0x190f);
  while (node) {
    u8 *o = (u8 *)((vNone)VT(node, 0x108))(node);
    ((vThree)VT(o, 0))(o, a, b, c);
    node = *(u8 **)(node + 8);
  }
}
PCREG(423fb0, walkListSlot0);

static void THISCALL walkListSlot4(u8 *self, u32 a, u32 b, u32 c) {
  u8 *node = *(u8 **)(self + 0x190f);
  while (node) {
    u8 *o = (u8 *)((vNone)VT(node, 0x108))(node);
    ((vThree)VT(o, 4))(o, a, b, c);
    node = *(u8 **)(node + 8);
  }
}
PCREG(424460, walkListSlot4);
