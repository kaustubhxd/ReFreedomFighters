// batch42003.cpp - Sonnet t3: tier H, /GS float function (asm, stack exact).
#include "ff.h"

extern "C" void ext_43e920(void);
extern "C" void ext_4e0030(void);
extern "C" void ext_633654(void);

// 0x521ed0, thiscall, no args, /GS frame: when [this+0x2610] != 0: copy vec3 at +0x25e5 to a local, slot 0x84 of the object at [+0x25d1] with &local;
// 0x43e920(&v, this+0x25fd, &local) (fastcall edx/ecx + 1 stack arg, ret 4), x87 result of 0x4e0030(&v, this+0x78): f = [0x683770] - result as float;
// [this+0x2691] = (K_a > f) ? K_a : minss(K_b, f).
asm(
    ".text\n"
    ".globl thunk521ed0\n"
    "thunk521ed0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  subl $0x20, %esp\n"
    "  movl 0x6f5630, %eax\n"
    "  xorl %ebp, %eax\n"
    "  movl %eax, -4(%ebp)\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  cmpl $0, 0x2610(%esi)\n"
    "  je 9f\n"
    "  movss 0x25e5(%esi), %xmm0\n"
    "  leal -0x10(%ebp), %edx\n"
    "  movl 0x25d1(%esi), %ecx\n"
    "  movss %xmm0, -0x10(%ebp)\n"
    "  movss 0x25e9(%esi), %xmm0\n"
    "  movss %xmm0, -0xc(%ebp)\n"
    "  movss 0x25ed(%esi), %xmm0\n"
    "  movss %xmm0, -8(%ebp)\n"
    "  movl (%ecx), %eax\n"
    "  pushl %edx\n"
    "  call *0x84(%eax)\n"
    "  leal -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  leal 0x25fd(%esi), %edx\n"
    "  leal -0x1c(%ebp), %ecx\n"
    "  call ext_43e920\n"
    "  leal 0x78(%esi), %edx\n"
    "  leal -0x1c(%ebp), %ecx\n"
    "  call ext_4e0030\n"
    "  fsubrs 0x683770\n"
    "  movss 0x6a0678, %xmm0\n"
    "  fstps -0x20(%ebp)\n"
    "  movss -0x20(%ebp), %xmm1\n"
    "  comiss %xmm1, %xmm0\n"
    "  ja 8f\n"
    "  movss 0x6a0670, %xmm0\n"
    "  minss %xmm1, %xmm0\n"
    "8:\n"
    "  movss %xmm0, 0x2691(%esi)\n"
    "9:\n"
    "  movl -4(%ebp), %ecx\n"
    "  xorl %ebp, %ecx\n"
    "  popl %esi\n"
    "  call ext_633654\n"
    "  movl %ebp, %esp\n"
    "  popl %ebp\n"
    "  ret\n"
);
extern "C" void thunk521ed0(void);
PCREG(521ed0, thunk521ed0);
