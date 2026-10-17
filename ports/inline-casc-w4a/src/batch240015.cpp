// batch240015.cpp - Sonnet-w4a: __report_gsfailure and its caller. Naked copies: the function saves the CALLER's registers
// and the frame it was called from into globals, so a compiled C++ body cannot reproduce it.
#include "ff.h"

// 0x634053: records the register file, segment registers, flags, ebp chain and the first stack argument into the CONTEXT
// record at 0x725594.., fills the EXCEPTION_RECORD at 0x7254b8.. (0xc0000409, 1 parameter) and calls the unhandled-exception
// path 0x633f24(0x6c1694). The fast-fail trap (int 0x29) is taken when the feature check 0x663bc2(0x17) is non-zero.
extern "C" __attribute__((naked, used)) void fn_634053() {
  asm volatile(
      "pushl %ebp\n"
      "movl %esp, %ebp\n"
      "subl $0x31c, %esp\n"
      "pushl $0x17\n"
      "call ext_663bc2\n"
      "testl %eax, %eax\n"
      "je 1f\n"
      "movl 8(%ebp), %ecx\n"
      "int $0x29\n"
      "1: movl %eax, 0x7255b8\n"
      "movl %ecx, 0x7255b4\n"
      "movl %edx, 0x7255b0\n"
      "movl %ebx, 0x7255ac\n"
      "movl %esi, 0x7255a8\n"
      "movl %edi, 0x7255a4\n"
      "movw %ss, 0x7255d0\n"
      "movw %cs, 0x7255c4\n"
      "movw %ds, 0x7255a0\n"
      "movw %es, 0x72559c\n"
      "movw %fs, 0x725598\n"
      "movw %gs, 0x725594\n"
      "pushfl\n"
      "popl 0x7255c8\n"
      "movl (%ebp), %eax\n"
      "movl %eax, 0x7255bc\n"
      "movl 4(%ebp), %eax\n"
      "movl %eax, 0x7255c0\n"
      "leal 8(%ebp), %eax\n"
      "movl %eax, 0x7255cc\n"
      "movl -0x31c(%ebp), %eax\n"
      "movl 0x7255c0, %eax\n"
      "movl %eax, 0x7254c4\n"
      "movl $0xc0000409, 0x7254b8\n"
      "movl $1, 0x7254bc\n"
      "movl $1, 0x7254c8\n"
      "pushl $4\n"
      "popl %eax\n"
      "imull $0, %eax, %eax\n"
      "movl 8(%ebp), %ecx\n"
      "movl %ecx, 0x7254cc(%eax)\n"
      "pushl $0x6c1694\n"
      "call ext_633f24\n");
}
PCREG(634053, fn_634053);

// 0x634047: pushes 8 (the fast-fail code) and enters 0x634053 as a call from 0x634051 (0x634053 never returns, and records the return address)
extern "C" __attribute__((naked, used)) void fn_634047() {
  asm volatile(
      "pushl %ebp\n"
      "movl %esp, %ebp\n"
      "pushl $8\n"
      "pushl $0x634051\n"        /* the exe return address: 0x634053 stores it in a global, and never returns here */
      "jmp ext_634053\n");
}
PCREG(634047, fn_634047);
