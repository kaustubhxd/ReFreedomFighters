// batch905.cpp - gap band slice, two SEH-framed rows (SEH frame not reproduced: fs:[0] writes not compared; tag below).
// 0x41e1f0 [thiscall, no args, ret 0]: this's first word = 0x67716c, then the base routine 0x41e590 on this (ECX = this).
// 0x41e230 ZSysMem::~ZSysMem() [thiscall, one stack arg (flag), ret 4, returns this]: the same vtable store and base call; if bit 0 of
//   the flag is set, 0x634273 (cdecl: this, 0x4f). Returns this.
// Stood in: 0x41e590 (base routine, thiscall no args) and 0x634273 (cdecl, two words).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_41e590(void *self);     // base routine (stood in)
extern "C" void ext_634273(void *obj, u32 n);        // cdecl (stood in)

// 0x41e1f0 (name GUESS "Ctor41e1f0"). SEH frame not reproduced.
static void THISCALL Ctor41e1f0(u8 *self) {
  U32(self, 0) = 0x67716cu;
  ext_41e590(self);
}
PCREG(41e1f0, Ctor41e1f0);

// 0x41e230 (name map: ZSysMem::~ZSysMem()). SEH frame not reproduced.
static u8 *THISCALL Dtor41e230(u8 *self, u32 flag) {
  U32(self, 0) = 0x67716cu;
  ext_41e590(self);
  if (flag & 1u) ext_634273(self, 0x4fu);
  return self;
}
PCREG(41e230, Dtor41e230);
