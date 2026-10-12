// batch1953.cpp - unclaimed-66 batches 59 to 62 (gap band, GUESS names). Four STDCALL-like thunks of one family, THISCALL(this), one stack
// argument x, ret 4: p1 = 0x5003d0(ECX = [x+4], 1); p0 = 0x5003d0(ECX = [x+4], 0) (another area's helper, hooked by address in the spec).
// Then the vtable slot of [this+0x14] is called with two arguments (in stack order: first listed = top).
//   0x519c70: vtable +0x344 with (*p0, *p1 as bits).
//   0x519cf0: vtable +0x2c8 with (*p0, *p1 as bits).
//   0x519d30: vtable +0x348 with (*p0, *p1 as bits).
//   0x519860: vtable +0x2f8 with (*p0 as bits, flag = (*p1 != 0)).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

// 0x519c70, GUESS FUN_00519c70 (batch 59).
static void THISCALL gapFn519c70(u8 *self, u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  vcall<void>(*(u8 **)(self + 0x14), 0x344, *(u32 *)p0, *(u32 *)p1);
}
PCREG(519c70, gapFn519c70);

// 0x519cf0, GUESS FUN_00519cf0 (batch 60).
static void THISCALL gapFn519cf0(u8 *self, u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  vcall<void>(*(u8 **)(self + 0x14), 0x2c8, *(u32 *)p0, *(u32 *)p1);
}
PCREG(519cf0, gapFn519cf0);

// 0x519d30, GUESS FUN_00519d30 (batch 61).
static void THISCALL gapFn519d30(u8 *self, u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  vcall<void>(*(u8 **)(self + 0x14), 0x348, *(u32 *)p0, *(u32 *)p1);
}
PCREG(519d30, gapFn519d30);

// 0x519860, GUESS FUN_00519860 (batch 62).
static void THISCALL gapFn519860(u8 *self, u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u32 flag = *(u32 *)p1 != 0;
  vcall<void>(*(u8 **)(self + 0x14), 0x2f8, *(u32 *)p0, flag);
}
PCREG(519860, gapFn519860);
