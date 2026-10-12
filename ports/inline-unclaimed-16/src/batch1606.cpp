// batch1606.cpp - unclaimed-16 batch 6 (docs/20-unclaimed-16.md): ZFFActor::DestroyWeapons() (high). Two lookups
// in the render-manager sub-object (slot 0x58 with the weapon slot at this+0x78a, then +0x78e); each non-null result
// has its slot cleared and its slot 0x320 called with no arguments. The second call is a tail jump in the exe.
#include "ff.h"

typedef u32(THISCALL *FnR1)(void *, u32);
typedef void(THISCALL *FnV0)(void *);

static void *renderMgrSub() {
  u32 rm = *(u32 *)0x70039c;
  return (void *)(u32)*(u32 *)(rm + 0x9b);
}

static void THISCALL ffActorDestroyWeapons(u8 *self) {
  void *q = renderMgrSub();
  u32 obj = ((FnR1)(*(u32 **)q)[0x58 / 4])(q, *(u32 *)(self + 0x78a));
  if (obj != 0) {
    *(u32 *)(self + 0x78a) = 0;
    u8 *o = (u8 *)obj;
    ((FnV0)(*(u32 **)o)[0x320 / 4])(o);
  }
  q = renderMgrSub();
  obj = ((FnR1)(*(u32 **)q)[0x58 / 4])(q, *(u32 *)(self + 0x78e));
  if (obj != 0) {
    *(u32 *)(self + 0x78e) = 0;
    u8 *o = (u8 *)obj;
    ((FnV0)(*(u32 **)o)[0x320 / 4])(o);
  }
}
PCREG(59f370, ffActorDestroyWeapons);
