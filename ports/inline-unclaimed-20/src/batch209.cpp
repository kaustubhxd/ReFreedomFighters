// batch209.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. A constructor that
// calls an original sub-object reset three times and a flag-gated release; and a wrapper that reads a float through
// the original 0x5003d0 and passes it to a vtable slot.
#include "ff.h"

extern "C" void THISCALL ext_480fd0(u8 *self);            // original sub-object reset, thiscall, no stack args
extern "C" void ext_634273(u8 *p, u32 n);                  // free-style release, original code (cdecl)
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);   // original, thiscall, one stack word (the harness binds ext_<hex> by name)

typedef void(THISCALL *SlotFloat)(u8 *, float);

// 0x4879b0, thiscall(flags): [this] = vtable 0x68d018; sub-object resets 480fd0 on this+0x55, +0x3d, +0x25; then
// [this] = vtable 0x68cf50; if flags & 1, release with ext_634273(this, 0x3bf); returns this. Name GUESS.
static u8 *THISCALL resetThreeRelease_4879b0(u8 *self, u32 flags) {
  *(u32 *)self = 0x68d018u;
  ext_480fd0(self + 0x55);
  ext_480fd0(self + 0x3d);
  ext_480fd0(self + 0x25);
  *(u32 *)self = 0x68cf50u;
  if (flags & 1) ext_634273(self, 0x3bf);
  return self;
}
PCREG(4879b0, resetThreeRelease_4879b0);

// 0x5081f0, thiscall(a): r = 5003d0(ecx = [a+4], 0); v = *(float *)r; obj = [this+0x18]; obj->vtable[0x624](obj, v).
// Name GUESS.
static void THISCALL floatSlot624_5081f0(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  float v = *(float *)r;
  u8 *obj = *(u8 **)(self + 0x18);
  SlotFloat fn = (SlotFloat)(*(u32 *)(*(u32 *)obj + 0x624));
  fn(obj, v);
}
PCREG(5081f0, floatSlot624_5081f0);
