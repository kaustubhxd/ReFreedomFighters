#include "ff.h"
// batch935.cpp - unclaimed-80, ZMovementGuide::WantControl (0x489df0; vtable entry, map name). Thiscall, three stack arguments (ret 12,
// bool result in al). The whole function is one harness port; its continuation (about 330 instructions of vtable calls and exe helpers
// from 0x489ec3 onward) is NOT ported, and the spec never reaches it. Reached paths:
//   (1) this+0x371 nonzero: return true.
//   (2) t = (x*x + C1) + z*z (x = c[0], z = c[2], C1 = 0.0 at 0x6785d0); if the threshold 0x679540 is greater than t: return false.
//   (3) this+0x375 zero: return false.
//   (4) this+0x3be = 0.
//   (5) if *(*(this+0x375) + 0x18) is zero: return false (the far exit at 0x48a231).
// The cookie check (0x633654) is omitted.

static u8 THISCALL wantControlEntry(u8 *self, const float *a, const float *b, const float *c) {
  (void)a;
  (void)b;
  if (*(u32 *)(self + 0x371) != 0)
    return 1;
  float x = c[0];
  float z = c[2];
  float t = (x * x + G(float, 0x6785d0)) + z * z;
  if (G(float, 0x679540) > t)
    return 0;
  if (*(u32 *)(self + 0x375) == 0)
    return 0;
  *(u8 *)(self + 0x3be) = 0;
  u8 *p = *(u8 **)(self + 0x375);
  if (*(u32 *)(p + 0x18) == 0)
    return 0;
  return 0;   // continuation (not ported; the spec never reaches it)
}
PCREG(489df0, wantControlEntry);
