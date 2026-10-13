// batch27.cpp - first-level functions, inline session batch 27 (Haiku, overnight).
#include "ff.h"

// 0x4ec720, thiscall (ret 4, returns AL): the count byte at this+0x1c says how many dwords at this+0 are valid. Returns 1
// when the stack argument equals one of them, 0 otherwise (also 0 when the count is 0). Name unknown.
static u8 THISCALL hasEntry(u8 *self, u32 v) {
  u32 count = self[0x1c];
  for (u32 i = 0; i < count; i++) {
    if (*(u32 *)(self + 4 * i) == v)
      return 1;
  }
  return 0;
}
PCREG(4ec720, hasEntry);

// 0x5248e0, thiscall (ret 4), one float stack arg. The value is the argument, or 50.0 when the argument is exactly 0.0.
// The dword at this+0xc is 0x46c35000 and at +0x10 is 0x447a0000. The float at +0x14 is the value, or 0x3dcccccd (0.1f)
// when the value is exactly 0.0. The branches use ucomiss with jp, so a NaN takes the non-zero path. Name unknown.
static void THISCALL setTuningA(u8 *self, float arg) {
  float v = arg;
  if (arg == 0.0f)
    v = G(float, 0x680a84);
  *(u32 *)(self + 0xc) = 0x46c35000u;
  *(u32 *)(self + 0x10) = 0x447a0000u;
  if (v == 0.0f)
    *(u32 *)(self + 0x14) = 0x3dcccccdu;
  else
    *(float *)(self + 0x14) = v;
}
PCREG(5248e0, setTuningA);

// 0x524930, same shape as setTuningA with other constants: the value is the argument, or 30.0 when the argument is exactly
// 0.0. The dwords at +0xc and +0x10 are 0x46435000 and 0x44480000. The float at +0x14 is the value, or 0.1f when the value
// is exactly 0.0. Name unknown.
static void THISCALL setTuningB(u8 *self, float arg) {
  float v = arg;
  if (arg == 0.0f)
    v = G(float, 0x67da24);
  *(u32 *)(self + 0xc) = 0x46435000u;
  *(u32 *)(self + 0x10) = 0x44480000u;
  if (v == 0.0f)
    *(u32 *)(self + 0x14) = 0x3dcccccdu;
  else
    *(float *)(self + 0x14) = v;
}
PCREG(524930, setTuningB);
