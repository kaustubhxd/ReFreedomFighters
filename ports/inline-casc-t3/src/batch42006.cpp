// batch42006.cpp - Sonnet t3: tier H, /GS float function (asm, stack exact).
#include "ff.h"

extern "C" void ext_5003d0(void);
extern "C" void ext_4deb20(void);
extern "C" void ext_4de4f0(void);
extern "C" void ext_633654(void);

// 0x501da0, thiscall(src) ret 4, /GS frame: obj = [this+0xc]; slot 0x80 of obj with (&v34, &v10) (callee pops 8); p = 0x5003d0([src+4], 0) (array element, 8-byte stride);
// 0x4deb20(0x4deb20(&m58, [p], v34.z? ...) builds a local from the four floats ([p], v34[0], v34[1], v34[2]);m58, [p], v34[0], v34[1], v34[2]) (4 floats, ret 0x10); 0x4de4f0(&v34, &m58) in place; slot 0x7c of obj with (&v34, &v10).
asm(
    ".text\n"
    ".globl thunk501da0\n"
    "thunk501da0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  subl $0x58, %esp\n"
    "  movl 0x6f5630, %eax\n"
    "  xorl %ebp, %eax\n"
    "  movl %eax, -4(%ebp)\n"
    "  pushl %esi\n"
    "  movl 8(%ebp), %esi\n"
    "  leal -0x10(%ebp), %edx\n"
    "  pushl %edi\n"
    "  movl %ecx, %edi\n"
    "  pushl %edx\n"
    "  leal -0x34(%ebp), %edx\n"
    "  pushl %edx\n"
    "  movl 0xc(%edi), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  call *0x80(%eax)\n"
    "  movl 4(%esi), %ecx\n"
    "  pushl $0\n"
    "  call ext_5003d0\n"
    "  movss -0x2c(%ebp), %xmm0\n"
    "  leal -0x58(%ebp), %ecx\n"
    "  subl $0x10, %esp\n"
    "  movss %xmm0, 0xc(%esp)\n"
    "  movss -0x30(%ebp), %xmm0\n"
    "  movss %xmm0, 8(%esp)\n"
    "  movss -0x34(%ebp), %xmm0\n"
    "  movss %xmm0, 4(%esp)\n"
    "  movss (%eax), %xmm0\n"
    "  movss %xmm0, (%esp)\n"
    "  call ext_4deb20\n"
    "  leal -0x58(%ebp), %edx\n"
    "  leal -0x34(%ebp), %ecx\n"
    "  call ext_4de4f0\n"
    "  movl 0xc(%edi), %ecx\n"
    "  leal -0x10(%ebp), %edx\n"
    "  pushl %edx\n"
    "  leal -0x34(%ebp), %edx\n"
    "  pushl %edx\n"
    "  movl (%ecx), %eax\n"
    "  call *0x7c(%eax)\n"
    "  movl -4(%ebp), %ecx\n"
    "  popl %edi\n"
    "  xorl %ebp, %ecx\n"
    "  popl %esi\n"
    "  call ext_633654\n"
    "  movl %ebp, %esp\n"
    "  popl %ebp\n"
    "  ret $4\n"
);
extern "C" void thunk501da0(void);
PCREG(501da0, thunk501da0);
