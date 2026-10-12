// batch683.cpp - unclaimed-68 batch 3 (claim 3). Names from the GC name map (naming only, never committed).
#include "ff.h"

// Virtual slot +0x2c0 on the object: (argument, flags), thiscall, the callee pops its two arguments.
typedef u32(THISCALL *VGroup2c0)(u8 *self, u32 arg, u32 flags);

// 0x4408b0, ZGROUP::FindMasterGeom(const char*) const (high): calls slot +0x2c0 with (name, 2) and returns its EAX (ret 4).
static u32 THISCALL groupFindMasterGeom(const u8 *self, u32 name) {
  return ((VGroup2c0)*(u32 *)(*(u8 **)self + 0x2c0))((u8 *)self, name, 2);
}
PCREG(4408b0, groupFindMasterGeom);
