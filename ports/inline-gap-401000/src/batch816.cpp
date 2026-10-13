// batch816.cpp - core gameplay batch 816 (docs/20-unclaimed-65.md, batch 816): 0x4a1140, a thiscall with no arguments that sets five
// fields of this, calls slot 0x1e0 of [this+0x44] with one argument (0x1007d1, callee pops) and stores its al at +0x64, sets cl = 1,
// stores bit 1 of [[[this+0x44]+8]+0x3c] at +0x65, and TAIL-JUMPS to 0x4a0d40 with ecx's low byte 1. The tail target's arity is unknown
// (another claim; hooked by address in the spec), so the jump is kept as assembly with the entry stack unchanged.
#include "ff.h"

extern "C" void fn4a1140(void);
extern "C" void ext_4a0d40(void);   // tail target (another claim; hooked in the spec)

asm(
    ".text\n"
    ".globl fn4a1140\n"
    "fn4a1140:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl $0x1007d1\n"
    "  movl 0x44(%esi), %ecx\n"
    "  movb $0, 0x5e(%esi)\n"
    "  movl $3, 0x66(%esi)\n"
    "  movb $0, 0x63(%esi)\n"
    "  movl $2, 0x5a(%esi)\n"
    "  movl (%ecx), %eax\n"
    "  movl 0x1e0(%eax), %eax\n"
    "  call *%eax\n"
    "  movb %al, 0x64(%esi)\n"
    "  movb $1, %cl\n"
    "  movl 0x44(%esi), %eax\n"
    "  movl 8(%eax), %eax\n"
    "  movl 0x3c(%eax), %eax\n"
    "  shrl $1, %eax\n"
    "  andb $1, %al\n"
    "  movb %al, 0x65(%esi)\n"
    "  popl %esi\n"
    "  jmp ext_4a0d40\n");

PCREG(4a1140, fn4a1140);
