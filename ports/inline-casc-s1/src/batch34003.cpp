// batch34003.cpp - cascade escalation batch 34003: thiscall vtable forwarders and tail stubs (assembly, entry stack untouched at the jump),
// plus a bit clear, a compare and a vtable store.
#include "ff.h"

extern "C" void thunk467cf0(void);
extern "C" void thunk474460(void);
extern "C" void thunk562380(void);
extern "C" void thunk650c10(void);
extern "C" void thunk64f930(void);
extern "C" void thunk465a70(void);
extern "C" void thunk474670(void);
extern "C" void thunk453120(void);
extern "C" void thunk5b0290(void);

asm(
    ".text\n"
    ".globl thunk467cf0\n"
    "thunk467cf0:\n"
    "  movl 0x1ce(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x8(%eax)\n"
    ".globl thunk474460\n"
    "thunk474460:\n"
    "  addl $0x2e7, %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x14(%eax)\n"
    ".globl thunk562380\n"
    "thunk562380:\n"
    "  movl 0x44(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x2c4(%eax)\n"
    ".globl thunk650c10\n"
    "thunk650c10:\n"
    "  movl 0x8c(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0xc(%eax)\n"
    ".globl thunk64f930\n"
    "thunk64f930:\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x4(%eax)\n"
    ".globl thunk465a70\n"
    "thunk465a70:\n"
    "  movl 0x1ce(%ecx), %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0xc(%eax)\n"
    ".globl thunk474670\n"
    "thunk474670:\n"
    "  addl $0x34f, %ecx\n"
    "  movl (%ecx), %eax\n"
    "  jmp *0x10(%eax)\n"
    ".globl thunk453120\n"
    "thunk453120:\n"          // this += 0x22, edx = 4, then 0x4e2bb0
    "  addl $0x22, %ecx\n"
    "  movl $4, %edx\n"
    "  jmp ext_4e2bb0\n"
    ".globl thunk5b0290\n"
    "thunk5b0290:\n"          // dword +0x1d91 = 0x40000000, byte +0x1d8c = 1, then 0x5b0220
    "  movl $0x40000000, 0x1d91(%ecx)\n"
    "  movb $1, 0x1d8c(%ecx)\n"
    "  jmp ext_5b0220\n");
PCREG(467cf0, thunk467cf0);
PCREG(474460, thunk474460);
PCREG(562380, thunk562380);
PCREG(650c10, thunk650c10);
PCREG(64f930, thunk64f930);
PCREG(465a70, thunk465a70);
PCREG(474670, thunk474670);
PCREG(453120, thunk453120);
PCREG(5b0290, thunk5b0290);

// 0x4c8350, thiscall ret 4 (arg ignored): clear bit 6 of dword +4, return true.
static bool THISCALL fn4c8350(u8 *self, u32) {
  *(u32 *)(self + 4) &= ~0x40u;
  return true;
}
PCREG(4c8350, fn4c8350);

// 0x46f500, thiscall: signed [this+0x8c] >= 5.
static bool THISCALL fn46f500(u8 *self) { return *(s32 *)(self + 0x8c) >= 5; }
PCREG(46f500, fn46f500);

// 0x655a60, thiscall ret 4 (arg ignored): vtable = 0x6c3be4, return this.
static u8 *THISCALL fn655a60(u8 *self, u32) {
  *(u32 *)self = 0x6c3be4;
  return self;
}
PCREG(655a60, fn655a60);
