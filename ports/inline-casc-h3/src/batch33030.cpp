// batch33030.cpp - h3 batch 33030: field initialization with float constants
#include "ff.h"

// 0x609a70, thiscall: initialize many fields to 0, four fields to float constant 0x3f800000
static u8 *THISCALL fn609a70(u8 *self) {
  *(u32 *)(self + 0x04) = 0;
  *(u32 *)(self + 0x08) = 0;
  *(u32 *)(self + 0x0c) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x2c) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x00) = 0x3f800000;
  *(u32 *)(self + 0x14) = 0x3f800000;
  *(u32 *)(self + 0x28) = 0x3f800000;
  *(u32 *)(self + 0x3c) = 0x3f800000;
  return self;
}
PCREG(609a70, fn609a70);
