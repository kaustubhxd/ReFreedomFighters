// batch6235 - unclaimed-62 claim 28 (short call-free exe functions): four small functions.
//   0x54dbb0  stdcall, one argument (a pointer; ret 4): returns (a[0x24] / a[0xc]) / a[0x1c] (unsigned; divisors non-zero)
//   0x54e430  thiscall, no argument: for i in 0 .. this[0x1c5] - 1 (signed): this[0x68 + 0x6b*i] = 0
//   0x54e9a0  thiscall, no argument: this[4] = 0, this[0] = vtable 0x6a4124, this[8] = 0; returns this (eax)
//   0x4cdaf0  thiscall, one argument (mask; ret 4): x = this[0x10]; t = this[4]; returns (t[(x & m)] & ~x) == (~x & m) as al
#include "ff.h"

static u32 rd32u(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static u8 *rdp(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return (u8 *)v; }

static u32 STDCALL fn54dbb0(u8 *a) {
  u32 q = rd32u(a + 0x24) / rd32u(a + 0xc);
  return q / rd32u(a + 0x1c);
}

static void THISCALL fn54e430(u8 *self) {
  s32 n = (s32)rd32u(self + 0x1c5);
  for (s32 i = 0; i < n; i++) self[0x68 + 0x6b * i] = 0;
}

static u8 *THISCALL fn54e9a0(u8 *self) {
  wr32u(self + 4, 0);
  wr32u(self, 0x6a4124);
  wr32u(self + 8, 0);
  return self;
}

static u8 THISCALL fn4cdaf0(u8 *self, u32 m) {
  u32 x = rd32u(self + 0x10);
  u8 *t = rdp(self + 4);
  u32 v = rd32u(t + (x & m) * 4) & ~x;
  return (v == (~x & m)) ? 1 : 0;
}

PCREG(54dbb0, fn54dbb0);
PCREG(54e430, fn54e430);
PCREG(54e9a0, fn54e9a0);
PCREG(4cdaf0, fn4cdaf0);
