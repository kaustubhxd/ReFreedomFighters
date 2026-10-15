// batch240.cpp - ZFFHERO::GetFocalPoint (inline-ladder thread, 2026-10-11). Vtable slots 0x438, 0x3a8, 0x390 and 0x4d0
// are called exactly as the exe calls them; their targets are not named here (the vtable map puts 0x466f50 at 0x3a8,
// whose body does not match the call shape, so the names are left open).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define F32(p, off) (*(float *)((u8 *)(p) + (off)))

// 0x591bb0 ZFFHERO::GetFocalPoint(float *out) [GameCube reference, medium], thiscall, ret 4.
// 1. slot 0x438() true: out is not written; slot 0x390(slot 0x3a8(buf, out)) (returns).
// 2. Target height (the camera focus point's y offset) from the input word +0x417 and slot 0x4d0():
//    flag 0x400 set: 165 or 155 when bits 0-1 are set (slot 0x4d0 true -> 165), else 130 or 120 (slot 0x4d0 true -> 130);
//    flag 0x400 clear: 180. Flag 0x8000000 forces 210.
// 3. Rate 75.0; 300.0 when flag 0x400 is set and the camera helper (+0x85a) byte +0xb45 is set.
// 4. Step = frame time (engine +0x48) * rate. The current value at +0x81f moves toward the target by the step, clamped
//    to the target; no store when equal.
// 5. out = (0, +0x81f, +0x823).
// The clamp is written as min/max; the exe's branch order gives the same result (checked by mutants and seeds).
static void THISCALL heroGetFocalPoint(u8 *self, float *out) {
  if (vcall<u32>(self, 0x438) & 0xff) {
    float buf[3];
    u32 r = vcall<u32>(self, 0x3a8, buf, out);
    vcall<void>(self, 0x390, r);
    return;
  }
  u32 flags = U32(self, 0x417);
  float target;
  if (flags & 0x400) {
    if (flags & 3)
      target = (vcall<u32>(self, 0x4d0) & 0xff) ? 165.0f : 155.0f;
    else
      target = (vcall<u32>(self, 0x4d0) & 0xff) ? 130.0f : 120.0f;
  } else {
    target = 180.0f;
  }
  if (flags & 0x8000000)
    target = 210.0f;
  float rate = 75.0f;
  if ((flags & 0x400) && *((u8 *)U32(self, 0x85a) + 0xb45))
    rate = 300.0f;
  float step = F32(G(u32, 0x70039c), 0x48) * rate;
  float cur = F32(self, 0x81f);
  if (cur > target) {
    float nc = cur - step;
    if (target > nc)
      nc = target;
    F32(self, 0x81f) = nc;
  } else if (target > cur) {
    float nc = cur + step;
    if (nc > target)
      nc = target;
    F32(self, 0x81f) = nc;
  }
  out[0] = 0.0f;
  out[1] = F32(self, 0x81f);
  out[2] = F32(self, 0x823);
}
PCREG(591bb0, heroGetFocalPoint);
