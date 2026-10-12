// batch6219.cpp - unclaimed-62 claim 12 (slice 2): two small leaves.
//   0x4682f0  thiscall, one float argument (ret 4): stores the float at this+0x1da (raw bits; the exe uses movss)
//   0x561ef0  thiscall, returns al: if this+0x44 is non-zero, clears it and this+0x30 and returns 1; otherwise returns 0
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static void THISCALL fn4682f0(u8 *self, u32 f) { wr32u(self + 0x1da, f); }

static u8 THISCALL fn561ef0(u8 *self) {
  if (rd32u(self + 0x44) == 0) return 0;
  wr32u(self + 0x44, 0);
  wr32u(self + 0x30, 0);
  return 1;
}

PCREG(4682f0, fn4682f0);
PCREG(561ef0, fn561ef0);
