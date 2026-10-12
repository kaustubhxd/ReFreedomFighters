// batch1029.cpp - unclaimed-04 batch 29 (docs/20-unclaimed-04.md): 0x4265b0, deleting destructor (thiscall, flag, ret 4).
// The base destructor 0x4264b0 and the CRT free 0x634273 (cdecl, pointer and size 0x118) are hooked by address in the spec.
#include "ff.h"

extern "C" void THISCALL ext_4264b0(void *self);  // base destructor (hooked by address in the spec; GUESS)
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);  // free (hooked by address in the spec; GUESS)

// 0x4265b0
static u8 *THISCALL unk4265b0DeletingDtor(u8 *self, u32 flags) {
  ext_4264b0(self);
  if (flags & 1) ext_634273(self, 0x118);
  return self;
}
PCREG(4265b0, unk4265b0DeletingDtor);
