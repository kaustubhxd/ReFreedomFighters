// batch6232 - unclaimed-62 claim 25 (short exe leaves): four small functions.
//   0x4d1b70  thiscall, no argument, returns the count of the chain that starts at this+0x24 and links through +0x30 (0 if null)
//   0x4d1b90  thiscall, no argument, returns the count of the chain that starts at this+0x18 and links through +8 (0 if null)
//   0x5a4590  thiscall, one argument (ret 4): n = arg; if (n - 1) <= 3 (unsigned), returns this + 0x99 + n * 16, else 0
//   0x54a220  thiscall, one argument (ret 4): c = this+0xa269; if c != 0 and arg != 0 returns arg + c, else 0
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn4d1b70(u8 *self) {
  u32 n = 0;
  u8 *p = rdp(self + 0x24);
  while (p != 0) {
    p = rdp(p + 0x30);
    n++;
  }
  return n;
}

static u32 THISCALL fn4d1b90(u8 *self) {
  u32 n = 0;
  u8 *p = rdp(self + 0x18);
  while (p != 0) {
    p = rdp(p + 8);
    n++;
  }
  return n;
}

static u32 THISCALL fn5a4590(u8 *self, u32 n) {
  if (n - 1 > 3) return 0;
  return (u32)(self + 0x99 + n * 16);
}

static u32 THISCALL fn54a220(u8 *self, u32 a) {
  u32 c = rd32u(self + 0xa269);
  if (c == 0) return 0;
  if (a == 0) return 0;
  return a + c;
}

PCREG(4d1b70, fn4d1b70);
PCREG(4d1b90, fn4d1b90);
PCREG(5a4590, fn5a4590);
PCREG(54a220, fn54a220);
