// batch991.cpp - area 56 claim A58 (0x4e8c00, CalcLineCollision). Four helpers and the 0x443ef0 tail are GUESS stubs (docs/20-unclaimed-56.md).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(u8 *ecx, u8 *edx, u8 *s);                        // GUESS: writes ecx (3 floats)
extern "C" void FASTCALL ext_441a60(u8 *ecx, u8 *edx);                               // GUESS: writes ecx (3 floats)
extern "C" void FASTCALL ext_459fc0(u8 *ecx, u8 *edx, u8 *s);                        // GUESS: writes ecx (3 floats)
extern "C" u8 THISCALL ext_4e8c80(u8 *self, u8 *p1, u8 *p2, u8 *p3, u32 p4);         // GUESS: returns al
extern "C" void FASTCALL ext_443ef0(u8 *ecx, u8 *edx, u32 a3, float f);              // GUESS: writes ecx (3 floats)

// A58 0x4e8c00: a1 is a pointer; a2, a3, a4 are dword values (passed in edx or on the stack).
static u8 THISCALL calcLineCollision4e8c00(u8 *self, u8 *a1, u32 a2, u32 a3, u32 a4) {
  u8 L1[12];
  u8 L2[12];
  ext_43e920(L1, (u8 *)a2, self + 0x3c);
  ext_441a60(L1, self + 0x18);
  ext_459fc0(L2, (u8 *)a3, self + 0x18);
  u8 bl = ext_4e8c80(self, a1, L1, L2, a4);
  if (bl != 0) {
    float f = *(float *)a1;
    ext_443ef0(a1 + 4, (u8 *)a2, a3, f);
  }
  return bl;
}
PCREG(4e8c00, calcLineCollision4e8c00);
