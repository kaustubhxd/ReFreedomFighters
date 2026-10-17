// batch33012.cpp - cascade h3 tier B: three thunks and one complex read/write/subtract
#include "ff.h"

extern "C" void THISCALL ext_584bc0(u8 *self);
extern "C" void THISCALL ext_5c1dc0(u8 *self);

// 0x563500: read global, copy from +0x6c to +0x70
static void THISCALL fn563500(u8 *self) {
  u8 *global = *(u8 **)0x7003a0;
  *(u32 *)(global + 0x70) = *(u32 *)(global + 0x6c);
}
PCREG(563500, fn563500);

// 0x5827a0: thunk wrapper
static void THISCALL fn5827a0(u8 *self) {
  ext_584bc0(self);
}
PCREG(5827a0, fn5827a0);

// 0x5c1640: thunk wrapper
static void THISCALL fn5c1640(u8 *self) {
  ext_5c1dc0(self);
}
PCREG(5c1640, fn5c1640);

// 0x65f5d0: read ecx[0xc], then ecx[0x10069] - ecx[0x10061]
static u32 THISCALL fn65f5d0(u8 *self) {
  u8 *ptr = *(u8 **)(self + 0xc);
  u32 a = *(u32 *)(ptr + 0x10069);
  u32 b = *(u32 *)(ptr + 0x10061);
  return a - b;
}
PCREG(65f5d0, fn65f5d0);
