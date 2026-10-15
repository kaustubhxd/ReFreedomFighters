#include "ff.h"

extern "C" void THISCALL ext_514480(u8 *self, u32 value);

// 0x51cfb0: validate the value through slot 0x310, save or clear it, then
// update the embedded selection helper when a nonzero value was accepted.
static void THISCALL fn51cfb0(u8 *self, u32 value) {
  u32 accepted = vcall<u32>(self, 0x310, value);
  u32 selected = (accepted & 0xff) ? value : 0;
  *(u32 *)(self + 0x3fd) = selected;
  if (selected) ext_514480(self + 0x59b, selected);
}

PCREG(51cfb0, fn51cfb0);
