// batch20.cpp - first-level functions, inline session batch 20 (Haiku, overnight).
#include "ff.h"

// 0x4856f0, fastcall (pointer to three floats in ECX), returns AL: 1 when all three are equal to 0.0 (ordered compare;
// NaN fails), otherwise 0. Name unknown.
static u8 FASTCALL isAllZero3(const float *v) {
  return v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f;
}
PCREG(4856f0, isAllZero3);

// 0x4464a0, thiscall (ret 4, returns AL): this holds a count at +0x2c and an array of u32 at +0x24. Finds value in the
// array; when found, the last element moves into its slot, the count drops by one, and the result is 1. Otherwise 0.
// Name unknown.
static u8 THISCALL takeValue(u8 *self, u32 value) {
  u32 count = *(u32 *)(self + 0x2c);
  u32 *arr = (u32 *)(self + 0x24);
  if (count == 0)
    return 0;
  u32 i = 0;
  while (arr[i] != value) {
    i++;
    if (i == count)
      return 0;
  }
  u32 last = count - 1;
  *(u32 *)(self + 0x2c) = last;
  arr[i] = arr[last];
  return 1;
}
PCREG(4464a0, takeValue);

// 0x467ea0, thiscall (no stack args, plain ret). When the byte at this+0x70 is 0, copies four u32 fields into the object
// at this+0x6c (+0x22d, +0x231, +0x235, +0x239). Then subtracts the float at global-pointer+0x48 times the constant at
// 0x67da1c from the float at this+0x1c6, and stores 0 when the result is below 0 (comiss with jbe: NaN keeps the value).
// Name unknown.
static void THISCALL stepFloat(u8 *self) {
  if (self[0x70] == 0) {
    u8 *o = *(u8 **)(self + 0x6c);
    *(u32 *)(o + 0x22d) = *(u32 *)(self + 0x1c6);
    *(u32 *)(o + 0x231) = *(u32 *)(self + 0x1ba);
    *(u32 *)(o + 0x235) = *(u32 *)(self + 0x1be);
    *(u32 *)(o + 0x239) = *(u32 *)(self + 0x1c2);
  }
  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  float cur = *(float *)(self + 0x1c6);
  float dec = *(float *)(g + 0x48) * G(float, 0x67da1c);
  float nv = cur - dec;
  *(float *)(self + 0x1c6) = nv;
  if (0.0f > nv)
    *(float *)(self + 0x1c6) = 0.0f;
}
PCREG(467ea0, stepFloat);
