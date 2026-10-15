// batch66078.cpp - cascade s4 batch 66078: 0x460cb0 (/GS-protected constructor chain; asm so the stack layout is exact).
#include "ff.h"

extern "C" void ext_4764b0(void);
extern "C" void ext_476500(void);
extern "C" void ext_476f50(void);
extern "C" void ext_477480(void);
extern "C" void ext_47f6c0(void);
extern "C" void ext_47f6f0(void);
extern "C" void ext_468030(void);
extern "C" void ext_468080(void);
extern "C" void ext_4654b0(void);
extern "C" void ext_465660(void);
extern "C" void ext_469da0(void);
extern "C" void ext_46a5c0(void);
extern "C" void ext_47fce0(void);
extern "C" void ext_47fd30(void);
extern "C" void ext_460e40(void);
extern "C" void ext_460f90(void);
extern "C" void ext_471b50(void);
extern "C" void ext_471f60(void);
extern "C" void ext_43de40(void);
extern "C" void ext_43de70(void);
extern "C" void ext_633654(void);

// 0x460cb0, cdecl() plain ret: clears the globals 0x6ffa68 / 0x6ffa6c / 0x6ffa70; then ten stack objects are constructed with three zero arguments (callee-popped, thiscall) and finished with a one-argument-free call, in this order:
// 0x4764b0 / 0x476500 (at ebp-0x7c), 0x476f50 / 0x477480 (-0x9f8), 0x47f6c0 / 0x47f6f0 (-0xa14), 0x468030 / 0x468080 (-0x278), 0x4654b0 / 0x465660 (-0x268), 0x469da0 / 0x46a5c0 (-0x80), 0x47fce0 / 0x47fd30 (-0x94),
// 0x460e40 / 0x460f90 (-0x1cc), 0x471b50 / 0x471f60 (-0x68c); the last object (-0xa10) is built by 0x43de40, its first dword set to the vtable 0x6852c0 and finished by 0x43de70. /GS check 0x633654.
asm(
    ".text\n"
    ".globl thunk460cb0\n"
    "thunk460cb0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  subl $0xa14, %esp\n"
    "  movl 0x6f5630, %eax\n"
    "  xorl %ebp, %eax\n"
    "  movl %eax, -4(%ebp)\n"
    "  movl $0, 0x6ffa68\n"
    "  movl $0, 0x6ffa6c\n"
    "  movl $0, 0x6ffa70\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x7c(%ebp), %ecx\n"
    "  call ext_4764b0\n"
    "  leal -0x7c(%ebp), %ecx\n"
    "  call ext_476500\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x9f8(%ebp), %ecx\n"
    "  call ext_476f50\n"
    "  leal -0x9f8(%ebp), %ecx\n"
    "  call ext_477480\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0xa14(%ebp), %ecx\n"
    "  call ext_47f6c0\n"
    "  leal -0xa14(%ebp), %ecx\n"
    "  call ext_47f6f0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x278(%ebp), %ecx\n"
    "  call ext_468030\n"
    "  leal -0x278(%ebp), %ecx\n"
    "  call ext_468080\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x268(%ebp), %ecx\n"
    "  call ext_4654b0\n"
    "  leal -0x268(%ebp), %ecx\n"
    "  call ext_465660\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x80(%ebp), %ecx\n"
    "  call ext_469da0\n"
    "  leal -0x80(%ebp), %ecx\n"
    "  call ext_46a5c0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x94(%ebp), %ecx\n"
    "  call ext_47fce0\n"
    "  leal -0x94(%ebp), %ecx\n"
    "  call ext_47fd30\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x1cc(%ebp), %ecx\n"
    "  call ext_460e40\n"
    "  leal -0x1cc(%ebp), %ecx\n"
    "  call ext_460f90\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0x68c(%ebp), %ecx\n"
    "  call ext_471b50\n"
    "  leal -0x68c(%ebp), %ecx\n"
    "  call ext_471f60\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  pushl $0\n"
    "  leal -0xa10(%ebp), %ecx\n"
    "  call ext_43de40\n"
    "  leal -0xa10(%ebp), %ecx\n"
    "  movl $0x6852c0, -0xa10(%ebp)\n"
    "  call ext_43de70\n"
    "  movl -4(%ebp), %ecx\n"
    "  xorl %ebp, %ecx\n"
    "  call ext_633654\n"
    "  movl %ebp, %esp\n"
    "  popl %ebp\n"
    "  ret\n");

extern "C" void thunk460cb0(void);
PCREG(460cb0, thunk460cb0);
