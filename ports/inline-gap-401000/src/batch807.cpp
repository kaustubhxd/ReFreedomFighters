// batch807.cpp - core gameplay batch 807 (docs/20-unclaimed-65.md, batch 807): 0x46d6c0 (assembly: the stack argument is rewritten and the
// call is a tail jump), 0x46e9c0, 0x478a80 and 0x53e940 (C).
#include "ff.h"

typedef u32(THISCALL *F2)(u8 *self, u32 a, u32 b);
static u32 vc2(u8 *o, u32 s, u32 a, u32 b) { return ((F2)(*(const u32 *)(*(const u32 *)o + s)))(o, a, b); }

extern "C" void __attribute__((cdecl)) ext_41e2c0(u32 p);   // CRT delete wrapper (exe code)
extern "C" void fn46d6c0(void);

asm(
    ".text\n"
    ".globl fn46d6c0\n"
    "fn46d6c0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 8(%ebp), %ecx\n"
    "  testl %ecx, %ecx\n"
    "  je 1f\n"
    "  movl (%ecx), %eax\n"
    "  movl $1, 8(%ebp)\n"
    "  popl %ebp\n"
    "  jmp *0x210(%eax)\n"
    "1:\n"
    "  popl %ebp\n"
    "  ret $4\n");

static u8 *THISCALL fn46e9c0(u8 *self) {
  const u32 r = vc2(self, 0x25c, 0x688860, 0);
  return r != 0 ? (u8 *)r : self;
}

static u32 THISCALL fn478a80(u32 *self) {
  const u32 p = *self;
  if (p == 0) return 0;
  u8 *obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return *(const u32 *)(obj + 0x44) + p;
}

static void THISCALL fn53e940(u8 *self) {
  const u32 p = *(const u32 *)(self + 0x135);
  if (p != 0) ext_41e2c0(p);
  *(u32 *)(self + 0x135) = 0;
}

PCREG(46d6c0, fn46d6c0);
PCREG(46e9c0, fn46e9c0);
PCREG(478a80, fn478a80);
PCREG(53e940, fn53e940);
