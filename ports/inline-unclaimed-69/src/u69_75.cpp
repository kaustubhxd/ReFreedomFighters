// u69_75.cpp - area 69, group 75 (slice 8). Six small residue-8 functions: three tail-jump thunks, two stores and a list walk.
#include "ff.h"

extern "C" void THISCALL ext_5efdf0(void *self);                 // other area; pure: stores 1 at +0x94 (real code runs)
extern "C" u32 THISCALL ext_4db1b0(void *self, u32 a, u32 b);     // other area, ret 8 (GUESS stub in the spec)
extern "C" u32 THISCALL ext_4db670(void *self, u32 a);            // other area, ret 4 (GUESS stub in the spec)

// 0x5a8500: mov ecx,[ecx+0x634]; jmp 0x5efdf0. Nothing else; eax is not defined on exit (ret=None in the spec).
static void THISCALL thunk5a8500(u8 *self) {
  ext_5efdf0(*(void **)(self + 0x634));
}
PCREG(5a8500, thunk5a8500);

// 0x45edc0: mov ecx,[ecx+8]; jmp 0x4db1b0 (two stack args, ret 8). Returns the callee's eax.
static u32 THISCALL thunk45edc0(u8 *self, u32 a, u32 b) {
  return ext_4db1b0(*(void **)(self + 8), a, b);
}
PCREG(45edc0, thunk45edc0);

// 0x45f040: mov ecx,[ecx+8]; jmp 0x4db670 (one stack arg, ret 4). Returns the callee's eax.
static u32 THISCALL thunk45f040(u8 *self, u32 a) {
  return ext_4db670(*(void **)(self + 8), a);
}
PCREG(45f040, thunk45f040);

// 0x4895c0: stores its two float args at +0x14 and +0x18 (thiscall, ret 8).
static void THISCALL setFloats4895c0(u8 *self, float a, float b) {
  *(float *)(self + 0x14) = a;
  *(float *)(self + 0x18) = b;
}
PCREG(4895c0, setFloats4895c0);

// 0x650e80: if the first stack arg is non-zero, stores 1.0 (the float at 0x678858) at +0x70, else 0.0 (thiscall, ret 4).
static void THISCALL setFlagFloat650e80(u8 *self, u32 flag) {
  if (flag != 0)
    *(float *)(self + 0x70) = *(const float *)0x678858;
  else
    *(float *)(self + 0x70) = 0.0f;
}
PCREG(650e80, setFlagFloat650e80);

// 0x4d1c80: eax = [self+0x24]; ecx = n; if n == 0 return eax; loop: ecx--; if eax == 0 return 0; eax = [eax+0x30]; until ecx == 0; return eax.
static u32 THISCALL walk4d1c80(u8 *self, u32 n) {
  u32 eax = *(u32 *)(self + 0x24);
  u32 ecx = n;
  if (ecx == 0)
    return eax;
  do {
    ecx--;
    if (eax == 0)
      return 0;
    eax = *(u32 *)(eax + 0x30);
  } while (ecx != 0);
  return eax;
}
PCREG(4d1c80, walk4d1c80);
