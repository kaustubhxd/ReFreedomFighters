// batch1412.cpp - unclaimed-14 batch 12 (slice 13, heavy list): ZMovementGuide::Move (float vector, five stack arguments).
#include "ff.h"

// Callees (original addresses; replaced by stubs in harness/specs_s1412.py, see harness/helper_stubs.py).
extern "C" void THISCALL ext_4e0d00(u8 *vec, u32 scale_bits);            // ecx = &vec, 1 stack argument (float bits)
extern "C" void FASTCALL ext_43e8e0(u8 *ecx, u8 *edx, u32 vec);          // ecx = d, edx = b, 1 stack argument (&vec)
extern "C" void FASTCALL ext_4de420(u8 *ecx, u32 edx);                    // ecx = c, edx = a
extern "C" void THISCALL ext_4946a0(u8 *obj, u32 v);                      // ecx = [self+8], 1 stack argument (eax)
extern "C" void THISCALL ext_4895e0(u8 *self, u32 b, u32 c, u32 d, u32 vec);  // own class, 4 stack arguments (ret 0x10)

// 0x4894d0, ZMovementGuide::Move(float*, float*, float*, float*, float*) (medium): thiscall, five stack arguments, ret 0x14.
// Arguments: a = [ebp+8], b = [ebp+0xc], c = [ebp+0x10], d = [ebp+0x14], out = [ebp+0x18] (a float[3]).
//  1. vec (ebp-0x10) = this->vtable[+0x3c](a, b, &vec, &aux) (4 stack arguments, ret 0x10); out[0..2] = vec[0..2]
//  2. f = this+0x18 (or the global's +0x48 when that equals the constant at 0x6785d0); f *= the constant at 0x685270
//  3. ext_4e0d00(&vec, bits(f))   4. ext_43e8e0(d, b, &vec)   5. ext_4de420(c, a)
//  6. r = global[+0x9b]->vtable[+0x4c]([this+0x371]); ext_4946a0([this+8], r)
//  7. ext_4895e0(this, b, c=arg, d, &vec) (the same class; original code, stubbed in the spec)
static void THISCALL zMovementGuideMove(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 *out) {
  u32 vec[3] = {0, 0, 0};
  u32 aux[3] = {0, 0, 0};   // &[ebp-0x1c]: a second out pointer pushed first (4 stack arguments in all)
  typedef void(THISCALL * vt3c_t)(u8 *, u32, u32, u32 *, u32 *);
  (*(vt3c_t *)(*(u32 *)self + 0x3c))(self, a, b, vec, aux);
  out[0] = vec[0];
  out[1] = vec[1];
  out[2] = vec[2];
  float f = *(float *)(self + 0x18);
  if (f == G(float, 0x6785d0))
    f = *(float *)(G(u8 *, 0x70039c) + 0x48);
  f *= G(float, 0x685270);
  ext_4e0d00((u8 *)vec, fbits(f));
  ext_43e8e0((u8 *)d, (u8 *)b, (u32)vec);
  ext_4de420((u8 *)c, a);
  u8 *gb = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  typedef u32(THISCALL * vt4c_t)(u8 *, u32);
  u32 r = (*(vt4c_t *)(*(u32 *)gb + 0x4c))(gb, *(u32 *)(self + 0x371));
  ext_4946a0(*(u8 **)(self + 8), r);
  ext_4895e0(self, b, c, d, (u32)vec);
}
PCREG(4894d0, zMovementGuideMove);
