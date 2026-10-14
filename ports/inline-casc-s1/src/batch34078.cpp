// batch34078.cpp - escalation batch 34078: tail thunks 0x4f4b60 / 0x536350 / 0x596d00 / 0x517510 / 0x5c08d0 (assembly, argument slot rewritten in place) and the table getter 0x4e5080.
#include "ff.h"

extern "C" void thunk4f4b60(void);
extern "C" void thunk536350(void);
extern "C" void thunk596d00(void);
extern "C" void thunk517510(void);
extern "C" void thunk5c08d0(void);
asm(
    ".text\n"
    ".globl thunk4f4b60\n"
    "thunk4f4b60:\n"          // arg = arg ? 0x10 : 1; tail through slot 0x2ec
    "  push %ebp\n  mov %esp, %ebp\n"
    "  cmpb $0, 8(%ebp)\n"
    "  mov (%ecx), %eax\n"
    "  je 1f\n"
    "  movl $0x10, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp *0x2ec(%eax)\n"
    "1:\n"
    "  movl $1, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp *0x2ec(%eax)\n"
    ".globl thunk536350\n"
    "thunk536350:\n"          // non-zero arg: arg += [this+0x5302], tail through slot 0x1ec; zero: ret 4
    "  push %ebp\n  mov %esp, %ebp\n"
    "  cmpl $0, 8(%ebp)\n"
    "  je 2f\n"
    "  mov 0x5302(%ecx), %eax\n"
    "  mov (%ecx), %edx\n"
    "  add %eax, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp *0x1ec(%edx)\n"
    "2:\n"
    "  pop %ebp\n"
    "  ret $4\n"
    ".globl thunk596d00\n"
    "thunk596d00:\n"          // [this+0x1fb6] = arg; this = [this+0x1d0f]; null: ret 4; else tail to 0x5a5e90
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 8(%ebp), %eax\n"
    "  mov %eax, 0x1fb6(%ecx)\n"
    "  mov 0x1d0f(%ecx), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je 3f\n"
    "  mov %eax, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp ext_5a5e90\n"
    "3:\n"
    "  pop %ebp\n"
    "  ret $4\n"
    ".globl thunk517510\n"
    "thunk517510:\n"          // when low word of arg == word [this+0x164e] and counter [this+0x1639] > 0: counter--; tail to 0x5153e0
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 8(%ebp), %edx\n"
    "  cmpw 0x164e(%ecx), %dx\n"
    "  jne 4f\n"
    "  mov 0x1639(%ecx), %eax\n"
    "  test %eax, %eax\n"
    "  jle 4f\n"
    "  dec %eax\n"
    "  mov %eax, 0x1639(%ecx)\n"
    "4:\n"
    "  mov %edx, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp ext_5153e0\n"
    ".globl thunk5c08d0\n"
    "thunk5c08d0:\n"          // arg < [this+0x54] (signed): arg = arg * 0x17 + [this+0x50], tail through slot 0x98; else ret 4
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 8(%ebp), %eax\n"
    "  cmp 0x54(%ecx), %eax\n"
    "  jge 5f\n"
    "  mov (%ecx), %edx\n"
    "  imul $0x17, %eax, %eax\n"
    "  add 0x50(%ecx), %eax\n"
    "  mov %eax, 8(%ebp)\n"
    "  pop %ebp\n"
    "  jmp *0x98(%edx)\n"
    "5:\n"
    "  pop %ebp\n"
    "  ret $4\n");
PCREG(4f4b60, thunk4f4b60);
PCREG(536350, thunk536350);
PCREG(596d00, thunk596d00);
PCREG(517510, thunk517510);
PCREG(5c08d0, thunk5c08d0);

// 0x4e5080, thiscall(a) ret 4: dword at [a+0x80] + [this+0xc] (byte offset into a table).
static u32 THISCALL fn4e5080(u8 *self, u8 *a) {
  return *(u32 *)(*(u8 **)(a + 0x80) + *(u32 *)(self + 0xc));
}
PCREG(4e5080, fn4e5080);
