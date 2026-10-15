// batch32122.cpp - cascade h2 (Sonnet): two tier H (x87 / vector) functions.
#include "ff.h"

extern "C" float FASTCALL ext_4e0870(void *a, void *b);                          // distance between two vectors (real exe code, float in st0)
extern "C" void FASTCALL ext_633654(u32 cookie);                                 // /GS check
extern "C" void FASTCALL ext_43e920(void *out, const void *a, const void *b);    // x87 vector subtract: out = a - b
extern "C" void FASTCALL ext_441a60(void *a, void *b);                           // vector helper (ecx, edx), plain ret
extern "C" void FASTCALL ext_459fc0(void *out, void *a, void *b);                // vector helper (ecx, edx, stack arg ret 4)
extern "C" u32 THISCALL ext_4e8c80(u8 *self, u8 *a, void *l1, void *l2, u32 d);  // thiscall ret 0x10, bool in AL
extern "C" void FASTCALL ext_443ef0(void *out, void *a, u32 c, float x);         // vector helper (ecx, edx, two stack args ret 8)

// 0x45ecd0, thiscall(p) ret 4, returns an x87 value (/GS frame): l1, l2 = zero vectors; slot 0x84 of this with &l1; slot 0x84 of p with &l2; fa = float [[p+8]+0x4c]; fb = float [[this+8]+0x4c];
// d = 0x4e0870(&l1, &l2) (distance, exe code); returns d - (fb + fa) with 53-bit x87 arithmetic.
static double THISCALL fn45ecd0(u8 *self, u8 *p) {
  float l1[3] = {0, 0, 0};
  float l2[3] = {0, 0, 0};
  vcall<void>(self, 0x84, (u32)l1);
  vcall<void>(p, 0x84, (u32)l2);
  float fa = *(float *)(*(u8 **)(p + 8) + 0x4c);
  float fb = *(float *)(*(u8 **)(self + 8) + 0x4c);
  float d = ext_4e0870(l1, l2);
  double sum = (double)fb + (double)fa;
  double r = (double)d - sum;
  ext_633654(0);
  return r;
}
PCREG(45ecd0, fn45ecd0);

// 0x4e8c00, thiscall(A, B, C, D) ret 0x10, returns AL: l1 = B - (this+0x3c) (0x43e920); 0x441a60(l1, this+0x18); l2 = 0x459fc0(l2, C, this+0x18); r = 0x4e8c80(this, A, l1, l2, D);
// r != 0 -> 0x443ef0(A+4, B, C, float [A]); returns r.
static u32 THISCALL fn4e8c00(u8 *self, u8 *A, u8 *B, u8 *C, u32 D) {
  float l1[3];
  float l2[3];
  ext_43e920(l1, B, self + 0x3c);
  ext_441a60(l1, self + 0x18);
  ext_459fc0(l2, C, self + 0x18);
  u32 r = ext_4e8c80(self, A, l1, l2, D);
  u8 bl = (u8)r;
  if (bl) ext_443ef0(A + 4, B, (u32)C, *(float *)A);
  return bl;
}
PCREG(4e8c00, fn4e8c00);
