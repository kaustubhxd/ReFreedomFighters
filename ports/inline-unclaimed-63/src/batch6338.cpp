// batch6338.cpp - unclaimed-63 gap-band batch 38: 0x4d23d0 (C-set; constructor, SEH tagged), thiscall, one stack argument flags, ret 4.
//   SEH frame and /GS cookie not reproduced (the original installs an fs:[0] frame; the port keeps only the body).
//   this[0] = 0x696220; 0x4cee30(this+0x40b4, 0, 0x4000) (thiscall, two stack arguments, callee pops 8); vtbl[+0xc] of the object at
//   this+0x4008 (thiscall, no arguments); this[+0x4004] = this + 4; 0x4cd180(this+0x40b4) (thiscall); 0x4ccf60(this+0x4008) (thiscall);
//   this[0] = 0x696168; if (flags & 1) 0x634273(this, 0x40c4) (cdecl, caller cleans). Returns this.
//   The helpers are original code, stubbed by the spec.
#include "ff.h"

extern "C" void THISCALL ext_4cee30(void *self, u32 a, u32 b);   // thiscall, two stack arguments, original, stubbed by the spec
extern "C" void THISCALL ext_4cd180(void *self);                 // thiscall, original, stubbed by the spec
extern "C" void THISCALL ext_4ccf60(void *self);                 // thiscall, original, stubbed by the spec
extern "C" void ext_634273(u32 self, u32 size);                  // cdecl, original, stubbed by the spec

typedef void(THISCALL * virtc_fn)(void *);

// 0x4d23d0 (C-set).
static u8 *THISCALL unnamed4d23d0(u8 *self, u32 flags) {
  *(u32 *)self = 0x696220u;
  ext_4cee30((void *)(self + 0x40b4), 0u, 0x4000u);
  u8 *obj = self + 0x4008;
  ((virtc_fn)(*(u32 *)(*(u32 *)obj + 0xc)))((void *)obj);
  *(u32 *)(self + 0x4004) = (u32)(self + 4);
  ext_4cd180((void *)(self + 0x40b4));
  ext_4ccf60((void *)(self + 0x4008));
  *(u32 *)self = 0x696168u;
  if (flags & 1)
    ext_634273((u32)self, 0x40c4u);
  return self;
}
PCREG(4d23d0, unnamed4d23d0);
