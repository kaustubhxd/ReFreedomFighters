// batch776.cpp - unclaimed-77 claim 6 (docs/20-unclaimed-77.md): CEntityTracker::~CEntityTracker (medium). Thiscall, one argument
// (flags), ret 4, returns this. SEH frame not reproduced (the exe installs and restores fs:[0]; the port does not). The null-hook
// branch traps in the original (int3) and is excluded: the harness keeps the hook at 0x7003b0 nonzero. Callees are stubs (GUESS).
#include "ff.h"

extern "C" void ext_41e2c0(u32 a);          // cdecl, one argument, stubbed (GUESS)
extern "C" void ext_4690b0(void *p, u32 n); // cdecl, two arguments, stubbed (GUESS): the array delete helper

// 0x5bfc80, CEntityTracker::~CEntityTracker() (medium): vtable 0x6b38b4, ext_41e2c0(this+0x50), ext_41e2c0(this+0x4c), zeroes
// this+0x44 and this+0x30, vtable 0x686874, then the render-manager object's vtable slot 0x34 with this (the object is the dword
// at 0x70039c, its +0x9b field). If bit 0 of the flags is set: bit 2 set calls ext_4690b0(this, 0x69); bit 2 clear calls the hook
// at 0x7003b0 (no arguments; excluded null case). Returns this.
static u8 *THISCALL entityTrackerDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b38b4;
  ext_41e2c0(*(u32 *)(self + 0x50));
  ext_41e2c0(*(u32 *)(self + 0x4c));
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *rm = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(rm + 0x9b);
  void **vt = *(void ***)obj;
  ((void (THISCALL *)(void *, u32))(*(void **)((u8 *)vt + 0x34)))(obj, (u32)self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4) {
      ext_4690b0(self, 0x69);
    } else {
      void (*hook)(void) = (void (*)(void))G(u32, 0x7003b0);
      hook();
    }
  }
  return self;
}
PCREG(5bfc80, entityTrackerDtor);
