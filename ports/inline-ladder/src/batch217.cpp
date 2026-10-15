// batch217.cpp - hero action bodies (inline-ladder thread, 2026-10-11): ZFFActionDropC4::CallBack.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

struct Quad217 { u32 a, b, c, d; };
extern "C" void THISCALL ext_467410(void *handPart, u32 hero, u32 zero, Quad217 q);   // no GC name; ret 0x18

static inline void *db217() { return (void *)U32(G(u32, 0x70039c), 0x9b); }

// 0x5df8b0 ZFFActionDropC4::CallBack() [GameCube reference, medium; slot 3], AL = 0. +8 hero, +0xc hand. The C4 is the hand's
// item (hand slot 0x10); GeomToRef(item) (unused); 0x467410 on hand+4 (hero, 0, {0,0,0,-1}); hand slot 8(hero, 0)
// empties the hand; item slot 0x2d0(3, 0) (drop mode 3, inference: "placed"); hero slot 0x4f4(item); then item slot
// 0x2f0(GeomToRef(hero), 0, 1) (the owner is set to the hero; item vtable read before the database call).
static bool THISCALL dropC4CallBack(u8 *self) {
  u8 **item = vcall<u8 **>((void *)U32(self, 0xc), 0x10);
  vcall<u32>(db217(), 0x4c, item);
  Quad217 q = {0, 0, 0, 0xffffffffu};
  ext_467410((u8 *)U32(self, 0xc) + 4, U32(self, 8), 0, q);
  vcall<void>((void *)U32(self, 0xc), 8, U32(self, 8), 0u);
  vcall<void>(item, 0x2d0, 3u, 0u);
  vcall<void>((void *)U32(self, 8), 0x4f4, item);
  u8 *vt = *item;
  u32 ref = vcall<u32>(db217(), 0x4c, U32(self, 8));
  typedef void(THISCALL * fn)(void *, u32, u32, u32);
  (*(fn *)(vt + 0x2f0))(item, ref, 0u, 1u);
  return false;
}
PCREG(5df8b0, dropC4CallBack);
