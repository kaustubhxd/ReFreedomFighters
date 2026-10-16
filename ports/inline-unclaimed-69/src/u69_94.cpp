// u69_94.cpp - area 69, residue-8 forwarders (listed separately, targets are GUESS hooks in the spec). Each is `lea ecx,[ebp+D]; jmp T`
// or `mov ecx,[ebp+D]; add ecx,N; jmp T`: no frame, stack untouched. Only the forwarder is checked; the targets are not verified bodies.
#include "ff.h"

extern "C" void ext_42ba10(void);
extern "C" void ext_4cbec0(void);
extern "C" void ext_4ccf60(void);
extern "C" void ext_4d2330(void);
extern "C" void ext_4f6b20(void);
extern "C" void ext_4ff9d0(void);
extern "C" void ext_5a5440(void);

extern "C" void fwd664acc(void);
__asm__(
    ".text\n"
    ".globl fwd664acc\n"
    "fwd664acc:\n"
    "  movl -0x9c(%ebp), %ecx\n"
    "  addl $0x6a3, %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(664acc, fwd664acc);

extern "C" void fwd666dcb(void);
__asm__(
    ".text\n"
    ".globl fwd666dcb\n"
    "fwd666dcb:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(666dcb, fwd666dcb);

extern "C" void fwd667b83(void);
__asm__(
    ".text\n"
    ".globl fwd667b83\n"
    "fwd667b83:\n"
    "  leal -0x310(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(667b83, fwd667b83);

extern "C" void fwd667b8e(void);
__asm__(
    ".text\n"
    ".globl fwd667b8e\n"
    "fwd667b8e:\n"
    "  leal -0x210(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(667b8e, fwd667b8e);

extern "C" void fwd66844c(void);
__asm__(
    ".text\n"
    ".globl fwd66844c\n"
    "fwd66844c:\n"
    "  leal -0x1b4(%ebp), %ecx\n"
    "  jmp ext_4f6b20\n");
PCREG(66844c, fwd66844c);

extern "C" void fwd669ac0(void);
__asm__(
    ".text\n"
    ".globl fwd669ac0\n"
    "fwd669ac0:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(669ac0, fwd669ac0);

extern "C" void fwd669e80(void);
__asm__(
    ".text\n"
    ".globl fwd669e80\n"
    "fwd669e80:\n"
    "  leal -0x40d4(%ebp), %ecx\n"
    "  jmp ext_4d2330\n");
PCREG(669e80, fwd669e80);

extern "C" void fwd66a605(void);
__asm__(
    ".text\n"
    ".globl fwd66a605\n"
    "fwd66a605:\n"
    "  leal -0xbc(%ebp), %ecx\n"
    "  jmp ext_4ccf60\n");
PCREG(66a605, fwd66a605);

extern "C" void fwd66aec0(void);
__asm__(
    ".text\n"
    ".globl fwd66aec0\n"
    "fwd66aec0:\n"
    "  leal -0x108(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(66aec0, fwd66aec0);

extern "C" void fwd66bdc0(void);
__asm__(
    ".text\n"
    ".globl fwd66bdc0\n"
    "fwd66bdc0:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(66bdc0, fwd66bdc0);

extern "C" void fwd66bdcb(void);
__asm__(
    ".text\n"
    ".globl fwd66bdcb\n"
    "fwd66bdcb:\n"
    "  leal -0x110(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(66bdcb, fwd66bdcb);

extern "C" void fwd66da80(void);
__asm__(
    ".text\n"
    ".globl fwd66da80\n"
    "fwd66da80:\n"
    "  leal -0x2c(%ebp), %ecx\n"
    "  jmp ext_42ba10\n");
PCREG(66da80, fwd66da80);

extern "C" void fwd66de40(void);
__asm__(
    ".text\n"
    ".globl fwd66de40\n"
    "fwd66de40:\n"
    "  leal -0x1c(%ebp), %ecx\n"
    "  jmp ext_5a5440\n");
PCREG(66de40, fwd66de40);

extern "C" void fwd66de48(void);
__asm__(
    ".text\n"
    ".globl fwd66de48\n"
    "fwd66de48:\n"
    "  leal -0x1c(%ebp), %ecx\n"
    "  jmp ext_4ff9d0\n");
PCREG(66de48, fwd66de48);

