// batch33027.cpp - h3 batch 33027: comparison and field checks
#include "ff.h"

// 0x471aa0, stdcall: test arg, if null return 0, else compare [arg+0xc]+0x23 to 0x1007d4
static u8 STDCALL fn471aa0(u32 arg) {
  if (!arg) return 0;
  u32 *p = *(u32 **)(arg + 0xc);
  if (!p) return 0;
  u32 val = *(u32 *)((u8 *)p + 0x23);
  return val == 0x1007d4 ? 1 : 0;
}
PCREG(471aa0, fn471aa0);

// 0x5889c0, thiscall: write fields and return this
static u8 *THISCALL fn5889c0(u8 *self, u32 arg) {
  *(u32 *)(self + 0x00) = 0;
  *(u32 *)(self + 0x34) = arg;
  *(u32 *)(self + 0x38) = 0;
  *(u32 *)(self + 0x7c) = 0;
  *(u32 *)(self + 0xb0) = 0;
  return self;
}
PCREG(5889c0, fn5889c0);

// 0x640c90, stdcall: check word at arg+0x5a (must be nonzero) AND dword at arg+0x3c (must NOT have 0x2000)
static u8 STDCALL fn640c90(u32 arg) {
  u16 w = *(u16 *)(arg + 0x5a);
  u32 d = *(u32 *)(arg + 0x3c);
  // return 1 if word is nonzero AND bit 0x2000 is NOT set
  return (w != 0 && !(d & 0x2000)) ? 1 : 0;
}
PCREG(640c90, fn640c90);
