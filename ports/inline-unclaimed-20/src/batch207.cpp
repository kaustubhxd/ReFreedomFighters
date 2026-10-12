// batch207.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Three wrappers that call a
// vtable slot on this+0x1c, then the original 0x5003d0 and 0x5002f0; and one constructor-plus-release wrapper.
#include "ff.h"

// 0x5003d0 and 0x5002f0 each take ONE stack word (ret 4). The exe pushes (value, 0) and calls 0x5003d0, which pops the 0
// (the index); the value stays on the stack and is the argument 0x5002f0 pops. So the exe calls are
// ext_5002f0(ext_5003d0(arr, 0), value): get element 0 of the array, then store value in it. Rewritten 2026-10-12
// (docs/20-unclaimed-22.md); the first version passed two words to 0x5003d0 and none to 0x5002f0.
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 index);   // original, thiscall, ret 4
extern "C" u8 *THISCALL ext_5002f0(u8 *self, u32 value);   // original, thiscall, ret 4
extern "C" void THISCALL ext_5ebbd0(u8 *self);      // original base ctor, thiscall, no stack args
extern "C" void ext_634273(u8 *p, u32 n);           // free-style release, original code (cdecl)

typedef u32(THISCALL *SlotNoArg)(u8 *);
typedef u32(THISCALL *SlotU32Arg0)(u8 *, u32);

// 0x5ebc70, thiscall(flags): call the base ctor 0x5ebbd0(this); if flags & 1, release with ext_634273(this, 0xa7);
// returns this. Name GUESS.
static u8 *THISCALL baseRelease_5ebc70(u8 *self, u32 flags) {
  ext_5ebbd0(self);
  if (flags & 1) ext_634273(self, 0xa7);
  return self;
}
PCREG(5ebc70, baseRelease_5ebc70);

// 0x55cf70, thiscall(a): value = (u8)[this+0x1c]->vtable[0x6b4](0); element 0 of a->[+8] gets value. Name GUESS.
static void THISCALL slot6b4Wrap_55cf70(u8 *self, u8 *a) {
  u8 *obj = *(u8 **)(self + 0x1c);
  SlotU32Arg0 fn = (SlotU32Arg0)(*(u32 *)(*(u32 *)obj + 0x6b4));
  u32 value = (u8)fn(obj, 0);   // the asm pushes 0 before the call and zero-extends al
  ext_5002f0(ext_5003d0(*(u8 **)(a + 8), 0), value);
}
PCREG(55cf70, slot6b4Wrap_55cf70);

// 0x559eb0, thiscall(a): value = [this+0x1c]->vtable[0x674](); element 0 of a->[+8] gets value. Name GUESS.
static void THISCALL slot674Wrap_559eb0(u8 *self, u8 *a) {
  u8 *obj = *(u8 **)(self + 0x1c);
  SlotNoArg fn = (SlotNoArg)(*(u32 *)(*(u32 *)obj + 0x674));
  u32 value = fn(obj);
  ext_5002f0(ext_5003d0(*(u8 **)(a + 8), 0), value);
}
PCREG(559eb0, slot674Wrap_559eb0);

// 0x51b1b0, thiscall(a): value = [this+0x1c]->vtable[0x370](); element 0 of a->[+8] gets value. Name GUESS.
static void THISCALL slot370Wrap_51b1b0(u8 *self, u8 *a) {
  u8 *obj = *(u8 **)(self + 0x1c);
  SlotNoArg fn = (SlotNoArg)(*(u32 *)(*(u32 *)obj + 0x370));
  u32 value = fn(obj);
  ext_5002f0(ext_5003d0(*(u8 **)(a + 8), 0), value);
}
PCREG(51b1b0, slot370Wrap_51b1b0);
