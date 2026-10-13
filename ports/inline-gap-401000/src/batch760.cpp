// batch760.cpp - gap band batch 760 (docs/20-gap-band-401000.md): 0x41ce80, cdecl, no arguments; the exit path (_exit(1) through the
// import slot 0x676394, which does not return). File-scope assembly: the C form adds a frame, which moves the caller's return address
// away from the stack shape the exe has at the _exit call.
#include "ff.h"

extern "C" void fn41ce80(void);

asm(
    ".text\n"
    ".globl fn41ce80\n"
    "fn41ce80:\n"
    "  movl 0x700390, %ecx\n"          // the object: its slot 0x20 with (0x676ad8, 0x71), callee pops 8
    "  pushl $0x71\n"
    "  pushl $0x676ad8\n"
    "  movl (%ecx), %eax\n"
    "  call *0x20(%eax)\n"
    "  pushl $0x676b3c\n"              // slot 0x2c of the returned object r, ecx = its vtable, args (r, 0x676b3c), caller cleans 8
    "  pushl %eax\n"
    "  movl (%eax), %ecx\n"
    "  call *0x2c(%ecx)\n"
    "  addl $8, %esp\n"
    "  pushl $1\n"                     // _exit(1) through the import slot (cdecl, no cleanup; does not return)
    "  call *0x676394\n"
    "  ret\n");

PCREG(41ce80, fn41ce80);
