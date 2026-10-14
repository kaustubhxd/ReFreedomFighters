// batch34000.cpp - cascade escalation batch 34000: two vtable tail-jump thunks and a constant stdcall.
// The thunks are assembly so the entry stack is untouched at the jump (arguments pass through to the slot).
#include "ff.h"

extern "C" void thunk46efc0(void);
extern "C" void thunk4cbad0(void);

asm(
    ".text\n"
    ".globl thunk46efc0\n"
    "thunk46efc0:\n"          // 0x46efc0: jump to slot 0x2e8 of this's vtable
    "  movl (%ecx), %eax\n"
    "  jmp *0x2e8(%eax)\n"
    ".globl thunk4cbad0\n"
    "thunk4cbad0:\n"          // 0x4cbad0: jump to slot 0xc of this's vtable
    "  movl (%ecx), %eax\n"
    "  jmp *0xc(%eax)\n");
PCREG(46efc0, thunk46efc0);
PCREG(4cbad0, thunk4cbad0);

// 0x539c60, stdcall with one ignored argument (ret 4): returns 1.
static u32 STDCALL fn539c60(u32) { return 1; }
PCREG(539c60, fn539c60);
