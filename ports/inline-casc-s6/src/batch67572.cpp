// batch67572.cpp - cascade s6 batch 67572: 0x590140.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x590140, thiscall(id) ret 4, return value unused: switches the current target. The new target is the object named by id (object table slot 0x58), the old one comes from this slot 0x504, the
// default one from this[0x842]. A change of target first closes the old one (slot 0x2d0(0, 0); when its slot 0x2e8 helper's slot 0x308 reports 1 this slot 0x3d8(this slot 0x3ec(0x17)) runs, else
// this slot 0x45c(6, 0)). The new handle (table slot 0x4c(old)) is stored in this[0x83a]; a non-null new target then runs this slot 0x3d8(this slot 0x3ec(0x18)) when it is the default one, else
// this slot 0x45c(8, id).
static void THISCALL fn590140(u8 *self, u32 id) {
  u8 *tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u8 *neu = vcall<u8 *>(tab, 0x58, id);
  u8 *old = vcall<u8 *>(self, 0x504);
  tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  u8 *def = vcall<u8 *>(tab, 0x58, D32(self, 0x842));
  if (neu == old) return;
  if (old) {
    vcall<void>(old, 0x2d0, 0u, 0u);
    u8 *h = vcall<u8 *>(old, 0x2e8);
    if (vcall<u32>(h, 0x308) == 1) {
      u32 y = vcall<u32>(self, 0x3ec, 0x17u);
      vcall<void>(self, 0x3d8, y);
    } else {
      vcall<void>(self, 0x45c, 6u, 0u);
    }
  }
  tab = *(u8 **)(*(u8 **)0x70039c + 0x9b);
  D32(self, 0x83a) = vcall<u32>(tab, 0x4c, (u32)old);
  if (!neu) return;
  if (neu == def) {
    u32 y = vcall<u32>(self, 0x3ec, 0x18u);
    vcall<void>(self, 0x3d8, y);
    return;
  }
  vcall<void>(self, 0x45c, 8u, id);
}
PCREG(590140, fn590140);
