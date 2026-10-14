// batch752.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 w);            // original, thiscall, one stack word, ret 4
extern "C" void THISCALL ext_59e730(u8 *self, u32 a, u32 b);   // original, thiscall, two stack words, ret 8

// 0x58b6d0, thiscall(a float) ret 4: x2 = a, or 3.0-style constant f3 = [0x67da18] when a > [0x6ad1fc] or when
// [0x6ad234] > a; sum = [this] + x2; if sum > f3, sum -= [0x68aef8]; else if [0x6ad238] > sum, sum += [0x68aef8]; store sum
// into [this]; returns this. Compares follow the asm's flags (an unordered compare takes the jbe branch). Name GUESS.
static u32 THISCALL clampAccumulate_58b6d0(u8 *self, float a) {
  float c1 = *(float *)0x6ad1fcu;
  float f3 = *(float *)0x67da18u;
  float d = *(float *)0x6ad234u;
  float k = *(float *)0x68aef8u;
  float x2 = a;
  if (a > c1) x2 = f3;
  else if (d > a) x2 = f3;
  float sum = *(float *)self + x2;
  if (sum > f3) {
    sum -= k;
  } else {
    float c2 = *(float *)0x6ad238u;
    if (c2 > sum) sum += k;
  }
  *(float *)self = sum;
  return (u32)self;
}
PCREG(58b6d0, clampAccumulate_58b6d0);

// 0x558a50, thiscall(arg) ret 4: r1 = 5003d0(ecx = [arg+4], 0); esi = [r1]; r2 = 5003d0(ecx = [arg+4], 1);
// 59e730(ecx = [this+0x1c], esi, [r2]). Name GUESS (two lookups then a call).
static void THISCALL twoLookupsThenCall_558a50(u8 *self, u8 *arg) {
  u8 *r1 = ext_5003d0(*(u8 **)(arg + 4), 0u);
  u32 esi = *(u32 *)r1;
  u8 *r2 = ext_5003d0(*(u8 **)(arg + 4), 1u);
  ext_59e730(*(u8 **)(self + 0x1c), esi, *(u32 *)r2);
}
PCREG(558a50, twoLookupsThenCall_558a50);
