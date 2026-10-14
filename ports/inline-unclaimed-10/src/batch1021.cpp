// batch1021.cpp - unclaimed-10, batch 17 (docs/20-unclaimed-10.md): CMAINCAMERACONTROL::Load2() (0x4fcfd0), thiscall, no
// arguments. Engine (global 0x70039c, field +0x9b) -> obj1->vt[+0x58](this+0x78) gives r1; engine -> obj2->vt[+0x4c](this+0x44, 0)
// gives r2; r1->vt[+0x128](word this+0x80 zero-extended, r2); then a tail jump to 0x4fdac0 with ecx = this (ret 0). The virtual
// callees are stubbed in the spec, and the tail target 0x4fdac0 is hooked (logged) because it is an unverified callee.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef u32(THISCALL *Slot58)(u8 *self, u32 a);          // obj1->vt[+0x58](value) -> object pointer
typedef u32(THISCALL *Slot4c)(u8 *self, u32 a, u32 b);   // obj2->vt[+0x4c](value, 0) -> value
typedef void(THISCALL *Slot128)(u8 *self, u32 a, u32 b); // r1->vt[+0x128](word, r2)

extern "C" void THISCALL ext_4fdac0(u8 *self);  // tail target, unverified (hooked in the spec)

// 0x4fcfd0, CMAINCAMERACONTROL::Load2() (high)
static void THISCALL cameraControlLoad2(u8 *self) {
  u8 *obj1 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r1 = (u8 *)(unsigned long)((Slot58)VT(obj1)[0x58 / 4])(obj1, *(u32 *)(self + 0x78));
  void **vt1 = VT(r1);
  u8 *obj2 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 r2 = ((Slot4c)VT(obj2)[0x4c / 4])(obj2, *(u32 *)(self + 0x44), 0);
  ((Slot128)vt1[0x128 / 4])(r1, *(u16 *)(self + 0x80), r2);
  ext_4fdac0(self);
}
PCREG(4fcfd0, cameraControlLoad2);
