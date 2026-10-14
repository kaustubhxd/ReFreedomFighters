// batch886.cpp - area 50 (residue-09 candidate table row): 0x598d90 [31 instr, thiscall, four stack args (ret 0x10), void;
// GUESS "Append598d90": append one 24-byte record to the table at this+0x4ff (capacity 0x100, count at this+0x1cff):
// three dwords copied from the vector at arg0, then arg1 (dword at +0x50b), arg2 (float at +0x50f) and arg3 (dword at +0x513).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x598d90 (name GUESS).
static void THISCALL Append598d90(u8 *self, const u32 *vec, u32 a1, float a2, u32 a3) {
  u32 n = U32(self, 0x1cff);
  if (n >= 0x100u) return;
  u32 *rec = (u32 *)(self + 0x4ff + 24 * n);   // edx = 3*n, *8 = 24*n
  rec[0] = vec[0];
  rec[1] = vec[1];
  rec[2] = vec[2];
  U32(self, 0x50b + 24 * n) = a1;
  *(float *)(self + 0x50f + 24 * n) = a2;
  U32(self, 0x513 + 24 * n) = a3;
  U32(self, 0x1cff) = n + 1;
}
PCREG(598d90, Append598d90);
