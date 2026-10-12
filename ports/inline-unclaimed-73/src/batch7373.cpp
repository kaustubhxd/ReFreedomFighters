// batch7373.cpp - area 73 batch 73 (gap band, GUESS names): FUN_4ee530, FUN_4f1ae0, FUN_4f4390, FUN_4f4a30.
// Arity from the call site: a call with no pushes takes no arguments; the constructors push three arguments.
#include "ff.h"

extern "C" void THISCALL ext_4ee440(u8 *self);
extern "C" void THISCALL ext_4f1a10(u8 *self);
extern "C" void THISCALL ext_4ee1b0(u8 *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_4f97f0(u8 *self, u32 a, u32 b, u32 c);
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 n);

// 0x4ee530 (GUESS FUN_4ee530): ret 4, returns this. 0x4ee440 on this; flag bit 0 gives 0x4690b0(this, 0xac) when bit 2 is set,
// else 0x45c510(this).
static u8 *THISCALL guess4ee530(u8 *self, u32 flags) {
  ext_4ee440(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0xacu);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(4ee530, guess4ee530);

// 0x4f1ae0 (GUESS FUN_4f1ae0): ret 4, returns this. As above, with 0x4f1a10 and the size 0x63c.
static u8 *THISCALL guess4f1ae0(u8 *self, u32 flags) {
  ext_4f1a10(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x63cu);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(4f1ae0, guess4f1ae0);

// 0x4f4390 (GUESS FUN_4f4390): ret 0xc, returns this. Base 0x4ee1b0(this, a, b, c), vtable word 0x699664, dword +0xac = 0, +0xb0 = 0.
static u8 *THISCALL guess4f4390(u8 *self, u32 a, u32 b, u32 c) {
  ext_4ee1b0(self, a, b, c);
  *(u32 *)self = 0x699664;
  *(u32 *)(self + 0xac) = 0;
  *(u32 *)(self + 0xb0) = 0;
  return self;
}
PCREG(4f4390, guess4f4390);

// 0x4f4a30 (GUESS FUN_4f4a30): ret 0xc, returns this. Base 0x4f97f0(this, a, b, c), vtable word 0x699924, dword +0x8f = 0, +0x93 = 1.
static u8 *THISCALL guess4f4a30(u8 *self, u32 a, u32 b, u32 c) {
  ext_4f97f0(self, a, b, c);
  *(u32 *)self = 0x699924;
  *(u32 *)(self + 0x8f) = 0;
  *(u32 *)(self + 0x93) = 1;
  return self;
}
PCREG(4f4a30, guess4f4a30);
