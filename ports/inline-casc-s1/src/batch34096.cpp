// batch34096.cpp - escalation batch 34096: 0x533da0 (free-list alloc), 0x5be720 (round-robin slot search), 0x63dbc0, 0x62d560 (event filter), 0x545cb0, 0x5aef80, 0x52db40.
#include "ff.h"

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x533da0, thiscall(a, b) ret 8: free list of 8-byte nodes (words at +8 value, +0xc link): i = [this+4]; [this]++; [this+4] = link(i) & 0x7fffffff; link(i) = 0xfffffffe; value(i) = b. When a is 0 or 0x80000000: link(i) = 0x80000000, returns i.
// Else link(i) = link(a); link(a) = i; returns a.
static u32 THISCALL fn533da0(u32 *self, u32 a, u32 b) {
  u32 i = self[1];
  u32 link = self[i * 2 + 3];
  self[0]++;
  self[1] = link & 0x7fffffff;
  self[i * 2 + 3] = 0xfffffffe;
  self[i * 2 + 2] = b;
  if (a == 0x80000000 || a == 0) {
    self[i * 2 + 3] = 0x80000000;
    return i;
  }
  self[i * 2 + 3] = self[a * 2 + 3];
  self[a * 2 + 3] = i;
  return a;
}
PCREG(533da0, fn533da0);

// 0x5be720, thiscall, plain ret: n = [this+0x910] (signed); up to n times: cursor (unaligned dword [this+0x922]) += 1, wrapped to 0 when it reaches n; the first 5-byte entry (this+0x718+5*cursor) whose tag byte (+4) is 0xff is returned (address).
// When none is found the assert hook [0x7003b0] is tail called (int3 when null).
static u32 THISCALL fn5be720(u8 *self) {
  s32 n = *(s32 *)(self + 0x910);
  for (s32 i = 0; i < n; i++) {
    wr32(self + 0x922, rd32(self + 0x922) + 1);
    if (!((s32)rd32(self + 0x922) < n)) wr32(self + 0x922, 0);
    u32 c = rd32(self + 0x922);
    u8 *e = self + 0x718 + c * 5;
    if (e[4] == 0xff) return (u32)e;
  }
  typedef u32 (*hf)(void);
  hf h = G(hf, 0x7003b0);
  if (!h) { asm volatile("int3"); }
  return h();
}
PCREG(5be720, fn5be720);

// 0x63dbc0, thiscall(a) ret 4: the first of the [this+0xec] pointers at this+0xf0 whose unaligned dword [e+0x10029] equals a (a == 0 matches the first one); 0 when none.
static u32 THISCALL fn63dbc0(u8 *self, u32 a) {
  u32 n = *(u32 *)(self + 0xec);
  for (u32 i = 0; i < n; i++) {
    u8 *e = *(u8 **)(self + 0xf0 + 4 * i);
    if (a == 0 || a == rd32(e + 0x10029)) return (u32)e;
  }
  return 0;
}
PCREG(63dbc0, fn63dbc0);

// 0x62d560, cdecl(a, id) event filter: id 0xf returns 0; 0x15 stores 0x62d510 and returns 0; 0x24 stores 0x62cf90 and returns 0x29; id 0x1c with [a+0xc] zero returns 0x34; otherwise stores 0x51f230 and returns -1.
static s32 fn62d560(u32 *a, u32 id) {
  if (id == 0xf) return 0;
  if (id == 0x15) { a[0] = 0x62d510; return 0; }
  if (id == 0x24) { a[0] = 0x62cf90; return 0x29; }
  if (a[3] == 0 && id == 0x1c) return 0x34;
  a[0] = 0x51f230;
  return -1;
}
PCREG(62d560, fn62d560);

// 0x545cb0, thiscall(i, p1, p2, p3, p4) ret 0x14, returns the last dword read: e = unaligned [this+0xf] + 0x34*i; p1[0..2] = e+0xc..0x14; p2[0..2] = e+0x24..0x2c; *p3 = e+0x30; p4[0..2] = e+0x18..0x20.
static u32 THISCALL fn545cb0(u8 *self, u32 i, u32 *p1, u32 *p2, u32 *p3, u32 *p4) {
  u8 *e = (u8 *)rd32(self + 0xf) + i * 0x34;
  p1[0] = *(u32 *)(e + 0xc);
  p1[1] = *(u32 *)(e + 0x10);
  p1[2] = *(u32 *)(e + 0x14);
  p2[0] = *(u32 *)(e + 0x24);
  p2[1] = *(u32 *)(e + 0x28);
  p2[2] = *(u32 *)(e + 0x2c);
  *p3 = *(u32 *)(e + 0x30);
  p4[0] = *(u32 *)(e + 0x18);
  p4[1] = *(u32 *)(e + 0x1c);
  u32 v = *(u32 *)(e + 0x20);
  p4[2] = v;
  return v;
}
PCREG(545cb0, fn545cb0);

// 0x5aef80, thiscall(a) ret 4: the [+4] field of the first of the [this] objects (pointers at this+4) whose dword +0x10 equals a; 0 when none.
static u32 THISCALL fn5aef80(u8 *self, u32 a) {
  u32 n = *(u32 *)self;
  for (u32 i = 0; i < n; i++) {
    u8 *e = *(u8 **)(self + 4 + 4 * i);
    if (a == *(u32 *)(e + 0x10)) return e ? *(u32 *)(e + 4) : 0;
  }
  return 0;
}
PCREG(5aef80, fn5aef80);

// 0x52db40, thiscall, plain ret: d = [[this]+0x38] - unaligned [this+0x12]; d == 0: unaligned dwords +0x21, +0x25, +0x29 = 1; else +0x21 = +0x25 = 8 << ((d-1) & 31), +0x29 = 1 << ((d-1) & 31). Then, with s = [this+0x12] and m = [[this]+0x38]:
// byte [this+0x20] = 3 when s == m, 2 when s == m - 1, 1 when s <= m - 2 (signed), in that order.
static void THISCALL fn52db40(u8 *self) {
  s32 m = *(s32 *)(*(u8 **)self + 0x38);
  s32 s = (s32)rd32(self + 0x12);
  s32 d = m - s;
  if (d == 0) {
    wr32(self + 0x21, 1);
    wr32(self + 0x25, 1);
    wr32(self + 0x29, 1);
  } else {
    u32 cl = (u32)(d - 1) & 31;
    wr32(self + 0x21, 8u << cl);
    wr32(self + 0x25, 8u << cl);
    wr32(self + 0x29, 1u << cl);
  }
  m = *(s32 *)(*(u8 **)self + 0x38);
  s = (s32)rd32(self + 0x12);
  if (s == m) self[0x20] = 3;
  if (s == m - 1) self[0x20] = 2;
  if (s <= m - 2) self[0x20] = 1;
}
PCREG(52db40, fn52db40);
