// batch755.cpp - gap band batch 755 (docs/20-gap-band-401000.md): 0x41c750, seven plain calls then a tail jump to 0x511ad0. File-scope
// assembly: the calls keep the entry stack (no arguments), and the tail jump runs on it.
#include "ff.h"

extern "C" void tail41c750(void);

asm(
    ".text\n"
    ".globl tail41c750\n"
    "tail41c750:\n"
    "  call ext_4fae80\n"
    "  call ext_53ccb0\n"
    "  call ext_49e680\n"
    "  call ext_43db70\n"
    "  call ext_460cb0\n"
    "  call ext_4edef0\n"
    "  call ext_52a2c0\n"
    "  jmp ext_511ad0\n");

PCREG(41c750, tail41c750);
