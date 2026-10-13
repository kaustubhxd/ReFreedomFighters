// batch4121.cpp - unclaimed-41 batch 21 (slice 13): 0x484b10 ZPlayer::PositionCollisionBox(ZCollisionBox*, ZBaseGeom*, const float*,
// const float*, const float*) (thiscall, five stack arguments, ret 0x14). The /GS cookie check is not reproduced.
#include "ff.h"

// Unported callees (checksum stubs, GUESS). Stack-local pointers are not in the checksum (see the spec).
extern "C" void THISCALL ext_43e920(float *self, u32 a1);                     // one stack argument, callee pops
extern "C" void THISCALL ext_4e0d00(float *self, u32 half);                   // one stack argument (0.5f), callee pops
extern "C" void FASTCALL ext_43e8e0(float *c, float *d, u32 a1);              // ecx, edx, one stack argument, callee pops
extern "C" void THISCALL ext_4856d0(float *self);                             // no arguments
extern "C" void FASTCALL ext_441940(float *c, u8 *d);                         // ecx, edx, no stack arguments
extern "C" void THISCALL ext_4de7a0(float *self);                             // no arguments
extern "C" void THISCALL ext_4db6c0(u8 *self, float *a1, float *a2);          // two stack arguments, callee pops
extern "C" void FASTCALL ext_4e2c60(float *c, float *d);                      // ecx, edx, no stack arguments
extern "C" void THISCALL ext_4eb020(u8 *self, float *a1, float *a2, float *a3); // three stack arguments, callee pops

// 0x484b10: the temporaries are L10 (x at -0x10, y at -0xc, z at -0x8), L1c, L40 and L4c.
static void THISCALL fn484b10(u8 *self, u8 *A1, u8 *P2, u8 *P3, u8 *P4, u8 *P5) {
  float L10[3];
  float L1c[3];
  float L40[3];
  float L4c[3];

  if (P4 != 0) {
    ext_43e920(L10, (u32)P3);
  } else {
    L10[0] = 0.0f;
    L10[1] = 0.0f;
    L10[2] = 0.0f;
  }
  ext_4e0d00(L10, 0x3f000000u);          // the 0.5f stack argument (the PC writes it over the pushed ecx)
  ext_43e8e0(L1c, L10, (u32)P3);
  ext_4856d0(L10);
  ext_441940(L10, P5 != 0 ? P5 : self + 0x439);

  float C1 = G(float, 0x680a84);
  float K = G(float, 0x685270);
  float x = L10[0] + K;
  float y = L10[1] + C1;
  float z = L10[2] + K;
  L10[1] = y;
  L10[0] = x;
  L10[2] = z;
  if (*(u8 *)(self + 0x591) != 0) {
    L10[0] = x + C1;
    L10[2] = z + C1;
  }

  ext_4de7a0(L40);
  if (P2 != 0) {
    ext_4db6c0(P2, L40, L4c);
    ext_4e2c60(L40, L10);
  }
  ext_4eb020(A1, L40, L1c, L10);
}
PCREG(484b10, fn484b10);
