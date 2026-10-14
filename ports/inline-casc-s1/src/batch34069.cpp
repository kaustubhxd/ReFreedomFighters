// batch34069.cpp - escalation batch 34069: vtable tail forwarders 0x4c5610 / 0x59a8d0 / 0x64fad0 (asm, stack untouched at the jump) and the flag getter 0x4d61c0.
#include "ff.h"

extern "C" void thunk4c5610(void);
extern "C" void thunk59a8d0(void);
extern "C" void thunk64fad0(void);
asm(
    ".text\n"
    ".globl thunk4c5610\n"
    "thunk4c5610:\n"          // slot 0x84 of this
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov (%ecx), %eax\n"
    "  pop %ebp\n"
    "  jmp *0x84(%eax)\n"
    ".globl thunk59a8d0\n"
    "thunk59a8d0:\n"          // this = [this+0x1d0f]; null: ret 4; else slot 0x214
    "  push %ebp\n  mov %esp, %ebp\n"
    "  mov 0x1d0f(%ecx), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je 1f\n"
    "  mov (%ecx), %eax\n"
    "  pop %ebp\n"
    "  jmp *0x214(%eax)\n"
    "1:\n"
    "  pop %ebp\n"
    "  ret $4\n"
    ".globl thunk64fad0\n"
    "thunk64fad0:\n"          // this = [this+0xbd]; null: ret; else slot 0x60
    "  mov 0xbd(%ecx), %ecx\n"
    "  test %ecx, %ecx\n"
    "  je 2f\n"
    "  mov (%ecx), %eax\n"
    "  jmp *0x60(%eax)\n"
    "2:\n"
    "  ret\n");
PCREG(4c5610, thunk4c5610);
PCREG(59a8d0, thunk59a8d0);
PCREG(64fad0, thunk64fad0);

// 0x4d61c0, stdcall(a) ret 4: [a+0x42e] (unaligned dword) == 1.
static bool STDCALL fn4d61c0(u8 *a) {
  u8 *p = a + 0x42e;
  u32 v = p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24;
  return v == 1;
}
PCREG(4d61c0, fn4d61c0);
