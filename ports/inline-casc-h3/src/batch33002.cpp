// batch33002.cpp - cascade h3: four small 2-instruction thiscall functions
#include "ff.h"

// 0x46eda0: read dword member at offset 0xba
static u32 THISCALL fn46eda0(u8 *self) {
  return *(u32 *)(self + 0xba);
}
PCREG(46eda0, fn46eda0);

// 0x46eee0: read dword member at offset 0x70
static u32 THISCALL fn46eee0(u8 *self) {
  return *(u32 *)(self + 0x70);
}
PCREG(46eee0, fn46eee0);
