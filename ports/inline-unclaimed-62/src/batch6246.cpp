// batch6246 - ragdoll side (claim 39): ZBoneModifyBase::ZBoneModifyBase(unsigned int) [0x645120; thiscall, one stack argument, ret 4, returns this].
// this[0] = vtable 0x6c28a4; the dword at this+5 is set to 0 and then to 0xfffffc00 (the exe compares the address this+5 with the address of a
// local and writes the second value unless they are equal, which they never are); this+0x69, +0x26d, +0x251, +0x65, +0x22d, +0x24d, +0x23d,
// +0x271, +0x241, +0x245, +0x249, +0x281, +0x285, +0x289, +0x291 = 0; this+9 = 0; this+0xd = -1; this+0x268 = -1; this+0x255 = 0x3d4ccccd;
// this+4 byte = 0, this+0x266 byte = 0, this+0x295 byte = 0; this+0x11 = the argument; this+0x275, +0x279, +0x27d = 0x3f800000;
// this+0x28d = the result of the engine's object at eng+0x1aa3, slot 0x94 (no argument).
#include "ff.h"

static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static u8 *THISCALL fn645120(u8 *self, u32 a) {
  wr32u(self, 0x6c28a4);
  u32 local = 0;
  wr32u(self + 5, 0);
  wr32u(self + 0x69, 0);
  wr32u(self + 0x26d, 0);
  wr32u(self + 0x268, 0xffffffffu);
  if ((u32)(self + 5) != (u32)&local) wr32u(self + 5, 0xfffffc00u);
  wr32u(self + 9, 0);
  wr32u(self + 0xd, 0xffffffffu);
  wr32u(self + 0x251, 0);
  wr32u(self + 0x255, 0x3d4ccccdu);
  self[4] = 0;
  wr32u(self + 0x65, 0);
  wr32u(self + 0x11, a);
  self[0x295] = 0;
  wr32u(self + 0x22d, 0);
  wr32u(self + 0x24d, 0);
  wr32u(self + 0x23d, 0);
  wr32u(self + 0x271, 0);
  self[0x266] = 0;
  wr32u(self + 0x241, 0);
  wr32u(self + 0x245, 0);
  wr32u(self + 0x249, 0);
  wr32u(self + 0x275, 0x3f800000u);
  wr32u(self + 0x279, 0x3f800000u);
  wr32u(self + 0x27d, 0x3f800000u);
  wr32u(self + 0x281, 0);
  wr32u(self + 0x285, 0);
  wr32u(self + 0x289, 0);
  wr32u(self + 0x291, 0);
  u8 *obj = rdp(G(u8 *, 0x70039c) + 0x1aa3);
  wr32u(self + 0x28d, vcall<u32>(obj, 0x94));
  return self;
}

PCREG(645120, fn645120);
