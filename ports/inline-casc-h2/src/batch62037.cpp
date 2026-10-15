#include "ff.h"

static u32 THISCALL fn4d0630(u8 *self) {
  u32 count = *(u32 *)(self + 0x1c4);
  if (count) {
    count--;
    *(u32 *)(self + 0x1c4) = count;
    return *(u32 *)(self + 0x34 + count * 4);
  }
  u32 i = *(u32 *)(self + 0x12130);
  u32 j = *(u32 *)(self + 0xd628);
  u32 left = *(u32 *)(self + 0x11530 + i * 4);
  u32 right = *(u32 *)(self + 0xc628 + j * 4);
  *(u32 *)(self + 0x12130) = i + 1;
  *(u32 *)(self + 0xd628) = j + 1;
  u8 *entry = (u8 *)right;
  *(u32 *)(entry + 0xc) = left;
  vcall<void>(self + 0x1ea, 0, right);
  return left;
}

PCREG(4d0630, fn4d0630);
