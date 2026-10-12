// batch690.cpp - unclaimed-68 batch 10 (claim 9). Names from the GC name map; GUESS where marked.
#include "ff.h"

typedef u8 *(THISCALL *VSlot4c)(u8 *self, float f);
typedef void(THISCALL *VSlot3c)(u8 *self, u32 v);

// 0x45dc30, ZGEOM::DispBound(bool) (high): thiscall, ret 4. With the flag set: bit 2 of this+0x14 stays if already set,
// otherwise bits 0 and 2 are set. With the flag clear: bit 2 is cleared when set. Stores only when the value changes.
static void THISCALL zgeomDispBound(u8 *self, u32 flag) {
  u32 v = *(u32 *)(self + 0x14);
  if ((u8)flag) {
    if (v & 4) return;
    v |= 5;
  } else {
    if (!(v & 4)) return;
    v &= ~4u;
  }
  *(u32 *)(self + 0x14) = v;
}
PCREG(45dc30, zgeomDispBound);

// 0x5deaf0 (GUESS FUN_5deaf0): x = obj->slot +0x4c (this's float); x->slot +0x3c (this+4). Thiscall, ret 4.
static void THISCALL guessFun5deaf0(u8 *self, u8 *obj) {
  float f = *(float *)self;
  u8 *x = ((VSlot4c)*(u32 *)(*(u8 **)obj + 0x4c))(obj, f);
  ((VSlot3c)*(u32 *)(*(u8 **)x + 0x3c))(x, *(u32 *)(self + 4));
}
PCREG(5deaf0, guessFun5deaf0);
