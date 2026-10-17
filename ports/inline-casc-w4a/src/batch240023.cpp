// batch240023.cpp - Sonnet-w4a: x87/SSE error and conversion helpers of the MSVC CRT (register conventions): naked copies.
#include "ff.h"

// 0x633aad (_raise_fp_exception-style): edx = exception code, xmm0 = the operand (double). Unless the current x87 control word
// masks the exception (mask table at 0x6c166f indexed by code; code 8 always reports), loads the CRT control word [0x6c1690],
// builds the 0x20-byte argument block {code, 0, operand, operand, old control word} on the stack and calls the CRT's
// _except1 through the thunk 0x634e6c, discarding its x87 result.
extern "C" __attribute__((naked, used)) void fn_633aad() {
  asm volatile(
      "subl $0x20, %esp\n"
      "fstcw (%esp)\n"
      "movzwl (%esp), %eax\n"
      "cmpl $8, %edx\n"
      "je 1f\n"
      "testb %al, 0x6c166f(%edx)\n"
      "jne 2f\n"
      "1: fldcw 0x6c1690\n"
      "movl %edx, (%esp)\n"
      "movl $0, 4(%esp)\n"
      "movsd %xmm0, 8(%esp)\n"
      "movsd %xmm0, 0x10(%esp)\n"
      "movl %eax, 0x18(%esp)\n"
      "call ext_634e6c\n"
      "fstp %st(0)\n"
      "2: addl $0x20, %esp\n"
      "ret\n");
}
PCREG(633aad, fn_633aad);

// 0x634670 (_ftol2_sse): st0 -> signed 64-bit integer in edx:eax (truncating). With the SSE flag [0x72580c] set it is a plain
// cvttsd2si (32 bit result); otherwise the x87 path computes the truncation by rounding to nearest and correcting by the
// sign of the remainder (fistp/fild/fsubp), leaving the x87 stack empty again. Naked copy; st0 is the input.
extern "C" __attribute__((naked, used)) void fn_634670() {
  asm volatile(
      "cmpl $0, 0x72580c\n"
      "je 10f\n"
      "pushl %ebp\n"
      "movl %esp, %ebp\n"
      "subl $8, %esp\n"
      "andl $0xfffffff8, %esp\n"
      "fstpl (%esp)\n"
      "cvttsd2si (%esp), %eax\n"
      "leave\n"
      "ret\n"
      "10: pushl %ebp\n"
      "movl %esp, %ebp\n"
      "subl $0x20, %esp\n"
      "andl $0xfffffff0, %esp\n"
      "fld %st(0)\n"
      "fsts 0x18(%esp)\n"
      "fistpll 0x10(%esp)\n"
      "fildll 0x10(%esp)\n"
      "movl 0x18(%esp), %edx\n"
      "movl 0x10(%esp), %eax\n"
      "testl %eax, %eax\n"
      "je 30f\n"
      "20: .byte 0xde, 0xe9\n"        /* fsubp st(1), st */
      "testl %edx, %edx\n"
      "jns 25f\n"
      "fstps (%esp)\n"
      "movl (%esp), %ecx\n"
      "xorl $0x80000000, %ecx\n"
      "addl $0x7fffffff, %ecx\n"
      "adcl $0, %eax\n"
      "movl 0x14(%esp), %edx\n"
      "adcl $0, %edx\n"
      "jmp 40f\n"
      "25: fstps (%esp)\n"
      "movl (%esp), %ecx\n"
      "addl $0x7fffffff, %ecx\n"
      "sbbl $0, %eax\n"
      "movl 0x14(%esp), %edx\n"
      "sbbl $0, %edx\n"
      "jmp 40f\n"
      "30: movl 0x14(%esp), %edx\n"
      "testl $0x7fffffff, %edx\n"
      "jne 20b\n"
      "fstps 0x18(%esp)\n"
      "fstps 0x18(%esp)\n"
      "40: leave\n"
      "ret\n");
}
PCREG(634670, fn_634670);
