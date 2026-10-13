#include "ff.h"
// batch2711.cpp - unclaimed-27 batch 11 (docs/20-unclaimed-27.md). Name from the GC name map (high).

// 0x483a60, ZPlayer::GetCenterSphere(float*, float*, float*) const (high). Thiscall, ret 0xc.
// Calls vtable slot +0x59c with (a1, a2) (callee cleans, ret 8), then copies the three dwords at this+0x439, +0x43d and
// +0x441 to the out pointer (the third argument).
static void THISCALL zPlayerGetCenterSphere(u8 *self, u32 a1, u32 a2, u32 *out) {
  typedef void(THISCALL * slot59c_fn)(u8 *, u32, u32);
  ((slot59c_fn)(*(u32 *)(*(u32 *)self + 0x59c)))(self, a1, a2);
  out[0] = *(u32 *)(self + 0x439);
  out[1] = *(u32 *)(self + 0x43d);
  out[2] = *(u32 *)(self + 0x441);
}
PCREG(483a60, zPlayerGetCenterSphere);
