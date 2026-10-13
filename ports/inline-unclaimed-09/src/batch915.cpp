// batch915.cpp - unclaimed-09 batch 7: ZActionControlMap::End() (docs/20-unclaimed-09.md, claim 7).
// thiscall, no arguments, plain ret. Virtual calls are unverified callees, stubbed in the spec.
#include "ff.h"

typedef u8 *(THISCALL *MapGetPtr)(u8 *self);                      // vt+0x134 of global+0x9b, returns an object
typedef void(THISCALL *MapFlagCall)(u8 *self, u32 a, u8 *flag);   // vt+0x90 of that object
typedef void(THISCALL *MapCall14)(u8 *self, u32 a);               // vt+0x14 of the object at global+0x1907

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x5b2c80, ZActionControlMap::End() (medium): gets the object r from global+0x9b, asks r for a flag byte, then
// calls vt+0x14 on the object at global+0x1907 with 0x6b2028 and reloads it and calls with 0x6b2004 when the flag is
// set; when clear, calls with 0x69c690. A null object is skipped.
static void THISCALL actionMapEnd(u8 *self) {
  u8 *g = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(g + 0x9b);
  u8 *r = ((MapGetPtr)slot(o, 0x134))(o);
  u8 flag = 0;
  ((MapFlagCall)slot(r, 0x90))(r, 0x68a9d4, &flag);
  u8 *a = *(u8 **)(g + 0x1907);
  if (flag) {
    if (a) ((MapCall14)slot(a, 0x14))(a, 0x6b2028);
    u8 *b = *(u8 **)(G(u8 *, 0x70039c) + 0x1907);
    if (b) ((MapCall14)slot(b, 0x14))(b, 0x6b2004);
  } else {
    if (a) ((MapCall14)slot(a, 0x14))(a, 0x69c690);
  }
}
PCREG(5b2c80, actionMapEnd);
