// batch44.cpp - walk-tree clean-ish leaf, inline session batch 44 (Haiku, night): 0x4dc290 ZBaseGeom::RequestCustomDraw.
#include "ff.h"

typedef u8(THISCALL *vcallRequestDraw)(void *self);

// 0x4dc290, thiscall, no stack args, result in al. If this+0x54 is null, returns 0. Otherwise the exe tail-jumps to slot 0xd0
// of the vtable of the object at this+0x54; the port calls that slot and returns its result.
static u8 THISCALL requestCustomDraw(u8 *self) {
  void *obj = *(void **)(self + 0x54);
  if (obj == 0)
    return 0;
  void **vt = *(void ***)obj;
  return ((vcallRequestDraw)vt[0xd0 / 4])(obj);
}
PCREG(4dc290, requestCustomDraw);
