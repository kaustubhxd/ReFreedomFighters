// batch3510.cpp - area 73 batch 10 (slice 6 leaf): ZRender::UnlockDrawBaseGeomsBuffer() (high, 0x651360).
#include "ff.h"

// 0x651360, ZRender::UnlockDrawBaseGeomsBuffer() (high), thiscall, plain ret: calls slot +0x24 on the object at this+0xbd with
// the dword at this+0x1f (first argument) and the dword at this+0x23 (second); then this+0x1f = 0.
static void THISCALL renderUnlockDrawBaseGeomsBuffer(u8 *self) {
  u32 a = *(u32 *)(self + 0x1f);
  u32 b = *(u32 *)(self + 0x23);
  vcall<void>(*(void **)(self + 0xbd), 0x24, a, b);
  *(u32 *)(self + 0x1f) = 0;
}
PCREG(651360, renderUnlockDrawBaseGeomsBuffer);
