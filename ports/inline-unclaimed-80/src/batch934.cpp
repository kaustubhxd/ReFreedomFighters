#include "ff.h"
// batch934.cpp - unclaimed-80 group (docs/20-unclaimed-80.md). Gap band 0x401000-0x4a1000. Two ZSTDOBJ checks, both thiscall, both
// call slot of the global's object: obj = [[[0x70039c] + 0x1aa3] + 0x18]; v = [[this+8] + 0x6c].
//   0x43df80 ZSTDOBJ::CheckBoxInside(const float*, const float*, const float*) (high), ret 12: returns obj slot +0x20 (v, a1, a2, a3).
//   0x43dfb0 ZSTDOBJ::CheckPointInside(const float*, float) const (high), ret 8: returns obj slot +0x1c (v, a1, float bits).

static u8 *zstdObj(void) {
  return *(u8 **)(*(u8 **)(G(u8 *, 0x70039c) + 0x1aa3) + 0x18);
}

static u32 THISCALL zstdCheckBoxInside(u8 *self, u32 a1, u32 a2, u32 a3) {
  u8 *o = zstdObj();
  u32 v = *(u32 *)(*(u32 *)(self + 8) + 0x6c);
  typedef u32(THISCALL * slot_fn)(u8 *, u32, u32, u32, u32);
  return ((slot_fn)(*(u32 *)(*(u32 *)o + 0x20)))(o, v, a1, a2, a3);
}
PCREG(43df80, zstdCheckBoxInside);

static u32 THISCALL zstdCheckPointInside(u8 *self, u32 a1, u32 fbits) {
  u8 *o = zstdObj();
  u32 v = *(u32 *)(*(u32 *)(self + 8) + 0x6c);
  typedef u32(THISCALL * slot_fn)(u8 *, u32, u32, u32);
  return ((slot_fn)(*(u32 *)(*(u32 *)o + 0x1c)))(o, v, a1, fbits);
}
PCREG(43dfb0, zstdCheckPointInside);
