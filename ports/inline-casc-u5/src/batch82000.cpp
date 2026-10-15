// batch82000.cpp - cascade tier H, batch 82000: 0x4bf6b0 (manage float-based game state resource).
#include "ff.h"

static inline bool is_nan(float f) { return f != f; }

// 0x4bf6b0, thiscall, no args, returns void. this[0x6e] == 0: skip. this[0x4a] == 0: skip.
// Complex control flow: ucomiss+lahf checks for NaN on floats at 0x56, 0x5a, 0x5e, 0x62, 0x66, 0x6a.
// Global [0x70039c] (state) refs: 0x40 (int), 0x48 (float), 0x9b (table).
// Calls state[0x9b]->vcall0x58(this[0x4a/0x52]), updates this[0x62], calls obj[0x1e0] or [0x210].
// Always ends with this->vcall0x68(0x10, 0).
static void THISCALL fn4bf6b0(u8 *self) {
  if (!(self[0x6e])) {
    vcall<void>(self, 0x68, 0x10u, 0u);
    return;
  }

  u32 edx = *(u32 *)(self + 0x4a);
  if (!edx) {
    vcall<void>(self, 0x68, 0x10u, 0u);
    return;
  }

  u8 *sys = G(u8 *, 0x70039c);
  float f1 = *(float *)(self + 0x56);
  float f5 = *(float *)(self + 0x66);
  float f3 = *(float *)(self + 0x5e);

  // Check f1 for NaN: if NaN, skip this block
  if (!is_nan(f1)) {
    float f2 = *(float *)(self + 0x5a);
    s32 lim = (s32)((f2 + f1) * *(float *)(0x678620));
    if (lim >= *(s32 *)(sys + 0x40)) {
      u8 *obj = vcall<u8 *>(*(u8 **)(sys + 0x9b), 0x58, edx);
      if (obj) {
        if (!(*(u32 *)(self + 0x52))) {
          vcall<void>(*(u8 **)(0x2007d0), 0x1e0);
        }
      }
    }
  }

  // Check f5 for NaN: if NOT NaN, enter block
  if (!is_nan(f5)) {
    float f2 = *(float *)(self + 0x5a);
    s32 lim2 = (s32)((f2 + f1) * *(float *)(0x678620));
    if (lim2 < *(s32 *)(sys + 0x40)) {
      float delta = *(float *)(sys + 0x48) / f5;
      float f4 = *(float *)(self + 0x62);
      f4 += delta;
      *(float *)(self + 0x62) = f4;

      u32 count = *(u32 *)(self + 0x52);
      u8 *obj2 = vcall<u8 *>(*(u8 **)(sys + 0x9b), 0x58, count);
      if (obj2) {
        u8 *ptr = *(u8 **)(obj2 + 0x18);
        *(float *)(ptr + 0x84) = f4;
      }
    }
  }

  // Check f3 for NaN: if NaN, skip to end
  if (!is_nan(f3)) {
    float f6 = *(float *)(self + 0x6a);
    if (!is_nan(f6)) {
      float f2 = *(float *)(self + 0x5a);
      s32 lim3 = (s32)((f3 + f1) * *(float *)(0x678620));
      if (lim3 >= *(s32 *)(sys + 0x40)) {
        float delta2 = *(float *)(sys + 0x48) / f6;
        float f4 = *(float *)(self + 0x62);
        f4 -= delta2;
        *(float *)(self + 0x62) = f4;

        u32 count = *(u32 *)(self + 0x52);
        u8 *obj3 = vcall<u8 *>(*(u8 **)(sys + 0x9b), 0x58, count);
        if (obj3) {
          u8 *ptr = *(u8 **)(obj3 + 0x18);
          *(float *)(ptr + 0x84) = f4;
        }
      }
    }

    {
      float f2 = *(float *)(self + 0x5a);
      float f6 = *(float *)(self + 0x6a);
      s32 lim4 = (s32)((f3 + f1 + f6) * *(float *)(0x678620));
      if (lim4 >= *(s32 *)(sys + 0x40)) {
        u32 edx2 = *(u32 *)(self + 0x52);
        if (edx2) {
          u8 *obj4 = vcall<u8 *>(*(u8 **)(sys + 0x9b), 0x58, edx2);
          if (obj4) {
            vcall<void>(obj4, 0x210, 1u);
            *(u32 *)(self + 0x52) = 0;
          }
        }
      }
    }
  }

  vcall<void>(self, 0x68, 0x10u, 0u);
}
PCREG(4bf6b0, fn4bf6b0);
