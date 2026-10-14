// batch35046.cpp - cascade s5 batch 35046: 0x5b2bd0 (GUESS dispatch an input id to the matching action of a control state).
#include "ff.h"

extern "C" void THISCALL ext_5b5420(u8 *self);                // plain ret
extern "C" void THISCALL ext_5b5370(u8 *self, u32 a);         // ret 4

// 0x5b2bd0, thiscall(id, p) ret 8, always returns 0. Only the low word of id is compared, in order, with the words at +0x240, +0x242, +0x244, +0x246, +0x24a, +0x24c, +0x24e:
// +0x240: byte +0x4c = 1; +0x242: when p is set byte +0x55 = (p[0] != 0); +0x244: the same for byte +0x56; +0x246: 0x5b5420(this); +0x24a: 0x5b5370(this, 0); +0x24c: 0x5b5370(this, 4);
// +0x24e: byte +0x1b2 = 0.
static u32 THISCALL fn5b2bd0(u8 *self, u32 id, u32 *p) {
  u16 w = (u16)id;
  if (w == *(u16 *)(self + 0x240)) {
    self[0x4c] = 1;
    return 0;
  }
  if (w == *(u16 *)(self + 0x242)) {
    if (p) self[0x55] = *p != 0;
    return 0;
  }
  if (w == *(u16 *)(self + 0x244)) {
    if (p) self[0x56] = *p != 0;
    return 0;
  }
  if (w == *(u16 *)(self + 0x246)) {
    ext_5b5420(self);
    return 0;
  }
  if (w == *(u16 *)(self + 0x24a)) {
    ext_5b5370(self, 0);
    return 0;
  }
  if (w == *(u16 *)(self + 0x24c)) {
    ext_5b5370(self, 4);
    return 0;
  }
  if (w == *(u16 *)(self + 0x24e)) self[0x1b2] = 0;
  return 0;
}
PCREG(5b2bd0, fn5b2bd0);
