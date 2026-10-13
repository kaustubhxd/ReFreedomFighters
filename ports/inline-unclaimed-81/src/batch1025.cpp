// batch1025.cpp - area 81, batch 1025: 0x4a21b0, thiscall(this, n, a2), ret 8. Cookie check not reproduced (no SEH frame). The helper 0x4e0870 is a real
// function that returns a float in st0 (a length); the port takes it as a float return. Stand-ins (GUESS): 0x4a1710 (thiscall, one argument), 0x4a15b0 and
// 0x4a0150 (thiscall, one argument, return an index). The function returns n (eax is n on every exit: the compares and loads do not change it).
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_4a1710(void *self, u32 k);                         // GUESS (stood in)
extern "C" u32 THISCALL ext_4a15b0(void *self, u32 k);                          // GUESS (stood in)
extern "C" u32 THISCALL ext_4a0150(void *self, u32 k);                          // GUESS (stood in)
extern "C" float __attribute__((fastcall)) ext_4e0870(void *ecx, void *edx);    // real function: length in st0 (stood in)

// 0x4a21b0 (thiscall: this, n, a2).
static u32 THISCALL elementCheckUpdate(u8 *self, u32 nArg, u32 a2) {
  int n = (int)nArg;
  u32 esi = 0;
  if (n > 0)
    esi = D(self, 0x800 + 4 * n) + 1;
  int ebxv = (n - 1 >= 0) ? (int)((u32)500 << ((u32)(n - 1) & 31)) : 0;
  float F;
  if (n >= 7)
    F = 9.999999680285692e+37f;   // the float at 0x67cd44
  else if (n >= 0)
    F = (float)(int)((u32)500 << ((u32)n & 31));
  else
    F = 0.0f;
  if ((int)esi > (int)D(self, 0x804 + 4 * n))
    return (u32)n;
  u8 *ebx = self + 4 + 4 * esi;
  for (;;) {
    u8 *Q = *(u8 **)0x70038c;
    u32 V = *(u32 *)ebx;
    u32 v[3] = {0u, 0u, 0u};
    u32 R = vcall<u32>(Q, 0xcc, V);
    if (R == 0) {
      ext_4a1710(self, esi);
    } else {
      u8 *M = (u8 *)D(R, 0x44);
      vcall<void>(M, 0x84, (u32)v);
      float T = ext_4e0870(v, (void *)a2);
      float B = (float)ebxv;
      bool inc = true;
      if (B > T) {
        if (ext_4a15b0(self, esi) != esi)
          inc = false;
      }
      if (inc && T > F) {
        if (ext_4a0150(self, esi) != esi)
          inc = false;
      }
      if (inc) {
        ++esi;
        ebx += 4;
      }
    }
    if ((int)esi > (int)D(self, 0x804 + 4 * n))
      break;
  }
  return (u32)n;
}
PCREG(4a21b0, elementCheckUpdate);
