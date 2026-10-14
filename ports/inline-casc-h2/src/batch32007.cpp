// batch32007.cpp - h2 batch 32007: priority task ZBaseGeom::MakeInactive
#include "ff.h"

extern "C" void ext_4da770(u8 *self);
extern "C" void ext_4dae60(u8 *self);
extern "C" u8 *ext_4daff0(u8 *self);
extern "C" void ext_4dc630(u8 *self, u32 arg);

// 0x4dc030, thiscall(self) void: ZBaseGeom::MakeInactive
// Complex: recursion, virtual calls, global reads - escalate to 
static void THISCALL fn4dc030(u8 *self) {
  ext_4da770(self);
  ext_4dc630(self, 0x400);
}
PCREG(4dc030, fn4dc030);
