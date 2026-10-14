// u69_93.cpp - area 69, residue-8 forwarders into SEH-framed functions. Each is `mov ecx,[ebp-0x10]; add ecx,N; jmp T` or `lea ecx,[ebp-N]; jmp T`:
// no frame, stack untouched. The targets are the real exe functions (plain ret); they are hooked as GUESS stubs in the spec, so only the forwarder itself is checked.
#include "ff.h"

extern "C" void ext_42ba10(void);
extern "C" void ext_480fd0(void);
extern "C" void ext_4ccf60(void);
extern "C" void ext_511950(void);
extern "C" void ext_5a5440(void);

extern "C" void fwd668d08(void);
__asm__(
    ".text\n"
    ".globl fwd668d08\n"
    "fwd668d08:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  addl $0x4c, %ecx\n"
    "  jmp ext_4ccf60\n");
PCREG(668d08, fwd668d08);

extern "C" void fwd668d13(void);
__asm__(
    ".text\n"
    ".globl fwd668d13\n"
    "fwd668d13:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  addl $0xfc, %ecx\n"
    "  jmp ext_4ccf60\n");
PCREG(668d13, fwd668d13);

extern "C" void fwd66c408(void);
__asm__(
    ".text\n"
    ".globl fwd66c408\n"
    "fwd66c408:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  addl $0x84, %ecx\n"
    "  jmp ext_4ccf60\n");
PCREG(66c408, fwd66c408);

extern "C" void fwd66c906(void);
__asm__(
    ".text\n"
    ".globl fwd66c906\n"
    "fwd66c906:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  addl $0x3eb, %ecx\n"
    "  jmp ext_480fd0\n");
PCREG(66c906, fwd66c906);

extern "C" void fwd66a108(void);
__asm__(
    ".text\n"
    ".globl fwd66a108\n"
    "fwd66a108:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  addl $0x2d8, %ecx\n"
    "  jmp ext_511950\n");
PCREG(66a108, fwd66a108);

extern "C" void fwd66ce04(void);
__asm__(
    ".text\n"
    ".globl fwd66ce04\n"
    "fwd66ce04:\n"
    "  movl -0x10(%ebp), %ecx\n"
    "  addl $0xac, %ecx\n"
    "  jmp ext_5a5440\n");
PCREG(66ce04, fwd66ce04);

extern "C" void fwd665101(void);
__asm__(
    ".text\n"
    ".globl fwd665101\n"
    "fwd665101:\n"
    "  leal -0x3f9c(%ebp), %ecx\n"
    "  jmp ext_42ba10\n");
PCREG(665101, fwd665101);

