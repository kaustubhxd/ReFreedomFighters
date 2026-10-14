// u69_46.cpp - area 69, group 46 (slice 8). SEH tag: the original sets up and tears down an fs:[0] frame, which the port does not reproduce (it does not change the returned value or the fields checked).
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);           // sized delete (cdecl), CRT
extern "C" u32 THISCALL ext_641b60(void *self, u32 a);   // thiscall, one stack arg, ret 4; other area (stubbed in the spec: GUESS)

// 0x645250, scalar deleting destructor (ZBoneModifyBase per the earlier note; the GC name is not confirmed here). thiscall, one stack arg (flags, ret 4), returns this.
// Sets the vtable 0x6c28a4. If the dword at self+0x291 is non-zero: calls slot 0x94 of the object at the global pointer 0x70039c -> +0x1aa3, stores the result at self+0x28d,
// calls 0x641b60(result, self+0x291) when the result is non-zero, and clears self+0x291. If bit 0 of flags is set, sized-deletes self (size 0x296).
static u8 *THISCALL dtor645250(u8 *self, u32 flags) {
  *(u32 *)self = 0x6c28a4;
  if (*(u32 *)(self + 0x291)) {
    u8 *g = *(u8 **)0x70039c;
    u8 *obj = *(u8 **)(g + 0x1aa3);
    u32 r = vcall<u32>(obj, 0x94);
    *(u32 *)(self + 0x28d) = r;
    if (r)
      ext_641b60((void *)r, *(u32 *)(self + 0x291));
    *(u32 *)(self + 0x291) = 0;
  }
  if (flags & 1)
    ext_634273(self, 0x296);
  return self;
}
PCREG(645250, dtor645250);
