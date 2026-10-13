// batch1053.cpp - area 81, batch 1053: 0x658d80, fastcall index calculation.
// Loads byte at this+0x3f, if zero returns (byte*3)*16, if non-zero adds offset from this+0x48+0x90.
#include "ff.h"

extern "C" void asm_658d80(void);

__asm__(
    ".text\n"
    ".globl asm_658d80\n"
    "asm_658d80:\n"
    "  movb 0x3f(%ecx), %al\n"
    "  testb %al, %al\n"
    "  jne asm_658d80_nonzero\n"
    // Zero case
    "  movzbl %al, %eax\n"
    "  xorl %ecx, %ecx\n"
    "  leal (%eax, %eax, 2), %eax\n"
    "  shll $4, %eax\n"
    "  addl %ecx, %eax\n"
    "  ret\n"
    // Non-zero case
    "asm_658d80_nonzero:\n"
    "  movl 0x48(%ecx), %ecx\n"
    "  movzbl %al, %eax\n"
    "  addl $0x90, %ecx\n"
    "  leal (%eax, %eax, 2), %eax\n"
    "  shll $4, %eax\n"
    "  addl %ecx, %eax\n"
    "  ret\n");

PCREG(658d80, asm_658d80);
