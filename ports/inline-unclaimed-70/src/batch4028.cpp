// batch4028.cpp - area 70 (slice 4/5), batch 4028: 0x5f0050, a deleting destructor shape (names GUESS). Sets the vtable
// 0x6b8214, calls the base destructor 0x5ec7e0 (thiscall, no arguments; SEH-framed, stubbed by address), then if bit 0 of its
// argument is set calls 0x634273 (the free routine, cdecl, (this, 0xdb); stubbed by address). Returns this.
#include "ff.h"

extern "C" void THISCALL ext_5ec7e0(void *self);     // exe: base destructor, SEH-framed, stubbed by address in the spec
extern "C" void ext_634273(void *p, u32 size);        // exe: free routine (cdecl), stubbed by address in the spec

// 0x5f0050 (name GUESS): thiscall (ECX = this), one stack argument flags, ret 4.
static u8 *THISCALL deleteShape5f0050(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b8214;
  ext_5ec7e0(self);
  if ((u8)flags & 1) ext_634273(self, 0xdb);
  return self;
}
PCREG(5f0050, deleteShape5f0050);
