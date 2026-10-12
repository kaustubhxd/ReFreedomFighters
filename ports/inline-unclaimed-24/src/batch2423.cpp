// batch2423.cpp - decomp area 24, batch 2423: three small leaves.
#include "ff.h"

// 0x4cc5f0 MYSTR::Length() const, thiscall, plain ret. strlen of the string the first dword points to.
static u32 THISCALL mystrLength(u8 *self) {
  const char *s = *(const char **)self;
  u32 n = 0;
  while (s[n] != 0)
    ++n;
  return n;
}
PCREG(4cc5f0, mystrLength);

// 0x5143f0 ZMoveOnSpline::SetMoveSoundParams(int, float), thiscall, ret 8.
static void THISCALL setMoveSoundParams(u8 *self, s32 v, float f) {
  *(s32 *)(self + 0x1dd) = v;
  *(float *)(self + 0x1e1) = f;
}
PCREG(5143f0, setMoveSoundParams);

// 0x435d30 (GUESS owner), thiscall, ret 4. Appends v while the count is 16 or less. Slot 16 is the count word itself
// (+0x20 + 4*16 = +0x60), so the count is incremented in memory after the store, as the original's `inc` does.
static void THISCALL boundedAppend(u8 *self, u32 v) {
  u32 n = *(u32 *)(self + 0x60);
  if (n <= 0x10) {
    *(u32 *)(self + 0x20 + 4 * n) = v;
    *(u32 *)(self + 0x60) += 1;
  }
}
PCREG(435d30, boundedAppend);
