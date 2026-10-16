// batch5753.cpp - unclaimed-57, band batch 53 (name GUESS): 0x5d57c0, thiscall, one stack arg (flags), ret 4, returns this. The deleting form of
// 0x5d5790: vtable 0x6b5610 at this+0; sub = dword this+0x19; if sub: sub->vt[0](1); delete(dword this+0x29, 1) (cdecl; hooked); 0x43de70(this)
// (base dtor; hooked); then if flags bit 0 is set: if bit 2 is set 0x4690b0(this, 0x36) (cdecl sized free; hooked), else 0x45c510(this) (cdecl,
// one argument; hooked). Returns this.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot1)(u8 *self, u32 a);

extern "C" void ext_634273(u8 *p, u32 size);       // cdecl, hooked and logged in the spec
extern "C" void THISCALL ext_43de70(u8 *self);    // base dtor, hooked and logged in the spec
extern "C" void ext_4690b0(u8 *p, u32 size);       // sized free, cdecl, hooked and logged in the spec
extern "C" void ext_45c510(u8 *p);                 // cdecl, one argument, hooked and logged in the spec

static u8 *THISCALL unnamed5d57c0(u8 *self, u32 flags) {
  u8 *sub = *(u8 **)(self + 0x19);
  *(u32 *)self = 0x6b5610;
  if (sub != 0) ((Slot1)VT(sub)[0])(sub, 1);
  ext_634273((u8 *)(unsigned long)*(u32 *)(self + 0x29), 1);
  ext_43de70(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x36);
    else ext_45c510(self);
  }
  return self;
}
PCREG(5d57c0, unnamed5d57c0);
