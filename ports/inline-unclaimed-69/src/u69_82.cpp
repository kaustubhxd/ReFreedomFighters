// u69_82.cpp - area 69, residue-8 forwarders to 0x4cbec0 (thiscall, no args, plain ret): `lea ecx,[ebp-N]; jmp 0x4cbec0`, no frame, stack untouched.
// Same target and shape as 0x664202 (u69_80.cpp); the offset N is per address (0x90, or 0xa8 for 0x6672c7).
#include "ff.h"

extern "C" void THISCALL ext_4cbec0(void *self);   // thiscall, no args, plain ret (real exe function)

extern "C" void fwd664346(void);
__asm__(
    ".text\n"
    ".globl fwd664346\n"
    "fwd664346:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(664346, fwd664346);

extern "C" void fwd664fc7(void);
__asm__(
    ".text\n"
    ".globl fwd664fc7\n"
    "fwd664fc7:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(664fc7, fwd664fc7);

extern "C" void fwd665d88(void);
__asm__(
    ".text\n"
    ".globl fwd665d88\n"
    "fwd665d88:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(665d88, fwd665d88);

extern "C" void fwd666000(void);
__asm__(
    ".text\n"
    ".globl fwd666000\n"
    "fwd666000:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(666000, fwd666000);

extern "C" void fwd666dc0(void);
__asm__(
    ".text\n"
    ".globl fwd666dc0\n"
    "fwd666dc0:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(666dc0, fwd666dc0);

extern "C" void fwd668bc0(void);
__asm__(
    ".text\n"
    ".globl fwd668bc0\n"
    "fwd668bc0:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(668bc0, fwd668bc0);

extern "C" void fwd6672c7(void);
__asm__(
    ".text\n"
    ".globl fwd6672c7\n"
    "fwd6672c7:\n"
    "  leal -0xa8(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(6672c7, fwd6672c7);

