// batch1682.cpp - three one-line forwarders with a virtual tail jump (residue 13 gap band, 2026-10-12). Each calls a
// ZBaseGeom thunk (0x45fc70 SetMat, 0x45fc80 SetMatPos, 0x45fd20 SetPos; hooked by address, each a tail jump to the
// ZBaseGeom method with ret 4, 8, 4), then asks the manager's slot 0x58 for the object at this+0x18 and, when it is set,
// tail-jumps into that object's virtual slot (0x6c, 0x74, 0x70) with the same stack arguments.
// 0x47fa50 (GUESS): SetMat(a); r = mgr.0x58(this+0x18); r ? r.vslot(0x6c)(a) : r. Ret 4.
// 0x47fa90 (GUESS): SetMatPos(a, b); r = ...; r ? r.vslot(0x74)(a, b) : r. Ret 8.
// 0x47fad0 (GUESS): SetPos(a); r = ...; r ? r.vslot(0x70)(a) : r. Ret 4.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern "C" char ext_45fc70[], ext_45fc80[], ext_45fd20[];
typedef void(THISCALL *Set1)(void *self, u32 a);
typedef void(THISCALL *Set2)(void *self, u32 a, u32 b);

static u32 MgrObj(u8 *self) {
  u8 *mgr = AT(u8 *, AT(u8 *, 0x70039c, 0), 0x9b);
  return vcall<u32>(mgr, 0x58, AT(u32, self, 0x18));
}

u32 THISCALL GUESS_47fa50(u8 *self, u32 a) {
  ((Set1)(void *)ext_45fc70)(self, a);
  u32 r = MgrObj(self);
  if (!r) return r;
  return vcall<u32>((void *)r, 0x6c, a);
}
PCREG(47fa50, GUESS_47fa50);

u32 THISCALL GUESS_47fa90(u8 *self, u32 a, u32 b) {
  ((Set2)(void *)ext_45fc80)(self, a, b);
  u32 r = MgrObj(self);
  if (!r) return r;
  return vcall<u32>((void *)r, 0x74, a, b);
}
PCREG(47fa90, GUESS_47fa90);

u32 THISCALL GUESS_47fad0(u8 *self, u32 a) {
  ((Set1)(void *)ext_45fd20)(self, a);
  u32 r = MgrObj(self);
  if (!r) return r;
  return vcall<u32>((void *)r, 0x70, a);
}
PCREG(47fad0, GUESS_47fad0);
