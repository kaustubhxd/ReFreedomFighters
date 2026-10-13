// batch8.cpp - first-level functions, inline session batch 8 (Haiku, overnight).
#include "ff.h"

// 0x4e4990, stdcall (ret 4): for v > 1 returns 15 - (position of the highest set bit of v, counted from 31 down);
// v <= 1 (signed) returns 15. Name unknown.
static u32 STDCALL spanBits(s32 v) {
  if (v <= 1)
    return 15;
  s32 ecx = 31;
  u32 eax = 0x80000000u;
  do {
    eax >>= 1;
    ecx--;
  } while (((u32)v & eax) == 0);
  return (u32)(15 - ecx);
}
PCREG(4e4990, spanBits);

// 0x4e6b80, thiscall (ret 4): reads the next u16 of a table (this+4) at index this+0x10 into *out. If the index equals
// this+8 (the limit), writes -1 to *out and returns 0. Otherwise increments the index and returns this+0 + this+0xc * word.
// Name unknown (a bit or index reader).
static u32 THISCALL readU16Step(u8 *self, u32 *out) {
  u32 idx = *(u32 *)(self + 0x10);
  if (idx == *(u32 *)(self + 8)) {
    *out = 0xffffffffu;
    return 0;
  }
  u32 word = *(u16 *)(*(u32 *)(self + 4) + idx * 2);
  *out = word;
  *(u32 *)(self + 0x10) = idx + 1;
  return *(u32 *)self + *(u32 *)(self + 0xc) * *out;
}
PCREG(4e6b80, readU16Step);

// 0x61fce0, cdecl (plain ret, the caller pops): hash of a NUL-terminated string, h = h * 33 + byte, starting from 0.
static u32 strHash33(const u8 *s) {
  u32 h = 0;
  u8 c = *s;
  while (c != 0) {
    h = h * 33u + c;
    c = *++s;
  }
  return h;
}
PCREG(61fce0, strHash33);

// 0x644fb0, thiscall (ret 8): sets one of three slots by mode: 1 -> this+0xc, 2 -> global 0x6ec3cc, 3 -> this+4;
// other modes do nothing. Value is a float argument. Name unknown.
static void THISCALL setSlotByMode(u8 *self, s32 mode, float v) {
  if (mode == 1) {
    *(float *)(self + 0xc) = v;
  } else if (mode == 2) {
    G(float, 0x6ec3cc) = v;
  } else if (mode == 3) {
    *(float *)(self + 4) = v;
  }
}
PCREG(644fb0, setSlotByMode);
