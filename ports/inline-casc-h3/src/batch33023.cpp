// batch33023.cpp - h3 batch 33023: field copiers
#include "ff.h"

// 0x445fc0, thiscall: copy 4 dwords from this at 0x171/0x175/0x179/0x17d to destination at 0/4/8/c, ret 4
static void THISCALL fn445fc0(u8 *self, u8 *dst) {
  *(u32 *)(dst + 0) = *(u32 *)(self + 0x171);
  *(u32 *)(dst + 4) = *(u32 *)(self + 0x175);
  *(u32 *)(dst + 8) = *(u32 *)(self + 0x179);
  *(u32 *)(dst + 0xc) = *(u32 *)(self + 0x17d);
}
PCREG(445fc0, fn445fc0);
