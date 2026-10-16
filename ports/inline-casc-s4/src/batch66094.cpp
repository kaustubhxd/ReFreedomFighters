// batch66094.cpp - cascade s4 batch 66094: 0x5df176 (cold fragment of a larger function: pushes two floats (120.0, 300.0) and edi, calls 0x5deb20 on esi and returns from the enclosing /GS frame with ret 0x18; literal transcription, the spec builds the enclosing frame).
#include "ff.h"

extern "C" void ext_5deb20(void);
extern "C" void ext_633654(void);

asm(
    ".text\n"
    ".intel_syntax noprefix\n"
    ".globl thunk5df176\n"
    "thunk5df176:\n"
    "sub    esp, 8\n"
    "mov    dword ptr [esp + 4], 0x43960000\n"
    "mov    dword ptr [esp], 0x42f00000\n"
    "jmp L5df19c\n"
    "L5df19c:\n"
    "push   edi\n"
    "mov    ecx, esi\n"
    "call ext_5deb20\n"
    "mov    ecx, dword ptr [ebp - 4]\n"
    "pop    edi\n"
    "xor    ecx, ebp\n"
    "pop    esi\n"
    "call ext_633654\n"
    "mov    esp, ebp\n"
    "pop    ebp\n"
    "ret    0x18\n"
    ".att_syntax prefix\n");

extern "C" void thunk5df176(void);
PCREG(5df176, thunk5df176);
