// batch1026.cpp - area 81, batch 1026: 0x4644f0, thiscall(this; X, Y as two stack arguments), ret 8. No SEH frame; cookie check not reproduced. The loop
// runs for k = 1 .. count-1 (count = this+0x20, which must be 1 or more; count 1 skips it). Per k: a fastcall helper chain (0x4de420, 0x4de4f0, 0x43e960,
// 0x441a60, 0x4de1d0; GUESS, stood in) on element structs at X, then four bytes of (int)(112 * U[i]) written at P1 + 8 + 0x18k (P1 = this+0x1c). The
// tail calls this's slot 0x2b4 (one argument, 2) and writes three bytes of (int)(0.5 * float) at P1 + 8, 9 and 0xa. The stand-ins do not write anything
// that is not compared.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void __attribute__((fastcall)) ext_4de420(void *ecx, void *edx);   // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_4de4f0(void *ecx, void *edx);   // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_43e960(void *ecx, void *edx);   // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_441a60(void *ecx, void *edx);   // GUESS (stood in)
extern "C" void __attribute__((fastcall)) ext_4de1d0(void *ecx, void *edx);   // GUESS (stood in)

// 0x4644f0 (thiscall: this, X, Y; ret 8).
static void THISCALL structElementsUpdate(u8 *self, u32 Xarg, u32 Yarg) {
  u8 *X = (u8 *)Xarg;
  u8 *Y = (u8 *)Yarg;
  u8 *P1 = (u8 *)D(self, 0x1c);
  u32 count = D(self, 0x20);
  if (count != 1) {
    for (u32 k = 1; k != count; ++k) {
      u8 *eaxk = Y + 0xc + 0x30 * k;     // element index pointer
      u8 *ecxk = X + 0x2c + 0x30 * k;    // vector source (its +0x24 .. +0x2c are read)
      u8 *edik = P1 + 8 + 0x18 * k;      // output bytes
      u32 E = D(eaxk, 0);
      u8 *esik = X + 48 * E;
      float V[3];
      ext_4de420(V, X + 0x30 * k);
      float W[3] = {*(float *)(ecxk - 8), *(float *)(ecxk - 4), *(float *)ecxk};
      ext_4de4f0(V, esik);
      ext_43e960(W, esik + 0x24);
      ext_441a60(W, esik);
      float U[4];
      ext_4de1d0(U, V);
      const float C = 112.0f;
      for (int i = 0; i < 4; ++i)
        edik[i] = (u8)(int)(U[i] * C);
    }
  }
  u32 R = vcall<u32>(self, 0x2b4, 2u);
  u8 *base = X + 48 * R;
  P1 = (u8 *)D(self, 0x1c);
  P1[8] = (u8)(int)(*(float *)(base + 0x24) * 0.5f);
  P1[9] = (u8)(int)(*(float *)(base + 0x28) * 0.5f);
  P1[0xa] = (u8)(int)(*(float *)(base + 0x2c) * 0.5f);
}
PCREG(4644f0, structElementsUpdate);
