#include "ff.h"
// batch2707.cpp - unclaimed-27 claim 7 (docs/20-unclaimed-27.md). Name from the GC name map (medium).

// 0x4daff0 is a lookup (original code in the exe). In the spec it is replaced by a hook that returns a chosen object, and
// the port calls the same address, so both sides see the same result. Thiscall-like: the argument is passed in ecx, no
// stack arguments, returns eax.
extern "C" u8 *THISCALL ext_4daff0(u8 *arg);

// 0x4da720, ZBaseGeom::DetachFromDynamicContainer(ZGROUP*) (medium). Thiscall, ret 4.
// Returns unless this+0x64 and the byte at this+0x3c are nonzero. The argument's container is found as: the argument itself
// if it is nonzero, else the object at this+0x50 (its +0x54 object); the lookup key is the dword at that object's +8, passed
// to 0x4daff0. If the lookup gives an object, calls its vtable slot +0x320 with this, then clears this+0x64.
static void THISCALL zBaseGeomDetachFromDynamicContainer(u8 *self, u8 *grp) {
  typedef void(THISCALL * slot320_fn)(u8 *, u8 *);
  if (*(u32 *)(self + 0x64) == 0) return;
  if (self[0x3c] == 0) return;

  u8 *c = grp;
  if (c == 0) {
    c = *(u8 **)(self + 0x50);
    if (c != 0) c = *(u8 **)(c + 0x54);
  }
  u8 *obj = ext_4daff0(*(u8 **)(c + 8));
  if (obj == 0) return;
  ((slot320_fn)(*(u32 *)(*(u32 *)obj + 0x320)))(obj, self);
  *(u32 *)(self + 0x64) = 0;
}
PCREG(4da720, zBaseGeomDetachFromDynamicContainer);
