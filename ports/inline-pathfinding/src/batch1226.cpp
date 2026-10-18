// batch1226.cpp - pathfinding tree: ZPathfinderControl scalar deleting destructor [map high; GC 802d026c; vtable
// slot 0; source zpathfinder control, lines not in the exe's assert table]. thiscall, ret 4, returns this.
// The owned list at +0x48 is released (deleting destructor, flag 1); the object is unregistered from the message table
// (vtable +0x34); the delete flag: bit 0 frees (through the delete hook 0x7003b0; bit 2 means "in an array", no free).
// The exe's SEH frame (fs:[0]) is not reproduced; nothing in the body can throw in this harness.
#include "pf.h"

#define CTRL_VT_BASE 0x694210   // ZPathfinderControl vtable while the base dtor runs
#define CTRL_VT_FINAL 0x686874  // the class's own vtable at the end of the dtor

static void *THISCALL pfcDtor(u8 *self, u32 flag) {
  *(u32 *)self = CTRL_VT_BASE;
  u8 *list = *(u8 **)(self + 0x48);
  if (list) vcall<void>(list, 0, 1);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = CTRL_VT_FINAL;
  u8 *eng = G(u8 *, 0x70039c);
  vcall<void>(*(void **)(eng + 0x9b), 0x34, self);
  if (flag & 1) {
    if (!(flag & 4)) {
      typedef void (*hook_t)(void);
      hook_t h = G(hook_t, 0x7003b0);
      if (h) h();
      else __builtin_debugtrap();
    }
  }
  return self;
}
PCREG(4c5390, pfcDtor);
