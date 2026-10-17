// batch33044.cpp - h3 (Sonnet) batch 33044: tier B vector-ish ctors, list destroy, table loads
#include "ff.h"

extern "C" void STDCALL ext_634123(u8 *p, u32 a, u32 b, u32 c, u32 d);       // ret 0x14
extern "C" void *__attribute__((cdecl)) ext_41e290(u32 n);                    // operator new
extern "C" void *__attribute__((cdecl)) ext_634d10(void *p, int v, u32 n);    // memset
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 n);
extern "C" void *STDCALL ext_6014a0(u32 n);                                   // ret 4, new wrapper
extern "C" u32 THISCALL ext_615650(u8 *self);                                 // bool in al

// 0x65e0b0: thiscall ctor
static u8 *THISCALL fn65e0b0(u8 *self) {
  *(u32 *)self = 0x6c48f4;
  ext_634123(self + 4, 0xc, 0x10, 0x65e090, 0x4690b0);
  u8 *edx = self + 0x2d0;
  *(u32 *)(self + 0xcc) = 0;
  *(u32 *)(edx + 0x3400) = 0;
  u32 i = 0;
  do {
    u32 cx = i + 1;
    i++;
    *(u16 *)edx = (u16)cx;
    edx += 0x68;
  } while (i != 0x7f);
  *(u16 *)edx = 0xffff;
  *(u32 *)(self + 0xc8) = 0;
  *(u32 *)(self + 0xc4) = 0x80;
  return self;
}
PCREG(65e0b0, fn65e0b0);

// 0x4e6c80: thiscall(a,b,c,d) ret 0x10
static u16 *THISCALL fn4e6c80(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u32 m = (d - a) & (d - 1);
  *(u32 *)self = c;
  *(u32 *)(self + 8) = b;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0xc) = m + a;
  u16 *p = (u16 *)ext_41e290(b + b);
  *(u16 **)(self + 4) = p;
  *(u8 *)(self + 0x14) = 0;
  for (int i = 0; i < *(int *)(self + 8); i++) p[i] = (u16)i;
  return p;
}
PCREG(4e6c80, fn4e6c80);

// 0x65e350: thiscall(src, n) ret 8
static void THISCALL fn65e350(u8 *self, u32 *src, u32 n) {
  u64 sz = (u64)n * 4;
  u32 *p = (u32 *)ext_41e290(sz > 0xffffffffull ? 0xffffffffu : (u32)sz);
  *(u32 **)self = p;
  for (u32 i = 0; i != n && n != 0; i++) {
    u8 *so = *(u8 **)(*(u8 **)0x70039c + 0x1aa3);
    p[i] = *(u32 *)(so + 0x20) + src[i];
  }
  *(u32 *)(self + 4) = n;
}
PCREG(65e350, fn65e350);

// 0x62f390: cdecl(p)
static void fn62f390(u8 *p) {
  *(u32 *)(p + 0x34) = *(u32 *)(p + 0x24) * 2;
  u32 n = *(u32 *)(p + 0x44);
  u8 *buf = *(u8 **)(p + 0x3c);
  *(u16 *)(buf + n * 2 - 2) = 0;
  ext_634d10(*(void **)(p + 0x3c), 0, *(u32 *)(p + 0x44) * 2 - 2);
  u32 idx = *(u32 *)(p + 0x7c);
  u8 *t = (u8 *)0x6c0248 + idx * 12;
  *(u32 *)(p + 0x78) = *(u16 *)(t + 2);
  *(u32 *)(p + 0x84) = *(u16 *)(t + 0);
  *(u32 *)(p + 0x88) = *(u16 *)(t + 4);
  *(u32 *)(p + 0x74) = *(u16 *)(t + 6);
  *(u32 *)(p + 0x64) = 0;
  *(u32 *)(p + 0x54) = 0;
  *(u32 *)(p + 0x6c) = 0;
  *(u32 *)(p + 0x70) = 2;
  *(u32 *)(p + 0x58) = 2;
  *(u32 *)(p + 0x60) = 0;
  *(u32 *)(p + 0x40) = 0;
}
PCREG(62f390, fn62f390);

// 0x4fc460: thiscall: destroy and unlink every node of the list headed at [this+0x48]
static void THISCALL fn4fc460(u8 *self) {
  while (*(u8 **)(self + 0x48)) {
    u8 *n = *(u8 **)(self + 0x48);
    if (n) {
      u8 *own = *(u8 **)(n + 0x10);
      if (*(u8 **)(own + 0x50) == n) *(u32 *)(own + 0x50) = *(u32 *)(n + 0xc);
      u8 *prev = *(u8 **)(n + 8);
      u32 next = *(u32 *)(n + 0xc);
      if (prev) *(u32 *)(prev + 0xc) = next;
      else *(u32 *)(*(u8 **)(n + 0x10) + 0x48) = next;
      u8 *nx = *(u8 **)(n + 0xc);
      u32 pv = *(u32 *)(n + 8);
      if (nx) *(u32 *)(nx + 8) = pv;
      else *(u32 *)(*(u8 **)(n + 0x10) + 0x4c) = pv;
      ext_634273(n, 0x15);
    }
  }
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x48) = 0;
  *(u32 *)(self + 0x50) = 0;
}
PCREG(4fc460, fn4fc460);

// 0x606b10: thiscall(n, valptr, unused) ret 0xc: vector of n copies of *valptr
static u8 *THISCALL fn606b10(u8 *self, u32 n, u32 *val, u32 unused) {
  *(u32 *)self = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  u32 *p = n ? (u32 *)ext_6014a0(n * 4) : 0;
  *(u32 **)self = p;
  *(u32 **)(self + 4) = p;
  *(u32 *)(self + 8) = (u32)p + n * 4;
  if (n) {
    do {
      if (p) *p = *val;
      p++;
      n--;
    } while (n != 0);
  }
  *(u32 **)(self + 4) = p;
  return self;
}
PCREG(606b10, fn606b10);

// 0x63ac70: thiscall: skip 0xffff nodes; refill via 0x615650; bump counter; returns pointer or 0
static u8 *THISCALL fn63ac70(u8 *self) {
  u8 *head = *(u8 **)(self + 8);
  u8 *edx;
  if (head) {
    for (;;) {
      u8 *n = *(u8 **)(self + 8);
      if (*(u16 *)(n + 2) != 0xffff) {
        edx = n;
        goto found;
      }
      u8 *nx = *(u8 **)(n + 8);
      *(u8 **)(self + 8) = nx;
      if (head == nx) break;
      if (!nx) break;
    }
  }
  if (!(u8)ext_615650(self)) return 0;
  edx = *(u8 **)(self + 8);
found:
  (*(u32 *)(self + 0xc))++;
  u32 ax = *(u16 *)(edx + 2);
  if ((u16)ax == 0xffff) return 0;
  u8 *p = edx + 0x10 + ax * 0x30;
  u16 cx = *(u16 *)p;
  edx[0]++;
  *(u16 *)(edx + 2) = cx;
  return p;
}
PCREG(63ac70, fn63ac70);

// 0x6033c0: thiscall(n) ret 4: array of n 8-byte entries {dword 0; byte [4] 0}
static u8 *THISCALL fn6033c0(u8 *self, u32 n) {
  u64 sz = (u64)n * 8;
  *(u32 *)(self + 4) = n;
  *(u32 *)(self + 8) = 0;
  u8 *p = (u8 *)ext_41e290(sz > 0xffffffffull ? 0xffffffffu : (u32)sz);
  if (p) {
    u8 *c = p;
    if (n) {
      do {
        *(u32 *)c = 0;
        c += 8;
        c[-4] = 0;
        n--;
      } while (n != 0);
    }
    *(u8 **)self = p;
    return self;
  }
  *(u32 *)self = 0;
  return self;
}
PCREG(6033c0, fn6033c0);
