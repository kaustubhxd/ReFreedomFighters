// batch5836.cpp - residue 9, 0x4fcfd0 (CMAINCAMERACONTROL::Load2(), gc name map), thiscall, no args. O = sub->vt[+0x58](this+0x78) (sub = engine+0x9b);
// r = sub->vt[+0x4c](this+0x44, 0); O->vt[+0x128]((u16)this+0x80, r); then tail-jump to 0x4fdac0 (original code, hooked in the spec; called here as the last step).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotA2)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *Slot2v)(u8 *self, u32 a, u32 b);

extern "C" void THISCALL ext_4fdac0(u8 *self);  // tail-jump target, plain ret, original code (hooked in the spec)

// 0x4fcfd0, thiscall, no args (CMAINCAMERACONTROL::Load2)
static void THISCALL unnamed4fcfd0(u8 *self) {
  u8 *sub = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *O = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x78));
  u32 r = ((SlotA2)VT(sub)[0x4c / 4])(sub, *(u32 *)(self + 0x44), 0);
  ((Slot2v)VT(O)[0x128 / 4])(O, (u32)*(u16 *)(self + 0x80), r);
  ext_4fdac0(self);
}
PCREG(4fcfd0, unnamed4fcfd0);
