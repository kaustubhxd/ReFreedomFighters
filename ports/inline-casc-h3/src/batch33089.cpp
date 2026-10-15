// batch33089.cpp - h3 (Sonnet) batch 33089: tier H float/SSE functions
#include "ff.h"

#define SYS (*(u8 **)0x70039c)

extern "C" void THISCALL ext_467410(u8 *self, u32 p, u32 f, u32 a, u32 b, u32 c, u32 d);   // ret 0x18
extern "C" u32 THISCALL ext_591080(u8 *self);                                              // plain ret
extern "C" u8 *THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c);                         // ret 0xc

// 0x44ea60: thiscall(float *p) ret 4: per axis (lo,hi) = ([+0x5c],[+0x68]), ([+0x60],[+0x6c]), ([+0x64],[+0x70]): lo >= p -> bit 1/4/0x10; else p >= hi -> bit 2/8/0x20
static u32 THISCALL fn44ea60(u8 *self, float *p) {
  u32 r = 0;
  float v = p[0];
  if (*(float *)(self + 0x5c) >= v) r = 1;
  else if (v >= *(float *)(self + 0x68)) r = 2;
  v = p[1];
  if (*(float *)(self + 0x60) >= v) r |= 4;
  else if (v >= *(float *)(self + 0x6c)) r |= 8;
  v = p[2];
  if (*(float *)(self + 0x64) >= v) r |= 0x10;
  else if (v >= *(float *)(self + 0x70)) r |= 0x20;
  return r;
}
PCREG(44ea60, fn44ea60);

// 0x5df970: thiscall no args, returns false: 0x467410([this+0xc]+4, [this+8], 0, 0,0,0,-1); x=0x591080([this+8]); r=sys table slot 0x4c(x); [this+0xc]->slot 8([this+8], r)
static u8 THISCALL fn5df970(u8 *self) {
  ext_467410(*(u8 **)(self + 0xc) + 4, *(u32 *)(self + 8), 0, 0, 0, 0, 0xffffffffu);
  u32 x = ext_591080(*(u8 **)(self + 8));
  u8 *tab = *(u8 **)(SYS + 0x9b);
  u32 r = vcall<u32>(tab, 0x4c, x);
  vcall<u32>(*(u8 **)(self + 0xc), 8, *(u32 *)(self + 8), r);
  return 0;
}
PCREG(5df970, fn5df970);

// 0x45b240: thiscall ctor(a, b, c) ret 0xc: base 0x43de40(a,b,c); fields, vtable 0x6847a8, internal pointers; returns this
static u8 *THISCALL fn45b240(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)(self + 0x28) = 0x41000000;
  *(u32 *)(self + 0x2c) = 0x41200000;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x30) = 0;
  *(u32 *)(self + 0x34) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)self = 0x6847a8;
  for (int i = 0; i < 4; i++) *(u32 *)(self + 0x4f8 + 4 * i) = 0;
  *(u32 *)(self + 0x40) = (u32)(self + 0x358);
  *(u32 *)(self + 0x248) = (u32)(self + 0x3d8);
  *(u32 *)(self + 0x24c) = (u32)(self + 0x3f8);
  *(u32 *)(self + 0x250) = (u32)(self + 0x478);
  *(u32 *)(self + 0x254) = (u32)(self + 0x4f8);
  *(u32 *)(self + 0x1c) = 0x20;
  *(u32 *)(self + 0x20) = 4;
  *(u32 *)(self + 0x18) = 0x10;
  return self;
}
PCREG(45b240, fn45b240);
