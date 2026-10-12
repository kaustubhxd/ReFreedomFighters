// batch1612.cpp - unclaimed-16 batch 12 (docs/20-unclaimed-16.md): CAction::UpdateObjectsInRange(ZGEOM*) (medium; the
// GC name map name fits the loop). The count is the dword at this+0x7e and the item pointers start at this+0x82. For
// each item, slot 0x84 of the item is called with the argument; its low byte decides the branch. Slot 0x128 of the
// object at item+0x44 is called with (word 0x7002c8, 2, that object) when the item's bit 1 (byte +0x5a) and flag byte
// (+0x63) say so. The callees 0x4a02e0 and 0x4a01c0 are original code (stubbed in the spec, not verified).
#include "ff.h"

extern "C" void THISCALL ext_4a02e0(u8 *self, u32 a1); // original code, stubbed in the spec
extern "C" void THISCALL ext_4a01c0(u8 *self, u32 a1); // original code, stubbed in the spec

typedef u8(THISCALL *FnB1)(void *, u32);
typedef void(THISCALL *Fn3)(void *, u32, u32, u32);

static void notifySub(u8 *item) {
  u8 *sub = *(u8 **)(item + 0x44);
  u32 w = *(u16 *)0x7002c8;
  u32 *vt = *(u32 **)sub;
  ((Fn3)vt[0x128 / 4])(sub, w, 2, (u32)sub);
}

// 0x4a20e0: returns at once when the argument is 0. Otherwise loops over the items (the exe loop test is "index !=
// count", re-reading the count each pass). Then calls 0x4a02e0(this, arg) if any item's slot 0x84 returned a nonzero
// low byte, and 0x4a01c0(this, arg) otherwise (also when the count was 0).
static void THISCALL actionUpdateObjectsInRange(u8 *self, u32 a1) {
  if (a1 == 0)
    return;
  u8 any = 0;
  u32 i = 0;
  if (*(u32 *)(self + 0x7e) != 0) {
    do {
      u8 *item = *(u8 **)(self + 0x82 + 4 * i);
      u32 *ivt = *(u32 **)item;
      u8 hit = ((FnB1)ivt[0x84 / 4])(item, a1);
      if (hit) {
        any = 1;
        if ((item[0x5a] & 2) && item[0x63])
          notifySub(item);
        *(u32 *)(item + 0x5a) &= 0xfffffffdu;
      } else {
        if (!(item[0x5a] & 2) && item[0x63])
          notifySub(item);
        *(u32 *)(item + 0x5a) |= 2;
      }
      i++;
    } while (i != *(u32 *)(self + 0x7e));
  }
  if (any)
    ext_4a02e0(self, a1);
  else
    ext_4a01c0(self, a1);
}
PCREG(4a20e0, actionUpdateObjectsInRange);
