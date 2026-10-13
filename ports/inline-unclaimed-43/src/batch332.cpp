// batch332.cpp - 0x4e5020 scalar deleting destructor (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument
// (flags), ret 4, returns this. Stores vtable 0x697360 at [this]; if (flags & 1): __builtin_delete(this, 4) (cdecl).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void ext_634273(void *p, unsigned long size);   // __builtin_delete (cdecl, 2 pushed words)

static u8 *THISCALL scalarDeletingPN(u8 *self, u32 flags) {
  U32(self, 0) = 0x697360u;
  if ((flags & 1) != 0)
    ext_634273(self, 4);
  return self;
}
PCREG(4e5020, scalarDeletingPN);
