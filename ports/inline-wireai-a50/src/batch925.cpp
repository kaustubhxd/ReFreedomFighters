// batch925.cpp - 0x44a650 [thiscall (ECX = this), one stack arg (a stream object), ret 4, returns al]. Body read in full (2026-10-12).
// First the gate 0x45f960 (thiscall: this, stream; verified in batch924, stood in here). If false, return 0.
// If this+0x18 is set: stream slot +0xc (1); r1 = obj(+0x18) slot +0x1c; r2 = obj slot +0x18; stream slot +0x10 on &r1 and on &r2
// (4 bytes each); stream slot +0x20 with obj. Otherwise stream slot +0xc (0).
// Then if this+0x1c is set: stream slot +0xc (1) and slot +0x20 with this+0x1c; otherwise stream slot +0xc (0). Returns 1.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" bool THISCALL ext_45f960(void *self, void *stream);   // stood in here (verified in batch924)

// 0x44a650 (no name in the map).
static bool THISCALL Read44a650(u8 *self, u8 *stream) {
  if (!ext_45f960(self, stream)) return false;
  u8 *obj = (u8 *)FP(self, 0x18);
  if (obj) {
    vcall<void>(stream, 0xc, 1u);
    u32 r1 = vcall<u32>(obj, 0x1c);
    u32 r2 = vcall<u32>(obj, 0x18);
    vcall<void>(stream, 0x10, (void *)&r1, 4u);
    vcall<void>(stream, 0x10, (void *)&r2, 4u);
    vcall<void>(stream, 0x20, (void *)obj);
  } else {
    vcall<void>(stream, 0xc, 0u);
  }
  u8 *obj2 = (u8 *)FP(self, 0x1c);
  if (obj2) {
    vcall<void>(stream, 0xc, 1u);
    vcall<void>(stream, 0x20, (void *)obj2);
  } else {
    vcall<void>(stream, 0xc, 0u);
  }
  return true;
}
PCREG(44a650, Read44a650);
