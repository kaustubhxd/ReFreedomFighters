// batch828.cpp - core gameplay batch 828 (docs/20-unclaimed-65.md, batch 828): 0x59e350 (ZFFActor::ClassInit2), a thiscall with no arguments
// that ends in a TAIL JUMP to 0x5a04f0 (ecx = this). Step 1: slot 0x110 of this with (0x10, 0) (callee pops), then 0x477de0 (ecx = this,
// hooked). Step 2: r = slot 0x678 of this; X = slot 0x58 of the render sub-object's vtable (ecx = that object) with r; Y = slot 0x100 of X
// with 0x690428; [this+0x8ee] = Y; slot 0x6f4 of this with (1, 1) (callee pops); slot 0x6cc of this (no arguments); tail jump to 0x5a04f0.
// Written in assembly: the stack and the tail jump must match the exe. 0x477de0 and 0x5a04f0 are other claims (hooked by address in the spec).
#include "ff.h"

extern "C" void fn59e350(void);
extern "C" void ext_477de0(void);   // thiscall, no arguments (hooked in the spec)
extern "C" void ext_5a04f0(void);   // tail target (hooked in the spec)

asm(
    ".text\n"
    ".globl fn59e350\n"
    "fn59e350:\n"
    "  pushl %esi\n"
    "  movl %ecx, %esi\n"
    "  pushl $0\n"
    "  pushl $0x10\n"
    "  movl (%esi), %eax\n"
    "  call *0x110(%eax)\n"
    "  movl %esi, %ecx\n"
    "  call ext_477de0\n"
    "  movl %esi, %ecx\n"
    "  popl %esi\n"
    "  movl 0x70039c, %eax\n"
    "  pushl %esi\n"
    "  pushl %edi\n"
    "  movl %ecx, %edi\n"
    "  movl 0x9b(%eax), %eax\n"
    "  movl (%eax), %esi\n"
    "  movl (%edi), %eax\n"
    "  call *0x678(%eax)\n"
    "  movl 0x70039c, %ecx\n"
    "  pushl %eax\n"
    "  movl 0x9b(%ecx), %ecx\n"
    "  call *0x58(%esi)\n"
    "  pushl $0x690428\n"
    "  movl %eax, %ecx\n"
    "  movl (%eax), %edx\n"
    "  call *0x100(%edx)\n"
    "  movl %eax, 0x8ee(%edi)\n"
    "  movl %edi, %ecx\n"
    "  movl (%edi), %eax\n"
    "  pushl $1\n"
    "  pushl $1\n"
    "  call *0x6f4(%eax)\n"
    "  movl (%edi), %eax\n"
    "  movl %edi, %ecx\n"
    "  call *0x6cc(%eax)\n"
    "  movl %edi, %ecx\n"
    "  popl %edi\n"
    "  popl %esi\n"
    "  jmp ext_5a04f0\n");

PCREG(59e350, fn59e350);
