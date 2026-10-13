// batch1060.cpp - area 81, batch 1060: 0x54cb80, initializer thiscall
// Sets vtable, zeros fields, initializes values. No exe calls.
#include "ff.h"

static void * THISCALL batch1060_init(u8 *self) {
  *(u32 *)(self + 0x0) = 0x6a3e14;
  *(u32 *)(self + 0x4) = 0;
  *(u32 *)(self + 0x804d) = 0;
  *(u32 *)(self + 0x8051) = 0;
  *(u32 *)(self + 0x8049) = 0;
  *(u32 *)(self + 0x8065) = 0;
  *(u32 *)(self + 0x8061) = 0;
  *(u32 *)(self + 0x802d) = 0;
  *(u32 *)(self + 0x8031) = 0;
  *(u32 *)(self + 0x8025) = 0;
  *(u32 *)(self + 0x801d) = 0;
  *(u8 *)(self + 0x801c) = 0;
  *(u32 *)(self + 0x8014) = 0;
  *(u32 *)(self + 0x8018) = 0;
  *(u32 *)(self + 0x805d) = 0x10;
  *(u32 *)(self + 0x8029) = 0x10;
  *(u32 *)(self + 0x8035) = 0;
  *(u32 *)(self + 0x8021) = 0x711d28;
  *(u32 *)0x711d28 = 0x10000;
  *(u32 *)0x711d2c = 8;
  return self;
}

PCREG(54cb80, batch1060_init);
