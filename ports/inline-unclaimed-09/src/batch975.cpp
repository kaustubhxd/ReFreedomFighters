// batch975.cpp - area 56 band, claim A41 (0x5244f0): a float argument, no calls.
#include "ff.h"

// A41 0x5244f0: f == K0 -> dword this+0x10 = 0; f == K1 -> dword this+0x10 = 0x7e967699; else float this+0x10 = K2 / f.
static void THISCALL setField5244f0(u8 *self, float f) {
  if (f == G(float, 0x67cd44)) {
    *(u32 *)(self + 0x10) = 0;
  } else if (f == G(float, 0x6785d0)) {
    *(u32 *)(self + 0x10) = 0x7e967699u;
  } else {
    *(float *)(self + 0x10) = G(float, 0x678858) / f;
  }
}
PCREG(5244f0, setField5244f0);
