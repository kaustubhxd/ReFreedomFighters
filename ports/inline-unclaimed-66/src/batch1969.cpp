// batch1969.cpp - slice-5 batches 92 to 94 (GUESS names). Callees are GUESS stubs by address.
//   0x4b5910: THISCALL(this), no arguments. L = 0; 0x6352f0(&L) (STDCALL, one argument: the callee cleans); vtable +0x98 of this with &L.
//   0x4cbc10: THISCALL(this, a), one argument, ret 4; returns al = 1. [this+4] &= ~0x40; vtable +0x40 of a with the word [this+0x50]; then
//             with the word [this+0x52].
//   0x548e90: THISCALL(this, w, p), ret 8; returns 0. If (u16)w == [this+0x48] word: 0x548f40(ECX = this, p) (THISCALL, one argument; callee
//             cleans). Else if (u16)w == [this+0x4a] word: [p+4] = 1.
#include "ff.h"

extern "C" void STDCALL ext_6352f0(u32 *out);      // STDCALL, one argument, callee cleans (stub by address)
extern "C" void THISCALL ext_548f40(u8 *self, u32 p);  // THISCALL, one argument, callee cleans (stub by address)

// 0x4b5910, GUESS FUN_004b5910 (batch 92).
static void THISCALL gapFn4b5910(u8 *self) {
  u32 L = 0;
  ext_6352f0(&L);
  vcall<void>(self, 0x98, (u32)&L);
}
PCREG(4b5910, gapFn4b5910);

// 0x4cbc10, GUESS FUN_004cbc10 (batch 93).
static u8 THISCALL gapFn4cbc10(u8 *self, u32 a) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>((u8 *)a, 0x40, (u32)*(u16 *)(self + 0x50));
  vcall<void>((u8 *)a, 0x40, (u32)*(u16 *)(self + 0x52));
  return 1;
}
PCREG(4cbc10, gapFn4cbc10);

// 0x548e90, GUESS FUN_00548e90 (batch 94).
static u32 THISCALL gapFn548e90(u8 *self, u32 w, u32 p) {
  if ((u16)w == *(u16 *)(self + 0x48)) {
    ext_548f40(self, p);
    return 0;
  }
  if ((u16)w == *(u16 *)(self + 0x4a)) *(u8 *)(p + 4) = 1;
  return 0;
}
PCREG(548e90, gapFn548e90);
