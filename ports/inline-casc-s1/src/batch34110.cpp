// batch34110.cpp - escalation batch 34110: 0x5d8880 (asm), 0x626ac0, 0x4764b0, 0x51eab0, 0x5f4d80, 0x4eb350, 0x5d5730.
#include "ff.h"

extern "C" void thunk5d8880(void);
asm(
    ".text\n"
    ".globl thunk5d8880\n"
    "thunk5d8880:\n"          // [this] = 0x6b5fc8; frees [this+0x20] (0x41e2c0) and [this+0x24] (0x634273, size 8) when set, clears both; tail jump to 0x43de70 with ecx = this
    "  push %esi\n"
    "  mov %ecx, %esi\n"
    "  mov 0x20(%esi), %eax\n"
    "  movl $0x6b5fc8, (%esi)\n"
    "  test %eax, %eax\n"
    "  je 1f\n"
    "  push %eax\n"
    "  call ext_41e2c0\n"
    "  add $4, %esp\n"
    "1:\n"
    "  mov 0x24(%esi), %eax\n"
    "  test %eax, %eax\n"
    "  je 2f\n"
    "  push $8\n"
    "  push %eax\n"
    "  call ext_634273\n"
    "  add $8, %esp\n"
    "2:\n"
    "  movl $0, 0x24(%esi)\n"
    "  mov %esi, %ecx\n"
    "  movl $0, 0x20(%esi)\n"
    "  pop %esi\n"
    "  jmp ext_43de70\n");
PCREG(5d8880, thunk5d8880);

extern "C" s32 ext_628c10(const u8 *s);                              // cdecl
extern "C" u32 THISCALL ext_43e990(void *self, u32 a, u32 b, u32 c); // thiscall ret 0xc
extern "C" u32 *THISCALL ext_5003d0(void *m, u32 i);                 // thiscall ret 4
extern "C" s32 THISCALL ext_5ffd70(void *self, u32 a, u32 b);        // thiscall ret 8
extern "C" u32 THISCALL ext_5f5620(void *self, u32 a);               // thiscall ret 4
extern "C" u32 THISCALL ext_4e8bd0(void *self);                      // thiscall, plain ret
extern "C" u32 THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c); // thiscall ret 0xc

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x626ac0, cdecl(a, b, c): r = ext_628c10(c); returns 0 when r is -1. Else byte [a+0x49] = r; [a] = 0x628eb0, [a+4] = 0x628e70, [a+0x4c] = b, [a+0x34] = 0x628ed0; [b] = a; returns 1.
static u32 fn626ac0(u8 *a, u32 *b, const u8 *c) {
  s32 r = ext_628c10(c);
  if (r == -1) return 0;
  a[0x49] = r;
  *(u32 *)a = 0x628eb0;
  *(u32 *)(a + 4) = 0x628e70;
  *(u32 **)(a + 0x4c) = b;
  *(u32 *)(a + 0x34) = 0x628ed0;
  *b = (u32)a;
  return 1;
}
PCREG(626ac0, fn626ac0);

// 0x4764b0, thiscall(a, b, c) ret 0xc, returns this: ext_43e990(this, a, b, c); [this] = 0x689de4; dwords +0x5c, +0x60, +0x64, +0x68, +0x6c = 0; byte +0x72 = 0.
static u32 THISCALL fn4764b0(u8 *self, u32 a, u32 b, u32 c) {
  ext_43e990(self, a, b, c);
  *(u32 *)self = 0x689de4;
  for (int i = 0; i < 5; i++) *(u32 *)(self + 0x5c + 4 * i) = 0;
  self[0x72] = 0;
  return (u32)self;
}
PCREG(4764b0, fn4764b0);

// 0x51eab0, thiscall(a) ret 4: [[this+0x18]+0x23a] = *ext_5003d0([a+4], 0); then [[this+0x18]+0x232] = *ext_5003d0([a+4], 1) (unaligned dwords); returns the second value.
static u32 THISCALL fn51eab0(u8 *self, u8 *a) {
  u32 v0 = *ext_5003d0(*(u8 **)(a + 4), 0);
  u8 *t = *(u8 **)(self + 0x18);
  wr32(t + 0x23a, v0);
  u32 v1 = *ext_5003d0(*(u8 **)(a + 4), 1);
  t = *(u8 **)(self + 0x18);
  wr32(t + 0x232, v1);
  return v1;
}
PCREG(51eab0, fn51eab0);

// 0x5f4d80, thiscall(a) ret 4: r = ext_5ffd70(unaligned [this+0x96], a, word [this+0x1e]); r == -1: unaligned dword [this+0xa6] += 8, returns -1; else [this+0xa6] = ext_5f5620(this, r), returns it.
static u32 THISCALL fn5f4d80(u8 *self, u32 a) {
  u32 w = self[0x1e] | self[0x1f] << 8;
  s32 r = ext_5ffd70((u8 *)rd32(self + 0x96), a, w);
  if (r == -1) {
    wr32(self + 0xa6, rd32(self + 0xa6) + 8);
    return (u32)r;
  }
  u32 v = ext_5f5620(self, r);
  wr32(self + 0xa6, v);
  return v;
}
PCREG(5f4d80, fn5f4d80);

// 0x4eb350, thiscall(unused) ret 4, returns this: [this] = 0x697738; ext_4e8bd0(this+4); unaligned dwords +0x1ad, +0x19d, +0x1a1, +0x1a5, +0x1a9 = 0; dwords +0x190, +0x194, +0x198 = 0; byte +0x19c = 0.
static u32 THISCALL fn4eb350(u8 *self, u32 unused) {
  (void)unused;
  *(u32 *)self = 0x697738;
  ext_4e8bd0(self + 4);
  wr32(self + 0x1ad, 0);
  *(u32 *)(self + 0x198) = 0;
  *(u32 *)(self + 0x194) = 0;
  *(u32 *)(self + 0x190) = 0;
  self[0x19c] = 0;
  wr32(self + 0x19d, 0);
  wr32(self + 0x1a1, 0);
  wr32(self + 0x1a5, 0);
  wr32(self + 0x1a9, 0);
  return (u32)self;
}
PCREG(4eb350, fn4eb350);

// 0x5d5730, thiscall(a, b, c) ret 0xc, returns this: ext_43de40(this, a, b, c); [this] = 0x6b5610; byte +0x18 = 0, unaligned dwords +0x19, +0x25, +0x29, +0x2d = 0, byte +0x31 = 0, unaligned dword +0x32 = 0.
static u32 THISCALL fn5d5730(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)self = 0x6b5610;
  self[0x18] = 0;
  wr32(self + 0x19, 0);
  wr32(self + 0x25, 0);
  wr32(self + 0x29, 0);
  wr32(self + 0x2d, 0);
  self[0x31] = 0;
  wr32(self + 0x32, 0);
  return (u32)self;
}
PCREG(5d5730, fn5d5730);
