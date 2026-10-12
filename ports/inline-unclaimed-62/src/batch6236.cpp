// batch6236 - unclaimed-62 claim 29 (short call-free exe functions): three small thiscall functions.
//   0x4d2300  thiscall, two arguments (ret 8): this[4] = arg2, this[8] = arg1, this[0] = vtable 0x6962dc, this[0xc] = 0; returns this
//   0x4e0e30  thiscall, one argument p (ret 4): this[0] = vtable 0x6970f4; this[4] = (*p & 0xffffff) - 4; this[8] = this[0xc] = p + 4; returns this
//   0x5a46f0  thiscall, one argument n (ret 4): k = n - 3; if k < 0 (signed) or n > 6 returns 0, else this + 18 * k + 0x61
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u8 *THISCALL fn4d2300(u8 *self, u32 a1, u32 a2) {
  wr32u(self + 4, a2);
  wr32u(self + 8, a1);
  wr32u(self, 0x6962dc);
  wr32u(self + 0xc, 0);
  return self;
}

static u8 *THISCALL fn4e0e30(u8 *self, u32 p) {
  wr32u(self, 0x6970f4);
  wr32u(self + 4, (rd32u((const u8 *)p) & 0xffffffu) - 4);
  wr32u(self + 8, p + 4);
  wr32u(self + 0xc, p + 4);
  return self;
}

static u32 THISCALL fn5a46f0(u8 *self, u32 n) {
  s32 k = (s32)n - 3;
  if (k < 0 || (s32)n > 6) return 0;
  return (u32)(self + 18 * k + 0x61);
}

PCREG(4d2300, fn4d2300);
PCREG(4e0e30, fn4e0e30);
PCREG(5a46f0, fn5a46f0);
