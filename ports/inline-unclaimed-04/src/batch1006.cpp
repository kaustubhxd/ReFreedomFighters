// batch1006.cpp - unclaimed-04 batch 6 (docs/20-unclaimed-04.md): ZFFHERO::CreateMovementStand (0x590db0, medium name).
// thiscall, no stack arguments, ret 0. The MSVC SEH frame in the prologue and epilogue (fs:[0]) is left out: it is
// installed and restored on exit, so memory is the same afterwards. The allocator 0x41e290 (cdecl, one argument, operator
// new: a hook in the spec, GUESS) and the constructor 0x5e1240 (thiscall on the new object, with the owner and 2) are
// called as the exe calls them.
#include "ff.h"

extern "C" void *ext_41e290(u32 size);                              // cdecl operator new, original code
extern "C" u32 THISCALL ext_5e1240(void *obj, void *owner, u32 n);  // constructor, original code

// 0x590db0: null when the allocator returns null, else the constructor's result (eax).
static u32 THISCALL zffHeroCreateMovementStand(u8 *self) {
  void *obj = ext_41e290(0x189);
  if (!obj) return 0;
  return ext_5e1240(obj, self, 2);
}
PCREG(590db0, zffHeroCreateMovementStand);
