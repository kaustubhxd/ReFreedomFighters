// batch1954.cpp - unclaimed-66 batches 63 and 64 (gap band, GUESS names).
//   0x5112e0 (STDCALL, one argument x, ret 4): p0 = 0x5003d0(ECX = [x+4], 0); v = vtable +0x60 of the ZSysInterface child with *p0; if v:
//       p1 = 0x5003d0(ECX = [x+4], 1); if *p1 == 0 then [v+0x40] &= ~8 else [v+0x40] |= 8.
//   0x50aee0 (STDCALL, one argument x, ret 4): p0 = 0x5003d0(ECX = [x+4], 0); A = *p0 (a pointer); p1 = 0x5003d0(ECX = [x+4], 1); B = *p1;
//       r = vtable +0x134 of the child (no arguments); then vtable +0x40 of r with the three arguments ([A+0xc], [B+0xc], 0xc).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

// 0x5112e0, GUESS FUN_005112e0 (batch 63).
static void STDCALL gapFn5112e0(u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *v = (u8 *)vcall<u32>(child, 0x60, *(u32 *)p0);
  if (v) {
    u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
    if (*(u32 *)p1 == 0) *(u32 *)(v + 0x40) &= 0xfffffff7u;
    else *(u32 *)(v + 0x40) |= 8u;
  }
}
PCREG(5112e0, gapFn5112e0);

// 0x50aee0, GUESS FUN_0050aee0 (batch 64).
static void STDCALL gapFn50aee0(u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u32 vA = *(u32 *)p0;
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
  u32 vB = *(u32 *)p1;
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *r = (u8 *)vcall<u32>(child, 0x134);
  vcall<void>(r, 0x40, *(u32 *)((u8 *)vA + 0xc), *(u32 *)((u8 *)vB + 0xc), (u32)0xc);
}
PCREG(50aee0, gapFn50aee0);
