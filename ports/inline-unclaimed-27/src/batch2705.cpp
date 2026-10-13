#include "ff.h"
// batch2705.cpp - unclaimed-27 claim 5 (docs/20-unclaimed-27.md). Name from the GC name map (high).
// Helpers are original code (bound by build.sh): 0x43e920 (PSVECSubtract, low name: fastcall, three arguments, ret 4) and
// 0x43e960 (fastcall, two arguments, ret 0).

extern "C" void FASTCALL ext_43e920(float *out, const float *a, const float *b);
extern "C" void FASTCALL ext_43e960(float *a, const float *b);

// 0x441660, ZGROUP::ResetGroupPosition(bool) (high). Thiscall, ret 4.
// Flag byte 0: if bit 0x40000000 of this+0x30 is set, calls vtable slot +0x2a4 with (0, 0x40000000); flag nonzero: if the bit
// is clear, calls it with (0x40000000, 0); otherwise returns. Then: copies the vector at g+0x30 to a
// local L, copies g+0x24 to g+0x30, puts L at g+0x24, and computes L = g+0x24 - g+0x30 (PSVECSubtract). Then for every node
// in the list from this+0x50 (linked by +0x60): node+0x24 -= L (0x43e960).
static void THISCALL zGroupResetGroupPosition(u8 *self, u32 flag) {
  typedef void(THISCALL * slot2a4_fn)(u8 *, u32, u32);
  if ((u8)flag == 0) {
    if (!(*(u32 *)(self + 0x30) & 0x40000000u)) return;
    ((slot2a4_fn)(*(u32 *)(*(u32 *)self + 0x2a4)))(self, 0u, 0x40000000u);
  } else {
    if (*(u32 *)(self + 0x30) & 0x40000000u) return;
    ((slot2a4_fn)(*(u32 *)(*(u32 *)self + 0x2a4)))(self, 0x40000000u, 0u);
  }

  u8 *g = *(u8 **)(self + 8);
  float L[3];
  L[0] = *(float *)(g + 0x30);
  L[1] = *(float *)(g + 0x34);
  L[2] = *(float *)(g + 0x38);
  *(u32 *)(g + 0x30) = *(u32 *)(g + 0x24);
  *(u32 *)(g + 0x34) = *(u32 *)(g + 0x28);
  *(u32 *)(g + 0x38) = *(u32 *)(g + 0x2c);
  *(float *)(g + 0x24) = L[0];
  *(float *)(g + 0x28) = L[1];
  *(float *)(g + 0x2c) = L[2];
  ext_43e920(L, (float *)(g + 0x24), (float *)(g + 0x30));

  u8 *node = *(u8 **)(self + 0x50);
  while (node != 0) {
    ext_43e960((float *)(node + 0x24), L);
    node = *(u8 **)(node + 0x60);
  }
}
PCREG(441660, zGroupResetGroupPosition);
