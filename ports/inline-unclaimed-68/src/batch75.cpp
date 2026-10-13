// batch75.cpp - unclaimed-68 batch 75 (slice 7). Names GUESS (FUN_addr). The CRT sized delete 0x634273 is cdecl (ptr, size).
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

typedef u32(THISCALL *VSlot168)(u8 *self, u32 a);
typedef u32(THISCALL *VSlot124)(u8 *self, u32 a, u32 b, u32 c, u32 d);
typedef void(THISCALL *VSlotFloat3)(u8 *self, float a, float b, float c);

// 0x4cd3f0: p = [this+4]; vt = 0x695b40; delete(p, 4); if (flags & 1) delete(this, 0x14); returns this; ret 4
static u32 THISCALL g4cd3f0(u8 *self, u32 flags) {
  void *p = *(void **)(self + 4);
  *(u32 *)self = 0x695b40u;
  ext_634273(p, 4u);
  if ((u8)flags & 1) ext_634273(self, 0x14u);
  return (u32)self;
}
PCREG(4cd3f0, g4cd3f0);

// 0x527530: this+0x28 object: slot 0(a, b, c) with the three float arguments in order; ret 0xc
static void THISCALL g527530(u8 *self, float a, float b, float c) {
  u8 *o = self + 0x28;
  ((VSlotFloat3)*(u32 *)(*(u8 **)o))(o, a, b, c);
}
PCREG(527530, g527530);

// 0x45fa30 is NOT ported: its exit pops the wrong words (an extra push of [ebp+0xc] at 45fa37 is never popped), so the exe
// faults on every input (unmapped fetch at the stack top). See docs/20-unclaimed-68.md, batch 75.
