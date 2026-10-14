// batch33020.cpp - h3 batch 33020: field initializers
#include "ff.h"

// 0x524660, thiscall: clear and initialize multiple fields with constants
static void THISCALL fn524660(u8 *self) {
  *(u32 *)(self + 0) = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0xc) = 0x46c35000;
  *(u32 *)(self + 0x10) = 0x44fa0000;
  *(u32 *)(self + 0x14) = 0x42a00000;
}
PCREG(524660, fn524660);

// 0x471640, thiscall: copy 3 dwords from stack arg to this at offsets 0xaa, 0xae, 0xb2, ret 4
static void THISCALL fn471640(u8 *self, u8 *src) {
  *(u32 *)(self + 0xaa) = *(u32 *)(src + 0);
  *(u32 *)(self + 0xae) = *(u32 *)(src + 4);
  *(u32 *)(self + 0xb2) = *(u32 *)(src + 8);
}
PCREG(471640, fn471640);
