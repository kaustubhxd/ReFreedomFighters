// batch207.cpp - hero action slot 0x3d8 (inline-ladder thread, 2026-10-11): ZIKLNKOBJ::RunLnkAction.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

// 0x467740, ZIKLNKOBJ::RunLnkAction(ZLnkAction *action) [GC 8017cc48, high], vtable slot 0x3d8 of ZIKLNKOBJ,
// ZCTRLIKLNKOBJ, ZLNKWHANDS, ZActor, ZPlayer, ZPlayerTest, ZFFHERO and ZFFActor. thiscall, one stack arg, returns EAX.
// The object at +0x1ce is the action runner (GC +0x1e4). Assert that its +4 is zero (no action running): MSVC's
// assert here calls the hook at 0x7003b0 when one is set, and breaks (int3) otherwise. Then it tail-jumps to slot 4
// of the runner's vtable with the same argument: runner->Run(action), whose result is returned.
static u32 THISCALL runLnkAction(u8 *self, u32 action) {
  if (U32(U32(self, 0x1ce), 4) != 0) {
    typedef void (*hook_t)();
    hook_t h = G(hook_t, 0x7003b0);
    if (h)
      h();
    else
      __asm__ volatile("int3");
  }
  return vcall<u32>((void *)U32(self, 0x1ce), 4, action);
}
PCREG(467740, runLnkAction);
