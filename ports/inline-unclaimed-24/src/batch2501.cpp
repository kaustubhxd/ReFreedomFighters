// batch2501.cpp - decomp area 24, batch 2501. SEH-framed constructors with stack arguments (GUESS names). Unlike 2499/2500, these
// frames push ECX before ESI/EDI, so the epilogue's `pop ecx` takes the cookie and ESI/EDI come back intact: plain C++ matches,
// no naked frame needed. The SEH registration itself is unobservable once the frame is unlinked.
#include "ff.h"

extern "C" void THISCALL ext_4359f0(u8 *self, u32 a);  // base ctor, thiscall, one argument (here 0)
extern "C" void THISCALL ext_4361a0(u8 *self, u32 a);  // thiscall, one argument (here the constant 0x6792c0)
extern "C" void THISCALL ext_5047c0(u8 *self, u32 a);  // base ctor, thiscall, one argument
extern "C" void THISCALL ext_509430(u8 *self);         // thiscall, no argument

// 0x4284f0: base ctor(0), vtable 0x678d8c, 0x4361a0(0x6792c0), then the four argument dwords copied to +0x1a1 (movups). ret 0x10.
extern "C" u8 *THISCALL f24_4284f0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  ext_4359f0(self, 0);
  *(u32 *)self = 0x678d8c;
  ext_4361a0(self, 0x6792c0);
  *(u32 *)(self + 0x1a1) = a;
  *(u32 *)(self + 0x1a5) = b;
  *(u32 *)(self + 0x1a9) = c;
  *(u32 *)(self + 0x1ad) = d;
  return self;
}
PCREG(4284f0, f24_4284f0);

// 0x5062f0: base ctor(arg), vtable 0x69cf6c, arg stored at +0x18; 0x509430 runs only while the dword at 0x701048 is 0. ret 4.
extern "C" u8 *THISCALL f24_5062f0(u8 *self, u32 a) {
  ext_5047c0(self, a);
  *(u32 *)self = 0x69cf6c;
  *(u32 *)(self + 0x18) = a;
  if (G(u32, 0x701048) == 0)
    ext_509430(self);
  return self;
}
PCREG(5062f0, f24_5062f0);
