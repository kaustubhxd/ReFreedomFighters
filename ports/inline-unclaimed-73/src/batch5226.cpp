// batch5226.cpp - area 73 batch 52 (gap band, GUESS names): FUN_4ffba0, FUN_500a20, FUN_4f0eb0, FUN_4f6dd0.
#include "ff.h"

extern "C" void THISCALL ext_4ffab0(u8 *self);
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);
extern "C" void STDCALL ext_43ef30(u32 a, u32 b, u32 c);

// 0x4ffba0 (GUESS FUN_4ffba0): ret 4, returns this. Calls ext_4ffab0 on this; the low bit of the argument frees this
// through the delete helper with size 0x34.
static u8 *THISCALL guess4ffba0(u8 *self, u32 flags) {
  ext_4ffab0(self);
  if (flags & 1)
    ext_634273(self, 0x34u);
  return self;
}
PCREG(4ffba0, guess4ffba0);

// 0x500a20 (GUESS FUN_500a20): ret 4, returns this. Sets the vtable word to 0x69c968; the low bit of the argument frees
// this with size 0x14.
static u8 *THISCALL guess500a20(u8 *self, u32 flags) {
  *(u32 *)self = 0x69c968;
  if (flags & 1)
    ext_634273(self, 0x14u);
  return self;
}
PCREG(500a20, guess500a20);

// 0x4f0eb0 (GUESS FUN_4f0eb0): ret 4. When the byte at this+0x20 differs from the argument, it stores the byte, calls vtable
// slot +0x228 and sets the byte at this+0x90 to 1.
static void THISCALL guess4f0eb0(u8 *self, u32 arg) {
  u8 v = (u8)arg;
  if (v == self[0x20])
    return;
  self[0x20] = v;
  vcall<void>(self, 0x228);
  self[0x90] = 1;
}
PCREG(4f0eb0, guess4f0eb0);

// 0x4f6dd0 (GUESS FUN_4f6dd0): ret 0xc, returns a dword. Calls the stdcall helper 0x43ef30 with the three arguments, then
// returns vtable slot +0x370 on this.
static u32 THISCALL guess4f6dd0(u8 *self, u32 a1, u32 a2, u32 a3) {
  ext_43ef30(a1, a2, a3);
  return vcall<u32>(self, 0x370);
}
PCREG(4f6dd0, guess4f6dd0);
