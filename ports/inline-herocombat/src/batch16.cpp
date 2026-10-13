// batch16.cpp - first-level functions, inline session batch 16 (Haiku, overnight).
#include "ff.h"

// 0x582740, thiscall (ret 4): copies a record from src to this, field by field: dwords at +0x48, +0x4c, +0x50, +0x57,
// +0x5b, +0x5f, +0x64, a word at +0x54 and a byte at +0x56. Name unknown.
static void THISCALL copyRecA(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x48) = *(const u32 *)(src + 0x48);
  *(u32 *)(self + 0x4c) = *(const u32 *)(src + 0x4c);
  *(u32 *)(self + 0x50) = *(const u32 *)(src + 0x50);
  *(u16 *)(self + 0x54) = *(const u16 *)(src + 0x54);
  self[0x56] = src[0x56];
  *(u32 *)(self + 0x57) = *(const u32 *)(src + 0x57);
  *(u32 *)(self + 0x5b) = *(const u32 *)(src + 0x5b);
  *(u32 *)(self + 0x5f) = *(const u32 *)(src + 0x5f);
  *(u32 *)(self + 0x64) = *(const u32 *)(src + 0x64);
}
PCREG(582740, copyRecA);

// 0x5bf850, thiscall (ret 4): copies a record from src to this: a dword at +0x48, words at +0x51, +0x53, +0x55, +0x57,
// +0x66, +0x68, and dwords at +0x5d and +0x6e. Name unknown.
static void THISCALL copyRecB(u8 *self, const u8 *src) {
  *(u32 *)(self + 0x48) = *(const u32 *)(src + 0x48);
  *(u16 *)(self + 0x51) = *(const u16 *)(src + 0x51);
  *(u16 *)(self + 0x53) = *(const u16 *)(src + 0x53);
  *(u16 *)(self + 0x55) = *(const u16 *)(src + 0x55);
  *(u16 *)(self + 0x57) = *(const u16 *)(src + 0x57);
  *(u32 *)(self + 0x5d) = *(const u32 *)(src + 0x5d);
  *(u16 *)(self + 0x66) = *(const u16 *)(src + 0x66);
  *(u16 *)(self + 0x68) = *(const u16 *)(src + 0x68);
  *(u32 *)(self + 0x6e) = *(const u32 *)(src + 0x6e);
}
PCREG(5bf850, copyRecB);

// 0x644e30, thiscall (ret 4, returns eax): 0 when x is 0; -1 when x equals the dword at +0x29; otherwise the signed
// quotient (x - the dword at +0x25) * 0x4468c067 / 2^39 (high half of the 64-bit product, shifted right 7), rounded
// as the original does: q + (q < 0 ? 1 : 0) + 1 where q is the shifted value. Name unknown.
static u32 THISCALL scaleDelta(u8 *self, u32 x) {
  if (x == 0)
    return 0;
  if (x == *(u32 *)(self + 0x29))
    return 0xffffffffu;
  s32 d = (s32)(x - *(u32 *)(self + 0x25));
  long long prod = (long long)d * (long long)(s32)0x4468c067;
  s32 q = (s32)(prod >> 32) >> 7;
  u32 sign = (u32)q >> 31;
  return (u32)q + sign + 1u;
}
PCREG(644e30, scaleDelta);
