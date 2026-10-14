// u69_80.cpp - area 69, residue-8 forwarder. 0x664202: `lea ecx,[ebp-0x90]; jmp 0x4cbec0`, no frame, stack untouched.
// The target is the real function 0x4cbec0 (thiscall, no args, plain ret), not a stub; its arity is therefore 0.
#include "ff.h"

extern "C" void THISCALL ext_4cbec0(void *self);   // thiscall, no args, plain ret (real exe function)
extern "C" void fwd664202(void);
__asm__(
    ".text\n"
    ".globl fwd664202\n"
    "fwd664202:\n"
    "  leal -0x90(%ebp), %ecx\n"
    "  jmp ext_4cbec0\n");
PCREG(664202, fwd664202);
