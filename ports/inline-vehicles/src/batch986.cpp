// batch986.cpp - residue-11 (core todo), batch 986: ZCharacterControl::~ZCharacterControl(flags), 0x57fdb0, thiscall(flags), ret 4.
// Same shape as ZFollowShape's deleting dtor (batch 967): [+0x44] = 0, [+0x30] = 0, vtable 0x686874, render manager slot 0x34(this),
// then flags&1: flags&4 -> operator delete(this, 0x98c) (0x4690b0, a bare ret), else the hook at 0x7003b0 (a null hook is an int3).
// The MSVC exception frame (fs:[0]) is not reproduced: it is not game state.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size);  // operator delete (cdecl, bare ret)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x57fdb0 ZCharacterControl::~ZCharacterControl(flags).
static u8 *THISCALL charCtrlDtor(u8 *t, u32 flags) {
  D(t, 0x44) = 0;
  D(t, 0x30) = 0;
  D(t, 0x0) = 0x686874;
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  vcall<void>(rm, 0x34, (u32)t);
  if ((u8)flags & 1) {
    if ((u8)flags & 4) {
      ext_4690b0(t, 0x98c);
    } else {
      void (*hook)() = *(void (**)())0x7003b0;
      if (!hook)
        __asm__ volatile("int3");
      hook();
    }
  }
  return t;
}
PCREG(57fdb0, charCtrlDtor);
