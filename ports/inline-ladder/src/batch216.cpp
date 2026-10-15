// batch216.cpp - hero action bodies (inline-ladder thread, 2026-10-11): ZFFActionGetBack and ZFFActionPutBack
// (take the item off the back / put it on the back). Fields (both): +8 hero, +0xc hand, +0x10 animation.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void *THISCALL ext_591f00(void *hero);                  // ZFFHERO::GetItemBack() const
extern "C" u32 THISCALL ext_591080(void *hero);                    // ZFFHERO::DetachItemBack()
extern "C" void THISCALL ext_58bc60(void *hero, void *item);       // ZFFHERO::AttachItemBack(ZItem*)
extern "C" u32 THISCALL ext_4614d0(void *boneAnim, float t, u32 fn, u32 data);   // ZBoneAnim::AddCallBack
struct Quad { u32 a, b, c, d; };
extern "C" void THISCALL ext_467410(void *handPart, u32 hero, u32 zero, Quad q);  // no GC name; ret 0x18

static inline u32 dbRef(void *g) { return vcall<u32>((void *)U32(G(u32, 0x70039c), 0x9b), 0x4c, g); }   // GeomToRef

// Play the action's animation (when set) through hero slot 0x230(anim, 1) and hang the action callback 0x465710 on it
// at t = 0.016 (0x3c83126f); true. Without an animation the action's own CallBack (slot 0xc) runs at once (tail call).
static u32 playOrCallBack(u8 *self) {
  u32 anim = U32(self, 0x10);
  if (anim) {
    void *ba = vcall<void *>((void *)U32(self, 8), 0x230, anim, 1u);
    ext_4614d0(ba, bitsf(0x3c83126f), 0x465710, 0);
    return 1;
  }
  return vcall<u32>(self, 0xc);
}

// 0x5e02e0 ZFFActionGetBack::Execute() [GameCube reference, medium; slot 2], AL: touches the back item (its slot 0x2e8), then
// plays the animation (or calls back at once).
static u32 THISCALL getBackExecute(u8 *self) {
  void *item = ext_591f00((void *)U32(self, 8));
  vcall<u32>(item, 0x2e8);
  return playOrCallBack(self);
}
PCREG(5e02e0, getBackExecute);

// 0x5df970 ZFFActionGetBack::CallBack() [GameCube reference, medium; slot 3], AL = 0: 0x467410 on hand+4 (hero, 0,
// {0, 0, 0, -1} by value), DetachItemBack, then hand slot 8(hero, ref(item)) puts the item in the hand.
static bool THISCALL getBackCallBack(u8 *self) {
  Quad q = {0, 0, 0, 0xffffffffu};
  ext_467410((u8 *)U32(self, 0xc) + 4, U32(self, 8), 0, q);
  u32 it = ext_591080((void *)U32(self, 8));
  u32 ref = vcall<u32>((void *)U32(G(u32, 0x70039c), 0x9b), 0x4c, it);
  vcall<void>((void *)U32(self, 0xc), 8, U32(self, 8), ref);
  return false;
}
PCREG(5df970, getBackCallBack);

// 0x5e03c0 ZFFActionPutBack::Execute() [GameCube reference, medium; slot 2], AL: the hand's item (hand slot 0x10), its slot
// 0x2e8, then as GetBack.
static u32 THISCALL putBackExecute(u8 *self) {
  void *item = vcall<void *>((void *)U32(self, 0xc), 0x10);
  vcall<u32>(item, 0x2e8);
  return playOrCallBack(self);
}
PCREG(5e03c0, putBackExecute);

// 0x5df9f0 ZFFActionPutBack::CallBack() [GameCube reference, medium; slot 3], AL = 0: item = hand slot 0x10; GeomToRef(item)
// (result unused); 0x467410 on hand+4 as in GetBack; hand slot 8(hero, 0) empties the hand. If the hero already has
// an item on the back, item slot 0x2d0(1, 0) (drops it, inference), else AttachItemBack(item).
static bool THISCALL putBackCallBack(u8 *self) {
  void *item = vcall<void *>((void *)U32(self, 0xc), 0x10);
  dbRef(item);
  Quad q = {0, 0, 0, 0xffffffffu};
  ext_467410((u8 *)U32(self, 0xc) + 4, U32(self, 8), 0, q);
  vcall<void>((void *)U32(self, 0xc), 8, U32(self, 8), 0u);
  if (ext_591f00((void *)U32(self, 8)))
    vcall<void>(item, 0x2d0, 1u, 0u);
  else
    ext_58bc60((void *)U32(self, 8), item);
  return false;
}
PCREG(5df9f0, putBackCallBack);
