// batch100.cpp - climb tree leaves (climb thread, batch 100). Every function does what the machine code at its PC
// address does; names come from the GC name map where it has one, otherwise they are guesses (marked).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);  // PSVECSubtract, original code
extern "C" void FASTCALL ext_446ee0(float *out, const float *a, const float *b);  // vcross, original code
extern "C" void FASTCALL ext_4878c0(void *self);                                  // base dtor body, original code
extern "C" void ext_634273(void *p, u32 size);                                    // operator delete(p, size), CRT

// 0x43e8e0, fastcall (out in ECX, a in EDX, b on the stack), ret 4. out = a + b on three floats. The exe adds on the x87
// stack; at 53 or 64-bit precision the sum of two floats rounded once more to float equals the float sum, but at 24-bit
// precision (Direct3D's setting, docs/15 E11) the x87 add has a wider exponent range, so the port uses long double too. All three loads happen before the stores, so out may alias a or b. Name: PSVECAdd (guess; the
// GC build calls PSVECAdd where the PC build calls this, and 0x43e920 next to it is PSVECSubtract).
static void FASTCALL psvecAdd(float *out, const float *a, const float *b) {
  long double x = (long double)a[0] + b[0], y = (long double)a[1] + b[1], z = (long double)a[2] + b[2];
  out[0] = x;
  out[1] = y;
  out[2] = z;
}
PCREG(43e8e0, psvecAdd);

// 0x451890, fastcall (v in ECX, a in EDX, s on the stack), ret 4. v += a * s, on the x87 stack (product and sum at the
// control word's precision, one rounding to float at the store). long double compiles to the same x87 operations, so the
// port follows the control word (doubles matched at 53-bit only; at 24-bit 4 of 1000 cases differed). Name vaddscalar (GC map).
static void FASTCALL vaddscalar(float *v, const float *a, float s) {
  long double ds = s;
  long double x = (long double)a[0] * ds + (long double)v[0];
  long double y = (long double)a[1] * ds + (long double)v[1];
  long double z = (long double)a[2] * ds + (long double)v[2];
  v[0] = (float)x;
  v[1] = (float)y;
  v[2] = (float)z;
}
PCREG(451890, vaddscalar);

// 0x45bfd0, thiscall (one stack arg: out), ret 4. Normal of the triangle whose corners are at this+0x48, +0x54, +0x60:
// e1 = c1 - c0, e2 = c2 - c0, out = vcross(e2, e1) (argument order as the exe passes them), then normalised unless all
// three components compare equal to zero (NaN counts as non-zero). The normalise is x87: squares, sums, fsqrt and 1/len at the
// control word's precision, each component times that rounded to float (long double + fsqrt_x87 in the port).
// Name guess: COLI hit-triangle normal (the GC WantControl does PSVECSubtract, vcross, vnorm inline on the same fields).
static void THISCALL triNormal(u8 *self, float *out) {
  float e1[3], e2[3];
  ext_43e920(e1, (float *)(self + 0x54), (float *)(self + 0x48));
  ext_43e920(e2, (float *)(self + 0x60), (float *)(self + 0x48));
  ext_446ee0(out, e2, e1);
  if (out[0] == 0.0f && out[1] == 0.0f && out[2] == 0.0f)
    return;
  long double x = out[0], y = out[1], z = out[2];
  long double len = fsqrt_x87(x * x + y * y + z * z);
  long double inv = 1.0L / len;
  out[0] = (float)(out[0] * inv);
  out[1] = (float)(out[1] * inv);
  out[2] = (float)(out[2] * inv);
}
PCREG(45bfd0, triNormal);

// 0x5e2580, thiscall, five stack args, ret 0x14, returns 0.0 in ST0. ZFFHeroMovementClimb::GetActiveAnim (a folded stub
// shared by three GC functions; the climb animation is picked elsewhere, so the movement reports weight 0).
static float THISCALL getActiveAnimZero(void *, void *, const float *, const float *, const float *, const float *) {
  return 0.0f;
}
PCREG(5e2580, getActiveAnimZero);

// 0x4878c0, thiscall, no args: writes the vtable 0x68cf50 into this (the base-class part of a destructor; the base is
// probably ZMovementBase, inferred from the dtor chain of ZFFHeroMovementClimb).
static void THISCALL setBaseVtable(u32 *self) { self[0] = 0x68cf50u; }
PCREG(4878c0, setBaseVtable);

// 0x4946a0, thiscall, one stack arg, ret 4: this+4 = owner. ZSoundBase::SetOwner (GC map, high).
static void THISCALL setOwner(u8 *self, u32 owner) { *(u32 *)(self + 4) = owner; }
PCREG(4946a0, setOwner);

// 0x5e1350, thiscall, one stack arg (flags), ret 4, returns this. ZFFHeroMovementClimb scalar deleting destructor:
// vtable = 0x6b7678; if the object at +0x76 is set, call its slot 0 with 1 (delete it); run the base part (0x4878c0);
// if flags bit 0, operator delete(this, 0x7a). The 0x76 offset is unaligned: the PC build is 1-byte packed.
static u8 *THISCALL climbDtor(u8 *self, u32 flags) {
  *(u32 *)self = 0x6b7678u;
  void *sub = *(void **)(self + 0x76);
  if (sub)
    vcall<void>(sub, 0, 1u);
  ext_4878c0(self);
  if (flags & 1)
    ext_634273(self, 0x7a);
  return self;
}
PCREG(5e1350, climbDtor);
