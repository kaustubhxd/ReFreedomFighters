// batch246.cpp - ZFFHERO::OperateObject(CAction *a) (inline-ladder thread, 2026-10-11). One port for all five step groups;
// verified per group in the spec (steps 0, 1, 2, 3 and the default). Hand/item objects are the fake kit in harness/ops_kit.py.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define U16(p, off) (*(u16 *)((u8 *)(p) + (off)))

extern "C" void *THISCALL ext_41e680(void *self);   // ConvPtr (batch 74, original code; takes the pointer in ECX)

static inline u8 *g2() { return (u8 *)G(u32, 0x70038c); }   // the global object pointer stored at 0x70038c

// Item-class test: vtable slot 0x1e0 with the class id 0x1007d1 (the same test the hand code uses).
static inline bool isItem(u32 obj) { return (u8)vcall<u32>((void *)obj, 0x1e0, 0x1007d1u) != 0; }

// 0x593af0 ZFFHERO::OperateObject(CAction *a) [GC 80078d5c, high], thiscall (this = the hero), ret 4.
// step = a+0x48, obj = a+0x44.
//   0: if isItem(obj): hero slot 0x4e4(obj). Else x = obj slot 0x20; if isItem(x): hero slot 0x4e4(obj slot 0x20).
//      Else the global G2 slot 0xcc(a+0x106).
//   1: as 0 with slot 0x4e8 and no final else.
//   2 / 3: hero slot 0x130(obj, word hero+0x7c8 (step 2) or +0x7ca (step 3), ConvPtr(hero)).
//   default: if hero != 0 and G2 slot 0x20(hero) is zero: fn = G2+8; if fn and G2+0xc <= hero < G2+0x10: a slot 0x94(fn(hero)).
//            else: if hero[-4] == 0, G2 slot 0xac(hero); a slot 0x94(hero[-4]).
//            Either way the final "A" branch is a slot 0x94(0) when the hero is 0 or G2 slot 0x20 is nonzero.
static void THISCALL heroOperateObject(u8 *self, u8 *a) {
  u32 step = U32(a, 0x48);
  u32 obj = U32(a, 0x44);
  if (step <= 3) {
    switch (step) {
    case 0:
      if (isItem(obj)) {
        vcall<void>(self, 0x4e4, obj);
        return;
      }
      {
        u32 x = vcall<u32>((void *)obj, 0x20);
        if (isItem(x)) {
          u32 x2 = vcall<u32>((void *)obj, 0x20);
          vcall<void>(self, 0x4e4, x2);
          return;
        }
      }
      vcall<void>(g2(), 0xcc, U32(a, 0x106));
      return;
    case 1:
      if (isItem(obj)) {
        vcall<void>(self, 0x4e8, obj);
        return;
      }
      {
        u32 x = vcall<u32>((void *)obj, 0x20);
        if (isItem(x)) {
          u32 x2 = vcall<u32>((void *)obj, 0x20);
          vcall<void>(self, 0x4e8, x2);
        }
      }
      return;
    case 2:
    case 3: {
      u32 word = (step == 2) ? (u32)U16(self, 0x7c8) : (u32)U16(self, 0x7ca);
      u32 cp = (u32)(unsigned long)ext_41e680(self);
      vcall<void>(self, 0x130, obj, word, cp);
      return;
    }
    }
    return;
  }
  // default
  if (self && !vcall<u32>(g2(), 0x20, (u32)(unsigned long)self)) {
    u8 *g = g2();
    u32 fn = U32(g, 8);
    if (fn && U32(g, 0xc) <= (u32)(unsigned long)self && (u32)(unsigned long)self < U32(g, 0x10)) {
      typedef u32(THISCALL * fnT)(void *);
      u32 r = ((fnT)fn)(self);
      vcall<void>(a, 0x94, r);
      return;
    }
    if (*(u32 *)(self - 4) == 0)
      vcall<void>(g2(), 0xac, (u32)(unsigned long)self);
    vcall<void>(a, 0x94, *(u32 *)(self - 4));
    return;
  }
  vcall<void>(a, 0x94, 0u);
}
PCREG(593af0, heroOperateObject);
