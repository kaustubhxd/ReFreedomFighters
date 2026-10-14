// batch756.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

typedef u32(THISCALL *VtFour)(u8 *, u32, u32, u32, u32);   // vt[0xe0]: this, then four stack words
typedef u32(THISCALL *VtNone)(u8 *);                       // vt[0x20]
typedef void(THISCALL *VtThree)(u8 *, u32, u32, float *);  // vt[0x84]: this, two words, then a float pointer

// 0x43fdd0, thiscall(a0, a1, a2, a3) ret 0x10. Name GUESS.
//   if ([[this+8]+0x6c] != 0 or [this+0x14] & 1):
//     if vt[0xe0](this, a0, a1, a2, a3) == 0 and vt[0x20](this) == 0:
//       a0->vt[0x84](a0, a2, a3, &buf), where buf = {5000.0f, 1.0f, 5000.0f} (the asm's three dwords 0x459c4000,
//       0x3f800000, 0x459c4000). The stack cookie check always passes and is dropped.
static void THISCALL callWithBuf_43fdd0(u8 *self, u8 *a0, u32 a1, u32 a2, u32 a3) {
  u8 *o8 = *(u8 **)(self + 8);
  if (*(u32 *)(o8 + 0x6c) != 0 || (self[0x14] & 1)) {
    VtFour fe0 = (VtFour)(*(u32 *)(*(u32 *)self + 0xe0));
    fe0(self, (u32)a0, a1, a2, a3);   // the asm does not test this result
    VtNone f20 = (VtNone)(*(u32 *)(*(u32 *)self + 0x20));
    if (f20(self) == 0) {
      float buf[3] = {5000.0f, 1.0f, 5000.0f};
      VtThree f84 = (VtThree)(*(u32 *)(*(u32 *)a0 + 0x84));
      f84(a0, a2, a3, buf);
    }
  }
}
PCREG(43fdd0, callWithBuf_43fdd0);
