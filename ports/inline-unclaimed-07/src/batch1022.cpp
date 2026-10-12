// batch1022.cpp - unclaimed-07 batch 22 (slice 6, small leaf): ZLINEOBJ::SetWidth(int) (high, 0x4f4760).
#include "ff.h"

// 0x4f4760, ZLINEOBJ::SetWidth(int) (high), thiscall, ret 4: stores the argument at this+0xb0; when this+0xac is non-zero,
// calls vtable slot +0x294 (no arguments).
static void THISCALL lineObjSetWidth(u8 *self, u32 width) {
  *(u32 *)(self + 0xb0) = width;
  if (*(u32 *)(self + 0xac))
    vcall<void>(self, 0x294);
}
PCREG(4f4760, lineObjSetWidth);
