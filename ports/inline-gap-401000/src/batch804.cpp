// batch804.cpp - core gameplay batch 804 (docs/20-unclaimed-65.md, batch 804): tail-jump thunks (assembly) and two small thiscall methods.
#include "ff.h"

typedef u32(THISCALL *F0)(u8 *self);
static u32 vc0(u8 *o, u32 s) { return ((F0)(*(const u32 *)(*(const u32 *)o + s)))(o); }

extern "C" void thunk5dbc10(void);
extern "C" void thunk5c26e0(void);
extern "C" void thunk5c39e0(void);
extern "C" void thunk5dc8a0(void);
extern "C" void thunk5c4190(void);

asm(
    ".text\n"
    ".globl thunk5dbc10\n"
    "thunk5dbc10:\n"
    "  jmp ext_5dbc30\n"
    ".globl thunk5c26e0\n"
    "thunk5c26e0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  popl %ebp\n"
    "  jmp ext_5c2870\n"
    ".globl thunk5c39e0\n"
    "thunk5c39e0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  popl %ebp\n"
    "  jmp ext_5c3b00\n"
    ".globl thunk5dc8a0\n"
    "thunk5dc8a0:\n"
    "  pushl %ebp\n"
    "  movl %esp, %ebp\n"
    "  popl %ebp\n"
    "  jmp ext_5dcea0\n"
    ".globl thunk5c4190\n"
    "thunk5c4190:\n"
    "  movl 0x48(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0xc(%eax)\n");

static void THISCALL fn4a0e90(u8 *self) {
  *(u32 *)(self + 0x5a) |= 1;
}

static u32 THISCALL fn4783f0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  (void)a; (void)b; (void)c; (void)d;
  vc0(self, 0x664);
  return 0;
}

PCREG(5dbc10, thunk5dbc10);
PCREG(4a0e90, fn4a0e90);
PCREG(4783f0, fn4783f0);
PCREG(5c4190, thunk5c4190);
PCREG(5c26e0, thunk5c26e0);
PCREG(5c39e0, thunk5c39e0);
PCREG(5dc8a0, thunk5dc8a0);
