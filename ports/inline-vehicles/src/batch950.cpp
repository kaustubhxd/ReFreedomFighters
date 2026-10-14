// batch950.cpp - vehicles thread, batch 950: deleting destructors of ZCar (0x5171f0), ZTank (0x520360), ZHeli (0x51bd30).
// Each: member dtor (thiscall, no args), base dtor 0x512070, then if flags&1: flags&4 ? operator delete(this, size)
// (0x4690b0, cdecl, a bare ret in this build) : free(this) (0x45c510, cdecl). Returns this, callee pops 4.
// ZHeli's member dtor is 0x4690b0 called with ECX (a bare ret: no effect), so that call is left out.
#include "ff.h"

extern "C" void THISCALL ext_511950(void *self);                    // ZCar member dtor at +0x2d8 (exe)
extern "C" void THISCALL ext_511a00(void *self);                    // ZTank member dtor at +0x2fd (exe)
extern "C" void THISCALL ext_512070(void *base);                    // ZMoveOnSpline base dtor (exe)
extern "C" void __attribute__((cdecl)) ext_45c510(void *obj);       // dealloc (cdecl, exe)
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 size); // operator delete (cdecl, bare ret)

// 0x5171f0 ZCar::~ZCar(flags).
static u8 *THISCALL carDtor(u8 *s, u32 flags) {
  ext_511950(s + 0x2d8);
  ext_512070(s);
  if ((u8)flags & 1) {
    if ((u8)flags & 4)
      ext_4690b0(s, 0x1654);
    else
      ext_45c510(s);
  }
  return s;
}
PCREG(5171f0, carDtor);

// 0x520360 ZTank::~ZTank(flags).
static u8 *THISCALL tankDtor(u8 *s, u32 flags) {
  ext_511a00(s + 0x2fd);
  ext_512070(s);
  if ((u8)flags & 1) {
    if ((u8)flags & 4)
      ext_4690b0(s, 0x270d);
    else
      ext_45c510(s);
  }
  return s;
}
PCREG(520360, tankDtor);

// 0x51bd30 ZHeli::~ZHeli(flags).
static u8 *THISCALL heliDtor(u8 *s, u32 flags) {
  ext_512070(s);
  if ((u8)flags & 1) {
    if ((u8)flags & 4)
      ext_4690b0(s, 0x5d9);
    else
      ext_45c510(s);
  }
  return s;
}
PCREG(51bd30, heliDtor);
