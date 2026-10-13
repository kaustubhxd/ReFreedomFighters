// batch1128.cpp - collision thread, batch 1128: ZCollisionBase::FreeSceneMemory (0x4ecaa0).
#include "ff.h"

// CRT sized delete (0x634273, __builtin_delete(ptr, size)): cdecl, the caller pops its two args.
extern "C" void ext_634273(void *p, u32 size);

// 0x4ecaa0 ZCollisionBase::FreeSceneMemory() [medium], thiscall, plain ret. Three owned pointers:
// +0x19d and +0x1a1 are objects whose slot 0x28 is called with 1 (a delete-with-flag), then cleared;
// +0x1a5 is a 0x14-byte block freed through the CRT delete (cdecl, size 0x14), then cleared.
static void THISCALL freeSceneMemory(u8 *self) {
  u8 *a = *(u8 **)(self + 0x19d);
  if (a) {
    vcall<void>(a, 0x28, 1u);
    *(u8 **)(self + 0x19d) = 0;
  }
  u8 *b = *(u8 **)(self + 0x1a1);
  if (b) {
    vcall<void>(b, 0x28, 1u);
    *(u8 **)(self + 0x1a1) = 0;
  }
  void *c = *(void **)(self + 0x1a5);
  if (c) {
    ext_634273(c, 0x14);
    *(void **)(self + 0x1a5) = 0;
  }
}
PCREG(4ecaa0, freeSceneMemory);
