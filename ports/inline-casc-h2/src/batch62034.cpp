#include "ff.h"

extern "C" void THISCALL ext_4d9430(u8 *node);
extern "C" void ext_4d9590(u32 node);
extern "C" u32 THISCALL ext_45c3e0(u8 *self);

static u32 THISCALL fn43ea20(u8 *self) {
  u32 head = *(u32 *)(self + 0x50);
  *(u32 *)self = 0x67c8f8;
  if (head) {
    while ((head = *(u32 *)(self + 0x50)) != 0) {
      ext_4d9430((u8 *)head);
      ext_4d9590(head);
    }
  }
  u8 *child = *(u8 **)(self + 0x44);
  if (child) {
    vcall<void>(child, 0, 1u);
    *(u32 *)(self + 0x44) = 0;
  }
  return ext_45c3e0(self);
}

PCREG(43ea20, fn43ea20);
