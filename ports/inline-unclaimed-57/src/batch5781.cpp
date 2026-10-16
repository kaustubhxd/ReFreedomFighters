// batch5781.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 81: 0x5d88d0 (GUESS name unnamed_5d88d0), thiscall, one stack argument
// (the flags byte, ret 4), returns this in eax. Order: p20 = this+0x20; this->vtable = 0x6b5fc8; if p20: 0x41e2c0(p20) (cdecl, hooked);
// p24 = this+0x24; if p24: 0x634273(p24, 8) (cdecl sized delete, hooked); this+0x24 = 0; this+0x20 = 0; base 0x43de70(this) (hooked);
// if flags & 1: if flags & 4: 0x4690b0(this, 0x48) (cdecl sized free, hooked) else 0x45c510(this) (hooked). Return this.
#include "ff.h"

extern "C" void ext_41e2c0(void *p);  // delete-like, cdecl, original code (hooked in the spec)
extern "C" void ext_634273(void *p, u32 n);  // operator delete (cdecl, pointer and size), original code (hooked in the spec)
extern "C" void THISCALL ext_43de70(u8 *self);  // base destructor, original code (hooked in the spec)
extern "C" void ext_4690b0(void *p, u32 n);  // sized free, cdecl, original code (hooked in the spec)
extern "C" void ext_45c510(u8 *self);  // cdecl, one pointer argument (the caller pops it), original code (hooked in the spec)

// 0x5d88d0, thiscall, one stack argument (GUESS name)
static u8 *THISCALL unnamed5d88d0(u8 *self, u32 flags) {
  u32 p20 = *(u32 *)(self + 0x20);
  *(u32 *)self = 0x6b5fc8;
  if (p20) ext_41e2c0((void *)(unsigned long)p20);
  u32 p24 = *(u32 *)(self + 0x24);
  if (p24) ext_634273((void *)(unsigned long)p24, 8);
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x20) = 0;
  ext_43de70(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x48);
    else ext_45c510(self);
  }
  return self;
}
PCREG(5d88d0, unnamed5d88d0);
