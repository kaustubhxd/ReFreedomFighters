// batch1036.cpp - area 81, batch 1036: 0x5daf20, thiscall (this), no stack arguments, plain ret. SEH frame and cookie check not reproduced.
// Sets the vtable word to 0x6b6754. If the object at this+0x84 (M) is set: M slot 0x4c is called with a local word, then M slot 0x5c (one
// argument, the local's address) gives a pointer p and fills the local; while the local is non-zero, 0x634273 (cdecl, p and 0xd) is called
// and slot 0x5c is called again. Then M slot 0 is called with 1 (scalar deleting destructor). this+0x44 and this+0x30 are cleared, the vtable
// word is set to 0x686874, and the render manager's object at sys+0x9b gets slot 0x34 with this. No stand-ins in the port itself: the M and
// render object slots and 0x634273 are GUESS stubs in the spec.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define G32(a) (*(volatile u32 *)(a))

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 sz);   // GUESS (stood in): frees p

// 0x5daf20 (thiscall: this).
static void THISCALL tearDownObj(u8 *self) {
  D(self, 0) = 0x6b6754u;
  u32 tmp = 0;
  u8 *m = (u8 *)D(self, 0x84);
  if (m != 0) {
    vcall<void>(m, 0x4c, (u32)&tmp);
    u32 p = vcall<u32>((u8 *)D(self, 0x84), 0x5c, (u32)&tmp);
    if (tmp != 0) {
      do {
        ext_634273((void *)p, 0xdu);
        p = vcall<u32>((u8 *)D(self, 0x84), 0x5c, (u32)&tmp);
      } while (tmp != 0);
    }
    vcall<void>((u8 *)D(self, 0x84), 0x0, 1u);
  }
  D(self, 0x44) = 0;
  D(self, 0x30) = 0;
  D(self, 0) = 0x686874u;
  u8 *sys = (u8 *)G32(0x70039c);
  u8 *rm = (u8 *)D(sys, 0x9b);
  vcall<void>(rm, 0x34, (u32)self);
}
PCREG(5daf20, tearDownObj);
