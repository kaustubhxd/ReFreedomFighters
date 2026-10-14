// batch896.cpp - gap band slice: four one-byte flag accessors of the same shape (thiscall, one stack arg = index, ret 4, returns a
// byte). The flag byte is at this + 5*idx + off. Each reads the byte, and clears its clear-bit when the test-bit is set (the stored
// byte keeps the rest), and returns the result bit. Names from the map: 0x4201d0 CheckKeyAlways, 0x4202d0 CheckKeyTapAlways,
// 0x420420 TexturePath; 0x420350 is listed as GetRegPaths but has the same shape (named here by its shape: FlagRegPaths).
#include "ff.h"

// 0x4201d0: off 0xa0b; result = bit 7; test bit 1, clear bit 7's neighbour (bit 1 cleared, the stored byte keeps bit 7).
static u8 THISCALL Key4201d0(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xa0b;
  u8 cl = *addr;
  u8 al = cl >> 7;
  if (cl & 2) *addr = cl & 0x7f;
  return al;
}
PCREG(4201d0, Key4201d0);

// 0x420350: off 0xf0b; same shape as 0x4201d0.
static u8 THISCALL Flag420350(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xf0b;
  u8 cl = *addr;
  u8 al = cl >> 7;
  if (cl & 2) *addr = cl & 0x7f;
  return al;
}
PCREG(420350, Flag420350);

// 0x4202d0: off 0xa0b; result = bit 5; test bit 2, clear bit 5 (cl &= 0xdf).
static u8 THISCALL TapKey4202d0(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xa0b;
  u8 cl = *addr;
  u8 al = (cl >> 5) & 1;
  if (cl & 4) *addr = cl & 0xdf;
  return al;
}
PCREG(4202d0, TapKey4202d0);

// 0x420420: off 0xf0b; same shape as 0x4202d0.
static u8 THISCALL TexFlag420420(u8 *self, u32 idx) {
  u8 *addr = self + 5 * idx + 0xf0b;
  u8 cl = *addr;
  u8 al = (cl >> 5) & 1;
  if (cl & 4) *addr = cl & 0xdf;
  return al;
}
PCREG(420420, TexFlag420420);
