// u69_81.cpp - area 69, residue-8 forwarder. 0x66ee80: `mov ecx,0x6ff938; jmp 0x4d23c0`, no frame, stack untouched.
// The target 0x4d23c0 is the real function (thiscall, no args, plain ret): `mov [ecx],0x696168; ret`, which sets the vtable of the global object at 0x6ff938.
#include "ff.h"

extern "C" void THISCALL ext_4d23c0(void *self);   // thiscall, no args, plain ret (real exe function)
extern "C" void fwd66ee80(void);
__asm__(
    ".text\n"
    ".globl fwd66ee80\n"
    "fwd66ee80:\n"
    "  movl $0x6ff938, %ecx\n"
    "  jmp ext_4d23c0\n");
PCREG(66ee80, fwd66ee80);
