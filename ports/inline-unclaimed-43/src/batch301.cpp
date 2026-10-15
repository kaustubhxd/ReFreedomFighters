// batch301.cpp - ZMoveOnSpline::GetAimPoint(float *out, ZGEOM *g) (area 43, 2026-10-12). 0x512ea0, stdcall, ret 8.
// GameCube reference (name map, high). ECX is not read; both arguments are on the stack.
// g is a ZGEOM-like object: slot 0x1e0 is a class test (class id 0x200074), slots 0x84 (out-param),
// 0x398 (one word in), 0x3a0 / 0x3a8 (word return) are the calls the body makes. vscalar (0x4e0d00) is original exe code
// (thiscall with one float on the stack); PSVECAdd (0x441940) is the usual fastcall.
#include "ff.h"

extern "C" void FASTCALL ext_441940(float *dst, const float *src);   // PSVECAdd (ecx = dst, edx = src)
extern "C" void THISCALL ext_4e0d00(float *v, float s);              // vscalar (ecx = v, one float on the stack)

static void STDCALL moveOnSplineGetAimPoint(float *out, u8 *g) {
  out[0] = 0.0f;
  out[1] = 0.0f;
  out[2] = 0.0f;
  if (g == 0)
    return;
  if (!vcall<u8>(g, 0x1e0, 0x200074u)) {
    vcall<void>(g, 0x84, (void *)out);
    return;
  }
  float tmp[3];
  u32 x = vcall<u32>(g, 0x3a0, (void *)tmp);
  vcall<void>(g, 0x398, x);
  vcall<void>(g, 0x84, (void *)tmp);
  u32 y = vcall<u32>(g, 0x3a8, (void *)out);
  vcall<void>(g, 0x398, y);
  vcall<void>(g, 0x84, (void *)out);
  ext_441940(out, tmp);
  ext_4e0d00(out, 0.5f);
}
PCREG(512ea0, moveOnSplineGetAimPoint);
