// batch1023.cpp - unclaimed-04 batch 24 (docs/20-unclaimed-04.md): 0x45ba30, thiscall, no arguments.
// vt[0x110](0x10, 0), then 0x43e0f0 (original, thiscall), then a tail jump through vt[0x214] with ecx = this. The tail
// jump is written as a final call: with no stack arguments that is the same control flow.
#include "ff.h"

typedef u32(THISCALL *vf2_t)(void *self, u32 a, u32 b);
typedef void(THISCALL *vf0_t)(void *self);

extern "C" void THISCALL ext_43e0f0(void *self);  // original code

static inline u32 vslot(void *o, u32 off) {
  return *(u32 *)(*(u32 *)o + off);
}

// 0x45ba30
static void THISCALL unk45ba30TailViaVt214(u8 *self) {
  ((vf2_t)vslot(self, 0x110))(self, 0x10, 0);
  ext_43e0f0(self);
  ((vf0_t)vslot(self, 0x214))(self);
}
PCREG(45ba30, unk45ba30TailViaVt214);
