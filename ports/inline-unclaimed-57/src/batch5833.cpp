// batch5833.cpp - residue 9, 0x5b3e10 (ZActionControlMap::Load2(), gc name map), thiscall, no args. O = this+0x5f; if O+0x85a == 0: O+0x85a = O->vt[+0x100](0x6a6e88);
// this+0x63 = O+0x85a; this+0x5b = O+0x852; this+0x51 = 0x591ae0(O) (thiscall, hooked); then tail-jump this->vt[+0xc]() (called here, same result).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);

extern "C" u32 THISCALL ext_591ae0(u8 *self);  // thiscall helper (ecx = O, no args), original code (hooked in the spec)

// 0x5b3e10, thiscall, no args (ZActionControlMap::Load2)
static void THISCALL unnamed5b3e10(u8 *self) {
  u8 *O = *(u8 **)(self + 0x5f);
  if (*(u32 *)(O + 0x85a) == 0) *(u32 *)(O + 0x85a) = ((SlotA)VT(O)[0x100 / 4])(O, 0x6a6e88);
  *(u32 *)(self + 0x63) = *(u32 *)(O + 0x85a);
  *(u32 *)(self + 0x5b) = *(u32 *)(O + 0x852);
  *(u32 *)(self + 0x51) = ext_591ae0(O);
  ((SlotN)VT(self)[0xc / 4])(self);
}
PCREG(5b3e10, unnamed5b3e10);
