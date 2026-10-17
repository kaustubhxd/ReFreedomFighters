// batch932.cpp - unclaimed-09 batch 24: ZFFItemBomb::Load(ZLoadGame*) (core list, residue 10/11; docs/20-unclaimed-09.md,
// claim 26). thiscall, one stack argument (the loader), ret 4, returns true in al. All calls are unverified callees.
#include "ff.h"

typedef void(THISCALL *LoadPtr)(u8 *self, u32 *p);    // loader vt+0x40, vt+0x50, vt+0x68
typedef u32(THISCALL *MgrGet)(u8 *self, u32 a);        // manager vt+0x58 (global+0x9b)
typedef u8 *(THISCALL *GetObj)(u8 *self);              // manager vt+0x138
typedef void(THISCALL *Call2)(u8 *self, u32 a, u32 b); // R vt+0x4c

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x5d4770, ZFFItemBomb::Load(ZLoadGame*) (list name): loads through the argument slot (a local here, starting as the
// loader pointer, as the original's slot does); stores the manager's answers at this+0x48, +0x63 and +0x6b; loads fields
// at this+0x56, +0x5a, +0x5b; loads a local and passes it with 0x6b52cc to the object from the manager's vt+0x138.
static u8 THISCALL itemBombLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= ~0x40u;
  u32 arg = (u32)ld;
  ((LoadPtr)slot(ld, 0x40))(ld, &arg);
  u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x48) = ((MgrGet)slot(m, 0x58))(m, arg);
  ((LoadPtr)slot(ld, 0x40))(ld, (u32 *)(self + 0x56));
  ((LoadPtr)slot(ld, 0x68))(ld, (u32 *)(self + 0x5a));
  ((LoadPtr)slot(ld, 0x50))(ld, (u32 *)(self + 0x5b));
  ((LoadPtr)slot(ld, 0x40))(ld, &arg);
  m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x63) = ((MgrGet)slot(m, 0x58))(m, arg);
  ((LoadPtr)slot(ld, 0x40))(ld, &arg);
  m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x6b) = ((MgrGet)slot(m, 0x58))(m, arg);
  u32 loc = 0;
  ((LoadPtr)slot(ld, 0x40))(ld, &loc);
  m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r = ((GetObj)slot(m, 0x138))(m);
  ((Call2)slot(r, 0x4c))(r, 0x6b52cc, loc);
  return 1;
}
PCREG(5d4770, itemBombLoad);
