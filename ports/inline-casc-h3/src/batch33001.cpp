// batch33001.cpp - cascade h3: four small 2-instruction read-only thiscall members
#include "ff.h"

// 0x46e570: read byte member at offset 0xbf
static u8 THISCALL fn46e570(u8 *self) {
  return self[0xbf];
}
PCREG(46e570, fn46e570);

// 0x46e6a0: read dword member at offset 0xa4
static u32 THISCALL fn46e6a0(u8 *self) {
  return *(u32 *)(self + 0xa4);
}
PCREG(46e6a0, fn46e6a0);

// 0x46e710: return constant
static u32 THISCALL fn46e710(u8 *self) {
  return 0x6864f8;
}
PCREG(46e710, fn46e710);

// 0x46e7f0: read dword member at offset 0x60
static u32 THISCALL fn46e7f0(u8 *self) {
  return *(u32 *)(self + 0x60);
}
PCREG(46e7f0, fn46e7f0);
