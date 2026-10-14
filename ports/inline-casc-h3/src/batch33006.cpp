// batch33006.cpp - cascade h3: three small 2-instruction thiscall functions
#include "ff.h"

// 0x59b340: lea - return self + 0x121a8
static u8 *THISCALL fn59b340(u8 *self) {
  return self + 0x121a8;
}
PCREG(59b340, fn59b340);

// 0x59ca40: lea - return self + 0x1210c
static u8 *THISCALL fn59ca40(u8 *self) {
  return self + 0x1210c;
}
PCREG(59ca40, fn59ca40);

// 0x600800: read dword member at offset 0x98
static u32 THISCALL fn600800(u8 *self) {
  return *(u32 *)(self + 0x98);
}
PCREG(600800, fn600800);
