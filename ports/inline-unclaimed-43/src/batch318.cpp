// batch318.cpp - 0x5422e0 scalar deleting destructor (area 43, 2026-10-12). thiscall (this = ECX), one stack argument (flags),
// ret 4, returns this. Body: store the class vtable 0x6a2e08 at [this]; if (flags & 1): __builtin_delete(this, 4) (cdecl).
// The name map has no entry for this address; the vtable value is the one the exe writes.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

extern "C" void ext_634273(void *p, unsigned long size);   // __builtin_delete (cdecl, 2 pushed words in the exe)

static u8 *THISCALL scalarDeletingNoBase(u8 *self, u32 flags) {
  U32(self, 0) = 0x6a2e08u;
  if ((flags & 1) != 0)
    ext_634273(self, 4);
  return self;
}
PCREG(5422e0, scalarDeletingNoBase);
