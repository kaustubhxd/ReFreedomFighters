// batch2434.cpp - decomp area 24, batch 2434.
#include "ff.h"

// 0x651330 ZRender::UPlotFNxt(const char*), cdecl: the count at +0x78 is bumped; slot 0x124 is called with (this, 0, old
// count, name) as four stack arguments (the caller pops them).
static void cdeclUPlotFNxt(u8 *self, const char *name) {
  u32 cnt = *(u32 *)(self + 0x78);
  *(u32 *)(self + 0x78) = cnt + 1;
  typedef void (*fn)(u8 *, u32, u32, const char *);
  fn f = *(fn *)(*(u8 **)self + 0x124);
  f(self, 0u, cnt, name);
}
PCREG(651330, cdeclUPlotFNxt);

// 0x4360f0 (GUESS owner), thiscall, ret 4, AL. Element lookup at +0x20 (count at +0x60); slot 0x34 of a set element.
static u32 THISCALL indexedSlot34(u8 *self, u32 idx) {
  if (idx < *(u32 *)(self + 0x60)) {
    u8 *el = *(u8 **)(self + 0x20 + 4 * idx);
    if (el)
      return vcall<u32>(el, 0x34);
  }
  return 0;
}
PCREG(4360f0, indexedSlot34);

// 0x436230 ZSysInput::StopAllGCEffects(int), thiscall, ret 4, AL. Slot 0x40 of the element; AL = 1 when called.
static u8 THISCALL sysInputStopAllGCEffects(u8 *self, u32 idx) {
  if (idx < *(u32 *)(self + 0x60)) {
    u8 *el = *(u8 **)(self + 0x20 + 4 * idx);
    if (el) {
      vcall<void>(el, 0x40);
      return 1;
    }
  }
  return 0;
}
PCREG(436230, sysInputStopAllGCEffects);
