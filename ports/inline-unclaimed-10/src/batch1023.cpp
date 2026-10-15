// batch1023.cpp - unclaimed-10, batch 19 (docs/20-unclaimed-10.md): ZActionControlMap::Load2() (0x5b3e10), thiscall, no
// arguments. s = this->[+0x5f]. If s->[+0x85a] is 0, it is set to s->vt[+0x100](0x6a6e88). Then this->[+0x63] = s->[+0x85a],
// this->[+0x5b] = s->[+0x852], this->[+0x51] = 0x591ae0(s) (plain call, ecx = s), and a tail jump to this->vt[+0xc] with ecx = this.
// The virtual slot, the call 0x591ae0 and the tail slot are unverified callees: the first two are stubbed and hooked (spec),
// the tail is a stub slot.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *Slot100)(u8 *self, u32 a);  // s->vt[+0x100](0x6a6e88) -> value
typedef void(THISCALL *SlotNone)(u8 *self);       // this->vt[+0xc]()

extern "C" u32 THISCALL ext_591ae0(u8 *self);     // plain call with ecx = s, original code (hooked in the spec)

// 0x5b3e10, ZActionControlMap::Load2() (high)
static void THISCALL actionControlMapLoad2(u8 *self) {
  u8 *s = *(u8 **)(self + 0x5f);
  if (*(u32 *)(s + 0x85a) == 0) *(u32 *)(s + 0x85a) = ((Slot100)VT(s)[0x100 / 4])(s, 0x6a6e88);
  *(u32 *)(self + 0x63) = *(u32 *)(s + 0x85a);
  *(u32 *)(self + 0x5b) = *(u32 *)(s + 0x852);
  *(u32 *)(self + 0x51) = ext_591ae0(s);
  ((SlotNone)VT(self)[0xc / 4])(self);
}
PCREG(5b3e10, actionControlMapLoad2);
