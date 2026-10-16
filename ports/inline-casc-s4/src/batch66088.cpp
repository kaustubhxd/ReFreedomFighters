// batch66088.cpp - cascade s4 batch 66088: 0x57b610 (thiscall(a, b) ret 8: prepare via 0x562e90, call slot 0x350 of this->[0x84]() with (this[0x44], saved ecx slot, 0x10000), then slot 0x74 of the engine's slot 0xbc object; returns with only AL cleared; asm so the upper EAX bits from slot 0x74 survive).
#include "ff.h"

extern "C" void ext_562e90(void);

asm(
    ".text\n"
    ".globl thunk57b610\n"
    "thunk57b610:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  pushl %esi\n"
    "  pushl 0xc(%ebp)\n"
    "  movl %ecx, %esi\n"
    "  pushl 8(%ebp)\n"
    "  call ext_562e90\n"
    "  movl (%esi), %eax\n"
    "  movl %esi, %ecx\n"
    "  call *0x84(%eax)\n"
    "  pushl 0x44(%esi)\n"
    "  pushl %ecx\n"
    "  movl %esp, %ecx\n"
    "  pushl $0x10000\n"
    "  movl $0, (%ecx)\n"
    "  movl %eax, %ecx\n"
    "  movl (%eax), %edx\n"
    "  call *0x350(%edx)\n"
    "  movl 0x70039c, %ecx\n"
    "  movl (%ecx), %eax\n"
    "  call *0xbc(%eax)\n"
    "  movl %eax, %ecx\n"
    "  movl (%eax), %edx\n"
    "  call *0x74(%edx)\n"
    "  xorb %al, %al\n"
    "  popl %esi\n"
    "  popl %ebp\n"
    "  ret $8\n");

extern "C" void thunk57b610(void);
PCREG(57b610, thunk57b610);
