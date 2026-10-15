// batch6514.cpp - unclaimed-65: batch 14 (docs/20-unclaimed-65.md, claim 14). Two deleting-style destructors with an SEH frame.
// SEH frame not reproduced: the fs:[0] writes are not compared (the port does not touch fs:[0]); the cookie check is not called.
#include "ff.h"

extern "C" void THISCALL ext_4ccf60(u8 *self);     // base-class part for CMAINCAMERACONTROL (plain thiscall, no args)
extern "C" void ext_4690b0(u8 *self, u32 size);   // cdecl, two arguments

typedef u32(THISCALL *F1)(u8 *self, u32 a);
static u32 vc1(u8 *o, u32 s, u32 a) { return ((F1)(*(const u32 *)(*(const u32 *)o + s)))(o, a); }

// 0x4fb9e0, CMAINCAMERACONTROL::~CMAINCAMERACONTROL() (residue 18). SEH frame not reproduced.
static u8 *THISCALL cameraControlDtor(u8 *self, u32 flags) {
  ext_4ccf60(self + 0x98);
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *render = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  vc1(render, 0x34, (u32)self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4) {
      ext_4690b0(self, 0x15a);
    } else {
      typedef void (*PlainFn)(void);
      ((PlainFn)G(u32, 0x7003b0))();
    }
  }
  return self;
}
PCREG(4fb9e0, cameraControlDtor);

// 0x577860, GUESS FUN_577860 (residue 18). SEH frame not reproduced. Same shape as the destructor above without the base call.
static u8 *THISCALL unknown577860(u8 *self, u32 flags) {
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)self = 0x686874;
  u8 *render = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  vc1(render, 0x34, (u32)self);
  if ((u8)flags & 1) {
    if ((u8)flags & 4) {
      ext_4690b0(self, 0x224);
    } else {
      typedef void (*PlainFn)(void);
      ((PlainFn)G(u32, 0x7003b0))();
    }
  }
  return self;
}
PCREG(577860, unknown577860);
