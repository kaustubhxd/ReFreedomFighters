// batch42000.cpp - tier H, /GS-protected float function (asm, stack exact).
#include "ff.h"

extern "C" void ext_523330(void);
extern "C" void ext_4e0d80(void);
extern "C" void ext_441940(void);
extern "C" void ext_633654(void);

// 0x514c70, thiscall, no args, /GS frame: zero the vec3 at this+0x29b, vcall slot 0x84 of this with &that vec3, 0x523330(this->[+0x5c], &local) (ret 4),
// normalise-scale local by float [this+0x223] via 0x4e0d80 (ret 4), then 0x441940 (fastcall: ecx = this+0x29b, edx = &local) adds local into the vec3.
asm(
    ".text\n"
    ".globl thunk514c70\n"
    "thunk514c70:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  subl $0x10, %esp\n"
    "  movl 0x6f5630, %eax\n"
    "  xorl %ebp, %eax\n"
    "  movl %eax, -4(%ebp)\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl %edi\n"
    "  leal 0x29b(%esi), %edi\n"
    "  movl $0, (%edi)\n"
    "  movl $0, 4(%edi)\n"
    "  movl $0, 8(%edi)\n"
    "  movl (%esi), %eax\n"
    "  pushl %edi\n"
    "  call *0x84(%eax)\n"
    "  movl 0x5c(%esi), %ecx\n"
    "  leal -0x10(%ebp), %eax\n"
    "  pushl %eax\n"
    "  call ext_523330\n"
    "  movss 0x223(%esi), %xmm0\n"
    "  pushl %ecx\n"
    "  leal -0x10(%ebp), %ecx\n"
    "  movss %xmm0, (%esp)\n"
    "  call ext_4e0d80\n"
    "  leal -0x10(%ebp), %edx\n"
    "  movl %edi, %ecx\n"
    "  call ext_441940\n"
    "  movl -4(%ebp), %ecx\n"
    "  popl %edi\n"
    "  xorl %ebp, %ecx\n"
    "  popl %esi\n"
    "  call ext_633654\n"
    "  movl %ebp, %esp\n"
    "  popl %ebp\n"
    "  ret\n"
);
extern "C" void thunk514c70(void);
PCREG(514c70, thunk514c70);
