// batch990.cpp - area 56 claim A57 (0x4e5330, ZAnimFilePack::GetAnimFileName): a pointer selector with no calls.
#include "ff.h"

// A57 0x4e5330: p = this->4; m = p->4 & 0xC0000000; off = (m is 0x40000000, 0x80000000 or 0xC0000000) ? p->8 : 8; return p + off.
static u8 *THISCALL getAnimFileName4e5330(u8 *self) {
  u8 *p = *(u8 **)(self + 4);
  u32 m = *(u32 *)(p + 4) & 0xC0000000u;
  u32 off = 8;
  if (m == 0x40000000u || m == 0x80000000u || m == 0xC0000000u) off = *(u32 *)(p + 8);
  return p + off;
}
PCREG(4e5330, getAnimFileName4e5330);
