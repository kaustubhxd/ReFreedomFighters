// batch6220.cpp - unclaimed-62 claim 13 (slice 2): eight call-free leaves.
//   0x4e6400  thiscall, returns al: byte at *this; 0xff -> 0, otherwise bit 6 of it
//   0x440cc0  thiscall, returns eax: count of the chain this+8 -> (+0x50) -> ... until null
//   0x4cf100  thiscall, one argument (dst, ret 4): dst+4 = 0, dst+8 = 1, dst = src+4; src+0xc &= 0x7fffffff
//   0x594f40  thiscall, one argument (flag, ret 4): this+0x417 |= 0x80000 when the flag byte is set, else &= 0xfff7ffff
//   0x581960  thiscall, one argument (ret 4): stores it at this+0x754 + 4*count, count (this+0x750) += 1, this+0xa54 = &this+0x754 + 4*(count+0x1d5)
//   0x5ac600  thiscall, four arguments (ret 0x10): stores them at this+9, +0xd, +0x11, +0x15
//   0x5966e0  thiscall, returns al: this+0x9d3 == arg and this+0x66c byte non-zero
//   0x4cf570  thiscall, one argument (pointer to a dword, ret 4): 0 if the dword is 0, else dword + (2 - this+0x18) * 4
#include "ff.h"

static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }
static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u8 THISCALL fn4e6400(u8 *self) {
  u8 b = *rdp(self);
  if (b == 0xff) return 0;
  return (u8)((b >> 6) & 1);
}

static u32 THISCALL fn440cc0(u8 *self) {
  u32 n = 0;
  u8 *p = rdp(self + 8);
  if (!p) return 0;
  do {
    p = rdp(p + 0x50);
    n++;
  } while (p);
  return n;
}

static void THISCALL fn4cf100(u8 *self, u8 *dst) {
  wr32u(dst + 4, 0);
  wr32u(dst + 8, 1);
  wr32u(dst, rd32u(self + 4));
  wr32u(self + 0xc, rd32u(self + 0xc) & 0x7fffffffu);
}

static void THISCALL fn594f40(u8 *self, u32 flag) {
  u32 v = rd32u(self + 0x417);
  if ((u8)flag) v |= 0x80000u;
  else v &= 0xfff7ffffu;
  wr32u(self + 0x417, v);
}

static void THISCALL fn581960(u8 *self, u32 val) {
  u32 cnt = rd32u(self + 0x750);
  wr32u(self + 0x754 + cnt * 4, val);
  cnt++;
  wr32u(self + 0x750, cnt);
  wr32u(self + 0xa54, (u32)(self + (cnt + 0x1d5) * 4));
}

static void THISCALL fn5ac600(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  wr32u(self + 9, a);
  wr32u(self + 0xd, b);
  wr32u(self + 0x11, c);
  wr32u(self + 0x15, d);
}

static u8 THISCALL fn5966e0(u8 *self, u32 arg) {
  if (rd32u(self + 0x9d3) == arg && self[0x66c] != 0) return 1;
  return 0;
}

static u32 THISCALL fn4cf570(u8 *self, u8 *pp) {
  u32 edx = rd32u(pp);
  if (edx == 0) return 0;
  return edx + (2 - rd32u(self + 0x18)) * 4;
}

PCREG(4e6400, fn4e6400);
PCREG(440cc0, fn440cc0);
PCREG(4cf100, fn4cf100);
PCREG(594f40, fn594f40);
PCREG(581960, fn581960);
PCREG(5ac600, fn5ac600);
PCREG(5966e0, fn5966e0);
PCREG(4cf570, fn4cf570);
