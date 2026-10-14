// batch34093.cpp - escalation batch 34093: 0x4e50a0, 0x494030 (asm), 0x534150, 0x65da30, 0x5ab1e0, 0x655f60.
#include "ff.h"

extern "C" void thunk494030(void);
asm(
    ".text\n"
    ".globl thunk494030\n"
    "thunk494030:\n"          // o = unaligned [[0x70039c]+0x1a9f]; null: return 0 (ret 4); else tail jump through slot 0x124 of o with ecx = o
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 0x70039c, %eax\n"
    "  mov 0x1a9f(%eax), %ecx\n"
    "  test %ecx, %ecx\n"
    "  jne 1f\n"
    "  xor %eax, %eax\n"
    "  pop %ebp\n"
    "  ret $4\n"
    "1:\n"
    "  mov (%ecx), %eax\n"
    "  pop %ebp\n"
    "  jmp *0x124(%eax)\n");
PCREG(494030, thunk494030);

static u32 rd32(u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static void wr32(u8 *p, u32 v) { p[0] = v; p[1] = v >> 8; p[2] = v >> 16; p[3] = v >> 24; }

// 0x4e50a0, thiscall plain: c = [this+4]; v = [c+4]; when v is non-negative the exe reads address 0 (faults). Else: bit 0x40000000 clear: returns [c+0x10]; set: returns [c + 4*[c+0x10] + 0x14].
static u32 THISCALL fn4e50a0(u8 *self) {
  u8 *c = *(u8 **)(self + 4);
  s32 v = *(s32 *)(c + 4);
  if (v >= 0) {
    u32 r;
    asm volatile("xor %0, %0\n\tmov (%0), %0" : "=&r"(r));
    return r;
  }
  u32 idx = *(u32 *)(c + 0x10);
  if (v & 0x40000000) return *(u32 *)(c + idx * 4 + 0x14);
  return idx;
}
PCREG(4e50a0, fn4e50a0);

// 0x534150, thiscall, returns k (0x7ff): [this+4] = 1, [this] = 0; for k = 2..0x7ff: dword at this+0x14+8*(k-2) = k | 0x80000000; then dword [this+0x4004] = 0 (same shape as 0x533ce0).
static u32 THISCALL fn534150(u8 *self) {
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
  return k;
}
PCREG(534150, fn534150);

// 0x65da30, thiscall(a) ret 4: when [this+0x41c] < [this+0x420] (unsigned): buf = [this+0x404]; m = [this+0x40c]; buf[[m+4]] = a; [m+4] += 1; [this+0x41c] += 4.
static void THISCALL fn65da30(u8 *self, u32 a) {
  if (*(u32 *)(self + 0x41c) < *(u32 *)(self + 0x420)) {
    u32 *m = *(u32 **)(self + 0x40c);
    u32 *buf = *(u32 **)(self + 0x404);
    buf[m[1]] = a;
    (*(u32 **)(self + 0x40c))[1]++;
    *(u32 *)(self + 0x41c) += 4;
  }
}
PCREG(65da30, fn65da30);

// 0x5ab1e0, thiscall(a) ret 4: with d = low byte of a: nothing when byte [this+0x3c6] == d. When d == 0 and the unaligned dword s = [this+0x3c2] is not 8: byte [this+0x3c7] = byte [this+0x37c], dword [this+0x3c8] = 0,
// dword [this+0x3cc] = s. Then byte [this+0x3c6] = d.
static void THISCALL fn5ab1e0(u8 *self, u32 a) {
  u8 d = a;
  if (self[0x3c6] == d) return;
  if (d == 0) {
    u32 s = rd32(self + 0x3c2);
    if (s != 8) {
      self[0x3c7] = self[0x37c];
      wr32(self + 0x3c8, 0);
      wr32(self + 0x3cc, s);
    }
  }
  self[0x3c6] = d;
}
PCREG(5ab1e0, fn5ab1e0);

// 0x655f60, stdcall(a) ret 4, bool: o = unaligned [[0x70039c]+0x1aa3]; c = [o+0x20]; true when c != 0 and c <= a < c + ([c-8] & 0x1fffffff).
static bool STDCALL fn655f60(u32 a) {
  u8 *o = (u8 *)rd32(G(u8 *, 0x70039c) + 0x1aa3);
  u32 c = *(u32 *)(o + 0x20);
  if (a < c) return false;
  if (c == 0) return false;
  u32 end = c + (*(u32 *)(c - 8) & 0x1fffffff);
  if (a >= end) return false;
  return true;
}
PCREG(655f60, fn655f60);
