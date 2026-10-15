// batch44001.cpp - cascade t5 (Sonnet): tier H float functions.
#include "ff.h"
#include <xmmintrin.h>

extern "C" void ext_42ab0d(void);

static inline float gf(u32 a) { return *(volatile float *)a; }

// 0x43d020, thiscall(), plain ret: n = this[0x80]; entries of 0x18 bytes at this+8+i*0x18 (int at +4, float at +8).
// For i = 0; i < this[0x80] (reloaded): t = e.int - (int)trunc(e.float * [0x67862c]); v = (int)trunc((float)t * [0x6785e4] * [0x678620]);
// if v < (int)[[0x70039c]+0x30]: move the entries after i down by one (0x18 bytes each) and decrement this[0x80] (i still advances).
static void THISCALL fn43d020(u8 *self) {
  s32 i = 0;
  s32 n = *(s32 *)(self + 0x80);
  while (i < n) {
    u8 *e = self + 8 + i * 0x18;
    s32 a = *(s32 *)(e + 4);
    float f = *(float *)(e + 8);
    s32 t = a - _mm_cvttss_si32(_mm_set_ss(f * gf(0x67862c)));
    s32 v = _mm_cvttss_si32(_mm_set_ss((float)t * gf(0x6785e4) * gf(0x678620)));
    if (v < *(s32 *)(G(u8 *, 0x70039c) + 0x30)) {
      for (s32 j = i; j < *(s32 *)(self + 0x80) - 1; j++) __builtin_memcpy(self + 8 + j * 0x18, self + 8 + (j + 1) * 0x18, 0x18);
      *(s32 *)(self + 0x80) -= 1;
    }
    i++;
    n = *(s32 *)(self + 0x80);
  }
}
PCREG(43d020, fn43d020);

// 0x64f9f0, thiscall(a) ret 4: v[2] floats on the stack. a != 0: v = {0,0}; 0x42ab0d(a, 0x6792b4, &v0, &v1) (cdecl); if v1 == 0.0f then v1 = v0;
// slot 0xfc of [this+0x104](&v). a == 0: slot 0x100 of [this+0x104](&v); log object = slot 0x20 of [0x700390](0x6c3180, 0x9f);
// slot 0x2c of its vtable(log, 0x6c31ac, (double)v0, (double)v1) cdecl, 0x18 bytes popped.
asm(
    ".text\n"
    ".globl thunk64f9f0\n"
    "thunk64f9f0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 8(%ebp), %eax\n"
    "  subl $8, %esp\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  testl %eax, %eax\n"
    "  je 2f\n"
    "  leal -4(%ebp), %ecx\n"
    "  movl $0, -8(%ebp)\n"
    "  pushl %ecx\n"
    "  leal -8(%ebp), %ecx\n"
    "  movl $0, -4(%ebp)\n"
    "  pushl %ecx\n"
    "  pushl $0x6792b4\n"
    "  pushl %eax\n"
    "  call ext_42ab0d\n"
    "  movss -4(%ebp), %xmm0\n"
    "  addl $0x10, %esp\n"
    "  xorps %xmm1, %xmm1\n"
    "  ucomiss %xmm1, %xmm0\n"
    "  jp 1f\n"
    "  jne 1f\n"
    "  movss -8(%ebp), %xmm0\n"
    "  movss %xmm0, -4(%ebp)\n"
    "1:\n"
    "  movl 0x104(%esi), %ecx\n"
    "  leal -8(%ebp), %edx\n"
    "  pushl %edx\n"
    "  movl (%ecx), %eax\n"
    "  call *0xfc(%eax)\n"
    "  popl %esi\n"
    "  movl %ebp, %esp\n"
    "  popl %ebp\n"
    "  ret $4\n"
    "2:\n"
    "  movl 0x104(%esi), %ecx\n"
    "  leal -8(%ebp), %edx\n"
    "  pushl %edx\n"
    "  movl (%ecx), %eax\n"
    "  call *0x100(%eax)\n"
    "  movl 0x700390, %ecx\n"
    "  pushl $0x9f\n"
    "  pushl $0x6c3180\n"
    "  movl (%ecx), %eax\n"
    "  call *0x20(%eax)\n"
    "  movss -4(%ebp), %xmm0\n"
    "  subl $0x10, %esp\n"
    "  cvtps2pd %xmm0, %xmm0\n"
    "  movl (%eax), %ecx\n"
    "  movsd %xmm0, 8(%esp)\n"
    "  movss -8(%ebp), %xmm0\n"
    "  cvtps2pd %xmm0, %xmm0\n"
    "  movsd %xmm0, (%esp)\n"
    "  pushl $0x6c31ac\n"
    "  pushl %eax\n"
    "  call *0x2c(%ecx)\n"
    "  addl $0x18, %esp\n"
    "  popl %esi\n"
    "  movl %ebp, %esp\n"
    "  popl %ebp\n"
    "  ret $4\n");
extern "C" void THISCALL thunk64f9f0(void *, u32);
PCREG(64f9f0, thunk64f9f0);
