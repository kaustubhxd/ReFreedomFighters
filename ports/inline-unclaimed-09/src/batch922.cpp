// batch922.cpp - unclaimed-09 batch 14: CCheckInsideBox::Load(ZLoadGame*) (docs/20-unclaimed-09.md, claim 14).
// thiscall, one stack argument (the loader), ret 4, returns true in al. Loader and manager calls are unverified callees.
#include "ff.h"

typedef void(THISCALL *LoadDword)(u8 *self, u32 *p);     // loader vt+0x40
typedef u32(THISCALL *MgrGet)(u8 *self, u32 a);          // manager vt+0x58 (global+0x9b)

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x5b8180, CCheckInsideBox::Load(ZLoadGame*) (high): clears bit 6 of this+4; loads this+0x48 and this+0x4c; loads the
// argument slot (here a local, p, which starts as the loader pointer, as the argument slot does), passes it to the
// manager and stores the result at this+0x50; loads p again, stores the manager's result at this+0x54; loads this+0x5c.
static u8 THISCALL checkInsideBoxLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((LoadDword)slot(ld, 0x40))(ld, (u32 *)(self + 0x48));
  ((LoadDword)slot(ld, 0x40))(ld, (u32 *)(self + 0x4c));
  u32 p = (u32)ld;
  ((LoadDword)slot(ld, 0x40))(ld, &p);
  u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x50) = ((MgrGet)slot(m, 0x58))(m, p);
  ((LoadDword)slot(ld, 0x40))(ld, &p);
  m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x54) = ((MgrGet)slot(m, 0x58))(m, p);
  ((LoadDword)slot(ld, 0x40))(ld, (u32 *)(self + 0x5c));
  return 1;
}
PCREG(5b8180, checkInsideBoxLoad);
