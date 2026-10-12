// batch6500.cpp - unclaimed-68 batch 50 (claim 50, gap band). Name is a GUESS (no name-map entry).
#include "ff.h"
#include <stdint.h>

typedef void(THISCALL *VGeomVoid)(u8 *self);
typedef void(THISCALL *VGeomStop)(u8 *self, u32 a, u32 b);

// 0x4a7af0, ZGeomSpawn::CheckDeactivate() (GUESS name): thiscall, no stack args, bool result in AL.
//   f = float at this+0x56. If f equals the constant at 0x6785d0 (unordered counts as not equal), return false.
//   n = (int)(f * the float at 0x67862c); n = dword(this+0x76) - n. If n >= engine(0x70039c)->+0x40 (signed), return false.
//   If word(this+0x50) is zero, call vtable slot +0x58 with no arguments; otherwise clear byte this+0x7b, then call
//   slot +0x68 with (0x10, 0). Return true.
static u8 THISCALL geomCheckDeactivate(u8 *self) {
  float f = *(float *)(self + 0x56);
  if (f == G(float, 0x6785d0)) return 0;
  float t = f * G(float, 0x67862c);
  int32_t n = (int32_t)(*(u32 *)(self + 0x76)) - (int32_t)t;
  u8 *eng = G(u8 *, 0x70039c);
  if (n >= *(int32_t *)(eng + 0x40)) return 0;
  u8 *vt = *(u8 **)self;
  if (*(u16 *)(self + 0x50) == 0) {
    ((VGeomVoid)*(u32 *)(vt + 0x58))(self);
  } else {
    *(u8 *)(self + 0x7b) = 0;
    ((VGeomStop)*(u32 *)(vt + 0x68))(self, 0x10u, 0u);
  }
  return 1;
}
PCREG(4a7af0, geomCheckDeactivate);
