// batch1137.cpp - collision thread, batch 1137 (hard-row lane, mid-size row, name GUESS): 0x5b9100. Clears bit 0x40 of
// [this+4], then makes 23 virtual calls on the argument object, each with a field of this (dwords, floats, one byte each, or
// the address of a field): slots 0x3c, 0x6c, 0x3c, 0x3c, 0x4c, 0x4c, 0x64, 0x64, 0x64, 0x68, 0x68, 0x68, 0x4c, 0x60, 0x4c,
// 0x70, 0x64, 0x3c, 0x64, 0x64, 0x68, 0x60. Returns true.
#include "ff.h"

// 0x5b9100 (name GUESS): thiscall (ECX = this), one stack argument o, ret 4.
static u8 THISCALL serialize5b9100(u8 *self, u8 *o) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x48));
  vcall<void>(o, 0x6c, *(u32 *)(self + 0x4c));
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x50));
  vcall<void>(o, 0x3c, *(u32 *)(self + 0x54));
  vcall<void>(o, 0x4c, *(float *)(self + 0x58));
  vcall<void>(o, 0x4c, *(float *)(self + 0x5c));
  vcall<void>(o, 0x64, *(u32 *)(self + 0x7e));
  vcall<void>(o, 0x64, *(u32 *)(self + 0x82));
  vcall<void>(o, 0x64, *(u32 *)(self + 0x86));
  vcall<void>(o, 0x68, (u32)(self + 0x8a));
  vcall<void>(o, 0x68, (u32)(self + 0x96));
  vcall<void>(o, 0x68, (u32)(self + 0xa2));
  vcall<void>(o, 0x4c, *(float *)(self + 0xae));
  vcall<void>(o, 0x60, (u32)self[0xb2]);
  vcall<void>(o, 0x4c, *(float *)(self + 0xb3));
  vcall<void>(o, 0x70, (u32)(self + 0xb7));
  vcall<void>(o, 0x64, *(u32 *)(self + 0xe2));
  vcall<void>(o, 0x3c, *(u32 *)(self + 0xde));
  vcall<void>(o, 0x64, *(u32 *)(self + 0xe2));
  vcall<void>(o, 0x64, *(u32 *)(self + 0xe6));
  vcall<void>(o, 0x68, (u32)(self + 0xea));
  vcall<void>(o, 0x60, (u32)self[0xdd]);
  return 1;
}
PCREG(5b9100, serialize5b9100);
