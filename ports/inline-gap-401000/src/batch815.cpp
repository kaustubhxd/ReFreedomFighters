// batch815.cpp - core gameplay batch 815 (docs/20-unclaimed-65.md, batch 815): 0x55fa00, a stdcall with one object argument (ret 4).
// It reads the word at obj+0x10 as an index. If the index is below the count at 0x7140c8, it pushes the object and calls the table entry
// 0x7140d0[index] (no ecx set: the entry is called with the caller's ecx, and it pops its argument). Otherwise it stores index - count
// back into the word, rewrites its own argument with the object and tail-jumps to 0x5060b0 (which pops the argument).
// The tail jump and the stack rewrite must match the exe, so the whole function is assembly.
#include "ff.h"

extern "C" void fn55fa00(void);
extern "C" void ext_5060b0(void);   // tail target (another claim; hooked in the spec)

asm(
    ".text\n"
    ".globl fn55fa00\n"
    "fn55fa00:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  movl 8(%ebp), %eax\n"
    "  pushl %esi\n"
    "  movzwl 0x10(%eax), %edx\n"
    "  movl %edx, %esi\n"
    "  cmpl 0x7140c8, %esi\n"
    "  jae 1f\n"
    "  pushl %eax\n"
    "  movl 0x7140d0(,%esi,4), %eax\n"
    "  call *%eax\n"
    "  popl %esi\n"
    "  popl %ebp\n"
    "  ret $4\n"
    "1:\n"
    "  subl 0x7140c8, %edx\n"
    "  movw %dx, 0x10(%eax)\n"
    "  popl %esi\n"
    "  movl %eax, 8(%ebp)\n"
    "  popl %ebp\n"
    "  jmp ext_5060b0\n");

PCREG(55fa00, fn55fa00);
