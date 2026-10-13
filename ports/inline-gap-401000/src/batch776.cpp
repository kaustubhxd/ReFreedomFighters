// batch776.cpp - gap band batch 776 (docs/20-gap-band-401000.md): 0x40b6a0, cdecl (a1..a5), returns a signed integer.
#include "ff.h"

typedef int i32;

static u32 __attribute__((cdecl)) fn40b6a0(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  const i32 esi = (i32)(a3 & 0x7fff);
  const i32 ecx = (i32)(a4 & 0x7fff) - esi;
  const u32 absd = (u32)(ecx < 0 ? -ecx : ecx);
  const i32 edi = (i32)(a5 - a1);
  const i32 prod = (i32)(absd * (u32)edi);
  const i32 d = (i32)(a2 - a1);
  const i32 quot = prod / d;
  return ecx >= 0 ? (u32)(quot + esi) : (u32)(esi - quot);
}

PCREG(40b6a0, fn40b6a0);
