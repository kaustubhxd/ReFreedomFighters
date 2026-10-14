// u69_40.cpp - area 69, group 40 (slice 8). Two call-then-tail-jump chains. Each function calls A, then runs B with the same ECX and no args; the port calls both and returns B's eax. A and B are other areas' functions (GUESS stubs in the spec).
#include "ff.h"

extern "C" u32 THISCALL ext_564e40(void *self);   // thiscall, no args, ret 0 (other area)
extern "C" u32 THISCALL ext_56bd90(void *self);   // thiscall, no args, ret 0 (other area)
extern "C" u32 THISCALL ext_562440(void *self);   // thiscall, no args, ret 0 (other area)
extern "C" u32 THISCALL ext_571f20(void *self);   // thiscall, no args, ret 0 (other area)

// 0x56bd80 (GC map name CLoadMenu::Load2). thiscall, no args (ret). Calls 0x564e40(self), then jumps to 0x56bd90 with ECX = self.
static u32 THISCALL chain56bd80(u8 *self) {
  ext_564e40(self);
  return ext_56bd90(self);
}
PCREG(56bd80, chain56bd80);

// 0x571f00 (GC map name CSoundMenu::Init()). thiscall, no args (ret). Calls 0x562440(self), then jumps to 0x571f20 with ECX = self.
static u32 THISCALL chain571f00(u8 *self) {
  ext_562440(self);
  return ext_571f20(self);
}
PCREG(571f00, chain571f00);
