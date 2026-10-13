// batch1105.cpp - unclaimed-11 batch 5 (docs/20-unclaimed-11.md): ZCollisionBase::FreeSceneMemory (0x4ecaa0, medium).
// Thiscall, no arguments. Releases the object at +0x19d and the object at +0x1a1 through vtable slot 0x28 (argument 1),
// then frees the block at +0x1a5 with cdecl free(ptr, 0x14). Each field is cleared to 0 after its release.
#include "ff.h"

// 0x634273: cdecl free(ptr, size). Original CRT code (not stubbed in the port's own build; stubbed in the harness).
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

typedef void(THISCALL *vdel)(void *self, u32 flag);

// 0x4ecaa0, ZCollisionBase::FreeSceneMemory() (medium).
static void THISCALL collisionBaseFreeSceneMemory(u8 *self) {
  void *a = *(void **)(self + 0x19d);
  if (a) {
    ((vdel)((*(void ***)a)[0x28 / 4]))(a, 1);
    *(void **)(self + 0x19d) = nullptr;
  }
  void *b = *(void **)(self + 0x1a1);
  if (b) {
    ((vdel)((*(void ***)b)[0x28 / 4]))(b, 1);
    *(void **)(self + 0x1a1) = nullptr;
  }
  void *c = *(void **)(self + 0x1a5);
  if (c) {
    ext_634273(c, 0x14);
    *(void **)(self + 0x1a5) = nullptr;
  }
}
PCREG(4ecaa0, collisionBaseFreeSceneMemory);
