// batch822.cpp - core gameplay batch 822 (docs/20-unclaimed-65.md, batch 822): 0x46d5d0 (ZItemTemplateWeapon::CreateItem), a stdcall with two
// stack words (ret 8). It pushes its second argument and the object at [[0x70039c]+0x9b]+0xadc, calls 0x46d530 (callee pops, the first argument
// of the call is the object) and returns that result. The first argument of this function is not read. ecx passes through untouched.
// 0x46d530 is another claim (hooked by address in the spec, GUESS). Assembly, so the stack layout matches the exe.
#include "ff.h"

extern "C" void fn46d5d0(void);
extern "C" u32 ext_46d530(void);   // hooked in the spec; the callee pops its two arguments

asm(
    ".text\n"
    ".globl fn46d5d0\n"
    "fn46d5d0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 0x70039c, %eax\n"
    "  pushl 0xc(%ebp)\n"
    "  movl 0x9b(%eax), %eax\n"
    "  pushl 0xadc(%eax)\n"
    "  call ext_46d530\n"
    "  popl %ebp\n"
    "  ret $8\n");

PCREG(46d5d0, fn46d5d0);
