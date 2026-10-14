// batch34081.cpp - escalation batch 34081: 0x537e90, 0x63b050, 0x6486e0 (free-list pops), 0x62ce20 / 0x62d160 / 0x62d940 / 0x62db60 (event filters), 0x532800 (box test).
#include "ff.h"

static void w32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x537e90, thiscall(a, b, c) ret 0xc, bool: false when a == 4. Else dword [this+13a+0x1e] = b, byte [this+13a+0x15] = 1, dword [this+13(a+2)] = c; true (unaligned fields, byte stores).
static bool THISCALL fn537e90(u8 *self, u32 a, u32 b, u32 c) {
  if (a == 4) return false;
  u32 d = a * 13;
  w32(self + d + 0x1e, b);
  self[d + 0x15] = 1;
  w32(self + (a + 2) * 13, c);
  return true;
}
PCREG(537e90, fn537e90);

// 0x63b050, thiscall, plain ret: free-list pop, 0x4c-byte entries: i = word [this+2]; 0 when 0xffff. c = this + i*0x4c; word [this+2] = word [c+0x10]; dwords c+0x10 = 0, c+0x14 = 0xffff1203, c+0x48, c+0x54, c+0x50,
// c+0x58 = 0; word c+0x4d = 0; bytes c+0x4c, c+0x4f = 0; byte [this] += 1; returns c+0x10.
static u32 THISCALL fn63b050(u8 *self) {
  u32 i = *(u16 *)(self + 2);
  if ((u16)i == 0xffff) return 0;
  u8 *c = self + i * 0x4c;
  *(u16 *)(self + 2) = *(u16 *)(c + 0x10);
  w32(c + 0x10, 0);
  w32(c + 0x14, 0xffff1203);
  w32(c + 0x48, 0);
  *(u16 *)(c + 0x4d) = 0;
  w32(c + 0x54, 0);
  w32(c + 0x50, 0);
  c[0x4c] = 0;
  w32(c + 0x58, 0);
  c[0x4f] = 0;
  self[0] += 1;
  return (u32)(c + 0x10);
}
PCREG(63b050, fn63b050);

// 0x6486e0, thiscall, plain ret: free-list pop, 32-byte entries: i = word [this+2]; 0 when 0xffff. c = this + i*32; word [this+2] = word [c+0x10]; word [c+0x22] = 0xffff; dwords c+0x10 = 0, c+0x14 = 0xffff1206,
// c+0x18, c+0x1c, c+0x24, c+0x2c, c+0x28 = 0; byte c+0x20 = 0; byte [this] += 1; returns c+0x10.
static u32 THISCALL fn6486e0(u8 *self) {
  u32 i = *(u16 *)(self + 2);
  if ((u16)i == 0xffff) return 0;
  u8 *c = self + i * 32;
  *(u16 *)(self + 2) = *(u16 *)(c + 0x10);
  *(u16 *)(c + 0x22) = 0xffff;
  w32(c + 0x10, 0);
  w32(c + 0x14, 0xffff1206);
  w32(c + 0x18, 0);
  w32(c + 0x1c, 0);
  w32(c + 0x24, 0);
  w32(c + 0x2c, 0);
  w32(c + 0x28, 0);
  c[0x20] = 0;
  self[0] += 1;
  return (u32)(c + 0x10);
}
PCREG(6486e0, fn6486e0);

// 0x62ce20 / 0x62d160 / 0x62d940 / 0x62db60, cdecl(a, id), event filters: id 0xf returns 0; id 0x1b sets [a] = X and returns R; otherwise when [a+0xc] is zero and id is 0x1c returns 0x34; else [a] = 0x51f230, returns -1.
static s32 filter(u32 *a, u32 id, u32 X, s32 R) {
  if (id == 0xf) return 0;
  if (id == 0x1b) { a[0] = X; return R; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
static s32 fn62ce20(u32 *a, u32 id) { return filter(a, id, 0x62ca20, 0x22); }
static s32 fn62d160(u32 *a, u32 id) { return filter(a, id, 0x62d1b0, 4); }
static s32 fn62d940(u32 *a, u32 id) { return filter(a, id, 0x62d990, 0xb); }
static s32 fn62db60(u32 *a, u32 id) { return filter(a, id, 0x62cf90, 0xb); }
PCREG(62ce20, fn62ce20);
PCREG(62d160, fn62d160);
PCREG(62d940, fn62d940);
PCREG(62db60, fn62db60);

// 0x532800, thiscall(a1, a2, p, q) ret 0x10, bool: p[i] < [this+0x10+4i] (signed) for i = 0..2 and q[i] > [this+4+4i] for i = 0..2.
static bool THISCALL fn532800(s32 *self, u32 a1, u32 a2, s32 *p, s32 *q) {
  (void)a1; (void)a2;
  if (!(p[0] < self[4])) return false;
  if (!(p[1] < self[5])) return false;
  if (!(p[2] < self[6])) return false;
  if (!(q[0] > self[1])) return false;
  if (!(q[1] > self[2])) return false;
  if (!(q[2] > self[3])) return false;
  return true;
}
PCREG(532800, fn532800);
