// batch66093.cpp - cascade s4 batch 66093: 0x4248e0 (RDTSC reader: stores EDX:EAX in a local through pushal/popal and returns it; literal transcription, the spec pins RDTSC to a fixed value).
#include "ff.h"


asm(
    ".text\n"
    ".intel_syntax noprefix\n"
    ".globl thunk4248e0\n"
    "thunk4248e0:\n"
    "push   ebp\n"
    "mov    ebp, esp\n"
    "sub    esp, 8\n"
    "push   ebx\n"
    "push   esi\n"
    "push   edi\n"
    "pushal\n"
    "rdtsc\n"
    "lea    ebx, [ebp - 8]\n"
    "mov    dword ptr [ebx], eax\n"
    "mov    dword ptr [ebx + 4], edx\n"
    "popal\n"
    "mov    eax, dword ptr [ebp - 8]\n"
    "mov    edx, dword ptr [ebp - 4]\n"
    "pop    edi\n"
    "pop    esi\n"
    "pop    ebx\n"
    "mov    esp, ebp\n"
    "pop    ebp\n"
    "ret\n"
    ".att_syntax prefix\n");

extern "C" void thunk4248e0(void);
PCREG(4248e0, thunk4248e0);
