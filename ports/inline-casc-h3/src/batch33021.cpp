// batch33021.cpp - h3 batch 33021: field readers and writers
#include "ff.h"

// 0x61c5c0, cdecl: take pointer and two values, store values at offsets 0x34 and 0x38
static void fn61c5c0(u8 *dst, u32 val1, u32 val2) {
  *(u32 *)(dst + 0x34) = val1;
  *(u32 *)(dst + 0x38) = val2;
}
PCREG(61c5c0, fn61c5c0);

// 0x591f30, thiscall: read 3 values from this at 0x65d/0x661/0x665, write to destination arg at 0/4/8, ret 4
static void THISCALL fn591f30(u8 *self, u8 *dst) {
  *(u32 *)(dst + 0) = *(u32 *)(self + 0x65d);
  *(u32 *)(dst + 4) = *(u32 *)(self + 0x661);
  *(u32 *)(dst + 8) = *(u32 *)(self + 0x665);
}
PCREG(591f30, fn591f30);
