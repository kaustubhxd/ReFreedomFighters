// batch528.cpp - weapons thread, batch 528: ZCollisionBox setter used by PerformDrop (0x4eb020). Arguments (thiscall,
// ret 0xc): mat (first), a, b. The box has a 4x3 matrix copy at +0x18 (mcpy, 0x4de420), a vector at +0x3c and another
// at +0x48. ZCollisionBox::GetStrips (0x4ea300) is already ported in decomp-pilot/inline-frameupdate (batch 410), so it
// is not repeated here.
#include "ff.h"

extern "C" void FASTCALL ext_4de420(float *d, const float *s);   // mcpy (9 floats)

// 0x4eb020: mcpy(this + 0x18, mat); this+0x3c = a[0..2]; this+0x48 = b[0..2].
static void THISCALL boxSetMatAndVecs(u8 *self, const float *mat, const u32 *a, const u32 *b) {
  ext_4de420((float *)(self + 0x18), mat);
  *(u32 *)(self + 0x3c) = a[0];
  *(u32 *)(self + 0x40) = a[1];
  *(u32 *)(self + 0x44) = a[2];
  *(u32 *)(self + 0x48) = b[0];
  *(u32 *)(self + 0x4c) = b[1];
  *(u32 *)(self + 0x50) = b[2];
}
PCREG(4eb020, boxSetMatAndVecs);
