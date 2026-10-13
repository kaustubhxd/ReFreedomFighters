// batch1143.cpp - collision thread, batch 1143 (hard-row lane, name GUESS): 0x45edf0. Thiscall (ECX = this), seven stack
// arguments (a1, a2, A, B, C, D, f), ret 0x1c. If the six dwords at A and at B are equal and the three dwords at C and at D
// are equal, returns 0. Otherwise calls slot 0xa4 of this with (a1, A, B, f) and slot 0xa8 with (a2, C, D, f) and returns 1.
#include "ff.h"

static u8 THISCALL test45edf0(u8 *self, u32 a1, u32 a2, u32 *A, u32 *B, u32 *C, u32 *D, float f) {
  bool same = true;
  for (int k = 0; k < 6; k++) {
    if (A[k] != B[k]) {
      same = false;
      break;
    }
  }
  if (same && C[0] == D[0] && C[1] == D[1] && C[2] == D[2]) return 0;
  vcall<void>(self, 0xa4, a1, (u32)A, (u32)B, f);
  vcall<void>(self, 0xa8, a2, (u32)C, (u32)D, f);
  return 1;
}
PCREG(45edf0, test45edf0);
