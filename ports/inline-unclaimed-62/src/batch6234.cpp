// batch6234 - unclaimed-62 claim 27 (short exe leaves): two small thiscall functions.
//   0x4dd8d0  thiscall, no argument, returns al: 1 when [this+0x54] and then [+0x10] are non-null and that object's byte +0x18 has bit 0 set; else 0
//   0x54e600  thiscall, one argument (ret 4): copies the zero-terminated string at the argument into this+0x1ca (the exe's byte loop, the terminator included)
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static u8 THISCALL fn4dd8d0(u8 *self) {
  u8 *p = rdp(self + 0x54);
  if (p == 0) return 0;
  u8 *q = rdp(p + 0x10);
  if (q == 0) return 0;
  if ((q[0x18] & 1) == 0) return 0;
  return 1;
}

static void THISCALL fn54e600(u8 *self, u8 *src) {
  u8 *d = self + 0x1ca;
  u8 *s = src;
  for (;;) {
    u8 c = *s;
    *d = c;
    if (c == 0) break;
    s++;
    d++;
  }
}

PCREG(4dd8d0, fn4dd8d0);
PCREG(54e600, fn54e600);
