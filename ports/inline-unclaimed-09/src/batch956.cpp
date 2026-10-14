// batch956.cpp - area 56 band claims A15-A18. Tail jumps and import calls are modelled as GUESS recording stubs in the spec.
#include "ff.h"

// A15 0x5274e0: target = dword at o+0x20 where o = dword this+0x28; tail call with ecx = this+0x28; returns the target's eax.
static u32 THISCALL tail5274e0(u8 *self) {
  u8 *o = *(u8 **)(self + 0x28);
  u32 target = *(u32 *)(o + 0x20);
  return ((u32(THISCALL *)(u8 *))target)(self + 0x28);
}
PCREG(5274e0, tail5274e0);

// A16 0x536980: ecx += 0x109f; tail call to 0x534050 with the argument.
extern "C" u32 THISCALL ext_534050(u8 *self, u32 a);
static u32 THISCALL tail536980(u8 *self, u32 a) {
  return ext_534050(self + 0x109f, a);
}
PCREG(536980, tail536980);

// A17 0x533c30: push dword 0x701b68; call the import slot at 0x67613c (stdcall, one argument); plain ret.
static void f533c30(void) {
  ((u32(STDCALL *)(u32))G(u32, 0x67613c))(G(u32, 0x701b68));
}
PCREG(533c30, f533c30);

// A18 0x533c40: push 0; push dword 0x701b6c; call the import slot at 0x676144 (stdcall, two arguments); returns (eax == 0) as al.
static u8 f533c40(void) {
  u32 r = ((u32(STDCALL *)(u32, u32))G(u32, 0x676144))(G(u32, 0x701b6c), 0);
  return r == 0;
}
PCREG(533c40, f533c40);
