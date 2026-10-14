// batch928.cpp - unclaimed-09 batch 20: CCheckVisible::Load(ZLoadGame*) (core-todo residue-10 fallback; docs/20-unclaimed-09.md
// claim 22). thiscall, one stack argument (the loader), ret 4, returns true in al. Loader calls are unverified callees.
#include "ff.h"

typedef void(THISCALL *LoadArr)(u8 *self, u8 *p, u32 n);   // loader vt+0x18: array of n bytes at p
typedef void(THISCALL *LoadPtr)(u8 *self, u8 *p);          // loader vt+0x40 (dword) and vt+0x50

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4aace0, CCheckVisible::Load(ZLoadGame*) (list name): clears bit 6 of this+4; loads this+0x54 (640 bytes) and this+0x694
// (0x157c0 bytes) through vt+0x18; loads dwords at this+0x15e54 and this+0x15e58 through vt+0x40, and this+0x15e78
// through vt+0x50; returns true.
static u8 THISCALL checkVisibleLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= ~0x40u;
  ((LoadArr)slot(ld, 0x18))(ld, self + 0x54, 0x640);
  ((LoadArr)slot(ld, 0x18))(ld, self + 0x694, 0x157c0);
  ((LoadPtr)slot(ld, 0x40))(ld, self + 0x15e54);
  ((LoadPtr)slot(ld, 0x40))(ld, self + 0x15e58);
  ((LoadPtr)slot(ld, 0x50))(ld, self + 0x15e78);
  return 1;
}
PCREG(4aace0, checkVisibleLoad);
