// batch28.cpp - first-level functions, inline session batch 28 (Haiku, overnight).
#include "ff.h"

// 0x4cc180, thiscall (ret 4, returns AL): this holds a pointer to a NUL-terminated string. The stack argument is a second
// string. Compares them two bytes at a time and returns 1 when they are equal, 0 otherwise. Name unknown.
static u8 THISCALL strIs(u8 **self, const u8 *s) {
  u8 *a = *self;
  for (;;) {
    u8 c = *a;
    if (c != *s)
      return 0;
    if (c == 0)
      return 1;
    u8 d = a[1];
    if (d != s[1])
      return 0;
    a += 2;
    s += 2;
    if (d == 0)
      return 1;
  }
}
PCREG(4cc180, strIs);

// 0x4d4270, thiscall, no args, returns AL. With the byte at this+4 set: v = float at +0xb plus float at +7; the byte at +6
// becomes 1; the float at +7 becomes v; the result is 0 when v is below 1.0 (ordered compare; NaN fails), otherwise the
// float at +7 becomes 1.0 and the result is 1. With the byte at +4 clear: v = float at +7 minus float at +0xb, stored at
// +7; the result is 0 when 0.0 is below v (NaN fails); otherwise +7 becomes 0, +6 becomes 0 and the result is 1.
// Name unknown.
static u8 THISCALL accumulate(u8 *self) {
  if (self[4] != 0) {
    float v = *(float *)(self + 0xb) + *(float *)(self + 7);
    self[6] = 1;
    *(float *)(self + 7) = v;
    if (!(v >= G(float, 0x678858)))
      return 0;
    *(u32 *)(self + 7) = 0x3f800000u;
    return 1;
  }
  float v = *(float *)(self + 7) - *(float *)(self + 0xb);
  *(float *)(self + 7) = v;
  if (!(0.0f >= v))
    return 0;
  *(u32 *)(self + 7) = 0;
  self[6] = 0;
  return 1;
}
PCREG(4d4270, accumulate);

// 0x4ccad0, thiscall (ret 8, returns this), two stack args a and b. The count is a when a >= 1, else 1; the stride is
// b + 4; the product count * stride goes to +0x10. Also stores 0 at +0x14, +4, +8, +0x1c, +0x20, +0x24, +0x28, the stride
// at +0x18, the count at +0xc, and the vtable word 0x6959f8 at +0. Name unknown.
static u8 *THISCALL initGrid(u8 *self, s32 a, u32 b) {
  s32 count = (a >= 1) ? a : 1;
  u32 stride = b + 4;
  u32 prod = (u32)count * stride;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = stride;
  *(u32 *)(self + 0xc) = (u32)count;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 0x10) = prod;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0x24) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)self = 0x6959f8u;
  *(u32 *)(self + 0x28) = 0;
  return self;
}
PCREG(4ccad0, initGrid);
