// batch6270.cpp - unclaimed-68 gap-band destructor (claim, medium). Name from the GC name map.
#include "ff.h"

// Engine virtual slot +0x34 on the object at [0x70039c]+0x9b (thiscall, one argument, callee pops 4).
typedef void(THISCALL *VEngine34)(u8 *self, u8 *arg);
typedef void (*VoidFn)(void);
// 0x4690b0 is a bare `ret` in the exe (a no-op). Called as cdecl with two arguments; the caller pops them.
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size);

// 0x4be5e0, ZSoundSpline::~ZSoundSpline() scalar deleting destructor (medium): thiscall, ret 4. Clears this+0x44 and
// this+0x30, writes the vtable word 0x686874, makes the engine call (slot +0x34 with this), then, when bit 0 of the argument is
// set: with bit 2 the no-op delete (size 0x6f), otherwise the hook at 0x7003b0 when it is not null. Returns this in EAX.
static u8 *THISCALL soundSplineDtor(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *en = *(u8 **)(eng + 0x9b);
  ((VEngine34)*(u32 *)(*(u8 **)en + 0x34))(en, self);
  u8 f = (u8)flags;
  if (f & 1) {
    if (f & 4) {
      ext_4690b0(self, 0x6f);
    } else {
      VoidFn hook = G(VoidFn, 0x7003b0);
      if (hook) hook();
    }
  }
  return self;
}
PCREG(4be5e0, soundSplineDtor);
