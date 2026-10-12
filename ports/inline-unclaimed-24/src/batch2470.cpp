// batch2470.cpp - decomp area 24, batch 2470 (parked: ZROOM::CalcBestRoom, 0x4442d0).
#include "ff.h"

// 0x4442d0 ZROOM::CalcBestRoom(unsigned int, const float*, const float*, const float*), stdcall (ret 16), eax = 0.
// The logger's slot 0x20 is thiscall (two arguments, callee pops); R1's vtable slot 0x2c is cdecl with (R1, 0x67d5a4) (the
// caller pops); then the global function pointer at 0x7003b0 is called with no pushed argument, so it sees the entry stack.
static u32 STDCALL roomCalcBestRoom(u32 a, const float *b, const float *c, const float *d) {
  (void)a;
  (void)b;
  (void)c;
  (void)d;
  u8 *logger = G(u8 *, 0x700390);
  u8 *r1 = (u8 *)(u32)vcall<u32>(logger, 0x20, 0x67d564u, 0x267u);
  void **vt = *(void ***)r1;
  typedef void (*cdecl2)(u32, u32);
  ((cdecl2)(vt[0x2c / 4]))((u32)r1, 0x67d5a4u);
  typedef void (*fn0)(void);
  fn0 fn = *(fn0 *)0x7003b0;
  if (!fn)
    __builtin_trap();
  fn();
  return 0;
}
PCREG(4442d0, roomCalcBestRoom);
