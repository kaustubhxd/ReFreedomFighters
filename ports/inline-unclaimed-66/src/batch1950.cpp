// batch1950.cpp - unclaimed-66 batches 53 to 55 (gap band, GUESS names). Two more chunks use 0x5003d0 and the ZSysInterface child (sys+0x9b):
//   0x511380 (STDCALL, one argument x, ret 4): p0 = 0x5003d0(ECX = [x+4], 0); v = vtable +0x60 of the child with *p0; if v: [v+0xc] = *p1
//       with p1 = 0x5003d0(ECX = [x+4], 1).
//   0x5113c0 (STDCALL, ret 4): same, but if v: [v+0x88] = (float)(s32)*p1.
//   0x514270 (THISCALL(this), two arguments a and b, ret 8): tmp = {vtable +0x4c of the child with this, b}; then vtable +0x12c of this with
//       the arguments (a, word [this+0x213], &tmp).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(void *holder, u32 index);  // ret 4 (one argument), hooked in the spec

// 0x511380, GUESS FUN_00511380 (batch 53).
static void STDCALL gapFn511380(u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *v = (u8 *)vcall<u32>(child, 0x60, *(u32 *)p0);
  if (v) {
    u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
    *(u32 *)(v + 0xc) = *(u32 *)p1;
  }
}
PCREG(511380, gapFn511380);

// 0x5113c0, GUESS FUN_005113c0 (batch 54).
static void STDCALL gapFn5113c0(u32 x) {
  u8 *xo = (u8 *)x;
  u8 *p0 = ext_5003d0(*(u8 **)(xo + 4), 0);
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u8 *v = (u8 *)vcall<u32>(child, 0x60, *(u32 *)p0);
  if (v) {
    u8 *p1 = ext_5003d0(*(u8 **)(xo + 4), 1);
    *(float *)(v + 0x88) = (float)*(s32 *)p1;
  }
}
PCREG(5113c0, gapFn5113c0);

// 0x514270, GUESS FUN_00514270 (batch 55).
static void THISCALL gapFn514270(u8 *self, u32 a, u32 b) {
  u8 *sys = *(u8 **)0x70039c;
  u8 *child = *(u8 **)(sys + 0x9b);
  u32 tmp[2];
  tmp[0] = vcall<u32>(child, 0x4c, (u32)self);
  tmp[1] = b;
  vcall<void>(self, 0x12c, a, (u32)*(u16 *)(self + 0x213), (u32)tmp);
}
PCREG(514270, gapFn514270);
