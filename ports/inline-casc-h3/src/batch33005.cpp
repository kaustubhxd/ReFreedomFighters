// batch33005.cpp - cascade h3: three small 2-instruction functions
#include "ff.h"

// 0x50d810: return constant
static u32 THISCALL fn50d810(u8 *self) {
  return 0x69c77c;
}
PCREG(50d810, fn50d810);

// 0x533b40: read byte member at offset 0x50a9
static u8 THISCALL fn533b40(u8 *self) {
  return self[0x50a9];
}
PCREG(533b40, fn533b40);

// 0x5422a0: set dword at offset 0 (vtable write)
static void THISCALL fn5422a0(u8 *self) {
  *(u32 *)self = 0x6a2e08;
}
PCREG(5422a0, fn5422a0);
