// batch8825.cpp - wire-hit-parts (2026-10-15): ZCollisionBox::GetStrips (0x4ea300, GC 8021a090 by structure, name [low]).
#include "ff.h"

typedef u8 (THISCALL *vGetStrips)(void *self, u32 *count, u32 buf, u32 size, float *mat, float *pos, float *half, u32 mask, u32 tree);
typedef void *(THISCALL *vLog)(void *self, const char *file, u32 line);
typedef void (*vMsg)(void *self, const char *fmt, u32 arg);

// 0x4ea300 ZCollisionBox::GetStrips(u32 mask) (thiscall, ret 4, al): the collision base [[0x70039c] + 0x1aa3] + 0x1c, slot 0x84
// (GetStripsInsideBox) fills the box's strip buffer: (&count +8, buffer +0xc, buffer size +0x10, matrix +0x18, position +0x3c, half size
// +0x48, mask, 0). False -> "ERROR: Stack buffer size %d too small for amount of strips within box!" (logger [0x700390] slot 0x20 with
// zcollisionbox.cpp line 0x87, then its slot 0x2c with +0x10). Either way +0x14 = 0; returns the call's result.
static u8 THISCALL getStrips(u8 *self, u32 mask) {
  u8 *cb = *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x1c);
  u8 ok = ((vGetStrips)(*(void ***)cb)[0x84 / 4])(cb, (u32 *)(self + 8), *(u32 *)(self + 0xc), *(u32 *)(self + 0x10), (float *)(self + 0x18),
                                                  (float *)(self + 0x3c), (float *)(self + 0x48), mask, 0);
  if (!ok) {
    u8 *lg = G(u8 *, 0x700390);
    void *o = ((vLog)(*(void ***)lg)[0x20 / 4])(lg, (const char *)0x697650, 0x87);
    ((vMsg)(*(void ***)o)[0x2c / 4])(o, (const char *)0x697680, *(u32 *)(self + 0x10));
    *(u32 *)(self + 0x14) = 0;
    return 0;
  }
  *(u32 *)(self + 0x14) = 0;
  return 1;
}
PCREG(4ea300, getStrips);
