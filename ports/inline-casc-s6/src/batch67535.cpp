// batch67535.cpp - cascade s6 batch 67535: 0x42d730.
#include "ff.h"

// 0x42d730, thiscall(stream) ret 4, returns the result of the last stream call: serialises the object's fields through the stream object's slots: slot 0xc(2) (mode), then each field address
// (this + offset) to the typed slot 0x5c / 0x58 / 0x50 / 0x40 / 0x48 / 0x68 in the order below.
static u32 THISCALL fn42d730(u8 *self, u8 *st) {
  vcall<void>(st, 0xc, 2u);
  vcall<void>(st, 0x5c, (u32)(self + 0xc));
  vcall<void>(st, 0x5c, (u32)(self + 4));
  vcall<void>(st, 0x5c, (u32)(self + 0x14));
  vcall<void>(st, 0x58, (u32)(self + 0x1c));
  vcall<void>(st, 0x50, (u32)(self + 0x20));
  vcall<void>(st, 0x58, (u32)(self + 0x24));
  vcall<void>(st, 0x50, (u32)(self + 0x2c));
  vcall<void>(st, 0x58, (u32)(self + 0x30));
  vcall<void>(st, 0x50, (u32)(self + 0x34));
  vcall<void>(st, 0x58, (u32)(self + 0x38));
  vcall<void>(st, 0x40, (u32)(self + 0x3c));
  vcall<void>(st, 0x58, (u32)(self + 0x40));
  vcall<void>(st, 0x58, (u32)(self + 0x44));
  vcall<void>(st, 0x50, (u32)(self + 0x48));
  vcall<void>(st, 0x58, (u32)(self + 0x4c));
  vcall<void>(st, 0x50, (u32)(self + 0x58));
  vcall<void>(st, 0x48, (u32)(self + 0x1b49));
  return vcall<u32>(st, 0x68, (u32)(self + 0x1b59));
}
PCREG(42d730, fn42d730);
