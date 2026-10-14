// batch31061.cpp - tail-jump thunks (asm, stack untouched) plus three small C bodies.
#include "ff.h"

extern "C" void ext_4690b0(void);

asm(
    ".text\n"
    ".globl thunk4616b0\nthunk4616b0:\n  movl 0x6c(%ecx), %ecx\n  movl (%ecx), %eax\n  movl 0x1c(%eax), %eax\n  jmp *%eax\n"
    ".globl thunk601a60\nthunk601a60:\n  movl 0x70039c, %eax\n  movl 0x9b(%eax), %ecx\n  movl (%ecx), %eax\n  jmp *0x118(%eax)\n"
    ".globl thunk4f4d00\nthunk4f4d00:\n  cmpl $1, 0x8f(%ecx)\n  je 1f\n  movl 0x70(%ecx), %eax\n  cmpl $0x20, %eax\n  je 1f\n  cmpl $2, %eax\n  jne ext_4690b0\n1:\n  ret\n"
    ".globl thunk4dc420\nthunk4dc420:\n  movl 0x54(%ecx), %ecx\n  testl %ecx, %ecx\n  je 2f\n  movl (%ecx), %eax\n  jmp *0xc(%eax)\n2:\n  ret $4\n");
extern "C" void thunk4616b0(void);
extern "C" void thunk601a60(void);
extern "C" void thunk4f4d00(void);
extern "C" void thunk4dc420(void);
PCREG(4616b0, thunk4616b0);
PCREG(601a60, thunk601a60);
PCREG(4f4d00, thunk4f4d00);
PCREG(4dc420, thunk4dc420);

// 0x4d4940 thiscall ret 8: if first arg == 0x10, clear byte at this+5.
THISCALL void fn4d4940(u8 *self, int a, int) {
  if (a == 0x10) self[5] = 0;
}
PCREG(4d4940, fn4d4940);

// 0x4cfd90 stdcall ret 8: copy the (unaligned) dword at +0x11 from src to dst.
STDCALL void fn4cfd90(u8 *dst, u8 *src) {
  u32 v = src[0x11] | (src[0x12] << 8) | (src[0x13] << 16) | ((u32)src[0x14] << 24);
  dst[0x11] = v; dst[0x12] = v >> 8; dst[0x13] = v >> 16; dst[0x14] = v >> 24;
}
PCREG(4cfd90, fn4cfd90);

// 0x4d0ee0 thiscall ret 4: returns -1 if byte +0x821b was nonzero else 0; clears it; sets it to 1 if arg < 0.
THISCALL int fn4d0ee0(u8 *self, int a) {
  int r = self[0x821b] ? -1 : 0;
  self[0x821b] = 0;
  if (a < 0) self[0x821b] = 1;
  return r;
}
PCREG(4d0ee0, fn4d0ee0);
