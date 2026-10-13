// batch2505.cpp - decomp area 24, batch 2505. 0x634730 (CRT 64-bit left shift helper, __allshl): value in EDX:EAX, count in CL,
// result in EDX:EAX, plain ret. The register convention is bridged by a naked trampoline into a C++ core.
#include "ff.h"

extern "C" __attribute__((used)) u64 allshl_core(u32 lo, u32 hi, u32 cl) {
  u8 n = (u8)cl;
  if (n >= 64) return 0;
  u64 v = ((u64)hi << 32) | lo;
  if (n >= 32) return (u64)(lo << (n & 31)) << 32;
  return v << n;
}

extern "C" __attribute__((naked, used)) void f24_634730() {
  asm volatile(
      "movzbl %cl, %ecx\n\t"
      "pushl %ecx\n\t"
      "pushl %edx\n\t"
      "pushl %eax\n\t"
      "call allshl_core\n\t"
      "addl $12, %esp\n\t"
      "ret");
}
PCREG(634730, f24_634730);
