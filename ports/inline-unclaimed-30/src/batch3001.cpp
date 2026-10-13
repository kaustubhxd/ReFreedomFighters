// batch3001.cpp - unclaimed-30: batch 1 (docs/20-unclaimed-30.md, claim 1). Two small members:
// ZGEOM-style bound distance (0x45ef10, float ST0 result) and REFTAB::RemoveIfExists (0x4ced10, returns al).
#include "ff.h"

// 0x43e920: dst = a - b (FASTCALL: dst in ecx, a in edx, b on the stack; x87 subtraction in the exe).
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);

static float absf(float x) {
  u32 v;
  __builtin_memcpy(&v, &x, 4);
  v &= 0x7fffffffu;
  __builtin_memcpy(&x, &v, 4);
  return x;
}

// 0x45ef10 (thiscall, ret 4, returns ST0): d = p - corner (corner at box+0x30, box = this+8); each |d| minus the extent
// at box+0x40/+0x44/+0x48; the result is the largest of the three, with the exe's comparison order (an unordered
// compare takes the exe's jbe, so a NaN makes its operand lose).
static float THISCALL boundDistance(u8 *self, const float *p) {
  u8 *box = *(u8 **)(self + 8);
  float d[3];
  ext_43e920(d, p, (const float *)(box + 0x30));
  float x = absf(d[0]) - *(const float *)(box + 0x40);
  float y = absf(d[1]) - *(const float *)(box + 0x44);
  float z = absf(d[2]) - *(const float *)(box + 0x48);
  // the exe's jbe is taken for an unordered compare, so the first test is x > y (not !(x <= y))
  if (x > y) return (x > z) ? x : z;
  return (y > z) ? y : z;
}
PCREG(45ef10, boundDistance);

// 0x4ced10 REFTAB::RemoveIfExists(key): no table -> false. Walks the table with its begin (vtable +0x4c) and next (+0x5c)
// calls; on the element equal to key, calls +0x44 (remove the current element) and sets bit 31 of the dword at +0xc.
static bool THISCALL refTabRemoveIfExists(u8 *self, u32 key) {
  if (!self) return false;
  u32 it[3];
  vcall<void>(self, 0x4c, it);
  u32 cur = vcall<u32>(self, 0x5c, it);
  if (it[0] == 0) return false;
  for (;;) {
    if (cur == key) {
      vcall<void>(self, 0x44);
      *(u32 *)(self + 0xc) |= 0x80000000u;
      return true;
    }
    cur = vcall<u32>(self, 0x5c, it);
    if (it[0] == 0) return false;
  }
}
PCREG(4ced10, refTabRemoveIfExists);
