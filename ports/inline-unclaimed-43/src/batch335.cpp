// batch335.cpp - 0x5ed4e0 scalar deleting destructor (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument
// (flags), ret 4, returns this. Stores vtable 0x6b813c at [this]; calls the base destructor 0x5ec7e0 (exe, ecx = this);
// if (flags & 1): __builtin_delete(this, 0xf7) (cdecl). The base destructor is hooked and logged in the spec.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void THISCALL ext_5ec7e0(u8 *self);            // base destructor (ecx = self, no stack arguments)
extern "C" void ext_634273(void *p, unsigned long size);  // __builtin_delete (cdecl)

static u8 *THISCALL scalarDeletingWithBase(u8 *self, u32 flags) {
  U32(self, 0) = 0x6b813cu;
  ext_5ec7e0(self);
  if ((flags & 1) != 0)
    ext_634273(self, 0xf7);
  return self;
}
PCREG(5ed4e0, scalarDeletingWithBase);
