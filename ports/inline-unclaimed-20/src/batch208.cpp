// batch208.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. Two constructor-with-flags
// wrappers that release through an original cdecl helper, and one wrapper that calls a vtable slot or an original helper.
#include "ff.h"

extern "C" void THISCALL ext_46a4f0(u8 *self);        // original base ctor, thiscall, no stack args
extern "C" void THISCALL ext_43ea20(u8 *self);        // original base ctor, thiscall, no stack args
extern "C" void ext_45c510(u8 *p);                    // original, cdecl(p): plain release
extern "C" void ext_4690b0(u8 *p, u32 n);             // original, cdecl(p, n): release with a size
extern "C" void THISCALL ext_4cbe80(u8 *self, u32 arg); // original, thiscall (ecx = arg0), one stack word, callee pops 4

typedef void(THISCALL *Slot1d8)(u8 *, u32, u32);

// 0x46a770, thiscall(flags): [this] = vtable 0x687cb0; base ctor 0x46a4f0(this); if flags & 1: if flags & 4 then
// ext_4690b0(this, 0x92), else ext_45c510(this). Returns this. Name GUESS.
static u8 *THISCALL ctorRelease_46a770(u8 *self, u32 flags) {
  *(u32 *)self = 0x687cb0u;
  ext_46a4f0(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x92);
    else ext_45c510(self);
  }
  return self;
}
PCREG(46a770, ctorRelease_46a770);

// 0x485bb0, thiscall(flags): base ctor 0x43ea20(this); if flags & 1: if flags & 4 then ext_4690b0(this, 0x5c), else
// ext_45c510(this). Returns this. Name GUESS.
static u8 *THISCALL baseRelease_485bb0(u8 *self, u32 flags) {
  ext_43ea20(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x5c);
    else ext_45c510(self);
  }
  return self;
}
PCREG(485bb0, baseRelease_485bb0);

// 0x4da2f0, thiscall(a0, a1) (ret 8): if [this+0x54] is set, call its vtable slot 0x1d8 (obj, a0, a1); else call the
// original 0x4cbe80 with ecx = a0 and the word 0x67c8e8. Returns a0 in eax. Name GUESS.
static u32 THISCALL vtSlot1d8OrBase_4da2f0(u8 *self, u32 a0, u32 a1) {
  u8 *obj = *(u8 **)(self + 0x54);
  if (obj) {
    Slot1d8 fn = (Slot1d8)(*(u32 *)(*(u32 *)obj + 0x1d8));
    fn(obj, a0, a1);
  } else {
    ext_4cbe80((u8 *)a0, 0x67c8e8u);
  }
  return a0;
}
PCREG(4da2f0, vtSlot1d8OrBase_4da2f0);
