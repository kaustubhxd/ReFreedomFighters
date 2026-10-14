// batch34080.cpp - escalation batch 34080: ten small queue items (constructors, loops, table helpers).
#include "ff.h"

// 0x5df690 / 0x5df620, thiscall(a, b, c, d) ret 0x10, return this: fields +4..+0x10 = a..d, vtable pointer [this] = 0x6b7400 / 0x6b7388.
static u32 THISCALL fn5df690(u32 *self, u32 a, u32 b, u32 c, u32 d) {
  self[1] = a; self[2] = b; self[3] = c; self[4] = d; self[0] = 0x6b7400;
  return (u32)self;
}
PCREG(5df690, fn5df690);
static u32 THISCALL fn5df620(u32 *self, u32 a, u32 b, u32 c, u32 d) {
  self[1] = a; self[2] = b; self[3] = c; self[4] = d; self[0] = 0x6b7388;
  return (u32)self;
}
PCREG(5df620, fn5df620);

// 0x65f170, thiscall, plain ret: for the [this+0xcc] objects pointed to by the dwords at this+0xd0 (do-while compared with !=): [obj+0x24] = 2, [obj+0x44] = 0. Then [this+0xc4] = 0x80.
static void THISCALL fn65f170(u8 *self) {
  u32 n = *(u32 *)(self + 0xcc);
  if (n != 0) {
    u32 i = 0;
    u32 *pp = (u32 *)(self + 0xd0);
    do {
      u8 *o = (u8 *)*pp++;
      i++;
      *(u32 *)(o + 0x24) = 2;
      *(u32 *)(o + 0x44) = 0;
    } while (i != *(u32 *)(self + 0xcc));
  }
  *(u32 *)(self + 0xc4) = 0x80;
}
PCREG(65f170, fn65f170);

// 0x533ce0, thiscall, returns this: [this+4] = 1, [this] = 0; for k = 2..0x7ff: dword at this+0x14+8*(k-2) = k | 0x80000000; then dword [this+0x4004] = 0.
static u32 THISCALL fn533ce0(u8 *self) {
  u32 k = 1;
  u8 *e = self + 0x14;
  *(u32 *)(self + 4) = 1;
  *(u32 *)self = 0;
  do {
    k++;
    e += 8;
    *(u32 *)(e - 8) = k | 0x80000000;
  } while ((s32)k < 0x7ff);
  *(u32 *)(self + k * 8 + 0xc) = 0;
  return (u32)self;
}
PCREG(533ce0, fn533ce0);

// 0x63da80, thiscall(a) ret 4: i = word [a+6]; when i != 0xffff: word [a+6] = 0xffff, dword [this+0x270+4*i] = 0. byte [a+5] |= 1; [a] = [[0x70039c]+0x3c]; returns that value.
static u32 THISCALL fn63da80(u8 *self, u8 *a) {
  u32 i = *(u16 *)(a + 6);
  if ((u16)i != 0xffff) {
    *(u16 *)(a + 6) = 0xffff;
    *(u32 *)(self + i * 4 + 0x270) = 0;
  }
  a[5] |= 1;
  u32 v = *(u32 *)(G(u8 *, 0x70039c) + 0x3c);
  *(u32 *)a = v;
  return v;
}
PCREG(63da80, fn63da80);

// 0x622aa0, cdecl(a, b), returns a pointer: skips bytes of b whose class (a[0x4c + byte]) is 9, 10 or 0x15 while the class is at least 9.
static u8 *fn622aa0(u8 *a, u8 *b) {
  u8 c = a[0x4c + *b];
  while (c >= 9 && (c <= 0xa || c == 0x15)) {
    b++;
    c = a[0x4c + *b];
  }
  return b;
}
PCREG(622aa0, fn622aa0);

// 0x63b160, thiscall, plain ret: pops an entry from the free list: i = word [this+2]; 0 when 0xffff. Else e = this + 24*i + 0x10: word [this+2] = word [e]; dwords e+0 = 0, e+4 = 0xffff1206, e+8 = 0, e+0x14 = 0,
// e+0xc = 0, e+0x10 = 0; byte [this] += 1; returns e.
static u32 THISCALL fn63b160(u8 *self) {
  u32 i = *(u16 *)(self + 2);
  if ((u16)i == 0xffff) return 0;
  u8 *e = self + i * 24 + 0x10;
  *(u16 *)(self + 2) = *(u16 *)e;
  *(u32 *)e = 0;
  *(u32 *)(e + 4) = 0xffff1206;
  *(u32 *)(e + 8) = 0;
  *(u32 *)(e + 0x14) = 0;
  *(u32 *)(e + 0xc) = 0;
  *(u32 *)(e + 0x10) = 0;
  self[0] += 1;
  return (u32)e;
}
PCREG(63b160, fn63b160);

// 0x5aedf0, thiscall(a) ret 4: set insert into a 20-entry array: n = [this]; nothing when n >= 0x14 or a is already among the n dwords at this+4; else [this+4+4n] = a, [this] += 1.
static void THISCALL fn5aedf0(u32 *self, u32 a) {
  u32 n = self[0];
  if (n >= 0x14) return;
  for (u32 i = 0; i < n; i++)
    if (self[1 + i] == a) return;
  self[1 + n] = a;
  self[0]++;
}
PCREG(5aedf0, fn5aedf0);

// 0x4d12e0, thiscall(a) ret 4, bool: any of the [this+0x88] 12-byte ranges (lo at +0x10, hi at +0x14 of the entry, unsigned) with lo <= a < hi.
static bool THISCALL fn4d12e0(u8 *self, u32 a) {
  u32 n = *(u32 *)(self + 0x88);
  for (u32 i = 0; i < n; i++) {
    u32 lo = *(u32 *)(self + 0x10 + 12 * i), hi = *(u32 *)(self + 0x14 + 12 * i);
    if (!(lo > a) && a < hi) return true;
  }
  return false;
}
PCREG(4d12e0, fn4d12e0);

// 0x5edc80, fastcall-like (ecx = begin, edx = end) plus one unused stack dword, ret 4: reverses the dwords in [begin, end).
static void FASTCALL fn5edc80(u32 *b, u32 *e, u32 unused) {
  (void)unused;
  if (b == e) return;
  for (;;) {
    e--;
    if (b == e) break;
    u32 t = *b;
    *b = *e;
    b++;
    *e = t;
    if (b == e) break;
  }
}
PCREG(5edc80, fn5edc80);
