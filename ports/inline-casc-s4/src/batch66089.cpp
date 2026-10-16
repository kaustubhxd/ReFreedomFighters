// batch66089.cpp - cascade s4 batch 66089: 0x659000 (thiscall(): resolve a nested resource and look its id up in the handle map; asm, literal transcription, unaligned sys reads kept).
#include "ff.h"

extern "C" void ext_63eab0(void);

// 0x659000, thiscall() returns eax. i = word [this+0xa]; a = [this+0x10]. i == 0: return [a+0x10]->[0x10]. Else d = [a+0x10] (null -> 0), d = [d+0xc];
// i != 0: d = [sys+0x1aa3]->slot 0x80([[d+0x3c] + i*4 + 4]); d null -> 0. Then handle = [sys+0x190f]->slot 0x20(word [d+0x40]); return 0x63eab0(ecx = handle, handle->[0x68][id & 0xfff]).
asm(
    ".text\n"
    ".globl thunk659000\n"
    "thunk659000:\n"
    "  movzwl 0xa(%ecx), %eax\n"
    "  testw %ax, %ax\n"
    "  jne 1f\n"
    "  movl 0x10(%ecx), %eax\n"
    "  movl 0x10(%eax), %eax\n"
    "  ret\n"
    "1:\n"
    "  pushl %esi\n"
    "  movl %eax, %esi\n"
    "  movl 0x10(%ecx), %eax\n"
    "  movl 0x10(%eax), %edx\n"
    "  testl %edx, %edx\n"
    "  je 3f\n"
    "  movl 0xc(%edx), %edx\n"
    "  testl %esi, %esi\n"
    "  je 2f\n"
    "  movl 0x70039c, %eax\n"
    "  movl 0x3c(%edx), %edx\n"
    "  movl 0x1aa3(%eax), %ecx\n"
    "  pushl 4(%edx,%esi,4)\n"
    "  movl (%ecx), %eax\n"
    "  call *0x80(%eax)\n"
    "  movl %eax, %edx\n"
    "2:\n"
    "  testl %edx, %edx\n"
    "  je 3f\n"
    "  movl 0x70039c, %eax\n"
    "  movl 0x190f(%eax), %ecx\n"
    "  movzwl 0x40(%edx), %eax\n"
    "  pushl %eax\n"
    "  movl (%ecx), %eax\n"
    "  call *0x20(%eax)\n"
    "  movl %eax, %ecx\n"
    "  call ext_63eab0\n"
    "  popl %esi\n"
    "  ret\n"
    "3:\n"
    "  xorl %eax, %eax\n"
    "  popl %esi\n"
    "  ret\n");

extern "C" void thunk659000(void);
PCREG(659000, thunk659000);
