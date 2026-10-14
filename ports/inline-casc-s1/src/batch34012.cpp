// batch34012.cpp - cascade tier E, batch 34012: two push_back-style helpers of a flag vector (this+0x1b61 -> {begin, end, cap}); the flag
// is 1/0 from the virtual predicate (slot 0x8c) and the previous element; they differ in the sense of the predicate.
#include "ff.h"

extern "C" u32 THISCALL ext_4301c0(u8 *vec, u8 *pos, u32 *val);   // grow + insert, thiscall ret 8

static inline u32 rd32u(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }

// 0x42d2e0, thiscall(arg) ret 4: v = predicate(arg) && [end-4] != 0; append v (grow through 0x4301c0 when full); returns the old end.
static u32 THISCALL fn42d2e0(u8 *self, u32 arg) {
  u8 al = vcall<u8>(self, 0x8c, arg);
  u8 *vec = (u8 *)rd32u(self + 0x1b61);
  u8 *end = *(u8 **)(vec + 4);
  u32 v = (al && *(u32 *)(end - 4) != 0) ? 1 : 0;
  if (end == *(u8 **)(vec + 8)) return ext_4301c0(vec, end, &v);
  if (end) *(u32 *)end = v;
  *(u8 **)(vec + 4) += 4;
  return (u32)end;
}
PCREG(42d2e0, fn42d2e0);

// 0x42d360: same with the predicate inverted: v = !predicate(arg) && [end-4] != 0.
static u32 THISCALL fn42d360(u8 *self, u32 arg) {
  u8 al = vcall<u8>(self, 0x8c, arg);
  u8 *vec = (u8 *)rd32u(self + 0x1b61);
  u8 *end = *(u8 **)(vec + 4);
  u32 v = (!al && *(u32 *)(end - 4) != 0) ? 1 : 0;
  if (end == *(u8 **)(vec + 8)) return ext_4301c0(vec, end, &v);
  if (end) *(u32 *)end = v;
  *(u8 **)(vec + 4) += 4;
  return (u32)end;
}
PCREG(42d360, fn42d360);
