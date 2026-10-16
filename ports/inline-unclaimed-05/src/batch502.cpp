// batch502.cpp - unclaimed-05 batch 2 (docs/20-unclaimed-05.md, claim 2: address slice floor(addr/16) mod 20 = 4).
// Names are from the GC name map (naming only, never committed); GUESS where marked.
#include "ff.h"

// ext_5e3e90: the base GetAnims of the hero movement class, original code (thiscall, void).
extern "C" void THISCALL ext_5e3e90(u8 *self);
// ext_634273: CRT sized operator delete (cdecl), original code; the harness stubs it.
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// A virtual slot at +0x58 that takes one string argument and returns a dword (thiscall).
typedef u32(THISCALL *VSlotStr)(u8 *self, const char *name);

// 0x5e4740, ZFFHeroMovementRaiseFlag::GetAnims() (high): calls the base GetAnims, then three virtual lookups
// (slot +0x58, strings at 0x6b7df4, 0x6b7e00, 0x6b7e14), stores the results at this+0x559, +0x55d, +0x561,
// then the word 0x0101 at this+0x371.
static void THISCALL raiseFlagGetAnims(u8 *self) {
  ext_5e3e90(self);
  u8 *vt = *(u8 **)self;
  *(u32 *)(self + 0x559) = ((VSlotStr)*(u32 *)(vt + 0x58))(self, (const char *)0x6b7df4);
  vt = *(u8 **)self;
  *(u32 *)(self + 0x55d) = ((VSlotStr)*(u32 *)(vt + 0x58))(self, (const char *)0x6b7e00);
  vt = *(u8 **)self;
  *(u32 *)(self + 0x561) = ((VSlotStr)*(u32 *)(vt + 0x58))(self, (const char *)0x6b7e14);
  *(u16 *)(self + 0x371) = 0x101;
}
PCREG(5e4740, raiseFlagGetAnims);

// 0x5df880, ZFFActionThrow::~ZFFActionThrow() scalar deleting destructor (medium): sets the vtable word to 0x685294;
// if bit 0 of the stack argument is set, calls the sized delete on this with size 0x22. Returns this in EAX, ret 4.
static u8 *THISCALL actionThrowDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;
  if ((u8)flags & 1) ext_634273(self, 0x22);
  return self;
}
PCREG(5df880, actionThrowDtor);
