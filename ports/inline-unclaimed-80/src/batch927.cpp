#include "ff.h"
// batch927.cpp - unclaimed-80 claim 7 (docs/20-unclaimed-80.md). CWheel::Init(const ZGROUP*, ZSTDOBJ*, bool) (0x529a30, vtable).
// Thiscall, three arguments, ret 12. The exe's stack-cookie check (0x633654) is omitted: it has no effect on a valid frame.
// 0x4db7c0 (thiscall, one argument: a pointer to a local vector) is original code, stubbed by the spec; it writes the float
// the code reads back from the local's third dword.

extern "C" void THISCALL ext_4db7c0(u8 *obj, u32 *out);

static void THISCALL wheelInit(u8 *self, u8 *grp, u8 *std, u32 flag) {
  *(u32 *)(self + 0x12f) = (u32)grp;
  self[0x28] = (u8)flag;
  *(u32 *)(self + 0x18) = (u32)std;
  u32 *v = (u32 *)(self + 4);
  v[0] = 0;
  v[1] = 0;
  v[2] = 0;
  typedef void(THISCALL * arg1_fn)(u8 *, u32);
  typedef void(THISCALL * arg2_fn)(u8 *, u32, u32);
  u8 *a = *(u8 **)(self + 0x18);
  ((arg1_fn)(*(u32 *)(*(u32 *)a + 0x84)))(a, (u32)v);
  ((arg1_fn)(*(u32 *)(*(u32 *)grp + 0x8c)))(grp, (u32)v);
  *(u32 *)(self + 0x1c) = v[0];
  *(u32 *)(self + 0x20) = v[1];
  *(u32 *)(self + 0x24) = v[2];
  *(u32 *)(self + 0x20) = 0;
  u32 local[4] = {0, 0, 0, 0};
  u8 *c = *(u8 **)(*(u8 **)(self + 0x18) + 8);
  ext_4db7c0(c, local);
  *(u32 *)(self + 0x14) = local[2];
  ((arg2_fn)(*(u32 *)(*(u32 *)self + 4)))(self, (u32)grp, (u32)std);
}
PCREG(529a30, wheelInit);
