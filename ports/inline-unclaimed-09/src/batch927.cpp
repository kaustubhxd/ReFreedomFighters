// batch927.cpp - unclaimed-09 batch 19: ZItemAmmo::Load(ZLoadGame*) (core-todo residue-10 fallback; docs/20-unclaimed-09.md,
// claim 21). thiscall, one stack argument (the loader), ret 4. 0x46f520 and the loader's slot 0x48 are unverified callees.
#include "ff.h"

// 0x46f520 (thiscall, one argument; original code, hooked in the spec).
extern "C" u8 THISCALL ext_46f520(u8 *self, u8 *ld);

typedef void(THISCALL *LoadPtr)(u8 *self, u8 *p);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x46f5a0, ZItemAmmo::Load(ZLoadGame*) (list name): loads through 0x46f520; when it reports true, asks the loader for the
// field at this+0x8e (vt+0x48) and returns true; otherwise returns false.
static u8 THISCALL ammoLoad(u8 *self, u8 *ld) {
  if (!ext_46f520(self, ld)) return 0;
  ((LoadPtr)slot(ld, 0x48))(ld, self + 0x8e);
  return 1;
}
PCREG(46f5a0, ammoLoad);
