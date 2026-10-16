// u69_95.cpp - area 69, residue-8 forwarders (listed separately, targets are GUESS hooks). Each is `mov ecx,[ebp+D]; jmp T`: no frame, stack untouched.
#include "ff.h"

extern "C" void ext_433f30(void);
extern "C" void ext_449d80(void);
extern "C" void ext_4d4d20(void);
extern "C" void ext_4f6b20(void);
extern "C" void ext_534be0(void);
extern "C" void ext_616a40(void);
extern "C" void ext_64f380(void);

extern "C" void fwd6645c0(void);
__asm__(
    ".text\n"
    ".globl fwd6645c0\n"
    "fwd6645c0:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_433f30\n");
PCREG(6645c0, fwd6645c0);

extern "C" void fwd668581(void);
__asm__(
    ".text\n"
    ".globl fwd668581\n"
    "fwd668581:\n"
    "  movl -0x14(%ebp), %ecx\n"
    "  jmp ext_4f6b20\n");
PCREG(668581, fwd668581);

extern "C" void fwd668a81(void);
__asm__(
    ".text\n"
    ".globl fwd668a81\n"
    "fwd668a81:\n"
    "  movl -0x14(%ebp), %ecx\n"
    "  jmp ext_4f6b20\n");
PCREG(668a81, fwd668a81);

extern "C" void fwd668d00(void);
__asm__(
    ".text\n"
    ".globl fwd668d00\n"
    "fwd668d00:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_4f6b20\n");
PCREG(668d00, fwd668d00);

extern "C" void fwd669480(void);
__asm__(
    ".text\n"
    ".globl fwd669480\n"
    "fwd669480:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_4d4d20\n");
PCREG(669480, fwd669480);

extern "C" void fwd669840(void);
__asm__(
    ".text\n"
    ".globl fwd669840\n"
    "fwd669840:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_449d80\n");
PCREG(669840, fwd669840);

extern "C" void fwd66a740(void);
__asm__(
    ".text\n"
    ".globl fwd66a740\n"
    "fwd66a740:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_534be0\n");
PCREG(66a740, fwd66a740);

extern "C" void fwd66c400(void);
__asm__(
    ".text\n"
    ".globl fwd66c400\n"
    "fwd66c400:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_4f6b20\n");
PCREG(66c400, fwd66c400);

extern "C" void fwd66e5c0(void);
__asm__(
    ".text\n"
    ".globl fwd66e5c0\n"
    "fwd66e5c0:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_616a40\n");
PCREG(66e5c0, fwd66e5c0);

extern "C" void fwd66ed40(void);
__asm__(
    ".text\n"
    ".globl fwd66ed40\n"
    "fwd66ed40:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  jmp ext_64f380\n");
PCREG(66ed40, fwd66ed40);

