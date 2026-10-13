// batch1000.cpp - area 81 (residue 0, unclaimed slice), batch 1000: ZMovementAnimation::Move(const float*, const float*, float*, float*, float*),
// 0x489400, thiscall, five stack args, ret 0x14. Calls vslot 0x50(a1, a2, a3, a4); helper 0x43e920 (fastcall: ecx = a5, edx = a4, stack a2; GUESS, stood in);
// x = ([this+0x18] == 0 ? sys[0x48] : [this+0x18]) * 0x67885c; when x != 0: helper 0x4e0d00(a5, 0x678858 / x) (GUESS, stood in); then vslot 0x48(a1..a5).
#include "ff.h"

extern "C" void __attribute__((fastcall)) ext_43e920(void *ecx, void *edx, void *a2);   // GUESS (stood in)
extern "C" void THISCALL ext_4e0d00(void *self, float d);                              // GUESS (stood in)

#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x489400 ZMovementAnimation::Move(...).
static void THISCALL zmaMove(u8 *t, float *a1, float *a2, float *a3, float *a4, float *a5) {
  vcall<void>(t, 0x50, (u32)a1, (u32)a2, (u32)a3, (u32)a4);
  ext_43e920(a5, a4, a2);
  u8 *sys = *(u8 **)0x70039c;
  float x = F(t, 0x18) == 0.0f ? F(sys, 0x48) : F(t, 0x18);
  x = x * *(float *)0x67885c;
  if (x != 0.0f)
    ext_4e0d00(a5, *(float *)0x678858 / x);
  vcall<void>(t, 0x48, (u32)a1, (u32)a2, (u32)a3, (u32)a4, (u32)a5);
}
PCREG(489400, zmaMove);
