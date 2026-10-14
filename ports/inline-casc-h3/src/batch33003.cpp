// batch33003.cpp - cascade h3: four small 2-instruction thiscall accessors
#include "ff.h"

// 0x474310: read byte member at offset 0x3bb
static u8 THISCALL fn474310(u8 *self) {
  return self[0x3bb];
}
PCREG(474310, fn474310);

// 0x4743e0: read dword member at offset 0x2e3
static u32 THISCALL fn4743e0(u8 *self) {
  return *(u32 *)(self + 0x2e3);
}
PCREG(4743e0, fn4743e0);

// 0x4744b0: read dword member at offset 0x3b7
static u32 THISCALL fn4744b0(u8 *self) {
  return *(u32 *)(self + 0x3b7);
}
PCREG(4744b0, fn4744b0);

// 0x4808c0: read dword from global address 0x6e5ef8
static u32 THISCALL fn4808c0(u8 *self) {
  return *(u32 *)0x6e5ef8;
}
PCREG(4808c0, fn4808c0);
