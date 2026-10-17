// batch240012.cpp - Sonnet-w4a: MSVC stack-probe helpers (_chkstk, _alloca_probe_16/8). Register convention (eax = size) with
// esp games, so the ports are naked copies of the exe instructions.
#include "ff.h"

// 0x6336b0 (_chkstk): eax = bytes; touches every page down to esp - eax, lowers esp by eax and returns to the caller
extern "C" __attribute__((naked, used)) void fn_6336b0() {
  asm volatile(
      "pushl %ecx\n"
      "leal 4(%esp), %ecx\n"
      "subl %eax, %ecx\n"
      "sbbl %eax, %eax\n"
      "notl %eax\n"
      "andl %eax, %ecx\n"
      "movl %esp, %eax\n"
      "andl $0xfffff000, %eax\n"
      "2: cmpl %eax, %ecx\n"
      "jb 3f\n"
      "movl %ecx, %eax\n"
      "popl %ecx\n"
      "xchgl %eax, %esp\n"
      "movl (%eax), %eax\n"
      "movl %eax, (%esp)\n"
      "ret\n"
      "3: subl $0x1000, %eax\n"
      "testl %eax, (%eax)\n"
      "jmp 2b\n");
}
PCREG(6336b0, fn_6336b0);

// 0x633c90 (_alloca_probe_16): rounds eax up so the new esp is 16-byte aligned (saturating), then tail jumps to _chkstk
extern "C" __attribute__((naked, used)) void fn_633c90() {
  asm volatile(
      "pushl %ecx\n"
      "leal 8(%esp), %ecx\n"
      "subl %eax, %ecx\n"
      "andl $0xf, %ecx\n"
      "addl %ecx, %eax\n"
      "sbbl %ecx, %ecx\n"
      "orl %ecx, %eax\n"
      "popl %ecx\n"
      "jmp ext_6336b0\n");
}
PCREG(633c90, fn_633c90);

// 0x633ca6 (_alloca_probe_8): same with 8-byte alignment
extern "C" __attribute__((naked, used)) void fn_633ca6() {
  asm volatile(
      "pushl %ecx\n"
      "leal 8(%esp), %ecx\n"
      "subl %eax, %ecx\n"
      "andl $7, %ecx\n"
      "addl %ecx, %eax\n"
      "sbbl %ecx, %ecx\n"
      "orl %ecx, %eax\n"
      "popl %ecx\n"
      "jmp ext_6336b0\n");
}
PCREG(633ca6, fn_633ca6);
