// batch33033.cpp - h3 cascade batch 33033: four tier B functions (call + field setup)
#include "ff.h"

extern "C" void THISCALL ext_436060(u8 *self, u32 arg);   // thiscall, ret 4
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 arg);    // thiscall, returns u32
extern "C" void THISCALL ext_655a60(u8 *self, u32 arg);   // thiscall, ret 4

// 0x429200, thiscall(arg) ret 4: call 0x436060, set fields, return 1
static u8 THISCALL fn429200(u8 *self, u32 arg) {
  ext_436060(self, arg);
  self[0x75] = 1;
  self[0xc] = 1;
  *(u32 *)(self + 0x5d) = 4;
  *(u32 *)(self + 0x61) = 0x10;
  return 1;
}
PCREG(429200, fn429200);

// 0x51e910, thiscall(arg) ret 4: call 0x5003d0 with [arg+4] as this, store deref result to [this+0x18].0x272, return eax
static u32 THISCALL fn51e910(u8 *self, u32 arg) {
  u32 obj_ptr = *(u32 *)(arg + 4);
  u32 res = ext_5003d0((u8 *)obj_ptr, 0);
  u8 *ptr = *(u8 **)(self + 0x18);
  u32 val = *(u32 *)res;
  *(u32 *)(ptr + 0x272) = val;
  return val;
}
PCREG(51e910, fn51e910);

// 0x55c770, thiscall(arg) ret 4: call 0x5003d0 with [arg+4] as this, store deref result to [this+0x1c].0x945, return eax
static u32 THISCALL fn55c770(u8 *self, u32 arg) {
  u32 obj_ptr = *(u32 *)(arg + 4);
  u32 res = ext_5003d0((u8 *)obj_ptr, 0);
  u8 *ptr = *(u8 **)(self + 0x1c);
  u32 val = *(u32 *)res;
  *(u32 *)(ptr + 0x945) = val;
  return val;
}
PCREG(55c770, fn55c770);

// 0x656de0, thiscall(arg) ret 4: call 0x655a60, set vtable, return this
static u8 *THISCALL fn656de0(u8 *self, u32 arg) {
  ext_655a60(self, arg);
  *(u32 *)self = 0x6c3e28;
  return self;
}
PCREG(656de0, fn656de0);
